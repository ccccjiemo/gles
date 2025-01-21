//
// Created on 2024/12/23.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "GLESExtends.h"
#include "utils.h"
#include <GLES3/gl3.h>

namespace GLESExtends {
// extend
napi_value NapiCreateShaderWidthSource(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum type = getGLenum(env, argv[0]);
    size_t source_size = 0;
    napi_get_value_string_utf8(env, argv[1], nullptr, 0, &source_size);
    GLchar *source = new char[source_size + 1]{'\0'};
    napi_get_value_string_utf8(env, argv[1], source, source_size + 1, &source_size);

    GLuint shader = glCreateShader(type);
    GLint length = source_size;
    glShaderSource(shader, 1, &source, &length);
    glCompileShader(shader);
    GLint info_length = 0;
    GLint compile_status = 1;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_length);
    char *info_log = new char[info_length + 1]{'\0'};
    glGetShaderInfoLog(shader, info_length + 1, &info_length, info_log);

    napi_value napi_info_log = nullptr;
    napi_value napi_shader_handle = nullptr;
    napi_value napi_shader_compile_status = nullptr;
    napi_value result = nullptr;
    napi_create_string_utf8(env, info_log, info_length, &napi_info_log);
    napi_create_int32(env, shader, &napi_shader_handle);
    napi_create_int32(env, compile_status, &napi_shader_compile_status);
    napi_create_object(env, &result);
    napi_set_named_property(env, result, "handle", napi_shader_handle);
    napi_set_named_property(env, result, "status", napi_shader_compile_status);
    napi_set_named_property(env, result, "log", napi_info_log);
    delete[] source;
    delete[] info_log;
    return result;
}

napi_value NapiGLTexParameteriGroup(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint texture = getGLuint(env, argv[0]);
    GLenum target = getGLenum(env, argv[1]);
    uint32_t len = 0;
    napi_get_array_length(env, argv[2], &len);
    napi_value data = nullptr;
    GLenum pname = 0;
    GLint param = 0;
    napi_value napi_pname = nullptr;
    napi_value napi_param = nullptr;
    glBindTexture(target, texture);
    for (int i = 0; i < len; i++) {
        napi_get_element(env, argv[2], i, &data);
        napi_get_named_property(env, data, "pname", &napi_pname);
        napi_get_named_property(env, data, "param", &napi_param);
        pname = getGLenum(env, napi_pname);
        napi_get_value_int32(env, napi_param, &param);
        glTexParameteri(target, pname, param);
    }
    return nullptr;
}
}