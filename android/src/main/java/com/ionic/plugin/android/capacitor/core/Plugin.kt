package com.ionic.plugin.android.capacitor.core

import com.ionic.plugin.android.capacitor.core.actions.Delegate
import com.ionic.plugin.android.capacitor.core.actions.WrapperDelegate

abstract class Plugin<TActionKey, TDelegate : Delegate> :
    com.ionic.plugin.android.core.Plugin<TActionKey, TDelegate>() {
    internal fun init(wrapperDelegate: WrapperDelegate) {
        super.init(wrapperDelegate)
    }
}
