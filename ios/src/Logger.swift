@objc
public class Logger : NSObject, ILogger {
    private let action: String?
    private let tag: String?
    private let pluginLogger: IPluginLogger
    
    @objc
    public init(action: String?, tag: String?, pluginLogger: IPluginLogger) {
        self.action = action
        self.tag = tag
        self.pluginLogger = pluginLogger
    }
    
    public func warning(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogType.Warning, message, params)
    }
    
    public func warning(message: String) {
        warning(message: message, params: nil)
    }
    
    public func debug(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogType.Debug, message, params)
    }
    
    public func debug(message: String) {
        debug(message: message, params: nil)
    }
    
    public func info(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogType.Info, message, params)
    }
    
    public func info(message: String) {
        info(message: message, params: nil)
    }
    
    public func error(message: String, params: LogParams?) {
        pluginLogger.sendLog(action, tag, LogType.Error, message, params)
    }
    
    public func error(message: String) {
        error(message: message, params: nil)
    }
    
    public func tag(_ tag: String) -> ILogger {
        return Logger(action: action, tag: tag, pluginLogger: pluginLogger)
    }
}
