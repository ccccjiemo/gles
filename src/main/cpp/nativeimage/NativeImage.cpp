//
// Created on 2024/12/16.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <cstdio>
#include <native_image/native_image.h>
#include <native_window/external_window.h>
#include "NativeImage.h"
#include "atomic/Atomic.h"
#include "common/utils.h"


namespace NativeImage {

std::unordered_map<OH_NativeImage *, std::atomic_int *> atomic_ints;

void NapiDispose(napi_env env, void *finalize_data, void *finalize_hint) {
    OH_NativeImage *image = (OH_NativeImage *)finalize_data;
    if (image == nullptr)
        return;
    OH_NativeImage_UnsetOnFrameAvailableListener(image);
    OH_NativeImage_Destroy(&image);
    atomic_ints.erase((OH_NativeImage *)image);
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

    OH_OnFrameAvailableListener listener;
    listener.context = flag;
    listener.onFrameAvailable = [](void *context) {
        std::atomic_int *flag = (std::atomic_int *)context;
        (*flag)++;
    };

    int error = OH_NativeImage_SetOnFrameAvailableListener(image, listener);
    if (error != 0)
        napi_throw_error(env, "NativeImage", "Set FrameAvailableListener Failed");

    napi_wrap_sendable(
        env, _this, static_cast<void *>(image),
        [](napi_env env, void *data, void *hint) {
            OH_NativeImage *image = (OH_NativeImage *)data;
            if (image == nullptr)
                return;
            OH_NativeImage_UnsetOnFrameAvailableListener(image);
            OH_NativeImage_Destroy(&image);
            atomic_ints.erase((OH_NativeImage *)image);
            image = nullptr;
        },
        nullptr);

    atomic_ints[image] = flag;
    return _this;
}

napi_value NapiUpdateSurfaceImage(napi_env env, napi_callback_info info) {

    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);

    OH_NativeImage *image = GetNativeImage(env, _this);

    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::UpdateSurfaceImage", "invalid operation");
        return nullptr;
    }

    auto it = atomic_ints.find(image);
    if (it == atomic_ints.end())
        napi_throw_error(env, "NativeImage", "Unknown problem");
    (*(it->second))--;
    int error = OH_NativeImage_UpdateSurfaceImage((OH_NativeImage *)image);
    return createNapiInt32(env, error);
}

napi_value NapiDestroyNativeImage(napi_env env, napi_callback_info info) {
    napi_value _this = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);

    void *image = nullptr;
    napi_remove_wrap_sendable(env, _this, &image);
    atomic_ints.erase((OH_NativeImage *)image);
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

    auto it = atomic_ints.find(image);
    if (it != atomic_ints.end()) {
        int val = it->second->load(std::memory_order_relaxed);
        napi_value result = nullptr;
        napi_create_int32(env, val, &result);
        return result;
    } else {
        napi_throw_error(env, "NativeImage", "Get Available Failed, Atomic_int IS Null");
        return nullptr;
    }
}

OH_NativeImage *GetNativeImage(napi_env env, napi_value value) {
    void *result = nullptr;
    napi_unwrap_sendable(env, value, &result);
    return static_cast<OH_NativeImage *>(result);
}

} // namespace NativeImage
