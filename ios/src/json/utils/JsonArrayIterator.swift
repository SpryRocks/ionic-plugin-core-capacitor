public class JsonArrayIterator: IteratorProtocol {
    public typealias Element = JsonValue
    
    private let jsonArray: JsonArray
    
    private var index = -1
    
    init(_ jsonArray: JsonArray) {
        self.jsonArray = jsonArray
    }
    
    public func next() -> JsonValue? {
        index += 1;
        return jsonArray.opt(index)
    }
}
