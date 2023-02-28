import Foundation
import Capacitor
import IonicPluginCore

public class CallContextWrapper : CallContext {
    private var _call: CAPPluginCall

    init(call: CAPPluginCall) {
        self._call = call
    }

    override public func asObject() -> CallContext.AsObject {
        return AsObjectImpl(call: _call)
    }

    override public func asArray() -> CallContext.AsArray {
        fatalError("Not supported")
    }

    override public func success(data: Any?, finish: Bool) {
        _call.keepAlive = !finish
        if (data == nil) {
            _call.resolve()
        }
        else if (data is JsonObject) {
            let json = mapFromKsonJsonObject(jsonObject: data as! JsonObject)
            _call.resolve(json)
        }
        else {
            fatalError("Not supported type")
        }
    }

    override public func error(error: KotlinThrowable?, finish: Bool) {
        _call.keepAlive = !finish
        if (error != nil) {
            let message = error!.message
            if (message != nil) {
                _call.reject(message!)
            } else {
                _call.reject("Unknown error")
            }
        } else {
            _call.reject("Unknown error")
        }
    }

    func mapFromKsonJsonObject(jsonObject: JsonObject) -> [String: Any] {
        do {
            let str = jsonObject.description()
            let data = str.data(using: .utf8)!
            let json = try JSONSerialization.jsonObject(with: data) as! [String: Any]
            return json
        } catch {
            fatalError()
        }
    }

    class AsObjectImpl : AsObject {
        private var _call: CAPPluginCall

        init(call: CAPPluginCall) {
            self._call = call
        }

        public override func optString(name: String) -> String? {
            return _call.getString(name)
        }

        public override func optJsonArray(name: String) -> JsonArray? {
            let array = _call.getArray(name)
            if (array == nil) { return nil }
            return mapToKsonJsonArray(array: array!)
        }

        public override func optJsonObject(name: String) -> JsonObject? {
            let object = _call.getObject(name)
            if (object == nil) { return nil }
            return mapToKsonJsonObject(object: object!)
        }

        public override func optBoolean(name: String) -> KotlinBoolean? {
            let value = _call.getBool(name)
            if(value == nil) { return nil }
            return KotlinBoolean(bool: value!)
        }

        public override func optInt(name: String) -> KotlinInt? {
            let value = _call.getInt(name)
            if(value == nil) { return nil }
            return KotlinInt(int: Int32(value!))
        }

        public func optDouble(key: String) -> KotlinDouble? {
            fatalError("Not implemented")
        }

        public override func opt(name: String) -> Any? {
            fatalError("Not implemented")
        }

        public override func optFloat(name: String) -> KotlinFloat? {
            fatalError("Not implemented")
        }

        public override func optLong(name: String) -> KotlinLong? {
            fatalError("Not implemented")
        }

        public override func optNumber(name: String) -> Any? {
            fatalError("Not implemented")
        }

        func mapToKsonJsonArray(array: JSArray) -> JsonArray {
            do {
                let data = try JSONSerialization.data(withJSONObject: array)
                let json = String(data: data, encoding: .utf8)!
                return JsonArray.companion.fromJson(json: json)
            } catch {
                fatalError()
            }
        }

        func mapToKsonJsonObject(object: JSObject) -> JsonObject {
            do {
                let data = try JSONSerialization.data(withJSONObject: object)
                let json = String(data: data, encoding: .utf8)!
                return JsonObject.companion.fromJson(json: json)
            } catch {
                fatalError()
            }
        }
    }
}
