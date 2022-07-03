import {Plugins, registerPlugin} from '@capacitor/core';

export const createPlugin = <TPlugin>(options: {pluginName: string}): TPlugin => {
  const pluginName = options.pluginName;
  if (registerPlugin) {
    return registerPlugin<TPlugin>(pluginName);
  } else {
    return Plugins[pluginName] as TPlugin;
  }
};
