open class ContextWithCall<TDelegate, TMappers>: Context<TDelegate, TMappers> where TDelegate : CoreDelegate, TMappers : CoreMappers {
    private var _call: CallContext? = nil
    
    var call: CallContext { get { return _call! }}
    
    internal func initialize(
        callback: any PluginCallbackInternal,
        delegate: TDelegate,
        mappers: TMappers,
        call: CallContext
    ) {
        super.initialize(
            callback: callback,
            delegate: delegate,
            mappers: mappers
        )
        self._call = call
    }
}
