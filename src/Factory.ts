import {CreatePlugin, CreatePluginOptions} from './IFactory';
import {IDefinitions, PluginProxy} from './definitions';
import {registerPlugin} from '@capacitor/core';

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: CreatePluginOptions,
): TPlugin => registerPlugin<TPlugin>(pluginName, {web: options?.web});

export const createPluginProxy = <TDefinitions extends IDefinitions>(
  pluginName: string,
  options?: CreatePluginOptions,
) => createPlugin<PluginProxy<TDefinitions>>(pluginName, options);
