import Foundation
import Capacitor
import IonicPluginCore

open class CapacitorPlugin<TActionKey:AnyObject, TDelegate:AnyObject, TMappers:AnyObject>: CAPPlugin {
    var plugin: Plugin<TActionKey, TDelegate, TMappers>? = nil
    
    public override func load() {
        //        let plugin = DatabasePlugin()
        plugin?._initializePluginInternal(wrapperDelegate: WrapperDelegateImpl())
        //        plugin.load()
        //        self.plugin = plugin
    }
    
    private func call(action: TActionKey, call: CAPPluginCall) {
        DispatchQueue.main.async {
            let wrapper = CallContextWrapper(call: call)
            self.plugin!.call(action: action, call: wrapper)
        }
    }
    
    public class WrapperDelegateImpl: WrapperDelegate {
    }
}
