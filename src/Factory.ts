import {
  CreateCapacitorPlugin,
  CreateCapacitorPluginOptions,
  CreatePlugin,
  CreatePluginOptions,
  PluginConstructor,
} from './IFactory';
import {IDefinitions, PluginProxy} from './definitions';
import {CapacitorPlugin} from './plugin';
import {Mappers} from './mappers';
import {Plugins} from '@capacitor/core';

export const createCapacitorPlugin: CreateCapacitorPlugin = <TPlugin>(
  options: CreateCapacitorPluginOptions,
): TPlugin => Plugins[options?.cap2?.pluginName ?? options.pluginName] as TPlugin;

export const createCapacitorPluginProxy = <TDefinitions extends IDefinitions>(
  options: CreateCapacitorPluginOptions,
) => createCapacitorPlugin<PluginProxy<TDefinitions>>(options);

export const createPlugin: CreatePlugin = <
  TPlugin extends CapacitorPlugin<TDefinitions, TMappers>,
  TDefinitions extends IDefinitions,
  TMappers extends Mappers,
>(
  pluginConstructor: PluginConstructor<TPlugin, TDefinitions, TMappers>,
  options: CreatePluginOptions,
): TPlugin => {
  const proxy = createCapacitorPluginProxy<TDefinitions>({
    pluginName: options.pluginName,
  });
  if (!proxy) {
    // eslint-disable-next-line
    // @ts-ignore
    return undefined;
  }
  return new pluginConstructor({
    pluginName: options.pluginName,
    pluginLogName: options.pluginLogName,
    proxy,
  });
};
