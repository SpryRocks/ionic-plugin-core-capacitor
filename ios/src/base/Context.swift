open class Context<TDelegate, TMappers> where TDelegate : CoreDelegate, TMappers : CoreMappers {
    private var _callback: PluginCallbackInternal? = nil
    private var _delegate: TDelegate? = nil
    private var _mappers: TMappers? = nil
    
    var callback: PluginCallbackInternal { get { return _callback! }}
    public var delegate: TDelegate { get { return _delegate! }}
    public var mappers: TMappers { get { return _mappers! }}
    
    internal func initialize(
        callback: any PluginCallbackInternal,
        delegate: TDelegate, 
        mappers: TMappers
    ) {
        _callback = callback
        _delegate = delegate
        _mappers = mappers
    }
}
