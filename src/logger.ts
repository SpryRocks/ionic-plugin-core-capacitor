export enum LogType {
  Warning = 'Warning',
  Debug = 'Debug',
  Info = 'Info',
  Error = 'Error',
}

export type LogParams = {[key: string]: string};

export type LogData = {
  type: LogType;
  plugin: string;
  action: string | undefined;
  tag: string | undefined;
  message: string;
  params: LogParams;
};

export interface IPluginLogger {
  onLogReceived: (data: LogData) => void;
}
