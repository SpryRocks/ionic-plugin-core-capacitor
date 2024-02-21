type IAction<TOptions, TResult> = {options: TOptions; result: TResult};

type SetLogLevelsOptions = {
  logLevels: string[] | undefined;
};

export type DefaultActions = {
  setLogLevels: IAction<SetLogLevelsOptions, void>;
};

export type IDefinitions = {
  [name: string]: IAction<unknown, unknown>;
} & DefaultActions;

export type CallbackId = string;
type PluginCallback<TData> = (
  data: TData | undefined,
  error: unknown | undefined,
) => void;
export type CallbackResult = Promise<CallbackId>;

export type CapPluginListener<TEvent> = (event: TEvent) => void;

type CapPlugin = {
  addListener: <TEvent>(name: string, listener: CapPluginListener<TEvent>) => void;
};

export type PluginProxy<TDefinitions extends IDefinitions> = CapPlugin & {
  [name in keyof TDefinitions]: (
    options: TDefinitions[name]['options'],
    callback: PluginCallback<TDefinitions[name]['result']> | undefined,
  ) => Promise<TDefinitions[name]['result']> | CallbackResult;
};
