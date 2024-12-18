//
// Created on 2024/12/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef CCC_ATOMIC_H
#define CCC_ATOMIC_H
#include <napi/native_api.h>
#include <atomic>

namespace Atomic {
napi_value NapiCreateAtomicBool(napi_env env, napi_callback_info info);
napi_value NapiSetBoolValue(napi_env env, napi_callback_info info);
napi_value NapiGetBoolValue(napi_env env, napi_callback_info info);
std::atomic_bool* GetAtomicBool(napi_env env, napi_value value);

napi_value NapiCreateAtomicInt(napi_env env, napi_callback_info info);
napi_value NapiGetIntValue(napi_env env, napi_callback_info info);
napi_value NapiAtomicIntSub(napi_env env, napi_callback_info info);
std::atomic_int* GetAtomicInt(napi_env env, napi_value value);
} // namespace Atomic
#endif // CCC_ATOMIC_H
