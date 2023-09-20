import {CapacitorPlugin, PluginOptions} from './plugin';
import {IDefinitions} from './definitions';
import {Mappers} from './mappers';

export type PluginImplementation = unknown;
export type PluginRegistration = () => PluginImplementation;

export type CreateCapacitorPluginOptions = {
  pluginName: string;
  web?: PluginRegistration;
  cap2?: {pluginName: string};
};

export type CreateCapacitorPlugin = <TPlugin>(
  options: CreateCapacitorPluginOptions,
) => TPlugin;

export type CreatePluginOptions = CreateCapacitorPluginOptions & {pluginLogName: string};

export type PluginConstructor<
  TPlugin extends CapacitorPlugin<TDefinitions, TMappers>,
  TDefinitions extends IDefinitions,
  TMappers extends Mappers,
> = new (options: PluginOptions<TDefinitions>) => TPlugin;

export type CreatePlugin = <
  TPlugin extends CapacitorPlugin<TDefinitions, TMappers>,
  TDefinitions extends IDefinitions,
  TMappers extends Mappers,
>(
  pluginConstructor: PluginConstructor<TPlugin, TDefinitions, TMappers>,
  options: CreatePluginOptions,
) => TPlugin;
