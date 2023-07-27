import Capacitor

public class CallContext {
    private let call: CAPPluginCall
    private let mappers: CoreMappers
    
    init(call: CAPPluginCall, mappers: CoreMappers) {
        self.call = call
        self.mappers = mappers
    }
    
    public func getString(_ key: String) -> String {
        return optString(key)!
    }
    
    public func optString(_ key: String) -> String? {
        return call.getString(key)
    }
    
    public func getObject(_ key: String) -> JSObject {
        return optObject(key)!
    }
    
    public func optObject(_ key: String) -> JSObject? {
        return call.getObject(key)
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
