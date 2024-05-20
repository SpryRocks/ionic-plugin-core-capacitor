public class JsonArrayIterator: IteratorProtocol {
    public typealias Element = JsonValue
    
    private let jsonArray: JsonArray
    
    private var index = -1
    
    init(_ jsonArray: JsonArray) {
        self.jsonArray = jsonArray
    }
    
    public func next() -> JsonValue? {
        var el: JsonValue? = nil
        while (index < jsonArray.size - 1) {
            index += 1
            el = jsonArray.opt(index)
            if (el != nil) {
                break
            }
        }
        return el
    }
}
