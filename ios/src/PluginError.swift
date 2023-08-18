open class PluginError : Error {
    public let message: String?
    public let code: String?
    public let cause: Error?
    
    public init(message: String? = nil, code: String? = nil, cause: Error? = nil) {
        self.message = message
        self.code = code
        self.cause = cause
    }
}
