import Foundation
import Capacitor

public protocol ICorePluginInitializer {
    func initialize(wrapperDelegate: CapacitorPluginDelegate)
}

open class CorePlugin<TDelegate : CoreDelegate, TMappers: CoreMappers>: IPluginLogger, ICorePluginInitializer, WithLogger {
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
    
    public func sendLog(_ action: String?, _ tag: String?, _ type: LogType, _ message: String, _ params: LogParams) {
        var data = Dictionary<String, Any>()
        data["type"] = getLogTypeValue(type)
        if (action != nil) {
            data["action"] = action
        }
        if (tag != nil) {
            data["tag"] = tag
        }
        data["message"] = message
        if (params != nil) {
            data["params"] = params
        } else {
            data["params"] = [:] as Dictionary<String, Any>
        }
        wrapperDelegate.sendEvent("log", data)
    }
    
    private func getLogTypeValue(_ type: LogType) -> String {
        switch(type) {
        case .Warning:
            return "Warning"
        case .Debug:
            return "Debug"
        case .Info:
            return "Info"
        case .Error:
            return "Error"
        }
    }

    public func call(_ actionType: CoreBaseAction<TDelegate, TMappers>.Type, _ call: CAPPluginCall) {
        let context = CallContext(call: call, mappers: mappers)
        do {
            let action = try actionType.init(call: context)
            action.initialize(delegate: delegate, mappers: mappers, pluginLogger: self)
            try action.onExecute()
        } catch {
            reportError(error, call: context, finish: true)
        }
    }
    
    func reportSuccess(_ data: PluginCallResultData?, call: CallContext, finish: Bool) {
        mappers.reportSuccess(data, call: call, finish: finish)
    }
    
    func reportError(_ error: Error?, call: CallContext, finish: Bool) {
        mappers.reportError(error, call: call, finish: finish)
    }
    
    public func logger(tag: String?) -> ILogger {
        return Logger(action: nil, tag: tag, params: nil, pluginLogger: self)
    }
    
    public func logger() -> ILogger {
        return logger(tag: nil)
    }
}
