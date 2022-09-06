export type PluginImplementation = unknown;
export type PluginRegistration = () => PluginImplementation;

export type CreatePlugin = <TPlugin>(
  pluginName: string,
  options?: {web?: PluginRegistration},
) => TPlugin;
