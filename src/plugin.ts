import {IDefinitions, PluginProxy} from './definitions';
import {IPluginLogger, LogParams, LogType} from './logger';
import {Mappers} from './mappers';

type LogEvent = {
  type: LogType;
  action: string | undefined;
  tag: string | undefined;
  message: string;
  params: LogParams;
};

export interface ICapacitorPlugin {
  addLogger(logger: IPluginLogger): void;
}

export abstract class CapacitorPlugin<
  TDefinitions extends IDefinitions,
  TMappers extends Mappers,
> implements ICapacitorPlugin
{
  private static readonly staticLoggers: IPluginLogger[] = [];

  protected abstract readonly mappers: TMappers;

  private readonly loggers: IPluginLogger[] = [];

  public constructor(
    private readonly plugin: PluginProxy<TDefinitions>,
    private readonly options: {
      name: string;
    },
  ) {
    this.registerEvents();
  }

  public static addLogger(logger: IPluginLogger) {
    CapacitorPlugin.staticLoggers.push(logger);
  }

  public addLogger(logger: IPluginLogger) {
    this.loggers.push(logger);
  }

  protected call<TMethod extends keyof TDefinitions>(
    method: TMethod,
    options: TDefinitions[TMethod]['options'],
  ): Promise<TDefinitions[TMethod]['result']> {
    return (
      this.plugin[method](options, undefined) as Promise<TDefinitions[TMethod]['result']>
    ).catch((error) => this.mappers.handlePluginError(error));
  }

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
        callback.error(this.mappers.handlePluginError(error));
        return;
      }

      callback.next(data);
    }) as string;
    return Promise.resolve(result);
  }

  private processLogEventReceived(event: LogEvent) {
    for (let logger of [...CapacitorPlugin.staticLoggers, ...this.loggers]) {
      logger.onLogReceived({
        type: event.type,
        plugin: this.options.name,
        action: event.action,
        tag: event.tag,
        message: event.message,
        params: event.params,
      });
    }
  }

  private registerEvents() {
    this.plugin.addListener('log', (event) => {
      this.processLogEventReceived(event as LogEvent);
    });
  }
}
