#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class IPCBaseAction<TDelegate, TMappers>, IPCKotlinThrowable, IPCCallContext, IPCMappers, IPCKotlinArray<T>, IPCKotlinException, IPCKotlinRuntimeException, IPCCallContextAsArray, IPCCallContextAsObject, IPCJsonArray, IPCJsonObject, IPCAtomicfuSynchronizedObject, IPCCurrentAction<TAction>, IPCPluginException, IPCErrorMapper, IPCMutableJsonObject, IPCJsonElement, IPCJsonArrayCompanion, IPCJsonArrayIterator, IPCMutableJsonArray, IPCKotlinx_serialization_jsonJsonElement, IPCJsonObjectCompanion, IPCAtomicfuSynchronizedObjectLockState, IPCKotlinAtomicReference<T>, IPCKotlinx_serialization_jsonJsonElementCompanion, IPCAtomicfuSynchronizedObjectStatus, IPCKotlinEnumCompanion, IPCKotlinEnum<E>, IPCKotlinx_serialization_coreSerializersModule, IPCKotlinx_serialization_coreSerialKind, IPCKotlinNothing;

@protocol IPCPluginCallback, IPCKotlinCoroutineContext, IPCKotlinx_coroutines_coreCoroutineScope, IPCWrapperDelegate, IPCAction, IPCIJsonArrayProperties, IPCIJsonObjectProperties, IPCIActionCreator, IPCIMutableJsonArray, IPCIJsonElement, IPCKotlinIterator, IPCKotlinIterable, IPCIJsonArray, IPCIJsonObject, IPCIMutableJsonObject, IPCKotlinCoroutineContextElement, IPCKotlinCoroutineContextKey, IPCKotlinx_serialization_coreKSerializer, IPCKotlinComparable, IPCKotlinx_serialization_coreEncoder, IPCKotlinx_serialization_coreSerialDescriptor, IPCKotlinx_serialization_coreSerializationStrategy, IPCKotlinx_serialization_coreDecoder, IPCKotlinx_serialization_coreDeserializationStrategy, IPCKotlinx_serialization_coreCompositeEncoder, IPCKotlinAnnotation, IPCKotlinx_serialization_coreCompositeDecoder, IPCKotlinx_serialization_coreSerializersModuleCollector, IPCKotlinKClass, IPCKotlinKDeclarationContainer, IPCKotlinKAnnotatedElement, IPCKotlinKClassifier;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface IPCBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface IPCBase (IPCBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface IPCMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface IPCMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorIPCKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface IPCNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface IPCByte : IPCNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface IPCUByte : IPCNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface IPCShort : IPCNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface IPCUShort : IPCNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface IPCInt : IPCNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface IPCUInt : IPCNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface IPCLong : IPCNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface IPCULong : IPCNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface IPCFloat : IPCNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface IPCDouble : IPCNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface IPCBoolean : IPCNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((swift_name("PluginCallback")))
@protocol IPCPluginCallback
@required
- (void)finishActionSafelyAction:(IPCBaseAction *)action __attribute__((swift_name("finishActionSafely(action:)")));
- (void)reportErrorError:(IPCKotlinThrowable * _Nullable)error call:(IPCCallContext *)call finish:(BOOL)finish __attribute__((swift_name("reportError(error:call:finish:)")));
- (void)reportSuccessData:(id _Nullable)data call:(IPCCallContext *)call finish:(BOOL)finish __attribute__((swift_name("reportSuccess(data:call:finish:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol IPCKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<IPCKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("Plugin")))
@interface IPCPlugin<TActionKey, TDelegate, TMappers> : IPCBase <IPCPluginCallback, IPCKotlinx_coroutines_coreCoroutineScope>

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)_initializePluginInternalWrapperDelegate:(id<IPCWrapperDelegate>)wrapperDelegate __attribute__((swift_name("_initializePluginInternal(wrapperDelegate:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)actionFinishedAction:(IPCBaseAction<TDelegate, TMappers> *)action __attribute__((swift_name("actionFinished(action:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)beforeActionRunAction:(IPCBaseAction<TDelegate, TMappers> *)action __attribute__((swift_name("beforeActionRun(action:)")));
- (BOOL)callAction:(TActionKey _Nullable)action call:(IPCCallContext *)call __attribute__((swift_name("call(action:call:)")));
- (IPCBaseAction<TDelegate, TMappers> *)createActionAction:(TActionKey _Nullable)action call:(IPCCallContext *)call __attribute__((swift_name("createAction(action:call:)")));
- (void)finishActionSafelyAction:(IPCBaseAction<TDelegate, TMappers> *)action __attribute__((swift_name("finishActionSafely(action:)")));
- (void)load __attribute__((swift_name("load()")));
- (void)reportErrorError:(IPCKotlinThrowable * _Nullable)error call:(IPCCallContext *)call finish:(BOOL)finish __attribute__((swift_name("reportError(error:call:finish:)")));
- (void)reportSuccessData:(id _Nullable)data call:(IPCCallContext *)call finish:(BOOL)finish __attribute__((swift_name("reportSuccess(data:call:finish:)")));
- (void)unload __attribute__((swift_name("unload()")));
@property (readonly) id<IPCKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) TDelegate delegate __attribute__((swift_name("delegate")));
@property (readonly) IPCMappers *mappers __attribute__((swift_name("mappers")));
@property (readonly) id<IPCWrapperDelegate> wrapperDelegate __attribute__((swift_name("wrapperDelegate")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface IPCKotlinThrowable : IPCBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (IPCKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) IPCKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface IPCKotlinException : IPCKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface IPCKotlinRuntimeException : IPCKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("PluginException")))
@interface IPCPluginException : IPCKotlinRuntimeException
- (instancetype)initWithMessage:(NSString * _Nullable)message code:(IPCInt * _Nullable)code cause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:code:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(IPCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) IPCInt * _Nullable code __attribute__((swift_name("code")));
@end

__attribute__((swift_name("WrapperDelegate")))
@protocol IPCWrapperDelegate
@required
@end

__attribute__((swift_name("Action")))
@protocol IPCAction
@required
@end

__attribute__((swift_name("BaseAction")))
@interface IPCBaseAction<TDelegate, TMappers> : IPCBase <IPCAction>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)cancelTimeout __attribute__((swift_name("cancelTimeout()")));
- (void)errorError:(IPCKotlinThrowable * _Nullable)error finish:(BOOL)finish __attribute__((swift_name("error(error:finish:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)executeAsyncBlock:(void (^)(void))block __attribute__((swift_name("executeAsync(block:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)executeSyncBlock:(void (^)(void))block __attribute__((swift_name("executeSync(block:)")));

/**
 * @note This method converts instances of PluginException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (BOOL)onExecuteAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("onExecute()")));
- (void)run __attribute__((swift_name("run()")));
- (void)successData:(id _Nullable)data finish:(BOOL)finish __attribute__((swift_name("success(data:finish:)")));
@property (readonly) IPCCallContext *call __attribute__((swift_name("call")));
@property (readonly) TDelegate delegate __attribute__((swift_name("delegate")));
@property (readonly) TMappers mappers __attribute__((swift_name("mappers")));
@end

__attribute__((swift_name("CallContext")))
@interface IPCCallContext : IPCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (IPCCallContextAsArray *)asArray __attribute__((swift_name("asArray()")));
- (IPCCallContextAsObject *)asObject __attribute__((swift_name("asObject()")));
- (void)errorError:(IPCKotlinThrowable * _Nullable)error finish:(BOOL)finish __attribute__((swift_name("error(error:finish:)")));
- (void)successData:(id _Nullable)data finish:(BOOL)finish __attribute__((swift_name("success(data:finish:)")));
@end

__attribute__((swift_name("IJsonArrayProperties")))
@protocol IPCIJsonArrayProperties
@required
- (id)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (BOOL)getBooleanIndex:(int32_t)index __attribute__((swift_name("getBoolean(index:)")));
- (float)getFloatIndex:(int32_t)index __attribute__((swift_name("getFloat(index:)")));
- (int32_t)getIntIndex:(int32_t)index __attribute__((swift_name("getInt(index:)")));
- (IPCJsonArray *)getJsonArrayIndex:(int32_t)index __attribute__((swift_name("getJsonArray(index:)")));
- (IPCJsonObject *)getJsonObjectIndex:(int32_t)index __attribute__((swift_name("getJsonObject(index:)")));
- (int64_t)getLongIndex:(int32_t)index __attribute__((swift_name("getLong(index:)")));
- (id)getNumberIndex:(int32_t)index __attribute__((swift_name("getNumber(index:)")));
- (NSString *)getStringIndex:(int32_t)index __attribute__((swift_name("getString(index:)")));
- (id _Nullable)optIndex:(int32_t)index __attribute__((swift_name("opt(index:)")));
- (IPCBoolean * _Nullable)optBooleanIndex:(int32_t)index __attribute__((swift_name("optBoolean(index:)")));
- (IPCFloat * _Nullable)optFloatIndex:(int32_t)index __attribute__((swift_name("optFloat(index:)")));
- (IPCInt * _Nullable)optIntIndex:(int32_t)index __attribute__((swift_name("optInt(index:)")));
- (IPCJsonArray * _Nullable)optJsonArrayIndex:(int32_t)index __attribute__((swift_name("optJsonArray(index:)")));
- (IPCJsonObject * _Nullable)optJsonObjectIndex:(int32_t)index __attribute__((swift_name("optJsonObject(index:)")));
- (IPCLong * _Nullable)optLongIndex:(int32_t)index __attribute__((swift_name("optLong(index:)")));
- (id _Nullable)optNumberIndex:(int32_t)index __attribute__((swift_name("optNumber(index:)")));
- (NSString * _Nullable)optStringIndex:(int32_t)index __attribute__((swift_name("optString(index:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("CallContext.AsArray")))
@interface IPCCallContextAsArray : IPCBase <IPCIJsonArrayProperties>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (BOOL)getBooleanIndex:(int32_t)index __attribute__((swift_name("getBoolean(index:)")));
- (double)getDoubleIndex:(int32_t)index __attribute__((swift_name("getDouble(index:)")));
- (float)getFloatIndex:(int32_t)index __attribute__((swift_name("getFloat(index:)")));
- (int32_t)getIntIndex:(int32_t)index __attribute__((swift_name("getInt(index:)")));
- (IPCJsonArray *)getJsonArrayIndex:(int32_t)index __attribute__((swift_name("getJsonArray(index:)")));
- (IPCJsonObject *)getJsonObjectIndex:(int32_t)index __attribute__((swift_name("getJsonObject(index:)")));
- (int64_t)getLongIndex:(int32_t)index __attribute__((swift_name("getLong(index:)")));
- (id)getNumberIndex:(int32_t)index __attribute__((swift_name("getNumber(index:)")));
- (NSString *)getStringIndex:(int32_t)index __attribute__((swift_name("getString(index:)")));
- (IPCDouble * _Nullable)optDoubleIndex:(int32_t)index __attribute__((swift_name("optDouble(index:)")));
@end

__attribute__((swift_name("IJsonObjectProperties")))
@protocol IPCIJsonObjectProperties
@required
- (id)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (BOOL)getBooleanName:(NSString *)name __attribute__((swift_name("getBoolean(name:)")));
- (float)getFloatName:(NSString *)name __attribute__((swift_name("getFloat(name:)")));
- (int32_t)getIntName:(NSString *)name __attribute__((swift_name("getInt(name:)")));
- (IPCJsonArray *)getJsonArrayName:(NSString *)name __attribute__((swift_name("getJsonArray(name:)")));
- (IPCJsonObject *)getJsonObjectName:(NSString *)name __attribute__((swift_name("getJsonObject(name:)")));
- (int64_t)getLongName:(NSString *)name __attribute__((swift_name("getLong(name:)")));
- (id)getNumberName:(NSString *)name __attribute__((swift_name("getNumber(name:)")));
- (NSString *)getStringName:(NSString *)name __attribute__((swift_name("getString(name:)")));
- (id _Nullable)optName:(NSString *)name __attribute__((swift_name("opt(name:)")));
- (IPCBoolean * _Nullable)optBooleanName:(NSString *)name __attribute__((swift_name("optBoolean(name:)")));
- (IPCFloat * _Nullable)optFloatName:(NSString *)name __attribute__((swift_name("optFloat(name:)")));
- (IPCInt * _Nullable)optIntName:(NSString *)name __attribute__((swift_name("optInt(name:)")));
- (IPCJsonArray * _Nullable)optJsonArrayName:(NSString *)name __attribute__((swift_name("optJsonArray(name:)")));
- (IPCJsonObject * _Nullable)optJsonObjectName:(NSString *)name __attribute__((swift_name("optJsonObject(name:)")));
- (IPCLong * _Nullable)optLongName:(NSString *)name __attribute__((swift_name("optLong(name:)")));
- (id _Nullable)optNumberName:(NSString *)name __attribute__((swift_name("optNumber(name:)")));
- (NSString * _Nullable)optStringName:(NSString *)name __attribute__((swift_name("optString(name:)")));
@end

__attribute__((swift_name("CallContext.AsObject")))
@interface IPCCallContextAsObject : IPCBase <IPCIJsonObjectProperties>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (BOOL)getBooleanName:(NSString *)name __attribute__((swift_name("getBoolean(name:)")));
- (double)getDoubleName:(NSString *)name __attribute__((swift_name("getDouble(name:)")));
- (float)getFloatName:(NSString *)name __attribute__((swift_name("getFloat(name:)")));
- (int32_t)getIntName:(NSString *)name __attribute__((swift_name("getInt(name:)")));
- (IPCJsonArray *)getJsonArrayName:(NSString *)name __attribute__((swift_name("getJsonArray(name:)")));
- (IPCJsonObject *)getJsonObjectName:(NSString *)name __attribute__((swift_name("getJsonObject(name:)")));
- (int64_t)getLongName:(NSString *)name __attribute__((swift_name("getLong(name:)")));
- (id)getNumberName:(NSString *)name __attribute__((swift_name("getNumber(name:)")));
- (NSString *)getStringName:(NSString *)name __attribute__((swift_name("getString(name:)")));
- (IPCDouble * _Nullable)optDoubleName:(NSString *)name __attribute__((swift_name("optDouble(name:)")));
@end

__attribute__((swift_name("CancelableAction")))
@protocol IPCCancelableAction <IPCAction>
@required
- (void)cancel __attribute__((swift_name("cancel()")));
@end

__attribute__((swift_name("CurrentAction")))
@interface IPCCurrentAction<TAction> : IPCBase
- (instancetype)initWith_currentActionLock:(IPCAtomicfuSynchronizedObject *)_currentActionLock __attribute__((swift_name("init(_currentActionLock:)"))) __attribute__((objc_designated_initializer));
- (void)clearAction:(TAction _Nullable)action __attribute__((swift_name("clear(action:)")));
- (TAction _Nullable)get __attribute__((swift_name("get()")));
- (void)setAction:(TAction _Nullable)action __attribute__((swift_name("set(action:)")));
@property (readonly) IPCAtomicfuSynchronizedObject *_currentActionLock __attribute__((swift_name("_currentActionLock")));
@property TAction _Nullable currentAction __attribute__((swift_name("currentAction")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CurrentActionCancelable")))
@interface IPCCurrentActionCancelable<TAction> : IPCCurrentAction<TAction>
- (instancetype)initWithCurrentActionLock:(IPCAtomicfuSynchronizedObject *)currentActionLock __attribute__((swift_name("init(currentActionLock:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWith_currentActionLock:(IPCAtomicfuSynchronizedObject *)_currentActionLock __attribute__((swift_name("init(_currentActionLock:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)cancel __attribute__((swift_name("cancel()")));
@end

__attribute__((swift_name("Delegate")))
@protocol IPCDelegate
@required
@property (readonly) IPCMappers *mappers __attribute__((swift_name("mappers")));
@end

__attribute__((swift_name("ErrorMapper")))
@interface IPCErrorMapper : IPCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (IPCPluginException *)mapError:(IPCKotlinThrowable *)error __attribute__((swift_name("map(error:)")));
- (IPCJsonObject * _Nullable)mapToJsonError:(IPCKotlinThrowable *)error __attribute__((swift_name("mapToJson(error:)")));
- (void)reportErrorError:(IPCKotlinThrowable * _Nullable)error callContext:(IPCCallContext *)callContext finish:(BOOL)finish __attribute__((swift_name("reportError(error:callContext:finish:)")));
@end

__attribute__((swift_name("IActionCreator")))
@protocol IPCIActionCreator
@required
- (IPCBaseAction *)createActionCall:(IPCCallContext *)call __attribute__((swift_name("createAction(call:)")));
@end

__attribute__((swift_name("IActionConstructor")))
@protocol IPCIActionConstructor <IPCIActionCreator>
@required
- (id _Nullable)mapperCall:(IPCCallContext *)call __attribute__((swift_name("mapper(call:)")));
@property (readonly) IPCBaseAction *(^action)(id _Nullable) __attribute__((swift_name("action")));
@end

__attribute__((swift_name("IActionFactory")))
@protocol IPCIActionFactory
@required
- (IPCBaseAction *)createActionAction:(id _Nullable)action call_:(IPCCallContext *)call __attribute__((swift_name("createAction(action:call_:)")));
@end

__attribute__((swift_name("Mappers")))
@interface IPCMappers : IPCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)reportErrorError:(IPCKotlinThrowable * _Nullable)error callContext:(IPCCallContext *)callContext finish:(BOOL)finish __attribute__((swift_name("reportError(error:callContext:finish:)")));
- (void)reportSuccessData:(id _Nullable)data callContext:(IPCCallContext *)callContext finish:(BOOL)finish __attribute__((swift_name("reportSuccess(data:callContext:finish:)")));
@property (readonly) IPCErrorMapper *errorMapper __attribute__((swift_name("errorMapper")));
@end

__attribute__((swift_name("IJsonElement")))
@protocol IPCIJsonElement
@required
@end

__attribute__((swift_name("KotlinIterable")))
@protocol IPCKotlinIterable
@required
- (id<IPCKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("IJsonArray")))
@protocol IPCIJsonArray <IPCIJsonElement, IPCIJsonArrayProperties, IPCKotlinIterable>
@required
- (id<IPCIMutableJsonArray>)mutate __attribute__((swift_name("mutate()")));
@end

__attribute__((swift_name("IJsonObject")))
@protocol IPCIJsonObject <IPCIJsonElement, IPCIJsonObjectProperties>
@required
- (IPCMutableJsonObject *)mutate __attribute__((swift_name("mutate()")));
@property (readonly) NSSet<NSString *> *names __attribute__((swift_name("names")));
@end

__attribute__((swift_name("IMutableJsonArray")))
@protocol IPCIMutableJsonArray <IPCIJsonArray>
@required
- (void)putValue:(IPCJsonArray *)value index:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index:)")));
- (void)putValue:(IPCJsonObject *)value index_:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index_:)")));
- (void)putValue:(id)value index__:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index__:)")));
- (void)putValue:(BOOL)value index___:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index___:)")));
- (void)putValue:(float)value index____:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index____:)")));
- (void)putValue:(int32_t)value index_____:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index_____:)")));
- (void)putValue:(int64_t)value index______:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index______:)")));
- (void)putValue:(id)value index_______:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index_______:)")));
- (void)putValue:(NSString *)value index________:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index________:)")));
- (void)putNullIndex:(IPCInt * _Nullable)index __attribute__((swift_name("putNull(index:)")));
@end

__attribute__((swift_name("IMutableJsonObject")))
@protocol IPCIMutableJsonObject <IPCIJsonObject>
@required
- (void)putName:(NSString *)name value:(IPCJsonArray *)value __attribute__((swift_name("put(name:value:)")));
- (void)putName:(NSString *)name value_:(IPCJsonObject *)value __attribute__((swift_name("put(name:value_:)")));
- (void)putName:(NSString *)name value__:(id)value __attribute__((swift_name("put(name:value__:)")));
- (void)putName:(NSString *)name value___:(BOOL)value __attribute__((swift_name("put(name:value___:)")));
- (void)putName:(NSString *)name value____:(float)value __attribute__((swift_name("put(name:value____:)")));
- (void)putName:(NSString *)name value_____:(int32_t)value __attribute__((swift_name("put(name:value_____:)")));
- (void)putName:(NSString *)name value______:(int64_t)value __attribute__((swift_name("put(name:value______:)")));
- (void)putName:(NSString *)name value_______:(id)value __attribute__((swift_name("put(name:value_______:)")));
- (void)putName:(NSString *)name value________:(NSString *)value __attribute__((swift_name("put(name:value________:)")));
- (void)putNullName:(NSString *)name __attribute__((swift_name("putNull(name:)")));
@end

__attribute__((swift_name("JsonElement")))
@interface IPCJsonElement : IPCBase <IPCIJsonElement>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end

__attribute__((swift_name("JsonArray")))
@interface IPCJsonArray : IPCJsonElement <IPCIJsonArray>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (class, readonly, getter=companion) IPCJsonArrayCompanion *companion __attribute__((swift_name("companion")));
- (id)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (BOOL)getBooleanIndex:(int32_t)index __attribute__((swift_name("getBoolean(index:)")));
- (float)getFloatIndex:(int32_t)index __attribute__((swift_name("getFloat(index:)")));
- (int32_t)getIntIndex:(int32_t)index __attribute__((swift_name("getInt(index:)")));
- (IPCJsonArray *)getJsonArrayIndex:(int32_t)index __attribute__((swift_name("getJsonArray(index:)")));
- (IPCJsonObject *)getJsonObjectIndex:(int32_t)index __attribute__((swift_name("getJsonObject(index:)")));
- (int64_t)getLongIndex:(int32_t)index __attribute__((swift_name("getLong(index:)")));
- (id)getNumberIndex:(int32_t)index __attribute__((swift_name("getNumber(index:)")));
- (NSString *)getStringIndex:(int32_t)index __attribute__((swift_name("getString(index:)")));
- (IPCJsonArrayIterator *)iterator __attribute__((swift_name("iterator()")));
- (IPCMutableJsonArray *)mutate __attribute__((swift_name("mutate()")));
- (id _Nullable)optIndex:(int32_t)index __attribute__((swift_name("opt(index:)")));
- (IPCBoolean * _Nullable)optBooleanIndex:(int32_t)index __attribute__((swift_name("optBoolean(index:)")));
- (IPCFloat * _Nullable)optFloatIndex:(int32_t)index __attribute__((swift_name("optFloat(index:)")));
- (IPCInt * _Nullable)optIntIndex:(int32_t)index __attribute__((swift_name("optInt(index:)")));
- (IPCJsonArray *)optJsonArrayIndex:(int32_t)index __attribute__((swift_name("optJsonArray(index:)")));
- (IPCJsonObject * _Nullable)optJsonObjectIndex:(int32_t)index __attribute__((swift_name("optJsonObject(index:)")));
- (IPCLong * _Nullable)optLongIndex:(int32_t)index __attribute__((swift_name("optLong(index:)")));
- (id _Nullable)optNumberIndex:(int32_t)index __attribute__((swift_name("optNumber(index:)")));
- (NSString * _Nullable)optStringIndex:(int32_t)index __attribute__((swift_name("optString(index:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonArray.Companion")))
@interface IPCJsonArrayCompanion : IPCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) IPCJsonArrayCompanion *shared __attribute__((swift_name("shared")));
- (IPCJsonArray *)fromJsonJson:(NSString *)json __attribute__((swift_name("fromJson(json:)")));
- (IPCJsonArray *)fromListList:(NSArray<IPCKotlinx_serialization_jsonJsonElement *> *)list __attribute__((swift_name("fromList(list:)")));
- (IPCJsonArray *)fromObjectData:(id _Nullable)data __attribute__((swift_name("fromObject(data:)")));
@end

__attribute__((swift_name("JsonObject")))
@interface IPCJsonObject : IPCJsonElement <IPCIJsonObject>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (class, readonly, getter=companion) IPCJsonObjectCompanion *companion __attribute__((swift_name("companion")));
- (id)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (BOOL)getBooleanName:(NSString *)name __attribute__((swift_name("getBoolean(name:)")));
- (float)getFloatName:(NSString *)name __attribute__((swift_name("getFloat(name:)")));
- (int32_t)getIntName:(NSString *)name __attribute__((swift_name("getInt(name:)")));
- (IPCJsonArray *)getJsonArrayName:(NSString *)name __attribute__((swift_name("getJsonArray(name:)")));
- (IPCJsonObject *)getJsonObjectName:(NSString *)name __attribute__((swift_name("getJsonObject(name:)")));
- (int64_t)getLongName:(NSString *)name __attribute__((swift_name("getLong(name:)")));
- (id)getNumberName:(NSString *)name __attribute__((swift_name("getNumber(name:)")));
- (NSString *)getStringName:(NSString *)name __attribute__((swift_name("getString(name:)")));
- (IPCMutableJsonObject *)mutate __attribute__((swift_name("mutate()")));
- (id _Nullable)optName:(NSString *)name __attribute__((swift_name("opt(name:)")));
- (IPCBoolean * _Nullable)optBooleanName:(NSString *)name __attribute__((swift_name("optBoolean(name:)")));
- (IPCFloat * _Nullable)optFloatName:(NSString *)name __attribute__((swift_name("optFloat(name:)")));
- (IPCInt * _Nullable)optIntName:(NSString *)name __attribute__((swift_name("optInt(name:)")));
- (IPCJsonArray * _Nullable)optJsonArrayName:(NSString *)name __attribute__((swift_name("optJsonArray(name:)")));
- (IPCJsonObject * _Nullable)optJsonObjectName:(NSString *)name __attribute__((swift_name("optJsonObject(name:)")));
- (IPCLong * _Nullable)optLongName:(NSString *)name __attribute__((swift_name("optLong(name:)")));
- (id _Nullable)optNumberName:(NSString *)name __attribute__((swift_name("optNumber(name:)")));
- (NSString * _Nullable)optStringName:(NSString *)name __attribute__((swift_name("optString(name:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSSet<NSString *> *names __attribute__((swift_name("names")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonObject.Companion")))
@interface IPCJsonObjectCompanion : IPCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) IPCJsonObjectCompanion *shared __attribute__((swift_name("shared")));
- (IPCJsonObject *)fromJsonJson:(NSString *)json __attribute__((swift_name("fromJson(json:)")));
- (IPCJsonObject *)fromMapMap:(NSDictionary<NSString *, IPCKotlinx_serialization_jsonJsonElement *> *)map __attribute__((swift_name("fromMap(map:)")));
- (IPCJsonObject *)fromObjectData:(id _Nullable)data __attribute__((swift_name("fromObject(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MutableJsonArray")))
@interface IPCMutableJsonArray : IPCJsonArray <IPCIMutableJsonArray>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)putValue:(IPCJsonArray *)value index:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index:)")));
- (void)putValue:(IPCJsonObject *)value index_:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index_:)")));
- (void)putValue:(id)value index__:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index__:)")));
- (void)putValue:(BOOL)value index___:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index___:)")));
- (void)putValue:(float)value index____:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index____:)")));
- (void)putValue:(int32_t)value index_____:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index_____:)")));
- (void)putValue:(int64_t)value index______:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index______:)")));
- (void)putValue:(id)value index_______:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index_______:)")));
- (void)putValue:(NSString *)value index________:(IPCInt * _Nullable)index __attribute__((swift_name("put(value:index________:)")));
- (void)putNullIndex:(IPCInt * _Nullable)index __attribute__((swift_name("putNull(index:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MutableJsonObject")))
@interface IPCMutableJsonObject : IPCJsonObject <IPCIMutableJsonObject>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)putName:(NSString *)name value:(IPCJsonArray *)value __attribute__((swift_name("put(name:value:)")));
- (void)putName:(NSString *)name value_:(IPCJsonObject *)value __attribute__((swift_name("put(name:value_:)")));
- (void)putName:(NSString *)name value__:(id)value __attribute__((swift_name("put(name:value__:)")));
- (void)putName:(NSString *)name value___:(BOOL)value __attribute__((swift_name("put(name:value___:)")));
- (void)putName:(NSString *)name value____:(float)value __attribute__((swift_name("put(name:value____:)")));
- (void)putName:(NSString *)name value_____:(int32_t)value __attribute__((swift_name("put(name:value_____:)")));
- (void)putName:(NSString *)name value______:(int64_t)value __attribute__((swift_name("put(name:value______:)")));
- (void)putName:(NSString *)name value_______:(id)value __attribute__((swift_name("put(name:value_______:)")));
- (void)putName:(NSString *)name value________:(NSString *)value __attribute__((swift_name("put(name:value________:)")));
- (void)putNullName:(NSString *)name __attribute__((swift_name("putNull(name:)")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol IPCKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonArrayIterator")))
@interface IPCJsonArrayIterator : IPCBase <IPCKotlinIterator>
- (instancetype)initWithJsonArray:(IPCJsonArray *)jsonArray __attribute__((swift_name("init(jsonArray:)"))) __attribute__((objc_designated_initializer));
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Stub")))
@interface IPCStub : IPCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)test __attribute__((swift_name("test()")));
@end

@interface IPCBaseAction (Extensions)
- (void)successData:(id _Nullable)data finish:(BOOL)finish serialize:(BOOL)serialize __attribute__((swift_name("success(data:finish:serialize:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KUtilsKt")))
@interface IPCKUtilsKt : IPCBase
+ (NSArray<IPCKotlinx_serialization_jsonJsonElement *> *)encodeToJsonArrayData:(id _Nullable)data __attribute__((swift_name("encodeToJsonArray(data:)")));
+ (NSDictionary<NSString *, IPCKotlinx_serialization_jsonJsonElement *> *)encodeToJsonObjectData:(id _Nullable)data __attribute__((swift_name("encodeToJsonObject(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonObjectHelpersKt")))
@interface IPCJsonObjectHelpersKt : IPCBase
+ (id)requireIndex:(int32_t)index block:(id _Nullable (^)(IPCInt *))block __attribute__((swift_name("require(index:block:)")));
+ (id)requireName:(NSString *)name block:(id _Nullable (^)(NSString *))block __attribute__((swift_name("require(name:block:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol IPCKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<IPCKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<IPCKotlinCoroutineContextElement> _Nullable)getKey:(id<IPCKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<IPCKotlinCoroutineContext>)minusKeyKey:(id<IPCKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<IPCKotlinCoroutineContext>)plusContext:(id<IPCKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface IPCKotlinArray<T> : IPCBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(IPCInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<IPCKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("AtomicfuSynchronizedObject")))
@interface IPCAtomicfuSynchronizedObject : IPCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)lock __attribute__((swift_name("lock()")));
- (BOOL)tryLock __attribute__((swift_name("tryLock()")));
- (void)unlock __attribute__((swift_name("unlock()")));
@property (readonly, getter=lock_) IPCKotlinAtomicReference<IPCAtomicfuSynchronizedObjectLockState *> *lock __attribute__((swift_name("lock")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonElementSerializer))
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement")))
@interface IPCKotlinx_serialization_jsonJsonElement : IPCBase
@property (class, readonly, getter=companion) IPCKotlinx_serialization_jsonJsonElementCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol IPCKotlinCoroutineContextElement <IPCKotlinCoroutineContext>
@required
@property (readonly) id<IPCKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol IPCKotlinCoroutineContextKey
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AtomicfuSynchronizedObject.LockState")))
@interface IPCAtomicfuSynchronizedObjectLockState : IPCBase
- (instancetype)initWithStatus:(IPCAtomicfuSynchronizedObjectStatus *)status nestedLocks:(int32_t)nestedLocks waiters:(int32_t)waiters ownerThreadId:(void * _Nullable)ownerThreadId mutex:(void * _Nullable)mutex __attribute__((swift_name("init(status:nestedLocks:waiters:ownerThreadId:mutex:)"))) __attribute__((objc_designated_initializer));
@property (readonly) void * _Nullable mutex __attribute__((swift_name("mutex")));
@property (readonly) int32_t nestedLocks __attribute__((swift_name("nestedLocks")));
@property (readonly) void * _Nullable ownerThreadId __attribute__((swift_name("ownerThreadId")));
@property (readonly) IPCAtomicfuSynchronizedObjectStatus *status __attribute__((swift_name("status")));
@property (readonly) int32_t waiters __attribute__((swift_name("waiters")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinAtomicReference")))
@interface IPCKotlinAtomicReference<T> : IPCBase
- (instancetype)initWithValue:(T _Nullable)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (BOOL)compareAndSetExpected:(T _Nullable)expected new:(T _Nullable)new_ __attribute__((swift_name("compareAndSet(expected:new:)")));
- (T _Nullable)compareAndSwapExpected:(T _Nullable)expected new:(T _Nullable)new_ __attribute__((swift_name("compareAndSwap(expected:new:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property T _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement.Companion")))
@interface IPCKotlinx_serialization_jsonJsonElementCompanion : IPCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) IPCKotlinx_serialization_jsonJsonElementCompanion *shared __attribute__((swift_name("shared")));
- (id<IPCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol IPCKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface IPCKotlinEnum<E> : IPCBase <IPCKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) IPCKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AtomicfuSynchronizedObject.Status")))
@interface IPCAtomicfuSynchronizedObjectStatus : IPCKotlinEnum<IPCAtomicfuSynchronizedObjectStatus *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) IPCAtomicfuSynchronizedObjectStatus *unlocked __attribute__((swift_name("unlocked")));
@property (class, readonly) IPCAtomicfuSynchronizedObjectStatus *thin __attribute__((swift_name("thin")));
@property (class, readonly) IPCAtomicfuSynchronizedObjectStatus *fat __attribute__((swift_name("fat")));
+ (IPCKotlinArray<IPCAtomicfuSynchronizedObjectStatus *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol IPCKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<IPCKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<IPCKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol IPCKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<IPCKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<IPCKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol IPCKotlinx_serialization_coreKSerializer <IPCKotlinx_serialization_coreSerializationStrategy, IPCKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface IPCKotlinEnumCompanion : IPCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) IPCKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol IPCKotlinx_serialization_coreEncoder
@required
- (id<IPCKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<IPCKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<IPCKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<IPCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<IPCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) IPCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol IPCKotlinx_serialization_coreSerialDescriptor
@required

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSArray<id<IPCKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<IPCKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSArray<id<IPCKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) IPCKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol IPCKotlinx_serialization_coreDecoder
@required
- (id<IPCKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<IPCKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (IPCKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<IPCKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<IPCKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) IPCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol IPCKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<IPCKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<IPCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<IPCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) IPCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface IPCKotlinx_serialization_coreSerializersModule : IPCBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<IPCKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<IPCKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<IPCKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<IPCKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<IPCKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<IPCKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<IPCKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<IPCKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol IPCKotlinAnnotation
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface IPCKotlinx_serialization_coreSerialKind : IPCBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol IPCKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<IPCKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<IPCKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<IPCKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<IPCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) IPCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface IPCKotlinNothing : IPCBase
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol IPCKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<IPCKotlinKClass>)kClass provider:(id<IPCKotlinx_serialization_coreKSerializer> (^)(NSArray<id<IPCKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<IPCKotlinKClass>)kClass serializer:(id<IPCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<IPCKotlinKClass>)baseClass actualClass:(id<IPCKotlinKClass>)actualClass actualSerializer:(id<IPCKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<IPCKotlinKClass>)baseClass defaultDeserializerProvider:(id<IPCKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)polymorphicDefaultDeserializerBaseClass:(id<IPCKotlinKClass>)baseClass defaultDeserializerProvider:(id<IPCKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)polymorphicDefaultSerializerBaseClass:(id<IPCKotlinKClass>)baseClass defaultSerializerProvider:(id<IPCKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol IPCKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol IPCKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol IPCKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol IPCKotlinKClass <IPCKotlinKDeclarationContainer, IPCKotlinKAnnotatedElement, IPCKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
