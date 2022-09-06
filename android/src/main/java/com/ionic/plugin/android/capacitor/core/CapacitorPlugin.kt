package com.ionic.plugin.android.capacitor.core

import android.app.Activity
import com.getcapacitor.PluginCall
import com.ionic.plugin.android.capacitor.core.actions.CallContext
import com.ionic.plugin.core.actions.Delegate

abstract class CapacitorPlugin<TActionKey, TDelegate : Delegate> : com.getcapacitor.Plugin() {
    private val plugin: com.ionic.plugin.core.Plugin<TActionKey, TDelegate>
    private val wrapperDelegate = WrapperDelegateImpl(this)

    init {
        plugin = createPlugin()
        plugin._initializePluginInternal(wrapperDelegate)
    }

    abstract fun createPlugin(): com.ionic.plugin.core.Plugin<TActionKey, TDelegate>

    override fun load() {
        plugin.load()
    }

    protected fun call(action: TActionKey, call: PluginCall) {
        plugin.call(action, CallContext(call, wrapperDelegate))
    }

    class WrapperDelegateImpl<TActionKey, TDelegate : Delegate>(private val wrapper: CapacitorPlugin<TActionKey, TDelegate>) :
        WrapperDelegate {
        override val activity: Activity
            get() = wrapper.activity
    }
}
