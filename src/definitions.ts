type IAction<TOptions, TResult> = {options: TOptions; result: TResult};

export type IDefinitions = {
  [name: string]: IAction<unknown, unknown>;
};

type CallbackId = string;
type PluginCallback<TData> = (
  data: TData | undefined,
  error: unknown | undefined,
) => void;

export type PluginProxy<TDefinitions extends IDefinitions> = {
  [name in keyof TDefinitions]: (
    options: TDefinitions[name]['options'],
    callback: PluginCallback<TDefinitions[name]['result']> | undefined,
  ) => Promise<TDefinitions[name]['result']> | CallbackId;
};
