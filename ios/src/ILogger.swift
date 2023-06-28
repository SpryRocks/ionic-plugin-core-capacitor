public typealias LogParams = Dictionary<String, Any>

@objc
public enum LogType: Int {
    case Warning
    case Debug
    case Info
    case Error
}

@objc
public protocol IPluginLogger {
    func sendLog(_ action: String?, _ tag: String?, _ type: LogType, _ message: String, _ params: LogParams?)
}

@objc
public protocol ILogger {
    func warning(message: String, params: LogParams?)
    func warning(message: String)
    func debug(message: String, params: LogParams?)
    func debug(message: String)
    func info(message: String, params: LogParams?)
    func info(message: String)
    func error(message: String, params: LogParams?)
    func error(message: String)
    func tag(_ tag: String) -> ILogger
}
