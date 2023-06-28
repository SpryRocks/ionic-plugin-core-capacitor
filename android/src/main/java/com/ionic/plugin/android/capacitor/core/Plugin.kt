package com.ionic.plugin.android.capacitor.core

import com.ionic.plugin.core.actions.Delegate as CoreDelegate
import com.ionic.plugin.android.capacitor.core.actions.Delegate
import com.ionic.plugin.core.actions.Mappers
import com.spryrocks.kson.JsonObject
import java.util.concurrent.Executors

abstract class Plugin<TActionKey, TDelegate : CoreDelegate<TMappers>, TMappers: Mappers> :
    com.ionic.plugin.android.core.Plugin<TActionKey, TDelegate, TMappers>(), Delegate<TMappers> {
    override val threadPool = Executors.newCachedThreadPool()!! // move to wrapper
}
