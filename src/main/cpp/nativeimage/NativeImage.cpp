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
#include "common/utils.h"


namespace NativeImage {


// napi_value NapiConstructor(napi_env env, napi_callback_info info) {
//     size_t argc = 1;
//     napi_value argv[1] = {nullptr};
//     napi_value _this = nullptr;
//     napi_get_cb_info(env, info, &argc, argv, &_this, nullptr);
//     uint32_t textureId = 0;
//     if (argc == 1) {
//         napi_get_value_uint32(env, argv[0], &textureId);
//     }
//
//     OH_NativeImage *image = OH_NativeImage_Create(textureId, GL_TEXTURE_EXTERNAL_OES);
//
//     OH_OnFrameAvailableListener listener;
//     listener.context = image;
//     listener.onFrameAvailable = [](void *context) {
//         OH_NativeImage *image;
//         OH_NativeImage_UpdateSurfaceImage(image);
//     };
// //     OH_NativeImage_SetOnFrameAvailableListener(image, OH_OnFrameAvailableListener listener)
//
//     napi_wrap(env, _this, image, NapiDispose, nullptr, nullptr);
//
//     return _this;
// }

void NapiDispose(napi_env env, void *finalize_data, void *finalize_hint) {
    OH_NativeImage *image = (OH_NativeImage *)finalize_data;
    if (image == nullptr)
        return;
    OH_NativeImage_UnsetOnFrameAvailableListener(image);
    OH_NativeImage_Destroy(&image);
    image = nullptr;
}


napi_value NapiAttachContext(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    uint32_t textureId = 0;
    void *image = nullptr;
    napi_unwrap(env, argv[0], &image);
    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::AttachContext", "invalid operation");
        return nullptr;
    }
    napi_get_value_uint32(env, argv[1], &textureId);
    int32_t error = OH_NativeImage_AttachContext((OH_NativeImage *)image, textureId);
    return createNapiInt32(env, error);
}
napi_value NapiDetachContext(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    void *image = nullptr;
    napi_unwrap(env, argv[0], &image);
    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::DetachContext", "invalid operation");
        return nullptr;
    }
    int32_t error = OH_NativeImage_DetachContext((OH_NativeImage *)image);
    napi_value result = nullptr;
    napi_create_int32(env, error, &result);
    return result;
}

napi_value NapiBindNativeImage(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint texture = 0;
    napi_get_value_uint32(env, argv[1], &texture);

    void *array = nullptr;
    size_t size = 0;
    getArray(env, argv[2], &array, &size);

    OH_NativeImage *image = OH_NativeImage_Create(texture, GL_TEXTURE_EXTERNAL_OES);

//     OH_NativeImage *image = OH_ConsumerSurface_Create();
    OH_OnFrameAvailableListener listener;
    listener.context = array;
    listener.onFrameAvailable = [](void *context) {
        unsigned char *arr = (unsigned char *)context;
        arr[0] = 1;
    };

    int error = OH_NativeImage_SetOnFrameAvailableListener(image, listener);
    if (error != 0)
        return nullptr;

    napi_wrap(env, argv[0], image, NapiDispose, nullptr, nullptr);
    uint64_t surfaceId = 0;
    error = OH_NativeImage_GetSurfaceId((OH_NativeImage *)image, &surfaceId);
    if (error != 0)
        return nullptr;

    char surfaceId_str[36] = {'\0'};
    sprintf(surfaceId_str, "%lu", surfaceId);
    napi_value result = nullptr;
    napi_create_string_utf8(env, surfaceId_str, NAPI_AUTO_LENGTH, &result);
    return result;
}

napi_value NapiUpdateSurfaceImage(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *image = nullptr;
    napi_unwrap(env, argv[0], &image);

    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::UpdateSurfaceImage", "invalid operation");
        return nullptr;
    }


    int error = OH_NativeImage_UpdateSurfaceImage((OH_NativeImage *)image);
    float matrix[16] = {0};
    OH_NativeImage_GetTransformMatrix((OH_NativeImage *)image, matrix);
    return createNapiInt32(env, error);
}

napi_value NapiDestroyNativeImage(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *image = nullptr;
    napi_remove_wrap(env, argv[0], &image);


    if (image == nullptr) {
        napi_throw_error(env, "NativeImage::DestroyNativeImage", "invalid operation");
        return nullptr;
    }

    auto img = (OH_NativeImage *)image;
    OH_NativeImage_UnsetOnFrameAvailableListener(img);
    OH_NativeImage_Destroy(&img);
    image = nullptr;

    return nullptr;
}
} // namespace NativeImage
