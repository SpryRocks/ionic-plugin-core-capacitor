package com.ionic.plugin.android.capacitor.core

import android.app.Activity
import android.content.Intent
import com.getcapacitor.PluginCall
import com.getcapacitor.PluginMethod
import com.ionic.plugin.android.capacitor.core.actions.CallContext
import com.ionic.plugin.android.core.utils.ActivityResultObserver
import com.ionic.plugin.android.core.utils.IActivityResultObserver
import com.ionic.plugin.core.actions.BaseAction
import com.ionic.plugin.core.actions.Delegate
import com.ionic.plugin.core.actions.IActionCreator
import com.ionic.plugin.core.actions.Mappers
import com.ionic.plugin.core.actions.SetLogLevelsAction
import com.spryrocks.kson.JsonObject

abstract class CapacitorPlugin<TActionKey, TDelegate : Delegate<TMappers>, TMappers : Mappers> :
    com.getcapacitor.Plugin() {
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
        plugin.call(action, call.toContext())
    }

    protected fun callAction(
        actionCreator: (call: CallContext) -> BaseAction<TDelegate, TMappers>,
        call: PluginCall
    ) {
        val context = call.toContext()
        val baseAction = actionCreator(context)
        plugin.callAction(baseAction, context)
    }

    private fun PluginCall.toContext(): CallContext {
        return CallContext(this, wrapperDelegate, plugin.mappers)
    }

    override fun handleOnActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        activityResultObserver_.onActivityResult(requestCode, resultCode, data)
    }

    @PluginMethod
    fun setLogLevels(call: PluginCall) {
        callAction({ SetLogLevelsAction(it.asObject()) }, call)
    }

    class WrapperDelegateImpl<TActionKey, TDelegate : Delegate<TMappers>, TMappers : Mappers>(
        private val wrapper: CapacitorPlugin<TActionKey, TDelegate, TMappers>
    ) :
        WrapperDelegate {
        override val activity: Activity
            get() = wrapper.activity

        override fun sendEvent(name: String, data: JsonObject) {
            wrapper.notifyListeners(name, data.toJSObject())
        }
    }
}
