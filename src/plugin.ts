import {
  CallbackId,
  CallbackResult,
  CapPluginListener,
  IDefinitions,
  PluginProxy,
} from './definitions';
import {
  createLoggerFactory,
  GlobalData,
  ILoggerObserver,
  LogData,
  LoggerObserver,
  prepareLogData,
} from './logger';
import {
  ErrorLevel,
  ILoggerFactory,
  LogLevel,
  LogParams,
  MultipleNotifiers,
} from '@spryrocks/logger-plugin';
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
  setLogLevels(logLevels: LogLevel[] | undefined): Promise<void>;
}

export type PluginOptions<TDefinitions extends IDefinitions> = {
  pluginName: string;
  pluginLogName: string;
  proxy: PluginProxy<TDefinitions>;
};

export abstract class CapacitorPlugin<
  TDefinitions extends IDefinitions,
  TMappers extends Mappers,
> implements ICapacitorPlugin
{
  private static readonly _logObserver = new LoggerObserver();

  private readonly _logObserver = new LoggerObserver();

  private readonly _logNotifiers = new MultipleNotifiers({
    notifiers: [this._logObserver, CapacitorPlugin._logObserver],
    filter: this.testLog.bind(this),
  });

  private readonly _loggerFactory: ILoggerFactory<GlobalData>;

  private logLevels: LogLevel[] | undefined;

  protected abstract readonly mappers: TMappers;

  // noinspection TypeScriptAbstractClassConstructorCanBeMadeProtected
  constructor(private readonly options: PluginOptions<TDefinitions>) {
    this._loggerFactory = createLoggerFactory({
      notifier: this._logNotifiers,
      plugin: this.options?.pluginLogName,
    });
    if (this.isEventsEnabled()) {
      this.initializeEventsInternal();
      this.initializeEvents();
    }
  }

  private initializeEventsInternal() {
    this.addEventListenerInternal<LogEvent>(
      'log',
      this.processLogEventReceived.bind(this),
    );
  }

  protected initializeEvents() {}

  // noinspection JSUnusedGlobalSymbols
  protected createLogger(tag?: string, action?: string) {
    return this._loggerFactory.createLogger(tag, {globalData: {action}});
  }

  // noinspection JSUnusedGlobalSymbols
  protected async call<TMethod extends keyof TDefinitions>(
    method: TMethod,
    options: TDefinitions[TMethod]['options'],
  ): Promise<TDefinitions[TMethod]['result']> {
    try {
      return await this.proxy[method](options, undefined);
    } catch (error) {
      const pluginError = this.mappers.createPluginError(error);
      this.logPluginError(method, pluginError);
      throw pluginError;
    }
  }

  // noinspection JSUnusedGlobalSymbols
  protected async observe<TMethod extends keyof TDefinitions>(
    method: TMethod,
    options: TDefinitions[TMethod]['options'],
    callback: {
      next: (result: TDefinitions[TMethod]['result']) => void;
      error: (error: unknown) => void;
    },
  ): CallbackResult {
    try {
      const callbackResult = this.proxy[method](options, (data, error) => {
        if (error) {
          const pluginError = this.mappers.createPluginError(error);
          this.logPluginError(method, pluginError);
          callback.error(pluginError);
          return;
        }

        callback.next(data);
      }) as CallbackResult;
      return await this.mapCallbackResult(callbackResult);
    } catch (error) {
      const pluginError = this.mappers.createPluginError(error);
      this.logPluginError(method, pluginError);
      throw pluginError;
    }
  }

  private mapCallbackResult(callbackResult: CallbackResult): Promise<CallbackId> {
    return callbackResult;
  }

  protected addEventListenerInternal<TListener>(
    name: string,
    listener: CapPluginListener<TListener>,
  ) {
    try {
      this.proxy.addListener(name, (event) => {
        // eslint-disable-next-line no-console
        console.log('CapacitorPlugin', 'event received', name, event);
        listener(event as TListener);
      });
    } catch (e) {
      // eslint-disable-next-line no-console
      console.error(`Cannot register ${name} listener`, e);
    }
  }

  protected isEventsEnabled() {
    // if (!this.isPluginAvailableInCapacitor()) return false;
    // if (this.isWeb()) return false;

    return true; // remove this method after implementation on web
  }

  // noinspection JSUnusedGlobalSymbols
  protected addEventListener<TMethod extends keyof TDefinitions>(
    name: TMethod,
    listener: CapPluginListener<TDefinitions[TMethod]['result']>,
  ) {
    this.addEventListenerInternal<TDefinitions[TMethod]['result']>(
      name as string,
      listener,
    );
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
          errorLevel: ErrorLevel.Medium,
        },
        globalData: {
          plugin: this.options.pluginLogName,
          action: event.action,
          isNative: true,
        },
      }),
    );
  }

  // private isPluginAvailableInCapacitor() {
  //   return Capacitor.isPluginAvailable(this.options.pluginName);
  // }

  // private isWeb() {
  //   return Capacitor.getPlatform() !== 'web';
  // }

  private logPluginError(method: string | number | symbol, error: PluginError) {
    const logger = this.createLogger(undefined, method.toString());
    logger.error(error, undefined, {level: ErrorLevel.Medium});
  }

  // noinspection JSUnusedGlobalSymbols
  public static get logObserver(): ILoggerObserver {
    return this._logObserver;
  }

  public get logObserver(): ILoggerObserver {
    return this._logObserver;
  }

  public get proxy() {
    return this.options.proxy;
  }

  public async setLogLevels(logLevels: LogLevel[] | undefined) {
    this.logLevels = logLevels;
    await this.call('setLogLevels', {
      logLevels: this.mappers.mapLogLevels(logLevels),
    }).catch(() => {});
  }

  private testLog(data: LogData) {
    const logLevels = this.logLevels;
    if (!logLevels) return true;
    return logLevels.includes(data.level);
  }
}
