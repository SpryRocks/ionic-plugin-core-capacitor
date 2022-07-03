import {Plugins} from '@capacitor/core';

export const createPlugin = <TPlugin>(pluginName: string): TPlugin => {
  return Plugins[pluginName] as TPlugin;
};
