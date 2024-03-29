public protocol WithLogger {
    func logger(tag: String?) -> ILogger
    func logger() -> ILogger
}

public typealias LogParams = Dictionary<String, Any?>

public enum LogLevel: Int {
    case Warning
    case Debug
    case Info
    case Error
    case Trace
}

public protocol IPluginLogger {
    func sendLog(_ action: String?, _ tag: String?, _ type: LogLevel, _ message: String, _ params: LogParams)
}

public protocol ILogger {
    func warning(message: String, params: LogParams?)
    func warning(message: String)
    func debug(message: String, params: LogParams?)
    func debug(message: String)
    func info(message: String, params: LogParams?)
    func info(message: String)
    func error(message: String, params: LogParams?)
    func error(message: String)
    func trace(message: String, params: LogParams?)
    func trace(message: String)
    func tag(_ tag: String) -> ILogger
    func child() -> ILogger
    func updateParams(_ params: LogParams)
}
