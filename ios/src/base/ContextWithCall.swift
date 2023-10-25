open class ContextWithCall<TDelegate, TMappers>: Context<TDelegate, TMappers> where TDelegate : CoreDelegate, TMappers : CoreMappers {
    let call: CallContext
    
    init(call: CallContext) throws {
        self.call = call
    }
}
