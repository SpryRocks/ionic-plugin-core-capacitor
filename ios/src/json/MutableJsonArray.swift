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
        if (value is String) {
            put(value as! String, index: index)
        } else if (value is Int) {
            put(value as! Int, index: index)
        } else if (value is Double) {
            put(value as! Double, index: index)
        } else if (value is Bool) {
            put(value as! Bool, index: index)
        } else if (value is JsonObject) {
            put(value as! JsonObject, index: index)
        } else if (value is JsonArray) {
            put(value as! JsonArray, index: index)
        }
    }
    
    private func putInternal(_ value: JsonValueRaw?, _ index: Int?) {
        arr.append(value)
    }
}
