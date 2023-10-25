public protocol ICoreEvent {
    var name: String { get }
    
    func getData() -> JsonObject
}

open class CoreBaseEvent<TDelegate, TMappers>: Context<TDelegate, TMappers>, ICoreEvent where TDelegate : CoreDelegate, TMappers : CoreMappers {
    public let name: String
    
    public init(name: String) {
        self.name = name
    }
    
    open func getData() -> JsonObject {
        return [:]
    }
}
