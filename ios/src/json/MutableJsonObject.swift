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
        if (value is String) {
            put(name, value as! String)
        } else if (value is Int) {
            put(name, value as! Int)
        } else if (value is Double) {
            put(name, value as! Double)
        } else if (value is Bool) {
            put(name, value as! Bool)
        } else if (value is JsonObject) {
            put(name, value as! JsonObject)
        } else if (value is JsonArray) {
            put(name, value as! JsonArray)
        }
    }
            
    private func putInternal(_ name: String, _ value: JsonValueRaw?) {
        dict[name] = value
    }
}
