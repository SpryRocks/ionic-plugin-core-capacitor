package com.ionic.plugin.android.capacitor.core

import com.getcapacitor.JSObject
import com.spryrocks.kson.JsonObject

fun JsonObject.toJSObject() = JSObject(this.toString())
