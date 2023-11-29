@objc
public protocol WithLoggerLegacy {
    func loggerLegacy(tag: String?) -> ILoggerLegacy
    func loggerLegacy() -> ILoggerLegacy
}

public typealias LogParamsLegacy = Dictionary<String, Any>

@objc
public protocol ILoggerLegacy {
    func warning(message: String, params: LogParamsLegacy?)
    func warning(message: String)
    func debug(message: String, params: LogParamsLegacy?)
    func debug(message: String)
    func info(message: String, params: LogParamsLegacy?)
    func info(message: String)
    func error(message: String, params: LogParamsLegacy?)
    func error(message: String)
    func trace(message: String, params: LogParamsLegacy?)
    func trace(message: String)
    func tag(_ tag: String) -> ILoggerLegacy
    func child() -> ILoggerLegacy
    func updateParams(_ params: LogParamsLegacy)
}
