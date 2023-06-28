import Foundation
import Capacitor

@objc
open class CapacitorPlugin: CAPPlugin, IPluginLogger {
    public func sendLog(_ action: String?, _ tag: String?, _ type: LogType, _ message: String, _ params: LogParams?) {
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
        sendEvent("log", data)
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
    
    private func sendEvent(_ name: String, _ data: [String: Any]) {
        notifyListeners(name, data: data)
    }
}
