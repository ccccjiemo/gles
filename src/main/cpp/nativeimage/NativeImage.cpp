//
// Created on 2024/12/16.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <cstdio>
#include <native_image/native_image.h>
#include "NativeImage.h"
#include "common/utils.h"
#include <hilog/log.h>


namespace NativeImage {

std::unordered_map<OH_NativeImage *, napi_threadsafe_function> sf_cache;

void NapiDispose(napi_env env, void *finalize_data, void *finalize_hint) {
    OH_NativeImage *image = static_cast<OH_NativeImage *>(finalize_data);
    if (image == nullptr)
        return;

    OH_NativeImage_UnsetOnFrameAvailableListener(image);
    OH_NativeImage_Destroy(&image);
    DestroyThreadSafeFunction(env, image);
    image = nullptr;
}


napi_value NapiAttachContext(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
    uint32_t textureId = 0;
    OH_NativeImage *image = GetNativeImage(env, _this);
    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::AttachContext", "invalid operation");
        return nullptr;
    }
    napi_get_value_uint32(env, argv[0], &textureId);
    int32_t error = OH_NativeImage_AttachContext(image, textureId);
    return createNapiInt32(env, error);
}

napi_value NapiDetachContext(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    OH_NativeImage *image = GetNativeImage(env, _this);
    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::DetachContext", "invalid operation");
        return nullptr;
    }
    int32_t error = OH_NativeImage_DetachContext(image);
    napi_value result = nullptr;
    napi_create_int32(env, error, &result);
    return result;
}

napi_value NapiBindNativeImage(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);

    GLuint texture = -1;
    if (argc != 0) {
        napi_get_value_uint32(env, argv[0], &texture);
    }

    std::atomic_int *flag = new std::atomic_int(0);

    OH_NativeImage *image = OH_NativeImage_Create(texture, GL_TEXTURE_EXTERNAL_OES);

    if (image == nullptr)
        napi_throw_error(env, "NativeImage", "Create NativeImage Failed");

    napi_wrap_sendable(env, _this, static_cast<void *>(image), NapiDispose, nullptr);

    return _this;
}

napi_value NapiUpdateSurfaceImage(napi_env env, napi_callback_info info) {

    auto id = std::this_thread::get_id();
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);

    OH_NativeImage *image = GetNativeImage(env, _this);

    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::UpdateSurfaceImage", "invalid operation");
        return nullptr;
    }
    
    int error = OH_NativeImage_UpdateSurfaceImage((OH_NativeImage *)image);
    return createNapiInt32(env, error);
}

napi_value NapiDestroyNativeImage(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);

    void *image = nullptr;
    napi_remove_wrap_sendable(env, _this, &image);

    return nullptr;
}

napi_value NapiGetSurfaceId(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    OH_NativeImage *image = GetNativeImage(env, _this);
    if (image == nullptr)
        napi_throw_error(env, "NativeImage", "Get SurfaceId Failed, NativeImage IS Null");

    uint64_t surfaceId = 0;
    OH_NativeImage_GetSurfaceId(image, &surfaceId);
    char surfaceId_str[36] = {'\0'};
    sprintf(surfaceId_str, "%lu", surfaceId);
    napi_value result = nullptr;
    napi_create_string_utf8(env, surfaceId_str, NAPI_AUTO_LENGTH, &result);
    return result;
}
napi_value NapiGetIsAvailable(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    OH_NativeImage *image = GetNativeImage(env, _this);
    if (image == nullptr)
        napi_throw_error(env, "NativeImage", "Get Available Failed, NativeImage IS Null");


}

OH_NativeImage *GetNativeImage(napi_env env, napi_value value) {
    void *result = nullptr;
    napi_unwrap_sendable(env, value, &result);
    return static_cast<OH_NativeImage *>(result);
}

napi_value NapiSetOnFrameAvailableListener(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);

    if (argc != 1)
        napi_throw_error(env, "NativeImage", "SetOnFrameAvailableListener must got 1 argument");

    OH_NativeImage *image = GetNativeImage(env, _this);
    if (image == nullptr) {
        napi_throw_error(env, "NativeImage", "SetOnFrameAvailableListener Failed, NativeImage IS Null");
        return nullptr;
    }

    napi_valuetype type;
    napi_typeof(env, argv[0], &type);

    if (type != napi_function) {
        napi_throw_error(env, "NativeImage", "SetOnFrameAvailableListener: arg 0 not a function");
        return nullptr;
    }

//     FrameListener *onFrame = new FrameListener();

    napi_threadsafe_function sf = nullptr;
    napi_value resourceName = nullptr;
    napi_create_string_utf8(env, "onFrameCallback", NAPI_AUTO_LENGTH, &resourceName);
    napi_create_threadsafe_function(env, argv[0], nullptr, resourceName, 0, 1, nullptr, nullptr, nullptr, RaiseFrameAvailable, &sf);


    OH_OnFrameAvailableListener listener;
    listener.context = sf;
    listener.onFrameAvailable = [](void *context) {
        napi_threadsafe_function func = static_cast<napi_threadsafe_function>(context);
        napi_acquire_threadsafe_function(func);
        napi_call_threadsafe_function(func, nullptr, napi_tsfn_nonblocking);
    };
    auto result = OH_NativeImage_SetOnFrameAvailableListener(image, listener);
    sf_cache[image] = sf;
    return createNapiInt32(env, result);
}

napi_value NapiUnSetOnFrameAvailableListener(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);
    OH_NativeImage *image = GetNativeImage(env, _this);
    if (image == nullptr) {
        napi_throw_error(env, "NativeImage", "UnSetOnFrameAvailableListener: NativeImage IS Null");
        return nullptr;
    }

    auto result = OH_NativeImage_UnsetOnFrameAvailableListener(image);
    DestroyThreadSafeFunction(env, image);
    return createNapiInt32(env, result);
}

void RaiseFrameAvailable(napi_env env, napi_value js_callback, void *context, void *data) {
    napi_call_function(env, nullptr, js_callback, 0, nullptr, nullptr);
}

void DestroyThreadSafeFunction(napi_env env, OH_NativeImage *image) {
    auto it = sf_cache.find(image);
    if (it != sf_cache.end()) {
        napi_release_threadsafe_function(it->second, napi_tsfn_release);
        sf_cache.erase(it);
    }
}

} // namespace NativeImage
