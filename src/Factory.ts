import {CreatePlugin, PluginRegistration} from './IFactory';
import {Plugins} from '@capacitor/core';

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  _?: {web?: PluginRegistration},
): TPlugin => {
  return Plugins[pluginName] as TPlugin;
};
