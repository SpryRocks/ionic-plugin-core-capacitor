import {Plugins, registerPlugin} from '@capacitor/core';

export class Factory<TPlugin> {
  constructor(protected readonly pluginName: string) {}

  protected async getPlugin(): Promise<TPlugin> {
    if (registerPlugin) {
      return registerPlugin<TPlugin>(this.pluginName);
    } else {
      return Plugins[this.pluginName] as TPlugin;
    }
  }
}
