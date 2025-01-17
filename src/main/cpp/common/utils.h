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

#define NAPI_CALL(env, func)                                                                                           \
    if (napi_ok != func) {                                                                                             \
        napi_throw_error(env, "NAPI_CALL", #func);                                                                     \
    }

#define GET_NAPI_INFO(env, info, argc, argc_v, argv, that, data)                                                       \
    size_t argc = argc_v;                                                                                              \
    napi_value argv[argc_v];                                                                                           \
    napi_value that = nullptr;                                                                                         \
    void *data = nullptr;                                                                                              \
    NAPI_CALL(env, napi_get_cb_info(env, info, &argc, argv, &that, &data))

#define DEFINE_NAPI_FUNCTION(name, func, getter, setter, value)                                                        \
    { name, nullptr, func, getter, setter, value, napi_default, nullptr }

#define DEFINE_SENDABLE_CLASS(env, exports, className, constructor, property)                                          \
    do {                                                                                                               \
        napi_value cons = nullptr;                                                                                     \
        napi_define_sendable_class(env, className, NAPI_AUTO_LENGTH, constructor, nullptr,                             \
                                   sizeof(property) / sizeof(property[0]), property, nullptr, &cons);                  \
        napi_set_named_property(env, exports, className, cons);                                                        \
    } while (0);


static bool type_equal(napi_env env, napi_value value, napi_valuetype type) {
    napi_valuetype t;
    NAPI_CALL(env, napi_typeof(env, value, &t))
    return t == type;
}

static unsigned int getUint32(napi_env env, napi_value value) {
    if (type_equal(env, value, napi_number)) {
        unsigned int result = 0;
        napi_get_value_uint32(env, value, &result);
        return result;
    }
    return -1;
}

static int getInt32(napi_env env, napi_value value) {
    napi_valuetype type;
    napi_typeof(env, value, &type);

    if (type != napi_number)
        return -1;

    int32_t result = 0;
    napi_get_value_int32(env, value, &result);
    return result;

    if (type_equal(env, value, napi_number)) {
        int result = 0;
        napi_get_value_int32(env, value, &result);
        return result;
    }
    return -1;
}

static GLenum getGLenum(napi_env env, napi_value value) { return getUint32(env, value); }

static GLuint getGLuint(napi_env env, napi_value value) { return getUint32(env, value); }

static GLfloat getGLfloat(napi_env env, napi_value value) {
    if (type_equal(env, value, napi_number)) {
        double result = 0;
        napi_get_value_double(env, value, &result);
        return result;
    }

    return 0;
}

static GLchar *getGLchar(napi_env env, napi_value value) {
    if (type_equal(env, value, napi_string)) {
        size_t size = 0;
        NAPI_CALL(env, napi_get_value_string_utf8(env, value, nullptr, size, &size))

        char *str = new char[size + 1]{'\0'};
        NAPI_CALL(env, napi_get_value_string_utf8(env, value, str, size + 1, &size))

        return str;
    }
    return nullptr;
}

static GLintptr getGLintptr(napi_env env, napi_value value) {
    long result = 0;
    if (type_equal(env, value, napi_number)) {
        NAPI_CALL(env, napi_get_value_int64(env, value, &result))
    }
    return result;
}

static GLsizeiptr getGLsizeiptr(napi_env env, napi_value value) { return getGLintptr(env, value); }
static GLbitfield getGLbitfield(napi_env env, napi_value value) { return getUint32(env, value); }


static void getArray(napi_env env, napi_value value, void **array, size_t *size) {

    bool result = false;
    NAPI_CALL(env, napi_is_typedarray(env, value, &result))

    if (result) {
        NAPI_CALL(env, napi_get_typedarray_info(env, value, nullptr, size, array, nullptr, nullptr))
        return;
    }

    NAPI_CALL(env, napi_is_arraybuffer(env, value, &result))

    if (result) {
        NAPI_CALL(env, napi_get_arraybuffer_info(env, value, array, size))
        return;
    }

    array = nullptr;
    size = 0;
}


static napi_value createNapiInt32(napi_env env, int32_t value) {
    napi_value result = nullptr;
    NAPI_CALL(env, napi_create_int32(env, value, &result))
    return result;
}

static napi_value createNapiFloat(napi_env env, float value) {
    napi_value result = nullptr;
    napi_create_double(env, value, &result);
    return result;
}

static void createGLuintArray(napi_env env, napi_value *array_buffer, void **data, size_t len) {
    napi_value buffers = nullptr;
    napi_create_arraybuffer(env, sizeof(GLuint) * len, data, &buffers);
    napi_create_typedarray(env, napi_uint32_array, len, buffers, 0, array_buffer);
}

static void transformData(napi_env env, napi_value value, GLenum type, int size) {}

#endif // GLTEST_UTILS_H
