import Foundation
import Capacitor

public protocol ICorePluginInitializer {
    func initialize(wrapperDelegate: CapacitorPluginDelegate)
}

open class CorePlugin<TDelegate : CoreDelegate, TMappers: CoreMappers>: IPluginLogger, ICorePluginInitializer, WithLogger, WithLoggerLegacy, PluginCallbackInternal, IEventSender {
    private struct Session {
        let wrapperDelegate: CapacitorPluginDelegate
    }

    private let delegate: TDelegate
    private let mappers: TMappers

    public init(delegate: TDelegate, mappers: TMappers) {
        self.delegate = delegate
        self.mappers = mappers
    }

    private var session_: Session? = nil
    private var session: Session { get { return session_! } }
    public var wrapperDelegate: CapacitorPluginDelegate { get { return session.wrapperDelegate } }

    public func initialize(wrapperDelegate: CapacitorPluginDelegate) {
        session_ = Session(wrapperDelegate: wrapperDelegate)
    }

    public func sendEvent(_ event: ICoreEvent) {
        if let event = event as? Context<TDelegate, TMappers> {
            event.initialize(callback: self, delegate: delegate, mappers: mappers)
        }
        wrapperDelegate.sendEvent(event.name, event.getData())
    }

    public func sendLog(_ action: String?, _ tag: String?, _ level: LogLevel, _ message: String, _ params: LogParams) {
        sendEvent(LogEvent<TDelegate, TMappers>(action: action, tag: tag, level: level, message: message, params: params))
    }

    public func call(_ actionType: CoreBaseAction<TDelegate, TMappers>.Type, _ call: CAPPluginCall) {
        let context = CallContext(call: call, mappers: mappers)
        do {
            let action = try actionType.init(args: context.asObject())
            action.initialize(callback: self, delegate: delegate, mappers: mappers, call: context)
            try action.onExecute()
        } catch {
            mappers.reportError(error, call: context, finish: true)
        }
    }

    public func logger(tag: String?) -> ILogger {
        return Logger(action: nil, tag: tag, params: nil, pluginLogger: self)
    }

    public func logger() -> ILogger {
        return logger(tag: nil)
    }

    public func loggerLegacy(tag: String?) -> ILoggerLegacy {
        return LoggerLegacy(action: nil, tag: tag, params: nil, pluginLogger: self)
    }

    public func loggerLegacy() -> ILoggerLegacy {
        return loggerLegacy(tag: nil)
    }
}
