//
// Created on 2024/11/14.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_UTILS_H
#define GLTEST_UTILS_H

#include <GLES3/gl3.h>
#include <cstdint>
#include <js_native_api.h>


unsigned int getUint32(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);

    if (type != napi_number)
        return -1;

    int32_t result = 0;
    napi_get_value_int32(env, value, &result);
    return result;
}

int getInt32(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);

    if (type != napi_number)
        return -1;

    int32_t result = 0;
    napi_get_value_int32(env, value, &result);
    return result;
}


GLenum getGLenum(napi_env env, napi_value value) { return getUint32(env, value); }

GLuint getGLuint(napi_env env, napi_value value) { return getUint32(env, value); }

GLfloat getGLfloat(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);

    if (type != napi_number)
        return -1;

    double result = 0;
    napi_get_value_double(env, value, &result);
    return result;
}

GLchar *getGLchar(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);

    if (type != napi_string)
        return nullptr;
    size_t size = 0;
    napi_get_value_string_utf8(env, value, nullptr, size, &size);

    char *str = new char[size + 1];
    napi_get_value_string_utf8(env, value, str, size + 1, &size);

    return str;
}

void getArray(napi_env env, napi_value value, void **array, size_t *size) {
    /*    napi_typedarray_type type;
        size_t byte_offset;
        napi_value input_buffer;*/
    bool result = false;
    napi_is_arraybuffer(env, value, &result);

    if (!result)
        return;
    napi_get_arraybuffer_info(env, value, array, size);
    // napi_get_typedarray_info(env, value, &type, size, array, &input_buffer, &byte_offset);
}


napi_value createNapiInt32(napi_env env, int32_t value) {
    napi_value result = nullptr;
    napi_create_int32(env, value, &result);
    return result;
}

napi_value createNapiFloat(napi_env env, float value) {
    napi_value result = nullptr;
    napi_create_double(env, value, &result);
    return result;
}

void createGLuintArray(napi_env env, napi_value *array_buffer, void **data, size_t len) {
    napi_value buffers = nullptr;
    napi_create_arraybuffer(env, sizeof(GLuint) * len, data, &buffers);
    napi_create_typedarray(env, napi_uint32_array, len, buffers, 0, array_buffer);
}

#endif // GLTEST_UTILS_H