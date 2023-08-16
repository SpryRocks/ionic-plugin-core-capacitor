type IAction<TOptions, TResult> = {options: TOptions; result: TResult};

export type IDefinitions = {
  [name: string]: IAction<unknown, unknown>;
};

export type CallbackId = string;
type PluginCallback<TData> = (
  data: TData | undefined,
  error: unknown | undefined,
) => void;
export type CallbackResult = Promise<CallbackId>;

type CapPluginListener = (event: unknown) => void;

type CapPlugin = {
  addListener: (name: string, listener: CapPluginListener) => void;
};

export type PluginProxy<TDefinitions extends IDefinitions> = CapPlugin & {
  [name in keyof TDefinitions]: (
    options: TDefinitions[name]['options'],
    callback: PluginCallback<TDefinitions[name]['result']> | undefined,
  ) => Promise<TDefinitions[name]['result']> | CallbackResult;
};
