package com.ionic.plugin.android.capacitor.core.actions

import com.getcapacitor.PluginCall
import com.ionic.plugin.android.capacitor.core.toJSObject
import com.ionic.plugin.android.core.actions.CallContext
import com.ionic.plugin.core.actions.CallContextResult
import com.spryrocks.kson.JsonArray
import com.spryrocks.kson.JsonObject

class CallContext(private val call: PluginCall, wrapperDelegate: WrapperDelegate) :
  CallContext(wrapperDelegate) {
  override fun getBoolean(key: String) = require(key, ::optBoolean)

  override fun getDouble(key: String) = require(key, ::optDouble)

  override fun getInt(key: String) = require(key, ::optInt)

  override fun getJsonArray(key: String) = require(key, ::optJsonArray)


  override fun getJsonObject(key: String) = require(key, ::optJsonObject)

  override fun getString(key: String) = require(key, ::optString)

  override fun optString(key: String) = nullable(key) { call.getString(key) }

  override fun optInt(key: String) = nullable(key) { call.getInt(key) }

  override fun optBoolean(key: String) = nullable(key) { call.getBoolean(key) }

  override fun optDouble(key: String) = nullable(key) { call.getDouble(key) }

  override fun optJsonObject(key: String) = nullable(key) {
    val jsonString = call.getObject(key).toString()
    return@nullable JsonObject.fromJson(jsonString)
  }

  override fun optJsonArray(key: String) = nullable(key) {
    val jsonString = call.getArray(key).toString()
    return@nullable JsonArray.fromJson(jsonString)
  }

  private fun <T> nullable(key: String, getter: () -> T): T? {
    if (!call.hasOption(key)) return null
    return getter()
  }

  private fun <T> require(name: String, block: (name: String) -> T?) =
    block(name) ?: throw Exception("value with name '${name}' is null")

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

    val defaultMessage = "Unknown message"

    if (exception != null) {
      call.reject(exception.message ?: defaultMessage, exception)
    } else {
      call.reject(defaultMessage)
    }
  }
}
