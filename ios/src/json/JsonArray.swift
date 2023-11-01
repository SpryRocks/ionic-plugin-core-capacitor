public class JsonArray: JsonElement, IJsonArray {
    internal var arr: Array<JsonValueRaw?>
    
    internal init(_ arr: Array<JsonValueRaw?>) {
        self.arr = arr
    }
    
    public static func fromRaw(_ arr: JsonArrayRaw) -> JsonArray {
        return JsonArray(arr)
    }
    
    public var size: Int {
        get {
            return arr.count
        }
    }
    
    public func opt(_ index: Int) -> JsonValue? {
        return convertFromRawJsonElement(raw: arr[index] as JsonValueRaw?)
    }
    
    public func optString(_ index: Int) -> String? {
        return opt(index) as! String?
    }
    
    public func optInt(_ index: Int) -> Int? {
        return opt(index) as! Int?
    }
    
    public func optDouble(_ index: Int) -> Double? {
        return opt(index) as! Double?
    }
    
    public func optBool(_ index: Int) -> Bool? {
        return opt(index) as! Bool?
    }
    
    public func optObject(_ index: Int) -> JsonObject? {
        return opt(index) as! JsonObject?
    }
    
    public func optArray(_ index: Int) -> JsonArray? {
        return opt(index) as! JsonArray?
    }
    
    public func get(_ index: Int) throws -> JsonValue {
        return try require(index, opt)
    }
    
    public func getString(_ index: Int) throws -> String {
        return try require(index, optString)
    }
    
    public func getInt(_ index: Int) throws -> Int {
        return try require(index, optInt)
    }
    
    public func getDouble(_ index: Int) throws -> Double {
        return try require(index, optDouble)
    }
    
    public func getBool(_ index: Int) throws -> Bool {
        return try require(index, optBool)
    }
    
    public func getObject(_ index: Int) throws -> JsonObject {
        return try require(index, optObject)
    }
    
    public func getArray(_ index: Int) throws -> JsonArray {
        return try require(index, optArray)
    }
    
    public func mutate() -> MutableJsonArray {
        return MutableJsonArray(arr)
    }
    
    public func toRaw() -> JsonArrayRaw {
        return arr
    }
}
