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
    return this.plugin[method](options).catch((error) =>
      this.mappers.handlePluginError(error),
    );
  }
}
