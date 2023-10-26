import Capacitor

public protocol PluginCallbackInternal: IPluginLogger, IEventSender {
    func reportSuccess(_ data: PluginCallResultData?, call: CallContext, finish: Bool)
    func reportError(_ error: Error?, call: CallContext, finish: Bool)
}
