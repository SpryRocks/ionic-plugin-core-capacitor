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
import {registerPlugin} from '@capacitor/core';

export const createCapacitorPlugin: CreateCapacitorPlugin = <TPlugin>(
  options: CreateCapacitorPluginOptions,
): TPlugin => registerPlugin<TPlugin>(options.pluginName, {web: options?.web});

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
    web: options.web,
    cap2: options.cap2,
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
