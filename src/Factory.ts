import {Plugins, registerPlugin} from '@capacitor/core';

export class Factory<TPlugin> {
  constructor(protected readonly options: {pluginName: string}) {}

  public getPlugin(): TPlugin {
    const pluginName = this.options.pluginName;
    if (registerPlugin) {
      return registerPlugin<TPlugin>(pluginName);
    } else {
      return Plugins[pluginName] as TPlugin;
    }
  }
}
