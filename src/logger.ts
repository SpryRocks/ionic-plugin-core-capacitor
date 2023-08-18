import {
  CoreLogData as CoreCoreLogData,
  ILoggerObserver as CoreILoggerObserver,
  LogData as CoreLogData,
  LoggerObserver as CoreLoggerObserver,
  ILoggerFactory,
  ILoggerNotifier,
  LoggerFactory,
} from '@spryrocks/logger-plugin';

export type LogData = CoreLogData & {isNative: boolean};

export interface ILoggerObserver extends CoreILoggerObserver {}

export class LoggerObserver extends CoreLoggerObserver<LogData> {}

export type GlobalData = {action: string | undefined; isNative: boolean; plugin: string};

export const prepareLogData = ({
  data,
  globalData,
}: {
  data: CoreCoreLogData;
  globalData: GlobalData;
}): LogData => ({
  ...data,
  isNative: globalData.isNative,
  plugin: globalData.plugin,
  action: globalData.action,
});

export const createLoggerFactory = (options: {
  notifier: ILoggerNotifier<LogData>;
  plugin: string;
}): ILoggerFactory<GlobalData> => {
  return new LoggerFactory<LogData, GlobalData>({
    notifier: options.notifier,
    globalData: {plugin: options.plugin, action: undefined, isNative: false},
    prepareLogData,
  });
};
