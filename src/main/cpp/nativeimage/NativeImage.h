//
// Created on 2024/12/16.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_NATIVEIMAGE_H
#define GLTEST_NATIVEIMAGE_H

#include <napi/native_api.h>
#include <native_image/native_image.h>
#include <unordered_map>

namespace NativeImage {
// napi_value NapiConstructor(napi_env env, napi_callback_info info);
void NapiDispose(napi_env env, void *finalize_data, void *finalize_hint);
napi_value NapiAttachContext(napi_env env, napi_callback_info info);
napi_value NapiDetachContext(napi_env env, napi_callback_info info);
napi_value NapiUpdateSurfaceImage(napi_env env, napi_callback_info info);
napi_value NapiBindNativeImage(napi_env env, napi_callback_info info);
napi_value NapiDestroyNativeImage(napi_env env, napi_callback_info info);
napi_value NapiGetSurfaceId(napi_env env, napi_callback_info info);
napi_value NapiGetIsAvailable(napi_env env, napi_callback_info info);
OH_NativeImage* GetNativeImage(napi_env env, napi_value value);
} // namespace NativeImage

#endif // GLTEST_NATIVEIMAGE_H
