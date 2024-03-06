public class MutableJsonArray: JsonArray, IMutableJsonArray {
    override init(_ arr: Array<JsonValueRaw?>) {
        super.init(arr)
    }

    internal convenience init() {
        self.init([])
    }

    public func put(_ value: String, index: Int? = nil) {
        putInternal(value, index)
    }

    public func put(_ value: Int, index: Int? = nil) {
        putInternal(value, index)
    }

    public func put(_ value: Double, index: Int? = nil) {
        putInternal(value, index)
    }

    public func put(_ value: Bool, index: Int? = nil) {
        putInternal(value, index)
    }

    public func put(_ value: JsonObject, index: Int? = nil) {
        putInternal(value.dict, index)
    }

    public func put(_ value: JsonArray, index: Int? = nil) {
        putInternal(value.arr, index)
    }

    public func putNull(index: Int? = nil) {
        putInternal(nil, index)
    }

    public func put(_ value: JsonValue, index: Int? = nil) {
        if let value = value as? String {
            put(value, index: index)
        } else if let value = value as? Int {
            put(value, index: index)
        } else if let value = value as? Double {
            put(value, index: index)
        } else if let value = value as? Bool {
            put(value, index: index)
        } else if let value = value as? JsonObject {
            put(value, index: index)
        } else if let value = value as? JsonArray {
            put(value, index: index)
        }
    }

    private func putInternal(_ value: JsonValueRaw?, _ index: Int?) {
        arr.append(value)
    }
}
