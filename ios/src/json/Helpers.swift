public func mutableJsonObject() -> MutableJsonObject {
    return MutableJsonObject()
}

public func mutableJsonArray() -> MutableJsonArray {
    return MutableJsonArray()
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
        else if (raw is Array<Any>) {
            return JsonArray(raw as! Array<Any>)
        } else if (raw is Dictionary<String, Any>) {
            return JsonObject(raw as! Dictionary<String, Any>)
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
