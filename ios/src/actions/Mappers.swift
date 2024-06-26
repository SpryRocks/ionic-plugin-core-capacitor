import Capacitor

open class CoreMappers {
    public init() {}

    func reportSuccess(_ data: JsonObject?, call: CallContext, finish: Bool) {
        call.success(data, finish: finish)
    }

    func reportError(_ error: Error?, call: CallContext, finish: Bool) {
        errorMapper.reportError(error, call: call, finish: finish)
    }

    open func createErrorMapper() -> CoreErrorMapper {
        return CoreErrorMapper()
    }

    lazy var errorMapper: CoreErrorMapper = {
        createErrorMapper()
    }()

    open func createLogMapper() -> CoreLogMapper {
        return CoreLogMapper()
    }

    lazy var logMapper: CoreLogMapper = {
        createLogMapper()
    }()
}

open class CoreErrorMapper {
    public init() {}

    open func map(_ error: Error) -> PluginError {
        if let error = error as? PluginError {
            return error
        }
        return PluginError(message: error.localizedDescription, cause: error)
    }

    open func mapToJson(_ error: Error) -> JsonObject? {
        guard let error = error as? PluginError else {
            return nil
        }
        
        let data = mutableJsonObject()

        if let errorMessage = error.message {
            data.put("message", errorMessage)
        }

        if let errorCode = error.code {
            data.put("code", errorCode)
        }

        return data
    }

    func reportError(_ error: Error?, call: CallContext, finish: Bool) {
        call.error(error, finish: finish)
    }
}

public typealias LogMapperObjectFormatter<T> = (_ obj: T) throws -> JsonObject

open class CoreLogMapper {
    private var formatters: Array<(type: Any.Type, formatter: LogMapperObjectFormatter<Any>)> = []

    public init() {
    }

    public func register<T>(type: T.Type, formatter: @escaping LogMapperObjectFormatter<T>) {
        let f: LogMapperObjectFormatter<Any> = { c in
            guard let c = c as? T else {
                throw PluginError(message: "Object formatting error, cannot cast to required type")
            }
            return try formatter(c)
        }
        formatters.append((type, f))
    }

    private func mapLogObject(_ obj: Any) -> JsonObject? {
        let type = type(of: obj)
        if let formatter = formatters.first(where: { it in it.type == type })?.formatter {
            return try? formatter(obj)
        } else {
            return nil
        }
    }

    internal func getLogTypeValue(_ type: LogLevel) -> String {
        switch(type) {
        case .Warning:
            return "Warning"
        case .Debug:
            return "Debug"
        case .Info:
            return "Info"
        case .Error:
            return "Error"
        case .Trace:
            return "Trace"
        }
    }

    internal func formatParams(_ params: LogParams) -> JsonObject {
        let result = mutableJsonObject()
        for param in params {
            if let value = formatValue(param.value) {
                result.put(param.key, value)
            } else {
                result.putNull(param.key)
            }
        }
        return result
    }

    private func formatValue(_ value: Any?) -> JsonValue? {
        if let value = value {
            if let value = value as? Array<Any> {
                return formatArray(value)
            } else if (
                value is String ||
                value is Int ||
                value is Double ||
                value is Bool
            ) {
                return value
            } else {
                return formatObject(value)
            }
        }

        return nil
    }

    private func formatArray(_ array: Array<Any>) -> JsonArray {
        let result = mutableJsonArray()
        array.forEach { it in
            if let value = formatValue(it) {
                result.put(value)
            } else {
                result.putNull()
            }
        }
        return result
    }

    private func formatObject(_ obj: Any) -> JsonValue? {
        if let formatted = mapLogObject(obj) {
            return formatted
        }
        if let obj = obj as? AnyClass {
            return obj.description()
        }
        return nil
    }
}
