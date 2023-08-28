import Capacitor

public class CallContext {
    private let call: CAPPluginCall
    private let mappers: CoreMappers
    
    init(call: CAPPluginCall, mappers: CoreMappers) {
        self.call = call
        self.mappers = mappers
    }
    
    public func getString(_ key: String) throws -> String {
        guard let result = optString(key) else {
            throw PluginError(message: "Value for required string '\(key)' is nil")
        }
        return result
    }
    
    public func optString(_ key: String) -> String? {
        return call.getString(key)
    }
    
    public func getObject(_ key: String) throws -> JsObject {
        guard let result = optObject(key) else {
            throw PluginError(message: "Value for required object '\(key)' is nil")
        }
        return result
    }
    
    public func optObject(_ key: String) -> JsObject? {
        guard let raw = call.getObject(key)
        else { return nil }
        return JsObject(raw: raw)
    }
    
    public func getArray(_ key: String) throws -> JsArray {
        guard let result = optArray(key) else {
            throw PluginError(message: "Value for required array '\(key)' is nil")
        }
        return result
    }
    
    public func optArray(_ key: String) -> JsArray? {
        guard let raw = call.getArray(key)
        else { return nil }
        return JsArray(raw: raw)
    }
    
    public func success(_ data: PluginCallResultData?, finish: Bool) {
        call.keepAlive = !finish
        
        if (data == nil) {
            call.resolve()
            return
        }
        
        call.resolve(data!)
    }
    
    public func error(_ error: Error?, finish: Bool) {
        call.keepAlive = !finish
        
        let errorData = prepareErrorData(error)
        
        let message = error?.localizedDescription ?? "Unknown error"
        
        if (errorData == nil) {
            call.reject(message)
            return
        }
        
        call.reject(message, nil, nil, errorData!)
    }
    
    private func prepareErrorData(_ error: Error?) -> PluginCallResultData? {
        if (error == nil) { return nil }
        let pluginError = mappers.errorMapper.map(error!)
        return mappers.errorMapper.mapToJson(pluginError)
    }
}

public class JsObject {
    public let raw: JSObject
    
    public func getString(_ key: String) throws -> String {
        guard let result = optString(key) else {
            throw PluginError(message: "Value for required string '\(key)' is nil")
        }
        return result
    }
    
    public func optString(_ key: String) -> String? {
        return raw[key] as! String?
    }
    
    init(raw: JSObject) {
        self.raw = raw
    }
}

public class JsArray {
    public let raw: JSArray
    
    init(raw: JSArray) {
        self.raw = raw
    }
}
