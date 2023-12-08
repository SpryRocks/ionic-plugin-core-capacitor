public func runInMainThreadAsync<T>(_ action: @escaping () async throws -> T) async throws -> T {
    return try await withCheckedThrowingContinuation { c in
        DispatchQueue.main.async {
            Task {
                c.resume(returning: try await action())
            }
        }
    }
}
