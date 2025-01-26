//
// Created on 2024/11/14.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_UTILS_H
#define GLTEST_UTILS_H

#include <GLES3/gl32.h>
#include <GLES3/gl3platform.h>
#include <GLES2/gl2ext.h>
#include <cstdint>
#include <js_native_api.h>
#include <map>
#include <napi/native_api.h>

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
    { name, nullptr, func, getter, setter, value, napi_static, nullptr }

#define DEFINE_NAPI_FUNCTION_DEFAULT(name, func, getter, setter, value)                                                        \
    { name, nullptr, func, getter, setter, value, napi_default, nullptr }

#define DEFINE_NAPI_CONSTANTS(name, value)                                                                             \
    { name, nullptr, nullptr, nullptr, nullptr, createNapiInt32(env, value), napi_static, nullptr }

#define DEFINE_NAPI_ENUM(name, value)                                                                                  \
    { name, nullptr, nullptr, nullptr, nullptr, createEnum(env, value), napi_static, nullptr }

#define DEFINE_NAPI_STATIC_VALUE(name, value)                                                                          \
    { name, nullptr, nullptr, nullptr, nullptr, value, napi_static, nullptr }


#define DEFINE_SENDABLE_CLASS(env, exports, name, constructor, desc)                                                   \
    do {                                                                                                               \
        napi_value cons = nullptr;                                                                                     \
        NAPI_CALL(env, napi_define_sendable_class(env, name, NAPI_AUTO_LENGTH, constructor, nullptr,                   \
                                                  sizeof(desc) / sizeof(desc[0]), desc, nullptr, &cons))               \
        NAPI_CALL(env, napi_set_named_property(env, exports, name, cons))                                              \
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
    NAPI_CALL(env, napi_create_arraybuffer(env, sizeof(GLuint) * len, data, &buffers))
    NAPI_CALL(env, napi_create_typedarray(env, napi_uint32_array, len, buffers, 0, array_buffer))
}

static void getBuffer(napi_env env, napi_value value, void **data, size_t *length) {
    bool isTargetBuffer = false;
    NAPI_CALL(env, napi_is_arraybuffer(env, value, &isTargetBuffer))
    if (isTargetBuffer) {
        NAPI_CALL(env, napi_get_arraybuffer_info(env, value, data, length))
        return;
    }
    NAPI_CALL(env, napi_is_typedarray(env, value, &isTargetBuffer))
    if (isTargetBuffer) {
        NAPI_CALL(env, napi_get_typedarray_info(env, value, nullptr, length, data, nullptr, nullptr))
        return;
    }
    *data = nullptr;
    *length = 0;
}

static void transformData(napi_env env, napi_value value, GLenum type, int size) {}

#include <node_api.h>
#include <iostream>
#include <string>
#include <unordered_map>


// 辅助模板函数，将枚举成员添加到对象中
template <typename EnumType> void AddEnumMembersToObject(napi_env env, napi_value obj, const std::string &prefix = "") {
    std::unordered_map<EnumType, std::string> enumMap;
    // 你需要在这里根据具体的枚举类型添加映射，可使用宏或其他方式填充 enumMap
    // 示例：对于一个具体的枚举，你可以添加类似 enumMap[EnumType::VALUE] = "VALUE";


    for (const auto &[value, name] : enumMap) {
        napi_value valueObj;
        napi_status status = napi_create_int32(env, static_cast<int32_t>(value), &valueObj);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Failed to create enum value");
            return;
        }
        std::string fullName = prefix + name;
        status = napi_set_named_property(env, obj, fullName.c_str(), valueObj);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Failed to set enum property");
            return;
        }
    }
}


// 模板函数，用于初始化枚举导出
template <typename EnumType> napi_value InitEnum(napi_env env, napi_value exports, const std::string &name) {
    napi_status status;
    napi_value enumObj;


    status = napi_create_object(env, &enumObj);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to create object");
        return nullptr;
    }


    AddEnumMembersToObject<EnumType>(env, enumObj);


    status = napi_set_named_property(env, exports, name.c_str(), enumObj);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to set named property");
        return nullptr;
    }


    return exports;
}

template <typename... Args> constexpr std::size_t args_length(Args... args) { return sizeof...(args); }

// typedef struct {
//   // One of utf8name or name should be NULL.
//   const char* utf8name;
//   napi_value name;
//
//   napi_callback method;
//   napi_callback getter;
//   napi_callback setter;
//   napi_value value;
//
//   napi_property_attributes attributes;
//   void* data;
// } napi_property_descriptor;

#define getString(value) #value

static napi_value createEnum(napi_env env, std::map<std::string, long> enums) {
    napi_value result = nullptr;
    NAPI_CALL(env, napi_create_object(env, &result))
    for (auto it = enums.begin(); it != enums.end(); it++) {
        napi_value enumName = nullptr;
        napi_value enumValue = nullptr;
        NAPI_CALL(env, napi_create_string_utf8(env, it->first.c_str(), NAPI_AUTO_LENGTH, &enumName))
        NAPI_CALL(env, napi_create_int64(env, it->second, &enumValue))
        NAPI_CALL(env, napi_set_named_property(env, result, it->first.c_str(), enumValue))
        NAPI_CALL(env, napi_set_named_property(env, result, std::to_string(it->second).c_str(), enumName))
    }
    return result;
}


#endif // GLTEST_UTILS_H
