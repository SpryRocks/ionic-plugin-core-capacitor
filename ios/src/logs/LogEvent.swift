public class LogEvent<TDelegate, TMappers>: CoreBaseEvent<TDelegate, TMappers> where TDelegate : CoreDelegate, TMappers : CoreMappers {
    private let action: String?
    private let tag: String?
    private let level: LogLevel
    private let message: String
    private let params: LogParams
    
    init(action: String?,
         tag: String?,
         level: LogLevel,
         message: String,
         params: LogParams
    ) {
        self.action = action
        self.tag = tag
        self.level = level
        self.message = message
        self.params = params
        super.init(name: "log")
    }
    
    public override func getData() -> JsonObject {
        let logMapper = mappers.logMapper
        let data = mutableJsonObject()
        data.put("level", logMapper.getLogTypeValue(level))
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
