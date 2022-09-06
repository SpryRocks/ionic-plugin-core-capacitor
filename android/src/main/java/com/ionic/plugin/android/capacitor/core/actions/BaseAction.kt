package com.ionic.plugin.android.capacitor.core.actions

import com.ionic.plugin.android.capacitor.core.WrapperDelegate

abstract class BaseAction<TDelegate : Delegate> :
    com.ionic.plugin.android.core.actions.BaseAction<TDelegate, WrapperDelegate>()
