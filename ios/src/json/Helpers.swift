public typealias MutableJsonObjectInit = (_ obj: MutableJsonObject) -> Void
public typealias MutableJsonArrayInit = (_ arr: MutableJsonArray) -> Void

public func mutableJsonObject(_ initFunc: MutableJsonObjectInit? = nil) -> MutableJsonObject {
    let obj = MutableJsonObject()
    if let initFunc = initFunc {
        initFunc(obj)
    }
    return obj
}

public func mutableJsonArray(_ initFunc: MutableJsonArrayInit? = nil) -> MutableJsonArray {
    let arr = MutableJsonArray()
    if let initFunc = initFunc {
        initFunc(arr)
    }
    return arr
}

func convertFromRawJsonElement(raw: JsonValueRaw?) -> JsonValue? {
    if let raw = raw {
        if (
            raw is String ||
            raw is Int ||
            raw is Double ||
            raw is Bool
        ) {
            return raw
        }
        else if let raw = raw as? Array<Any> {
            return JsonArray(raw)
        } else if let raw = raw as? Dictionary<String, Any> {
            return JsonObject(raw)
        }
    }
    return nil
}

func require<T>(_ name: String, _ block: (_ name: String) -> T?) throws -> T {
    guard let result = block(name) else {
        throw PluginError(message: "value with name '\(name)' is null")
    }
    return result
}

func require<T>(_ index: Int, _ block: (_ index: Int) -> T?) throws -> T {
    guard let result = block(index) else {
        throw PluginError(message: "value with index '\(index)' is null")
    }
    return result
}
