package com.ionic.plugin.android.capacitor.core.actions

import com.getcapacitor.PluginCall
import com.ionic.plugin.android.capacitor.core.WrapperDelegate
import com.ionic.plugin.android.capacitor.core.toJSObject
import com.ionic.plugin.android.core.actions.CallContext
import com.ionic.plugin.core.PluginException
import com.ionic.plugin.core.actions.Mappers
import com.spryrocks.kson.JsonArray
import com.spryrocks.kson.JsonObject

class CallContext(
    private val call: PluginCall,
    wrapperDelegate: WrapperDelegate,
    private val mappers: Mappers,
) : CallContext(wrapperDelegate) {
    override fun asObject() = AsObject(call)

    override fun asArray(): AsArray {
        throw PluginException("Not implemented")
    }

    class AsObject(private val call: PluginCall) : com.ionic.plugin.core.actions.CallContext.AsObject() {
        override fun opt(name: String) = throw NotImplementedError()

        override fun optString(name: String) = nullable(name) { call.getString(name) }

        override fun optInt(name: String) = nullable(name) { call.getInt(name) }

        override fun optBoolean(name: String) = nullable(name) { call.getBoolean(name) }

        override fun optFloat(name: String) = nullable(name) { call.getFloat(name) }

        override fun optDouble(name: String) = nullable(name) { call.getDouble(name) }

        override fun optJsonObject(name: String) = nullable(name) {
            val jsonString = call.getObject(name).toString()
            return@nullable JsonObject.fromJson(jsonString)
        }

        override fun optLong(name: String) = nullable(name) { call.getInt(name)?.toLong() }

        override fun optNumber(name: String) = nullable(name) {
            try {
                return@nullable call.getDouble(name)
            } catch (e: Throwable) {
                return@nullable call.getInt(name) as Number
            }
        }

        override fun optJsonArray(name: String) = nullable(name) {
            val jsonString = call.getArray(name).toString()
            return@nullable JsonArray.fromJson(jsonString)
        }

        private fun <T> nullable(key: String, getter: () -> T): T? {
            val data = call.data
            if (!data.has(key)) return null
            if (data.isNull(key)) return null
            return getter()
        }
    }

    override fun success(data: Any?, finish: Boolean) {
        if (!finish) call.setKeepAlive(true)
        when(data) {
            null -> call.resolve()
            is JsonObject -> call.resolve(data.toJSObject())
            else -> throw NotImplementedError("This data type is not supported")
        }
    }

    override fun error(error: Throwable?, finish: Boolean) {
        if (!finish) call.setKeepAlive(true)
        val exception: Exception? = when (error) {
            is Exception -> error
            is Throwable -> Exception(error)
            else -> null
        }

        val defaultMessage = "Unknown error"

        val message = exception?.message ?: defaultMessage
        val json = (exception as? PluginException)?.let(mappers.errorMapper::mapToJson)

        if (json != null) {
            call.reject(message, json.toString())
        } else {
            call.reject(message)
        }
    }
}
