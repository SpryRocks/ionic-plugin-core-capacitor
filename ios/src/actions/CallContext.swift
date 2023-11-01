import Capacitor

public class CallContext {
    private let call: CAPPluginCall
    private let mappers: CoreMappers
    
    init(call: CAPPluginCall, mappers: CoreMappers) {
        self.call = call
        self.mappers = mappers
    }
    
    public func asObject() -> CallContextAsJsonObject {
        return CallContextAsJsonObject(call: call)
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
        return mappers.errorMapper.mapToJson(pluginError)?.toRaw()
    }
}

public class CallContextAsJsonObject: IJsonObjectProperties {
    private let call: CAPPluginCall
    
    init(call: CAPPluginCall) {
        self.call = call
    }
    
    public func opt(_ name: String) -> JsonValue? {
        return nil
    }
    
    public func optString(_ name: String) -> String? {
        return call.getString(name)
    }
    
    public func optInt(_ name: String) -> Int? {
        return call.getInt(name)
    }
    
    public func optDouble(_ name: String) -> Double? {
        return call.getDouble(name)
    }
    
    public func optBool(_ name: String) -> Bool? {
        return call.getBool(name)
    }
    
    public func optObject(_ name: String) -> JsonObject? {
        guard let raw = call.getObject(name)
        else { return nil }
        return JsonObject.fromRaw(raw)
    }
    
    public func optArray(_ name: String) -> JsonArray? {
        guard let raw = call.getArray(name)
        else { return nil }
        return JsonArray.fromRaw(raw)
    }
    
    public func get(_ name: String) throws -> JsonValue {
        guard let result = opt(name) else {
            throw PluginError(message: "Value for required '\(name)' is nil")
        }
        return result
    }
    
    public func getString(_ name: String) throws -> String {
        guard let result = optString(name) else {
            throw PluginError(message: "Value for required string '\(name)' is nil")
        }
        return result
    }
    
    public func getInt(_ name: String) throws -> Int {
        guard let result = optInt(name) else {
            throw PluginError(message: "Value for required int '\(name)' is nil")
        }
        return result
    }
    
    public func getDouble(_ name: String) throws -> Double {
        guard let result = optDouble(name) else {
            throw PluginError(message: "Value for required double '\(name)' is nil")
        }
        return result
    }
    
    public func getBool(_ name: String) throws -> Bool {
        guard let result = optBool(name) else {
            throw PluginError(message: "Value for required bool '\(name)' is nil")
        }
        return result
    }
    
    public func getObject(_ name: String) throws -> JsonObject {
        guard let result = optObject(name) else {
            throw PluginError(message: "Value for required object '\(name)' is nil")
        }
        return result
    }
    
    public func getArray(_ name: String) throws -> JsonArray {
        guard let result = optArray(name) else {
            throw PluginError(message: "Value for required array '\(name)' is nil")
        }
        return result
    }
}
