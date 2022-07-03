import {registerPlugin} from '@capacitor/core';

export const createPlugin = <TPlugin>(pluginName: string): TPlugin => {
  return registerPlugin<TPlugin>(pluginName);
};
