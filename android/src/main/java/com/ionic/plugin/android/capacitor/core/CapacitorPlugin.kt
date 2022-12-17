package com.ionic.plugin.android.capacitor.core

import android.app.Activity
import com.getcapacitor.PluginCall
import com.ionic.plugin.android.capacitor.core.actions.CallContext
import com.ionic.plugin.core.actions.Delegate
import com.ionic.plugin.core.actions.Mappers

abstract class CapacitorPlugin<TActionKey, TDelegate : Delegate<TMappers>, TMappers: Mappers> : com.getcapacitor.Plugin() {
    private val plugin: com.ionic.plugin.core.Plugin<TActionKey, TDelegate, TMappers>
    private val wrapperDelegate = WrapperDelegateImpl<TActionKey, TDelegate, TMappers>(this)

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

    class WrapperDelegateImpl<TActionKey, TDelegate : Delegate<TMappers>, TMappers: Mappers>(private val wrapper: CapacitorPlugin<TActionKey, TDelegate, TMappers>) :
        WrapperDelegate {
        override val activity: Activity
            get() = wrapper.activity
    }
}
