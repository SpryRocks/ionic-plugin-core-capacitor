package com.ionic.plugin.android.capacitor.core.actions

import com.getcapacitor.PluginCall
import com.ionic.plugin.android.capacitor.core.WrapperDelegate
import com.ionic.plugin.android.capacitor.core.toJSObject
import com.ionic.plugin.android.core.actions.CallContext
import com.ionic.plugin.core.PluginException
import com.ionic.plugin.core.actions.CallContextResult
import com.ionic.plugin.core.actions.IErrorMapper
import com.spryrocks.kson.JsonArray
import com.spryrocks.kson.JsonObject

class CallContext(
    private val call: PluginCall,
    wrapperDelegate: WrapperDelegate,
    private val errorMapper: IErrorMapper,
) : CallContext(wrapperDelegate) {
    override fun opt(name: String) = throw NotImplementedError()

    override fun optString(name: String) = nullable(name) { call.getString(name) }

    override fun optInt(name: String) = nullable(name) { call.getInt(name) }

    override fun optBoolean(name: String) = nullable(name) { call.getBoolean(name) }

    override fun optFloat(name: String) = nullable(name) { call.getFloat(name) }

    override fun optDouble(key: String) = nullable(key) { call.getDouble(key) }

    override fun optJsonObject(name: String) = nullable(name) {
        val jsonString = call.getObject(name).toString()
        return@nullable JsonObject.fromJson(jsonString)
    }

    override fun optLong(name: String) = nullable(name) { call.getInt(name).toLong() }

    override fun optNumber(name: String) = throw NotImplementedError()

    override fun optJsonArray(name: String) = nullable(name) {
        val jsonString = call.getArray(name).toString()
        return@nullable JsonArray.fromJson(jsonString)
    }

    private fun <T> nullable(key: String, getter: () -> T): T? {
        if (!call.hasOption(key)) return null
        return getter()
    }

    override fun result(result: CallContextResult, finish: Boolean) {
    //    if (!finish) call.setKeepAlive(true)
        when (result) {
            is CallContextResult.Success -> success(result.data)
            is CallContextResult.Error -> error(result.error)
            else -> error(null)
        }
    }

    private fun success(data: JsonObject?) {
        call.resolve(data?.toJSObject())
    }

    private fun error(error: Throwable?) {
        val exception: Exception? = when (error) {
            is Exception -> error
            is Throwable -> Exception(error)
            else -> null
        }

        val defaultMessage = "Unknown error"

        val message = exception?.message ?: defaultMessage
        val json = (exception as? PluginException)?.let(errorMapper::mapToJson)

        if (json != null) {
            call.reject(message, json.toString())
        } else {
            call.reject(message)
        }
    }
}
