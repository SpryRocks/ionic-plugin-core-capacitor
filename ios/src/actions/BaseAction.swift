import Capacitor

open class CoreBaseAction<TDelegate, TMappers>: WithLogger where TDelegate : CoreDelegate, TMappers : CoreMappers {
    struct Session {
        let delegate: TDelegate
        let mappers: TMappers
        let pluginLogger: IPluginLogger
    }
    
    private var session_: Session? = nil
    private var session: Session { get { return session_! }}
    public var delegate: TDelegate { get { return session.delegate }}
    public var mappers: TMappers { get { return session.mappers }}
    private var call: CallContext
    
    public required init(call: CallContext) throws {
        self.call = call
    }
    
    public func initialize(delegate: TDelegate, mappers: TMappers, pluginLogger: IPluginLogger) {
        session_ = Session(delegate: delegate, mappers: mappers, pluginLogger: pluginLogger)
    }
    
    open func onExecute() throws {}
    
    public func executeAsync(operation: @escaping () throws -> Void) {
        DispatchQueue.main.async {
            do {
                try operation()
            } catch {
                self.error(error)
            }
        }
    }
    
    public func executeTask(operation: @Sendable @escaping () async throws -> Void) {
        Task.init {
            do {
                try await operation()
            } catch {
                self.error(error)
            }
        }
    }
    
    public func success(_ data: PluginCallResultData? = nil, finish: Bool = true) {
        mappers.reportSuccess(data, call: call, finish: finish)
    }
    
    public func success(_ data: Encodable, finish: Bool = true, serialize: Bool) {
        let encoded = try! JSONEncoder().encode(data)
        let dict = try! JSONSerialization.jsonObject(with: encoded) as! [String: Any]
        success(dict, finish: finish)
    }
    
    public func error(_ error: Error? = nil, finish: Bool = true) {
        mappers.reportError(error, call: call, finish: finish)
    }
    
    public func logger(tag: String?) -> ILogger {
        return Logger(action: getClassName(), tag: tag, pluginLogger: session.pluginLogger)
    }
    
    public func logger() -> ILogger {
        return logger(tag: nil)
    }
    
    private func getClassName() -> String {
        let fullName = String(describing: self)
        let parts = fullName.split(separator: ".")
        return parts.last!.description
    }
}
