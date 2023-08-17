export type PluginImplementation = unknown;
export type PluginRegistration = () => PluginImplementation;

export type CreatePluginOptions = {web?: PluginRegistration; cap2?: {pluginName: string}};

export type CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: CreatePluginOptions,
) => TPlugin;
