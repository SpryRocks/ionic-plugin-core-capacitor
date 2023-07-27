import Capacitor

open class CoreMappers {
    public init() {}
    
    func reportSuccess(_ data: PluginCallResultData?, call: CallContext, finish: Bool) {
        call.success(data, finish: finish)
    }
    
    func reportError(_ error: Error?, call: CallContext, finish: Bool) {
        errorMapper.reportError(error, call: call, finish: finish)
    }
    
    var errorMapper = CoreErrorMapper()
}

open class CoreErrorMapper {
    public init() {}
    
    func map(_ error: Error) -> PluginError {
        if (error is PluginError) {
            return error as! PluginError
        }
        return PluginError(message: "Unknown error", cause: error)
    }
    
    func mapToJson(_ error_: Error) -> PluginCallResultData? {
        if (!(error_ is PluginError)) {
            return nil
        }
        let error = error_ as! PluginError
        
        var data = Dictionary<String, Any>();
        data["message"] = error.message
      
        if (error.code != nil) {
            data["code"] = error.code
        }
        
        return data
    }
    
    func reportError(_ error: Error?, call: CallContext, finish: Bool) {
        call.error(error, finish: finish)
    }
}
