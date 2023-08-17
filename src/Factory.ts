import {CreatePlugin, PluginRegistration} from './IFactory';
import {IDefinitions, PluginProxy} from './definitions';
import {registerPlugin} from '@capacitor/core';

type CreatePluginOptions = {web?: PluginRegistration; cap2?: {pluginName: string}};

export const createPlugin: CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: CreatePluginOptions,
): TPlugin => registerPlugin<TPlugin>(pluginName, {web: options?.web});

export const createPluginProxy = <TDefinitions extends IDefinitions>(
  pluginName: string,
  options?: CreatePluginOptions,
) => createPlugin<PluginProxy<TDefinitions>>(pluginName, options);
