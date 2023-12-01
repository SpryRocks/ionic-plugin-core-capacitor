public typealias HashableDictionary = Dictionary<AnyHashable, Any>

public func cannotGet(_ name: String, type: String, from: String) -> Error {
    return PluginError(message: "Cannot get \"\(name)\" \(type) from \(from)")
}

public func getDictionaryFromDictionary(_ dict: HashableDictionary, _ name: String) throws -> HashableDictionary {
    guard let result = dict[name] as? HashableDictionary else {
        throw cannotGet(name, type: "dictionary", from: "dictionary")
    }
    return result
}

public func optStringFromDictionary(_ dict: HashableDictionary, _ name: String) throws -> String? {
    guard let result = dict[name] as? String? else {
        throw cannotGet(name, type: "optional string", from: "dictionary")
    }
    return result
}

public func getStringFromDictionary(_ dict: HashableDictionary, _ name: String) throws -> String {
    guard let result = dict[name] as? String else {
        throw cannotGet(name, type: "string", from: "dictionary")
    }
    return result
}

public func getDoubleFromDictionary(_ dict: HashableDictionary, _ name: String) throws -> Double {
    guard let result = dict[name] as? Double else {
        throw cannotGet(name, type: "double", from: "dictionary")
    }
    return result
}

public func getIntFromDictionary(_ dict: HashableDictionary, _ name: String) throws -> Int {
    guard let result = dict[name] as? Int else {
        throw cannotGet(name, type: "int", from: "dictionary")
    }
    return result
}
