import {CreatePlugin, PluginRegistration} from './IFactory';
import {registerPlugin} from '@capacitor/core';

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: {web?: PluginRegistration},
): TPlugin => {
  return registerPlugin<TPlugin>(pluginName, {web: options?.web});
};
