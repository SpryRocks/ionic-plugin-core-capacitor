import * as cap from '@capacitor/core';

export const createPlugin = <TPlugin>(pluginName: string): TPlugin => {
  // eslint-disable-next-line @typescript-eslint/ban-ts-comment
  // @ts-ignore
  if (cap.registerPlugin) {
    // eslint-disable-next-line @typescript-eslint/ban-ts-comment
    // @ts-ignore
    return cap.registerPlugin<TPlugin>(pluginName);
  } else {
    return cap.Plugins[pluginName] as TPlugin;
  }
};
