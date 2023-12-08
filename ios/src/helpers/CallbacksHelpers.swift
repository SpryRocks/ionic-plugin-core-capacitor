public typealias OnSuccess = () -> Void
public typealias OnSuccess1<T> = (_ value: T) -> Void
public typealias OnError = (_ cause: Error) -> Void

public class ContinuationCallback<TResult> {
    private var continuation: CheckedContinuation<TResult, Error>? = nil
    
    public init() {
    }

    public func setContinuation(_ continuation: CheckedContinuation<TResult, Error>) {
        if let continuation = self.continuation {
            continuation.resume(throwing: PluginError(message: "Cancelled because another callback was set"))
        }
        self.continuation = continuation
    }

    public func onSuccess(_ result: TResult) {
        if let continuation = continuation {
            continuation.resume(returning: result)
        }
        continuation = nil
    }

    public func onError(_ error: Error) {
        if let continuation = continuation {
            continuation.resume(throwing: error)
        }
        continuation = nil
    }
}
