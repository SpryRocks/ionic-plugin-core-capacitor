public class MutableJsonObject: JsonObject, IMutableJsonObject {
    override init(_ dict: Dictionary<String, JsonValueRaw?>) {
        super.init(dict)
    }

    internal convenience init() {
        self.init([:])
    }

    public func put(_ name: String, _ value: String) {
        putInternal(name, value)
    }

    public func put(_ name: String, _ value: Int) {
        putInternal(name, value)
    }

    public func put(_ name: String, _ value: Double) {
        putInternal(name, value)
    }

    public func put(_ name: String, _ value: Bool) {
        putInternal(name, value)
    }

    public func put(_ name: String, _ value: JsonObject) {
        putInternal(name, value.dict)
    }

    public func put(_ name: String, _ value: JsonArray) {
        putInternal(name, value.arr)
    }

    public func putNull(_ name: String) {
        putInternal(name, nil)
    }

    public func put(_ name: String, _ value: JsonValue) {
        if let value = value as? String {
            put(name, value)
        } else if let value = value as? Int {
            put(name, value)
        } else if let value = value as? Double {
            put(name, value)
        } else if let value = value as? Bool {
            put(name, value)
        } else if let value = value as? JsonObject {
            put(name, value)
        } else if let value = value as? JsonArray {
            put(name, value)
        }
    }

    private func putInternal(_ name: String, _ value: JsonValueRaw?) {
        dict[name] = value
    }
}
