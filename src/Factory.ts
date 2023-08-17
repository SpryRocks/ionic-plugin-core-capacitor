import {CreatePlugin, PluginRegistration} from './IFactory';
import {IDefinitions, PluginProxy} from './definitions';
import {Plugins} from '@capacitor/core';

type CreatePluginOptions = {web?: PluginRegistration; cap2?: {pluginName: string}};

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: CreatePluginOptions,
): TPlugin => Plugins[options?.cap2?.pluginName ?? pluginName] as TPlugin;

export const createPluginProxy = <TDefinitions extends IDefinitions>(
  pluginName: string,
  options?: CreatePluginOptions,
) => createPlugin<PluginProxy<TDefinitions>>(pluginName, options);
