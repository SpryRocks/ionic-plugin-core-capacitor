import {IDefinitions, PluginProxy} from './definitions';
import {Mappers} from './mappers';

export abstract class CapacitorPlugin<
  TDefinitions extends IDefinitions,
  TMappers extends Mappers,
> {
  protected abstract readonly mappers: TMappers;

  public constructor(private readonly plugin: PluginProxy<TDefinitions>) {}

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
}
