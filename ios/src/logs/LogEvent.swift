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
        var data = Dictionary<String, Any>()
        data["type"] = getLogTypeValue(type)
        if (action != nil) {
            data["action"] = action
        }
        if (tag != nil) {
            data["tag"] = tag
        }
        data["message"] = message
        data["params"] = params
        return data
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
}
