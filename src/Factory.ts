import {CreatePlugin, PluginRegistration} from './IFactory';
import {IDefinitions, PluginProxy} from './definitions';
import {Plugins} from '@capacitor/core';

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  _?: {web?: PluginRegistration},
): TPlugin => {
  return Plugins[pluginName] as TPlugin;
};

export const createPluginProxy = <TDefinitions extends IDefinitions>(
  pluginName: string,
  options?: {
    web?: PluginRegistration;
  },
) => createPlugin<PluginProxy<TDefinitions>>(pluginName, options);
