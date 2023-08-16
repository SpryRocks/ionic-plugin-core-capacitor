import {
  createLoggerFactory,
  GlobalData,
  ILoggerObserver,
  LogData,
  LoggerObserver,
  prepareLogData,
} from './logger';
import {IDefinitions, PluginProxy} from './definitions';
import {
  LoggerFactory,
  LogLevel,
  LogParams,
  MultipleNotifiers,
} from '@spryrocks/logger-plugin';
import {Capacitor} from '@capacitor/core';
import {Mappers} from './mappers';
import {PluginError} from './error';

type LogEvent = {
  level: LogLevel;
  action: string | undefined;
  tag: string | undefined;
  message: string;
  params: LogParams;
};

export interface ICapacitorPlugin {
  get logObserver(): ILoggerObserver;
}

export type PluginOptions<TDefinitions extends IDefinitions> = {
  name: string;
  proxy: PluginProxy<TDefinitions>;
};

export abstract class CapacitorPlugin<
  TDefinitions extends IDefinitions,
  TMappers extends Mappers,
> implements ICapacitorPlugin
{
  private static readonly _logObserver = new LoggerObserver();

  private readonly _logObserver = new LoggerObserver();

  private readonly _logNotifiers = new MultipleNotifiers([
    this._logObserver,
    CapacitorPlugin._logObserver,
  ]);

  private readonly _loggerFactory: LoggerFactory<LogData, GlobalData>;

  protected abstract readonly mappers: TMappers;

  // noinspection TypeScriptAbstractClassConstructorCanBeMadeProtected
  constructor(private readonly options: PluginOptions<TDefinitions>) {
    this._loggerFactory = createLoggerFactory({
      notifier: this._logNotifiers,
      plugin: this.options?.name ?? 'Unknown plugin',
    });
    this.registerEvents();
  }

  // noinspection JSUnusedGlobalSymbols
  protected createLogger(tag?: string, action?: string) {
    return this._loggerFactory.createLogger(tag, {globalData: {action}});
  }

  // noinspection JSUnusedGlobalSymbols
  protected call<TMethod extends keyof TDefinitions>(
    method: TMethod,
    options: TDefinitions[TMethod]['options'],
  ): Promise<TDefinitions[TMethod]['result']> {
    return this.plugin[method](options, undefined).catch((error) => {
      const pluginError = this.mappers.createPluginError(error);
      this.logPluginError(method, pluginError);
      throw pluginError;
    });
  }

  // noinspection JSUnusedGlobalSymbols
  protected observe<TMethod extends keyof TDefinitions>(
    method: TMethod,
    options: TDefinitions[TMethod]['options'],
    callback: {
      next: (result: TDefinitions[TMethod]['result']) => void;
      error: (error: unknown) => void;
    },
  ): Promise<string> {
    const result = this.plugin[method](options, (data, error) => {
      if (error) {
        const pluginError = this.mappers.createPluginError(error);
        this.logPluginError(method, pluginError);
        callback.error(pluginError);
        return;
      }

      callback.next(data);
    }) as Promise<string>;
    return result.catch((error) => {
      const pluginError = this.mappers.createPluginError(error);
      this.logPluginError(method, pluginError);
      callback.error(pluginError);
    }) as Promise<string>;
  }

  private processLogEventReceived(event: LogEvent) {
    this._logNotifiers.notify(
      prepareLogData({
        data: {
          tag: event.tag,
          message: event.message,
          params: event.params,
          level: event.level,
          error: undefined,
        },
        globalData: {
          plugin: this.options.name,
          action: event.action,
          isNative: true,
        },
      }),
    );
  }

  private registerEvents() {
    if (Capacitor.getPlatform() !== 'web') {
      try {
        this.plugin.addListener('log', (event) => {
          this.processLogEventReceived(event as LogEvent);
        });
      } catch (e) {
        // eslint-disable-next-line no-console
        console.error(e);
      }
    }
  }

  private logPluginError(method: string | number | symbol, error: PluginError) {
    const logger = this.createLogger(undefined, method.toString());
    logger.error(error);
  }

  // noinspection JSUnusedGlobalSymbols
  public static get logObserver(): ILoggerObserver {
    return this._logObserver;
  }

  public get logObserver(): ILoggerObserver {
    return this._logObserver;
  }

  public get plugin() {
    return this.options.proxy;
  }
}
