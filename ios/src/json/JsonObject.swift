public class JsonObject: JsonElement, IJsonObject {
    internal var dict: Dictionary<String, JsonValueRaw?>
    
    internal init(_ dict: Dictionary<String, JsonValueRaw?>) {
        self.dict = dict
    }
    
    public static func fromRaw(_ dict: JsonObjectRaw) -> JsonObject {
        return JsonObject(dict)
    }
    
    public static func fromObject<T>(_ obj: T) throws -> JsonObject where T: Encodable {
        let data = try JSONEncoder().encode(obj)
        let result = try JSONSerialization.jsonObject(with: data)
        if (result is Dictionary<String, JsonValueRaw>) {
            return JsonObject(result as! Dictionary<String, JsonValueRaw>)
        }
        throw PluginError(message: "Cannot create json object")
    }
    
    public func opt(_ name: String) -> JsonValue? {
        return convertFromRawJsonElement(raw: dict[name] as JsonValueRaw?)
    }
    
    public func optString(_ name: String) -> String? {
        return opt(name) as! String?
    }
    
    public func optInt(_ name: String) -> Int? {
        return opt(name) as! Int?
    }
    
    public func optDouble(_ name: String) -> Double? {
        return opt(name) as! Double?
    }
    
    public func optBool(_ name: String) -> Bool? {
        return opt(name) as! Bool?
    }
    
    public func optObject(_ name: String) -> JsonObject? {
        return opt(name) as! JsonObject?
    }
    
    public func optArray(_ name: String) -> JsonArray? {
        return opt(name) as! JsonArray?
    }
    
    public func get(_ name: String) throws -> JsonValue {
        return try require(name, opt)
    }
    
    public func getString(_ name: String) throws -> String {
        return try require(name, optString)
    }
    
    public func getInt(_ name: String) throws -> Int {
        return try require(name, optInt)
    }
    
    public func getDouble(_ name: String) throws -> Double {
        return try require(name, optDouble)
    }
    
    public func getBool(_ name: String) throws -> Bool {
        return try require(name, optBool)
    }
    
    public func getObject(_ name: String) throws -> JsonObject {
        return try require(name, optObject)
    }
    
    public func getArray(_ name: String) throws -> JsonArray {
        return try require(name, optArray)
    }
    
    public func mutate() -> MutableJsonObject {
        return MutableJsonObject(dict)
    }
    
    public func toRaw() -> JsonObjectRaw {
        return dict
    }
}
