package com.ionic.plugin.android.capacitor.core

import android.app.Activity
import android.content.Intent
import com.getcapacitor.PluginCall
import com.ionic.plugin.android.capacitor.core.actions.CallContext
import com.ionic.plugin.android.core.utils.ActivityResultObserver
import com.ionic.plugin.android.core.utils.IActivityResultObserver
import com.ionic.plugin.core.actions.Delegate
import com.ionic.plugin.core.actions.Mappers
import com.spryrocks.kson.JsonObject
import com.spryrocks.kson.mutableJsonObject

abstract class CapacitorPlugin<TActionKey, TDelegate : Delegate<TMappers>, TMappers: Mappers> : com.getcapacitor.Plugin() {
    private val plugin: com.ionic.plugin.core.Plugin<TActionKey, TDelegate, TMappers>
    private val wrapperDelegate = WrapperDelegateImpl(this)
    private var activityResultObserver_ = ActivityResultObserver()
    protected val activityResultObserver: IActivityResultObserver get() = activityResultObserver_

    init {
        plugin = createPlugin()
        plugin._initializePluginInternal(wrapperDelegate)
    }

    abstract fun createPlugin(): com.ionic.plugin.core.Plugin<TActionKey, TDelegate, TMappers>

    override fun load() {
        plugin.load()
    }

    protected fun call(action: TActionKey, call: PluginCall) {
        plugin.call(action, CallContext(call, wrapperDelegate, plugin.mappers))
    }

    override fun handleOnActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        activityResultObserver_.onActivityResult(requestCode, resultCode, data)
    }

    class WrapperDelegateImpl<TActionKey, TDelegate : Delegate<TMappers>, TMappers: Mappers>(private val wrapper: CapacitorPlugin<TActionKey, TDelegate, TMappers>) :
        WrapperDelegate {
        override val activity: Activity
            get() = wrapper.activity

        override fun sendEvent(name: String, data: JsonObject) {
            wrapper.notifyListeners(name, data.toJSObject())
        }
    }
}
