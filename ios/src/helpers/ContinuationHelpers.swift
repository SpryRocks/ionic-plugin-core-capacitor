@inlinable public func withCheckedThrowingContinuationSafe<T>(_ body: (CheckedContinuationSafe<T, Error>) -> Void) async throws -> T {
    return try await withCheckedThrowingContinuation { c in
        let continuation = CheckedContinuationSafe<T, Error>(continuation: c)
        body(continuation)
    }
}

public final class CheckedContinuationSafe<T, E> : Sendable where E : Error {
    private let continuation: CheckedContinuation<T, E>
    private var isResumed = false
    
    public init(continuation: CheckedContinuation<T, E>) {
        self.continuation = continuation
    }

    public func resume(returning value: T) {
        if (isResumed) { return }
        self.isResumed = true
        continuation.resume(returning: value)
    }

    public func resume(throwing error: E) {
        if (isResumed) { return }
        self.isResumed = true
        continuation.resume(throwing: error)
    }
    
    public func resume() where T == () {
        if (isResumed) { return }
        self.isResumed = true
        continuation.resume()
    }
}
