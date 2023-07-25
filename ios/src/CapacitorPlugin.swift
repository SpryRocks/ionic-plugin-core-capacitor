import Capacitor

public protocol IWebViewProvider {
    func getWebView() -> WKWebView?
}

public protocol CapacitorPluginDelegate: IWebViewProvider {
    func sendEvent(_ name: String, _ data: [String: Any])
}

open class CapacitorPlugin: CAPPlugin, CapacitorPluginDelegate {
    public func initializePlugin(_ plugin: ICorePluginInitializer) {
        plugin.initialize(wrapperDelegate: self)
    }
    
    public func sendEvent(_ name: String, _ data: [String: Any]) {
        notifyListeners(name, data: data)
    }
    
    public func getWebView() -> WKWebView? {
        return self.webView
    }
}
