import {CreatePlugin, CreatePluginOptions} from './IFactory';
import {IDefinitions, PluginProxy} from './definitions';
import {Plugins} from '@capacitor/core';

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: CreatePluginOptions,
): TPlugin => Plugins[options?.cap2?.pluginName ?? pluginName] as TPlugin;

export const createPluginProxy = <TDefinitions extends IDefinitions>(
  pluginName: string,
  options?: CreatePluginOptions,
) => createPlugin<PluginProxy<TDefinitions>>(pluginName, options);
