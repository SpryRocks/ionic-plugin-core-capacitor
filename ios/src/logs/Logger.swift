public class Logger : NSObject, ILogger {
    private let action: String?
    private let tag: String?
    private var params: LogParams?
    private let pluginLogger: IPluginLogger

    public init(action: String?, tag: String?, params: LogParams?, pluginLogger: IPluginLogger) {
        self.action = action
        self.tag = tag
        self.params = params
        self.pluginLogger = pluginLogger
    }

    public func warning(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogLevel.Warning, message, prepareParams(params))
    }

    public func warning(message: String) {
        warning(message: message, params: nil)
    }

    public func debug(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogLevel.Debug, message, prepareParams(params))
    }

    public func debug(message: String) {
        debug(message: message, params: nil)
    }

    public func info(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogLevel.Info, message, prepareParams(params))
    }

    public func info(message: String) {
        info(message: message, params: nil)
    }

    public func error(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogLevel.Error, message, prepareParams(params))
    }

    public func error(message: String) {
        error(message: message, params: nil)
    }

    public func trace(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogLevel.Trace, message, prepareParams(params))
    }

    public func trace(message: String) {
        trace(message: message, params: nil)
    }

    public func tag(_ tag: String) -> ILogger {
        return Logger(action: action, tag: tag, params: nil, pluginLogger: pluginLogger)
    }

    public func child() -> ILogger {
        return Logger(action: action, tag: nil, params: nil, pluginLogger: pluginLogger)
    }

    public func updateParams(_ params: LogParams) {
        self.params = mergeParams(self.params, params)
    }

    private func prepareParams(_ params: LogParams?) -> LogParams {
        return mergeParams(self.params, params)
    }

    private func mergeParams(_ params1: LogParams?, _ params2: LogParams?) -> LogParams {
        return (params1 ?? [:]).merging(params2 ?? [:]) { (_, new) in new }
    }
}
