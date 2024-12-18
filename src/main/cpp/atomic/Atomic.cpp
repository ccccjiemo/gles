//
// Created on 2024/12/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "Atomic.h"
#include "common/utils.h"

namespace Atomic {
napi_value NapiCreateAtomicBool(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    bool init = false;
    napi_get_value_bool(env, argv[1], &init);
    std::atomic_bool *flag = new std::atomic_bool(init);

    napi_wrap(
        env, argv[0], flag,
        [](napi_env env, void *data, void *init) {
            std::atomic_bool *flag = (std::atomic_bool *)data;
            delete flag;
            flag = nullptr;
        },
        nullptr, nullptr);
    return nullptr;
}

napi_value NapiSetBoolValue(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    void *t = nullptr;
    napi_unwrap(env, argv[0], &t);
    std::atomic_bool *flag = (std::atomic_bool *)t;
    bool value = false;
    napi_get_value_bool(env, argv[1], &value);
    flag->store(value);
    return nullptr;
}

napi_value NapiGetBoolValue(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    void *t = nullptr;
    napi_unwrap(env, argv[0], &t);
    std::atomic_bool *flag = (std::atomic_bool *)t;
    bool result = flag->load();
    return createNapiInt32(env, result);
}

std::atomic_bool *GetAtomicBool(napi_env env, napi_value value) {
    void *result = nullptr;
    napi_unwrap(env, value, &result);
    return (std::atomic_bool *)result;
}

napi_value NapiCreateAtomicInt(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    bool init = false;
    napi_get_value_bool(env, argv[1], &init);
    std::atomic_int *at_int = new std::atomic_int(init);

    napi_wrap(
        env, argv[0], at_int,
        [](napi_env env, void *data, void *init) {
            std::atomic_int *flag = (std::atomic_int *)data;
            delete flag;
            flag = nullptr;
        },
        nullptr, nullptr);
    return nullptr;
}

napi_value NapiAtomicIntSub(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    void *t = nullptr;
    napi_unwrap(env, argv[0], &t);
    std::atomic_int *flag = (std::atomic_int *)t;
    int value = 0;
    napi_get_value_int32(env, argv[1], &value);
    flag->fetch_sub(value);
    return nullptr;
}


napi_value NapiGetIntValue(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    void *t = nullptr;
    napi_unwrap(env, argv[0], &t);
    std::atomic_int *flag = (std::atomic_int *)t;
    int result = flag->load();
    return createNapiInt32(env, result);
}
std::atomic_int *GetAtomicInt(napi_env env, napi_value value) {
    void *result = nullptr;
    napi_unwrap(env, value, &result);
    return (std::atomic_int *)result;
}
} // namespace Atomic
