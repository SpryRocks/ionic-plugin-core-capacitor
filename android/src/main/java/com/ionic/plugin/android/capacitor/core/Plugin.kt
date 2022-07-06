package com.ionic.plugin.android.capacitor.core

import com.ionic.plugin.android.capacitor.core.actions.Delegate
import com.ionic.plugin.android.capacitor.core.actions.WrapperDelegate
import java.util.concurrent.Executors

abstract class Plugin<TActionKey, TDelegate : Delegate> :
    com.ionic.plugin.android.core.Plugin<TActionKey, TDelegate>(), Delegate {
    override val threadPool = Executors.newCachedThreadPool()!! // move to wrapper

    internal fun initialize(wrapperDelegate: WrapperDelegate) {
        super.initialize(wrapperDelegate)
    }
}
