public typealias JsonValueRaw = Any
public typealias JsonObjectRaw = [String: JsonValueRaw?]
public typealias JsonArrayRaw = [JsonValueRaw?]

public typealias JsonValue = Any

public protocol IJsonElement {
}

public protocol IJsonObjectProperties {
    func opt(_ name: String) -> JsonValue?
    func optString(_ name: String) -> String?
    func optInt(_ name: String) -> Int?
    func optDouble(_ name: String) -> Double?
    func optBool(_ name: String) -> Bool?
    func optObject(_ name: String) -> JsonObject?
    func optArray(_ name: String) -> JsonArray?
    
    func get(_ name: String) throws -> JsonValue
    func getString(_ name: String) throws -> String
    func getInt(_ name: String) throws -> Int
    func getDouble(_ name: String) throws -> Double
    func getBool(_ name: String) throws -> Bool
    func getObject(_ name: String) throws -> JsonObject
    func getArray(_ name: String) throws -> JsonArray
}

public protocol IJsonObject : IJsonElement, IJsonObjectProperties {
    func mutate() -> MutableJsonObject
    func toRaw() -> JsonObjectRaw
}

public protocol IJsonArrayProperties {
    var size: Int { get }
    
    func opt(_ index: Int) -> JsonValue?
    func optString(_ index: Int) -> String?
    func optInt(_ index: Int) -> Int?
    func optDouble(_ index: Int) -> Double?
    func optBool(_ index: Int) -> Bool?
    func optObject(_ index: Int) -> JsonObject?
    func optArray(_ index: Int) -> JsonArray?
    
    func get(_ index: Int) throws -> JsonValue
    func getString(_ index: Int) throws -> String
    func getInt(_ index: Int) throws -> Int
    func getDouble(_ index: Int) throws -> Double
    func getBool(_ index: Int) throws -> Bool
    func getObject(_ index: Int) throws -> JsonObject
    func getArray(_ index: Int) throws -> JsonArray
}

public protocol IJsonArray : IJsonElement, IJsonArrayProperties {
    func mutate() -> MutableJsonArray
    func toRaw() -> JsonArrayRaw
}

public protocol IMutableJsonObject : IJsonObject {
    func put(_ name: String, _ value: String)
    func put(_ name: String, _ value: Int)
    func put(_ name: String, _ value: Double)
    func put(_ name: String, _ value: Bool)
    func put(_ name: String, _ value: JsonObject)
    func put(_ name: String, _ value: JsonArray)
    func putNull(_ name: String)
    func put(_ name: String, _ value: JsonValue)
}

public protocol IMutableJsonArray : IJsonArray {
    func put(_ value: String, index: Int?)
    func put(_ value: Int, index: Int?)
    func put(_ value: Double, index: Int?)
    func put(_ value: Bool, index: Int?)
    func put(_ value: JsonObject, index: Int?)
    func put(_ value: JsonArray, index: Int?)
    func putNull(index: Int?)
    func put(_ value: JsonValue, index: Int?)
}
