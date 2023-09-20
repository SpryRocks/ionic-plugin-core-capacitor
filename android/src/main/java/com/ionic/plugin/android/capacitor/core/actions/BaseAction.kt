package com.ionic.plugin.android.capacitor.core.actions

import com.ionic.plugin.android.capacitor.core.WrapperDelegate
import com.ionic.plugin.core.actions.Mappers
import com.spryrocks.kson.IJsonObjectProperties

typealias Args = IJsonObjectProperties

abstract class BaseAction<TDelegate : Delegate<TMappers>, TMappers: Mappers> :
    com.ionic.plugin.android.core.actions.BaseAction<TDelegate, WrapperDelegate, TMappers>()
