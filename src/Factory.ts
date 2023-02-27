import {CreatePlugin, PluginRegistration} from './IFactory';
import {IDefinitions, PluginProxy} from './definitions';
import {registerPlugin} from '@capacitor/core';

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: {web?: PluginRegistration},
): TPlugin => {
  return registerPlugin<TPlugin>(pluginName, {web: options?.web});
};

export const createPluginProxy = <TDefinitions extends IDefinitions>(
  pluginName: string,
  options?: {
    web?: PluginRegistration;
  },
) => createPlugin<PluginProxy<TDefinitions>>(pluginName, options);
