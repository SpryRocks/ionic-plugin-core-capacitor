import Capacitor

open class CoreBaseAction<TDelegate, TMappers>: ContextWithCall<TDelegate, TMappers>, WithLogger, IEventSender where TDelegate : CoreDelegate, TMappers : CoreMappers {

    required public init(args: IJsonObjectProperties) throws {
        super.init()
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

    public func success(_ data: JsonObject? = nil, finish: Bool = true) {
        mappers.reportSuccess(data, call: call, finish: finish)
    }

    public func success(_ data: Encodable, finish: Bool = true, serialize: Bool) {
        do {
            let data = try JsonObject.fromObject(data)
            success(data, finish: finish)
        } catch {
            self.error(error)
        }
    }

    public func error(_ error: Error? = nil, finish: Bool = true) {
        mappers.reportError(error, call: call, finish: finish)
    }

    public func logger(tag: String?) -> ILogger {
        return Logger(action: getClassName(), tag: tag, params: nil, pluginLogger: callback)
    }

    public func logger() -> ILogger {
        return logger(tag: nil)
    }

    private func getClassName() -> String {
        let fullName = String(describing: self)
        let parts = fullName.split(separator: ".")
        return parts.last?.description ?? "Unknown class name"
    }

    public func sendEvent(_ event: ICoreEvent) {
        callback.sendEvent(event)
    }
}
