import Capacitor

public protocol IWebViewProvider {
    func getWebView() -> WKWebView?
}

public protocol CapacitorPluginDelegate: IWebViewProvider {
    func sendEvent(_ name: String, _ data: JsonObject)
}

open class CapacitorPlugin: CAPPlugin, CapacitorPluginDelegate {
    public override init() {
        super.init()
    }
    
    public override init(bridge: CAPBridgeProtocol, pluginId: String, pluginName: String) {
        super.init(bridge: bridge, pluginId: pluginId, pluginName: pluginName)
    }
    
    public func initializePlugin(_ plugin: ICorePluginInitializer) {
        plugin.initialize(wrapperDelegate: self)
    }
    
    public func sendEvent(_ name: String, _ data: JsonObject) {
        notifyListeners(name, data: data.toRaw())
    }
    
    public func getWebView() -> WKWebView? {
        return self.webView
    }
}
