public class LogEvent<TDelegate, TMappers>: CoreBaseEvent<TDelegate, TMappers> where TDelegate : CoreDelegate, TMappers : CoreMappers {
    private let action: String?
    private let tag: String?
    private let type: LogType
    private let message: String
    private let params: LogParams
    
    init(action: String?, tag: String?, type: LogType, message: String, params: LogParams) {
        self.action = action
        self.tag = tag
        self.type = type
        self.message = message
        self.params = params
        super.init(name: "log")
    }
    
    public override func getData() -> JsonObject {
        let logMapper = mappers.logMapper
        let data = mutableJsonObject()
        data.put("type", logMapper.getLogTypeValue(type))
        if let action = action {
            data.put("action", action)
        }
        if let tag = tag {
            data.put("tag", tag)
        }
        data.put("message", message)
        data.put("params", logMapper.formatParams(params))
        return data
    }
}
