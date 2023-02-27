type IAction<TOptions, TResult> = {options: TOptions; result: TResult};

export type IDefinitions = {
  [name: string]: IAction<unknown, unknown>;
};

export type PluginProxy<TDefinitions extends IDefinitions> = {
  [name in keyof TDefinitions]: (
    options: TDefinitions[name]['options'],
  ) => Promise<TDefinitions[name]['result']>;
};
