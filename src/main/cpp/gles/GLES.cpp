//
// Created on 2024/11/14.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "GLES.h"
#include "common/utils.h"
#include <GLES3/gl32.h>
#include <GLES2/gl2ext.h>
#include <napi/native_api.h>

namespace GLES {

napi_value NapiGLActiveShaderProgram(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint pipeline = getGLuint(env, argv[0]);
    GLuint program = getGLuint(env, argv[1]);

    glActiveShaderProgram(pipeline, program);
    return nullptr;
}

napi_value NapiGLActiveTexture(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum texture = getGLenum(env, argv[0]);
    glActiveTexture(texture);
    return nullptr;
}

napi_value NapiGLAttachShader(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);

    if (argc == 1)
        return nullptr;

    napi_value *argv = new napi_value[argc];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);

    for (int i = 1; i < argc; i++) {
        GLuint shader = getGLuint(env, argv[i]);
        glAttachShader(program, shader);
    }

    return nullptr;
}

napi_value NapiGLBindAttribLocation(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    GLuint index = getGLuint(env, argv[1]);
    GLchar *name = getGLchar(env, argv[2]);

    glBindAttribLocation(program, index, name);
    delete[] name;
    return nullptr;
}

napi_value NapiGLBindBuffer(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLuint buffer = getGLuint(env, argv[1]);

    glBindBuffer(target, buffer);
    return nullptr;
}

napi_value NapiGLBindVertexArray(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint array = getGLuint(env, argv[0]);
    glBindVertexArray(array);
    return nullptr;
}

napi_value NapiGLBindVertexBuffer(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint bindingindex = getGLuint(env, argv[0]);
    GLuint buffer = getGLuint(env, argv[1]);
    GLintptr offset = 0;
    napi_get_value_int64(env, argv[2], &offset);
    GLsizei stride = getInt32(env, argv[3]);
    glBindVertexBuffer(bindingindex, buffer, offset, stride);
    return nullptr;
}


napi_value NapiGLBindFramebuffer(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLuint framebuffer = getGLuint(env, argv[1]);

    glBindFramebuffer(target, framebuffer);
    return nullptr;
}

napi_value NapiGLBindRenderbuffer(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLuint renderbuffer = getGLuint(env, argv[1]);

    glBindRenderbuffer(target, renderbuffer);
    return nullptr;
}

napi_value NapiGLBindTexture(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLuint texture = getGLuint(env, argv[1]);

    glBindTexture(target, texture);
    return nullptr;
}

napi_value NapiGLBlendColor(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLfloat red = getGLfloat(env, argv[0]);
    GLfloat green = getGLfloat(env, argv[1]);
    GLfloat blue = getGLfloat(env, argv[2]);
    GLfloat alpha = getGLfloat(env, argv[3]);

    glBlendColor(red, green, blue, alpha);
    return nullptr;
}

napi_value NapiGLBlendEquation(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum mode = getGLenum(env, argv[0]);

    glBlendEquation(mode);
    return nullptr;
}

napi_value NapiGLBlendEquationi(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint buffer = getGLuint(env, argv[0]);
    GLenum mode = getGLenum(env, argv[1]);

    glBlendEquationi(buffer, mode);
    return nullptr;
}

napi_value NapiGLBlendEquationSeparate(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum modeRGB = getGLenum(env, argv[0]);
    GLenum modeAlpha = getGLenum(env, argv[1]);

    glBlendEquationSeparate(modeRGB, modeAlpha);
    return nullptr;
}

napi_value NapiGLBlendFunc(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum sfactor = getGLenum(env, argv[0]);
    GLenum dfactor = getGLenum(env, argv[1]);

    glBlendFunc(sfactor, dfactor);
    return nullptr;
}

napi_value NapiGLBlendFuncSeparate(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum sfactorRGB = getGLenum(env, argv[0]);
    GLenum dfactorRGB = getGLenum(env, argv[1]);
    GLenum sfactorAlpha = getGLenum(env, argv[2]);
    GLenum dfactorAlpha = getGLenum(env, argv[3]);

    glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    return nullptr;
}

napi_value NapiGLBlendFuncSeparatei(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint buf = getGLuint(env, argv[0]);
    GLenum sfactorRGB = getGLenum(env, argv[1]);
    GLenum dfactorRGB = getGLenum(env, argv[2]);
    GLenum sfactorAlpha = getGLenum(env, argv[3]);
    GLenum dfactorAlpha = getGLenum(env, argv[4]);

    glBlendFuncSeparatei(buf, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    return nullptr;
}


napi_value NapiGLBufferData(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum target = getGLenum(env, argv[0]);
    size_t size = 0;
    void *data = nullptr;
    getArray(env, argv[1], &data, &size);
    GLenum usage = getGLenum(env, argv[2]);

    glBufferData(target, size, data, usage);
    return nullptr;
}

napi_value NapiGLBufferSubData(napi_env env, napi_callback_info info) {

    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLintptr offset = 0;
    napi_get_value_int64(env, argv[1], &offset);
    size_t size;
    void *data;
    getArray(env, argv[2], &data, &size);

    glBufferSubData(target, offset, size, data);
    return nullptr;
}

napi_value NapiGLCheckFramebufferStatus(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);

    GLenum status = glCheckFramebufferStatus(target);
    return createNapiInt32(env, status);
}

napi_value NapiGLClear(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLbitfield mask = getUint32(env, argv[0]);
    glClear(mask);

    return nullptr;
}

napi_value NapiGLClearColor(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLfloat red = getGLfloat(env, argv[0]);
    GLfloat green = getGLfloat(env, argv[1]);
    GLfloat blue = getGLfloat(env, argv[2]);
    GLfloat alpha = getGLfloat(env, argv[3]);

    glClearColor(red, green, blue, alpha);
    return nullptr;
}

napi_value NapiGLClearDepthf(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLfloat d = getGLfloat(env, argv[0]);
    glClearDepthf(d);
    return nullptr;
}

napi_value NapiGLClearStencil(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint s = getInt32(env, argv[0]);
    glClearStencil(s);
    return nullptr;
}

napi_value NapiGLColorMask(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLboolean red = getInt32(env, argv[0]);
    GLboolean green = getInt32(env, argv[1]);
    GLboolean blue = getInt32(env, argv[2]);
    GLboolean alpha = getInt32(env, argv[3]);
    glColorMask(red, green, blue, alpha);
    return nullptr;
}

napi_value NapiGLCompileShader(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint shader = getUint32(env, argv[0]);
    glCompileShader(shader);
    return nullptr;
}

napi_value NapiGLCompressedTexImage2D(napi_env env, napi_callback_info info) {
    size_t argc = 7;
    napi_value argv[7];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getUint32(env, argv[0]);
    GLint level = getInt32(env, argv[1]);
    GLenum internalformat = getUint32(env, argv[2]);
    GLsizei width = getInt32(env, argv[3]);
    GLsizei height = getInt32(env, argv[4]);
    GLint border = getInt32(env, argv[5]);
    size_t imageSize;
    void *data;
    getArray(env, argv[6], &data, &imageSize);

    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
    return nullptr;
}

napi_value NapiGLCompressedTexSubImage2D(napi_env env, napi_callback_info info) {
    size_t argc = 8;
    napi_value argv[8];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getUint32(env, argv[0]);
    GLint level = getInt32(env, argv[1]);
    GLint xoffset = getInt32(env, argv[2]);
    GLint yoffset = getInt32(env, argv[3]);
    GLsizei width = getInt32(env, argv[4]);
    GLsizei height = getInt32(env, argv[5]);
    GLenum format = getUint32(env, argv[6]);
    size_t imageSize;
    void *data;
    getArray(env, argv[7], &data, &imageSize);
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);

    return nullptr;
}

napi_value NapiGLCopyTexImage2D(napi_env env, napi_callback_info info) {
    size_t argc = 8;
    napi_value argv[8];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLint level = getInt32(env, argv[1]);
    GLenum internalformat = getGLenum(env, argv[2]);
    GLint x = getInt32(env, argv[3]);
    GLint y = getInt32(env, argv[4]);
    GLsizei width = getInt32(env, argv[5]);
    GLsizei height = getInt32(env, argv[6]);
    GLint border = getInt32(env, argv[7]);
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);

    return nullptr;
}

napi_value NapiGLCopyTexSubImage2D(napi_env env, napi_callback_info info) {
    size_t argc = 8;
    napi_value argv[8];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLint level = getInt32(env, argv[1]);
    GLint xoffset = getInt32(env, argv[2]);
    GLint yoffset = getInt32(env, argv[3]);
    GLint x = getInt32(env, argv[4]);
    GLint y = getInt32(env, argv[5]);
    GLsizei width = getInt32(env, argv[6]);
    GLsizei height = getInt32(env, argv[7]);
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    return nullptr;
}

napi_value NapiGLCreateProgram(napi_env env, napi_callback_info info) {
    GLuint program = glCreateProgram();
    return createNapiInt32(env, program);
}

napi_value NapiGLCreateShader(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum type = getGLenum(env, argv[0]);
    GLuint shader = glCreateShader(type);

    return createNapiInt32(env, shader);
}

napi_value NapiGLCullFace(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum mode = getGLenum(env, argv[0]);
    glCullFace(mode);

    return nullptr;
}

napi_value NapiGLDeleteBuffers(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *data = nullptr;
    size_t size = 0;
    getArray(env, argv[0], &data, &size);
    glDeleteBuffers(size / sizeof(GLuint), (GLuint *)data);

    return nullptr;
}

napi_value NapiGLDeleteVertexArrays(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];

    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *data = nullptr;
    size_t size = 0;
    getArray(env, argv[0], &data, &size);
    glDeleteVertexArrays(size / sizeof(GLuint), (GLuint *)data);

    return nullptr;
}

napi_value NapiGLDeleteFramebuffers(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *data = nullptr;
    size_t size = 0;
    getArray(env, argv[0], &data, &size);
    glDeleteFramebuffers(size / sizeof(GLuint), (GLuint *)data);

    return nullptr;
}

napi_value NapiGLDeleteProgram(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getUint32(env, argv[0]);
    glDeleteProgram(program);

    return nullptr;
}

napi_value NapiGLDeleteRenderbuffers(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *data = nullptr;
    size_t size = 0;
    getArray(env, argv[0], &data, &size);
    glDeleteRenderbuffers(size / sizeof(GLuint), (GLuint *)data);

    return nullptr;
}

napi_value NapiGLDeleteShader(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint shader = getUint32(env, argv[0]);
    glDeleteShader(shader);
    return nullptr;
}

napi_value NapiGLDeleteTextures(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    void *data = nullptr;
    size_t size = 0;
    getArray(env, argv[0], &data, &size);
    glDeleteTextures(size / sizeof(GLuint), (GLuint *)data);
    return nullptr;
}

napi_value NapiGLDepthFunc(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint func = getUint32(env, argv[0]);
    glDepthFunc(func);
    return nullptr;
}

napi_value NapiGLDepthMask(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLboolean flag = getInt32(env, argv[0]);
    glDepthMask(flag);

    return nullptr;
}

napi_value NapiGLDepthRangef(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLfloat n = getGLfloat(env, argv[0]);
    GLfloat f = getGLfloat(env, argv[1]);
    glDepthRangef(n, f);

    return nullptr;
}

napi_value NapiGLDetachShader(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    GLuint shader = getGLuint(env, argv[1]);

    glDetachShader(program, shader);

    return nullptr;
}

napi_value NapiGLDisable(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum cap = getGLenum(env, argv[0]);
    glDisable(cap);
    return nullptr;
}

napi_value NapiGLDisableVertexAttribArray(napi_env env, napi_callback_info info) {

    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint index = getGLuint(env, argv[0]);
    glDisableVertexAttribArray(index);
    return nullptr;
}

napi_value NapiGLDrawArrays(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum mode = getGLenum(env, argv[0]);
    GLint first = getInt32(env, argv[1]);
    GLsizei count = getInt32(env, argv[2]);
    glDrawArrays(mode, first, count);
    return nullptr;
}

napi_value NapiGLDrawElements(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum mode = getGLenum(env, argv[0]);
    GLsizei count = getInt32(env, argv[1]);
    GLenum type = getGLenum(env, argv[2]);
    void *data = nullptr;
    size_t size = 0;

    getArray(env, argv[3], &data, &size);

    glDrawElements(mode, count, type, data);
    return nullptr;
}

napi_value NapiGLEnable(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum cap = getGLenum(env, argv[0]);
    glEnable(cap);
    return nullptr;
}

napi_value NapiGLEnableVertexAttribArray(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint index = getUint32(env, argv[0]);
    glEnableVertexAttribArray(index);
    return nullptr;
}

napi_value NapiGLFinish(napi_env env, napi_callback_info info) {
    glFinish();
    return nullptr;
}

napi_value NapiGLFlush(napi_env env, napi_callback_info info) {
    glFlush();
    return nullptr;
}

napi_value NapiGLFramebufferRenderbuffer(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum attachment = getGLenum(env, argv[1]);
    GLenum renderbuffertarget = getGLenum(env, argv[2]);
    GLuint renderbuffer = getUint32(env, argv[3]);

    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    return nullptr;
}

napi_value NapiGLFramebufferTexture2D(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum attachment = getGLenum(env, argv[1]);
    GLenum textarget = getGLenum(env, argv[2]);
    GLuint texture = getUint32(env, argv[3]);
    GLint level = getInt32(env, argv[4]);

    glFramebufferTexture2D(target, attachment, textarget, texture, level);
    return nullptr;
}

napi_value NapiGLFrontFace(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum mode = getGLenum(env, argv[0]);
    glFrontFace(mode);
    return nullptr;
}

napi_value NapiGLGenBuffers(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLsizei n = getInt32(env, argv[0]);
    void *buffers = nullptr;
    napi_value result = nullptr;
    createGLuintArray(env, &result, &buffers, n);

    glGenBuffers(n, (GLuint *)buffers);

    return result;
}

napi_value NapiGLGenVertexArrays(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLsizei n = getInt32(env, argv[0]);
    void *data = nullptr;
    napi_value buffer = nullptr;
    createGLuintArray(env, &buffer, &data, n);
    glGenVertexArrays(n, (GLuint *)data);
    return buffer;
}


napi_value NapiGLGenerateMipmap(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    glGenerateMipmap(target);
    return nullptr;
}

napi_value NapiGLGenFramebuffers(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLsizei n = getInt32(env, argv[0]);
    void *buffers = nullptr;
    napi_value result = nullptr;

    createGLuintArray(env, &result, &buffers, n);

    glGenFramebuffers(n, (GLuint *)buffers);
    return result;
}

napi_value NapiGLGenRenderbuffers(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLsizei n = getInt32(env, argv[0]);
    void *buffers = nullptr;
    napi_value result = nullptr;

    createGLuintArray(env, &result, &buffers, n);
    glGenRenderbuffers(n, (GLuint *)buffers);
    return result;
}
napi_value NapiGLGenTextures(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLsizei n = getInt32(env, argv[0]);
    void *buffers = nullptr;
    napi_value result = nullptr;

    createGLuintArray(env, &result, &buffers, n);
    glGenTextures(n, (GLuint *)buffers);
    return result;
}
napi_value NapiGLGetActiveAttrib(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    GLuint index = getGLuint(env, argv[1]);

    GLsizei length = 0;

    glGetActiveAttrib(program, index, length + 1, &length, nullptr, nullptr, nullptr);
    char *name = new char[length + 1];
    GLint size = 0;
    GLenum type = 0;

    glGetActiveAttrib(program, index, length, &length, &size, &type, name);

    napi_value jsName = nullptr;
    napi_value jsSize = nullptr;
    napi_value jsType = nullptr;
    napi_create_string_utf8(env, name, length, &jsName);
    napi_create_int32(env, size, &jsSize);
    napi_create_int32(env, size, &jsType);
    napi_value result = nullptr;
    napi_property_descriptor properties[] = {
        {"name", nullptr, nullptr, nullptr, nullptr, jsName, napi_default, nullptr},
        {"type", nullptr, nullptr, nullptr, nullptr, jsType, napi_default, nullptr},
        {"size", nullptr, nullptr, nullptr, nullptr, jsSize, napi_default, nullptr}};
    napi_create_object_with_properties(env, &result, 3, properties);
    delete[] name;
    return result;
}

napi_value NapiGLGetActiveUniform(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    GLuint index = getGLuint(env, argv[1]);

    GLsizei length = 0;

    glGetActiveUniform(program, index, length, &length, nullptr, nullptr, nullptr);
    char *name = new char[length + 1];
    GLint size = 0;
    GLenum type = 0;

    glGetActiveUniform(program, index, length + 1, &length, &size, &type, name);

    napi_value jsName = nullptr;
    napi_value jsSize = nullptr;
    napi_value jsType = nullptr;
    napi_create_string_utf8(env, name, length, &jsName);
    napi_create_int32(env, size, &jsSize);
    napi_create_int32(env, size, &jsType);
    napi_value result = nullptr;
    napi_property_descriptor properties[] = {
        {"name", nullptr, nullptr, nullptr, nullptr, jsName, napi_default, nullptr},
        {"type", nullptr, nullptr, nullptr, nullptr, jsType, napi_default, nullptr},
        {"size", nullptr, nullptr, nullptr, nullptr, jsSize, napi_default, nullptr}};
    napi_create_object_with_properties(env, &result, 3, properties);
    delete[] name;
    return result;
}

napi_value NapiGLGetAttachedShaders(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);

    GLsizei count = 0;

    glGetAttachedShaders(program, count, &count, nullptr);

    napi_value result = nullptr;
    void *data = nullptr;
    createGLuintArray(env, &result, &data, count);

    glGetAttachedShaders(program, count, &count, (GLuint *)data);
    return result;
}
napi_value NapiGLGetAttribLocation(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    size_t length = 0;
    napi_get_value_string_utf8(env, argv[1], nullptr, 0, &length);
    char *name = new char[length + 1];
    napi_get_value_string_utf8(env, argv[1], name, length + 1, &length);
    GLuint location = glGetAttribLocation(program, name);
    return createNapiInt32(env, location);
}


napi_value NapiGLGetBufferParameteriv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLint params = 0;
    glGetBufferParameteriv(target, pname, &params);
    return createNapiInt32(env, params);
}

napi_value NapiGLGetBufferParameteri64v(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLint64 params = 0;
    glGetBufferParameteri64v(target, pname, &params);
    napi_value result = nullptr;
    napi_create_int64(env, params, &result);
    return result;
}

napi_value NapiGLGetError(napi_env env, napi_callback_info info) { return createNapiInt32(env, glGetError()); }

napi_value NapiGLGetFloatv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum pname = getGLenum(env, argv[0]);
    GLuint size = getGLuint(env, argv[1]);
    void *data = nullptr;
    napi_value result = nullptr;
    napi_value arraybuffer = nullptr;
    napi_create_arraybuffer(env, sizeof(GLfloat) * size, &data, &arraybuffer);
    napi_create_typedarray(env, napi_float32_array, size, arraybuffer, 0, &result);
    glGetFloatv(pname, (GLfloat *)data);
    return result;
}

napi_value NapiGLGetBooleanv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum pname = getGLenum(env, argv[0]);
    GLsizei size = getInt32(env, argv[1]);
    napi_value result = nullptr;
    void *data = nullptr;
    napi_create_arraybuffer(env, size, &data, &result);
    glGetBooleanv(pname, (GLboolean *)data);
    return result;
}

napi_value NapiGLGetIntegerv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum pname = getGLenum(env, argv[0]);
    GLsizei size = getInt32(env, argv[1]);

    void *data = nullptr;
    napi_value result = nullptr;
    napi_value arraybuffer = nullptr;

    napi_create_arraybuffer(env, size * sizeof(GLint), &data, &arraybuffer);
    napi_create_typedarray(env, napi_int32_array, size, arraybuffer, 0, &result);

    glGetIntegerv(pname, (GLint *)data);
    return result;
}

napi_value NapiGLGetInteger64v(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum pname = getGLenum(env, argv[0]);
    GLsizei size = getInt32(env, argv[1]);

    void *data = nullptr;
    napi_value result = nullptr;
    napi_value arraybuffer = nullptr;

    napi_create_arraybuffer(env, size * sizeof(GLint64), &data, &arraybuffer);
    napi_create_typedarray(env, napi_bigint64_array, size, arraybuffer, 0, &result);

    glGetInteger64v(pname, (GLint64 *)data);
    return result;
}

napi_value NapiGLGetFramebufferAttachmentParameteriv(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum target = getGLenum(env, argv[0]);
    GLenum attachment = getGLenum(env, argv[1]);
    GLenum pname = getGLenum(env, argv[2]);
    GLint params = 0;
    glGetFramebufferAttachmentParameteriv(target, attachment, pname, &params);
    return createNapiInt32(env, params);
}


napi_value NapiGLGetProgramiv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint program = getGLuint(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLint params = 1;
    glGetProgramiv(program, pname, &params);
    return createNapiInt32(env, params);
}

napi_value NapiGLGetProgramInfoLog(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    GLint bufSize = 0;

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufSize);
    char *infoLog = new char[bufSize + 1];
    glGetProgramInfoLog(program, bufSize + 1, &bufSize, infoLog);

    napi_value result = nullptr;
    napi_create_string_utf8(env, infoLog, bufSize, &result);
    delete[] infoLog;
    return result;
}

napi_value NapiGLGetRenderbufferParameteriv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLint params = 0;
    glGetRenderbufferParameteriv(target, pname, &params);
    return createNapiInt32(env, params);
}

napi_value NapiGLGetShaderiv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint shader = getGLuint(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLint params = 0;
    glGetShaderiv(shader, pname, &params);
    return createNapiInt32(env, params);
}

napi_value NapiGLGetShaderInfoLog(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint shader = getGLuint(env, argv[0]);
    GLint size = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
    char *infoLog = new char[size + 1];
    glGetShaderInfoLog(shader, size + 1, &size, infoLog);

    napi_value result = nullptr;
    napi_create_string_utf8(env, infoLog, size, &result);
    delete[] infoLog;
    return result;
}

napi_value NapiGLGetShaderPrecisionFormat(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum shadertype = getGLenum(env, argv[0]);
    GLenum precisiontype = getGLenum(env, argv[1]);
    GLint range = 0;
    GLint precision = 0;
    glGetShaderPrecisionFormat(shadertype, precisiontype, &range, &precision);

    napi_value result = nullptr;
    napi_property_descriptor properties[] = {
        {"range", nullptr, nullptr, nullptr, nullptr, createNapiInt32(env, range), napi_default, nullptr},
        {"precision", nullptr, nullptr, nullptr, nullptr, createNapiInt32(env, precision), napi_default, nullptr},
    };
    napi_create_object_with_properties(env, &result, 2, properties);

    return result;
}

napi_value NapiGLGetShaderSource(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint shader = getGLuint(env, argv[0]);
    GLsizei bufSize = 0;
    glGetShaderSource(shader, bufSize, &bufSize, nullptr);
    char *source = new char[bufSize + 1];
    glGetShaderSource(shader, bufSize + 1, &bufSize, source);

    napi_value result = nullptr;
    napi_create_string_utf8(env, source, bufSize, &result);

    delete[] source;
    return result;
}

napi_value NapiGLGetString(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum name = getGLenum(env, argv[0]);
    const GLubyte *str = glGetString(name);

    napi_value result = nullptr;
    napi_create_string_utf8(env, (char *)str, NAPI_AUTO_LENGTH, &result);
    return result;
}

napi_value NapiGLGetTexParameterfv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLfloat params = 0;
    glGetTexParameterfv(target, pname, &params);

    napi_value result = nullptr;
    napi_create_double(env, params, &result);
    return result;
}

napi_value NapiGLGetTexParameteriv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLint params = 0;
    glGetTexParameteriv(target, pname, &params);
    return createNapiInt32(env, params);
}

napi_value NapiGLGetUniformfv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    GLint location = getInt32(env, argv[1]);
    GLfloat params = 0;
    glGetUniformfv(program, location, &params);
    return createNapiFloat(env, params);
}

napi_value NapiGLGetUniformiv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    GLint location = getInt32(env, argv[1]);
    GLint params = 0;
    glGetUniformiv(program, location, &params);
    return createNapiInt32(env, params);
}

napi_value NapiGLGetUniformLocation(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint program = getGLuint(env, argv[0]);
    char *name;
    size_t size = 0;
    napi_get_value_string_utf8(env, argv[1], nullptr, size, &size);
    name = new char[size + 1];
    napi_get_value_string_utf8(env, argv[1], name, size + 1, &size);
    GLint location = glGetUniformLocation(program, name);
    return createNapiInt32(env, location);
}
napi_value NapiGLGetVertexAttribfv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    void *data = nullptr;
    napi_value arraybuffer = nullptr;
    napi_value result = nullptr;
    size_t n = GL_TEXTURE_BORDER_COLOR == pname ? 4 : 1;
    napi_create_arraybuffer(env, sizeof(GLfloat) * n, &data, &arraybuffer);
    napi_create_typedarray(env, napi_float32_array, n, arraybuffer, 0, &result);

    glGetVertexAttribfv(index, pname, (GLfloat *)data);
    return result;
}
napi_value NapiGLGetVertexAttribiv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    void *data = nullptr;
    napi_value result = nullptr;
    napi_value arraybuffer = nullptr;
    size_t n = GL_TEXTURE_BORDER_COLOR == pname ? 4 : 1;
    napi_create_arraybuffer(env, sizeof(GLfloat) * n, &data, &arraybuffer);
    napi_create_typedarray(env, napi_int32_array, n, arraybuffer, 0, &result);

    glGetVertexAttribiv(index, pname, (GLint *)data);

    return result;
}
napi_value NapiGLGetVertexAttribPointerv(napi_env env, napi_callback_info info) {
    // glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer)
    return nullptr;
}
napi_value NapiGLHint(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum target = getGLenum(env, argv[0]);
    GLenum mode = getGLenum(env, argv[1]);
    glHint(target, mode);
    return nullptr;
}
napi_value NapiGLIsBuffer(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint buffer = getGLuint(env, argv[0]);
    GLboolean result = glIsBuffer(buffer);
    return createNapiInt32(env, result);
}
napi_value NapiGLIsEnabled(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum cap = getGLenum(env, argv[0]);
    GLboolean result = glIsEnabled(cap);
    return createNapiInt32(env, result);
}
napi_value NapiGLIsFramebuffer(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint framebuffer = getUint32(env, argv[0]);
    return createNapiInt32(env, glIsFramebuffer(framebuffer));
}
napi_value NapiGLIsProgram(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint program = getUint32(env, argv[0]);
    return createNapiInt32(env, glIsProgram(program));
}
napi_value NapiGLIsRenderbuffer(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint renderbuffer = getUint32(env, argv[0]);
    return createNapiInt32(env, glIsRenderbuffer(renderbuffer));
}
napi_value NapiGLIsShader(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint shader = getUint32(env, argv[0]);
    return createNapiInt32(env, glIsShader(shader));
}
napi_value NapiGLIsTexture(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint texture = getUint32(env, argv[0]);
    return createNapiInt32(env, glIsTexture(texture));
}
napi_value NapiGLLineWidth(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLfloat width = getGLfloat(env, argv[0]);
    glLineWidth(width);
    return nullptr;
}
napi_value NapiGLLinkProgram(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint program = getGLuint(env, argv[0]);
    glLinkProgram(program);
    return nullptr;
}
napi_value NapiGLPixelStorei(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum pname = getGLenum(env, argv[0]);
    GLint param = getInt32(env, argv[1]);
    glPixelStorei(pname, param);
    return nullptr;
}
napi_value NapiGLPolygonOffset(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLfloat factor = getGLfloat(env, argv[0]);
    GLfloat units = getGLfloat(env, argv[1]);
    glPolygonOffset(factor, units);
    return nullptr;
}
napi_value NapiGLReadPixels(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value argv[6];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint x = getInt32(env, argv[0]);
    GLint y = getInt32(env, argv[1]);
    GLsizei width = getInt32(env, argv[2]);
    GLsizei height = getInt32(env, argv[3]);
    GLenum readFormat = getGLenum(env, argv[4]);
    GLenum readType = getGLenum(env, argv[5]);

    GLuint bytesPerPixel = 0;

    switch (readType) {
    case GL_UNSIGNED_BYTE:
    case GL_BYTE:
        switch (readFormat) {
        case GL_RGBA:
            bytesPerPixel = 4;
            break;
        case GL_RGB:
        case GL_RGB_INTEGER:
            bytesPerPixel = 3;
            break;
        case GL_RG:
        case GL_RG_INTEGER:
        case GL_LUMINANCE_ALPHA:
            bytesPerPixel = 2;
            break;
        case GL_RED:
        case GL_RED_INTEGER:
        case GL_ALPHA:
        case GL_LUMINANCE:
            bytesPerPixel = 1;
            break;
        default:
            // Undetected format/error
            break;
        }
        break;
    case GL_FLOAT:
    case GL_UNSIGNED_INT:
    case GL_INT:
        switch (readFormat) {
        case GL_RGBA:
        case GL_RGBA_INTEGER:
            bytesPerPixel = 16;
            break;
        case GL_RGB:
        case GL_RGB_INTEGER:
            bytesPerPixel = 12;
            break;
        case GL_RG:
        case GL_RG_INTEGER:
            bytesPerPixel = 8;
            break;
        case GL_RED:
        case GL_RED_INTEGER:
        case GL_DEPTH_COMPONENT:
            bytesPerPixel = 4;
            break;
        default:
            // Undetected format/error
            break;
        }
        break;
    case GL_HALF_FLOAT:
    case GL_UNSIGNED_SHORT:
    case GL_SHORT:
        switch (readFormat) {
        case GL_RGBA:
        case GL_RGBA_INTEGER:
            bytesPerPixel = 8;
            break;
        case GL_RGB:
        case GL_RGB_INTEGER:
            bytesPerPixel = 6;
            break;
        case GL_RG:
        case GL_RG_INTEGER:
            bytesPerPixel = 4;
            break;
        case GL_RED:
        case GL_RED_INTEGER:
            bytesPerPixel = 2;
            break;
        default:
            // Undetected format/error
            break;
        }
        break;
    case GL_FLOAT_32_UNSIGNED_INT_24_8_REV: // GL_DEPTH_STENCIL
        bytesPerPixel = 8;
        break;
        // GL_RGBA, GL_RGBA_INTEGER format
    case GL_UNSIGNED_INT_2_10_10_10_REV:
    case GL_UNSIGNED_INT_10F_11F_11F_REV: // GL_RGB format
    case GL_UNSIGNED_INT_5_9_9_9_REV:     // GL_RGB format
    case GL_UNSIGNED_INT_24_8:            // GL_DEPTH_STENCIL format
        bytesPerPixel = 4;
        break;
    case GL_UNSIGNED_SHORT_4_4_4_4: // GL_RGBA format
    case GL_UNSIGNED_SHORT_5_5_5_1: // GL_RGBA format
    case GL_UNSIGNED_SHORT_5_6_5:   // GL_RGB format
        bytesPerPixel = 2;
        break;
    default:
        break;
        // Undetected type/error
    }

    size_t byte_length = width * height * bytesPerPixel;
    void *data = nullptr;
    napi_value result = nullptr;
    napi_create_arraybuffer(env, byte_length, &data, &result);

    glReadPixels(x, y, width, height, readFormat, readType, data);
    return result;
}

napi_value NapiGLReleaseShaderCompiler(napi_env env, napi_callback_info info) {
    glReleaseShaderCompiler();
    return nullptr;
}
napi_value NapiGLRenderbufferStorage(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum internalformat = getGLenum(env, argv[1]);
    GLsizei width = getInt32(env, argv[2]);
    GLsizei height = getInt32(env, argv[3]);
    glRenderbufferStorage(target, internalformat, width, height);
    return nullptr;
}
napi_value NapiGLSampleCoverage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLfloat value = getGLfloat(env, argv[0]);
    GLboolean invert = getInt32(env, argv[1]);
    glSampleCoverage(value, invert);
    return nullptr;
}
napi_value NapiGLScissor(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLint x = getInt32(env, argv[0]);
    GLint y = getInt32(env, argv[1]);
    GLsizei width = getInt32(env, argv[2]);
    GLsizei height = getInt32(env, argv[3]);
    glScissor(x, y, width, height);
    return nullptr;
}
napi_value NapiGLShaderBinary(napi_env env, napi_callback_info info) { 
//     glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length)

    return nullptr;
}
napi_value NapiGLShaderSource(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint shader = getGLuint(env, argv[0]);
    char *source = nullptr;
    size_t size = 0;
    napi_get_value_string_utf8(env, argv[1], nullptr, size, &size);
    source = new char[size + 1]{'\0'};
    GLint length = size + 1;
    napi_get_value_string_utf8(env, argv[1], source, size + 1, &size);
    glShaderSource(shader, 1, &source, &length);
    return nullptr;
}
napi_value NapiGLStencilFunc(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum func = getGLenum(env, argv[0]);
    GLint ref = getInt32(env, argv[1]);
    GLuint mask = getGLuint(env, argv[2]);
    glStencilFunc(func, ref, mask);
    return nullptr;
}
napi_value NapiGLStencilFuncSeparate(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum face = getGLenum(env, argv[0]);
    GLenum func = getGLenum(env, argv[1]);
    GLint ref = getInt32(env, argv[2]);
    GLuint mask = getGLuint(env, argv[3]);
    glStencilFuncSeparate(face, func, ref, mask);
    return nullptr;
}
napi_value NapiGLStencilMask(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint mask = getGLuint(env, argv[0]);
    glStencilMask(mask);
    return nullptr;
}
napi_value NapiGLStencilMaskSeparate(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum face = getGLenum(env, argv[0]);
    GLuint mask = getGLuint(env, argv[1]);
    glStencilMaskSeparate(face, mask);
    return nullptr;
}
napi_value NapiGLStencilOp(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum fail = getGLenum(env, argv[0]);
    GLenum zfail = getGLenum(env, argv[1]);
    GLenum zpass = getGLenum(env, argv[2]);

    glStencilOp(fail, zfail, zpass);
    return nullptr;
}
napi_value NapiGLStencilOpSeparate(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum face = getGLenum(env, argv[0]);
    GLenum sfail = getGLenum(env, argv[1]);
    GLenum dpfail = getGLenum(env, argv[2]);
    GLenum dppass = getGLenum(env, argv[3]);

    glStencilOpSeparate(face, sfail, dpfail, dppass);
    return nullptr;
}
napi_value NapiGLTexImage2D(napi_env env, napi_callback_info info) {
    size_t argc = 9;
    napi_value argv[9];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLint level = getInt32(env, argv[1]);
    GLint internalformat = getInt32(env, argv[2]);
    GLsizei width = getInt32(env, argv[3]);
    GLsizei height = getInt32(env, argv[4]);
    GLint border = getInt32(env, argv[5]);
    GLenum format = getGLenum(env, argv[6]);
    GLenum type = getGLenum(env, argv[7]);

    void *data = nullptr;
    bool r = false;
    napi_is_arraybuffer(env, argv[8], &r);
    if (r) {
        napi_get_arraybuffer_info(env, argv[8], &data, nullptr);
    }

    glTexImage2D(target, level, internalformat, width, height, border, format, type, data);
    return nullptr;
}
napi_value NapiGLTexParameterf(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLfloat param = getGLfloat(env, argv[2]);
    glTexParameterf(target, pname, param);
    return nullptr;
}
napi_value NapiGLTexParameterfv(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[2], &data, nullptr);

    glTexParameterfv(target, pname, (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLTexParameteri(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    GLint param = getInt32(env, argv[2]);

    glTexParameteri(target, pname, param);
    return nullptr;
}
napi_value NapiGLTexParameteriv(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLenum pname = getGLenum(env, argv[1]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[2], &data, nullptr);

    glTexParameteriv(target, pname, (GLint *)data);
    return nullptr;
}
napi_value NapiGLTexSubImage2D(napi_env env, napi_callback_info info) {
    size_t argc = 9;
    napi_value argv[9];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLint level = getInt32(env, argv[1]);
    GLint xoffset = getInt32(env, argv[2]);
    GLint yoffset = getInt32(env, argv[3]);
    GLsizei width = getInt32(env, argv[4]);
    GLsizei height = getInt32(env, argv[5]);
    GLenum format = getGLenum(env, argv[6]);
    GLenum type = getGLenum(env, argv[7]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[8], &data, &size);
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, data);
    return nullptr;
}
napi_value NapiGLUniform1f(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLfloat v0 = getGLfloat(env, argv[1]);
    glUniform1f(location, v0);
    return nullptr;
}
napi_value NapiGLUniform1fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);

    glUniform1fv(location, size / sizeof(GLfloat), (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLUniform1i(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLint v0 = getInt32(env, argv[1]);
    glUniform1i(location, v0);
    return nullptr;
}
napi_value NapiGLUniform1iv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);
    glUniform1iv(location, size / sizeof(GLint), (GLint *)data);
    return nullptr;
}
napi_value NapiGLUniform2f(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLfloat v0 = getGLfloat(env, argv[1]);
    GLfloat v1 = getGLfloat(env, argv[2]);
    glUniform2f(location, v0, v1);
    return nullptr;
}
napi_value NapiGLUniform2fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);

    glUniform2fv(location, size / sizeof(GLfloat), (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLUniform2i(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLint v0 = getInt32(env, argv[1]);
    GLint v1 = getInt32(env, argv[2]);
    glUniform2i(location, v0, v1);
    return nullptr;
}
napi_value NapiGLUniform2iv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);

    glUniform2iv(location, size / sizeof(GLint), (GLint *)data);
    return nullptr;
}

napi_value NapiGLUniform3f(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLfloat v0 = getGLfloat(env, argv[1]);
    GLfloat v1 = getGLfloat(env, argv[2]);
    GLfloat v2 = getGLfloat(env, argv[3]);

    glUniform3f(location, v0, v1, v2);
    return nullptr;
}
napi_value NapiGLUniform3fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);

    glUniform3fv(location, size / sizeof(GLfloat), (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLUniform3i(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLint v0 = getInt32(env, argv[1]);
    GLint v1 = getInt32(env, argv[2]);
    GLint v2 = getInt32(env, argv[3]);

    glUniform3i(location, v0, v1, v2);
    return nullptr;
}
napi_value NapiGLUniform3iv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);

    glUniform3iv(location, size / sizeof(GLint), (GLint *)data);
    return nullptr;
}
napi_value NapiGLUniform4f(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLfloat v0 = getGLfloat(env, argv[1]);
    GLfloat v1 = getGLfloat(env, argv[2]);
    GLfloat v2 = getGLfloat(env, argv[3]);
    GLfloat v3 = getGLfloat(env, argv[4]);

    glUniform4f(location, v0, v1, v2, v3);
    return nullptr;
}
napi_value NapiGLUniform4fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);

    glUniform4fv(location, size / sizeof(GLfloat), (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLUniform4i(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLint v0 = getInt32(env, argv[1]);
    GLint v1 = getInt32(env, argv[2]);
    GLint v2 = getInt32(env, argv[3]);
    GLint v3 = getInt32(env, argv[4]);

    glUniform4i(location, v0, v1, v2, v3);
    return nullptr;
}
napi_value NapiGLUniform4iv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    void *data = nullptr;
    size_t size = 0;
    napi_get_arraybuffer_info(env, argv[1], &data, &size);

    glUniform4iv(location, size / sizeof(GLint), (GLint *)data);
    return nullptr;
}

napi_value NapiGLUniformMatrix2fv(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLsizei count = getInt32(env, argv[1]);
    GLboolean transpose = getInt32(env, argv[2]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[3], &data, nullptr);
    glUniformMatrix2fv(location, count, transpose, (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLUniformMatrix3fv(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLsizei count = getInt32(env, argv[1]);
    GLboolean transpose = getInt32(env, argv[2]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[3], &data, nullptr);
    glUniformMatrix3fv(location, count, transpose, (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLUniformMatrix4fv(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLint location = getInt32(env, argv[0]);
    GLsizei count = getInt32(env, argv[1]);
    GLboolean transpose = getInt32(env, argv[2]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[3], &data, nullptr);
    glUniformMatrix4fv(location, count, transpose, (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLUseProgram(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint program = getGLuint(env, argv[0]);
    glUseProgram(program);
    return nullptr;
}
napi_value NapiGLValidateProgram(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint program = getGLuint(env, argv[0]);
    glValidateProgram(program);
    return nullptr;
}
napi_value NapiGLVertexAttrib1f(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    GLfloat x = getGLfloat(env, argv[1]);
    glVertexAttrib1f(index, x);
    return nullptr;
}
napi_value NapiGLVertexAttrib1fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[1], &data, nullptr);
    glVertexAttrib1fv(index, (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLVertexAttrib2f(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    GLfloat x = getGLfloat(env, argv[1]);
    GLfloat y = getGLfloat(env, argv[2]);
    glVertexAttrib2f(index, x, y);
    return nullptr;
}
napi_value NapiGLVertexAttrib2fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[1], &data, nullptr);
    glVertexAttrib2fv(index, (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLVertexAttrib3f(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    GLfloat x = getGLfloat(env, argv[1]);
    GLfloat y = getGLfloat(env, argv[2]);
    GLfloat z = getGLfloat(env, argv[3]);
    glVertexAttrib3f(index, x, y, z);
    return nullptr;
}
napi_value NapiGLVertexAttrib3fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[1], &data, nullptr);
    glVertexAttrib3fv(index, (GLfloat *)data);
    return nullptr;
}
napi_value NapiGLVertexAttrib4f(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    GLfloat x = getGLfloat(env, argv[1]);
    GLfloat y = getGLfloat(env, argv[2]);
    GLfloat z = getGLfloat(env, argv[3]);
    GLfloat w = getGLfloat(env, argv[4]);
    glVertexAttrib4f(index, x, y, z, w);
    return nullptr;
    return nullptr;
}
napi_value NapiGLVertexAttrib4fv(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint index = getGLuint(env, argv[0]);
    void *data = nullptr;
    napi_get_arraybuffer_info(env, argv[1], &data, nullptr);
    glVertexAttrib4fv(index, (GLfloat *)data);
    return nullptr;
}

napi_value NapiGLVertexAttribPointer(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value argv[6];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLuint index = getGLuint(env, argv[0]);
    GLint size = getInt32(env, argv[1]);
    GLenum type = getGLenum(env, argv[2]);
    GLboolean normalized = getInt32(env, argv[3]);
    GLsizei stride = getInt32(env, argv[4]);
    GLint pointer = getInt32(env, argv[5]);
    glVertexAttribPointer(index, size, type, normalized, stride, (void *)pointer);
    return nullptr;
}
napi_value NapiGLViewport(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLint x = getInt32(env, argv[0]);
    GLint y = getInt32(env, argv[1]);
    GLsizei width = getInt32(env, argv[2]);
    GLsizei height = getInt32(env, argv[3]);
    glViewport(x, y, width, height);
    return nullptr;
}

napi_value NapiGLBeginQuery(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);
    GLuint id = getGLuint(env, argv[1]);

    glBeginQuery(target, id);
    return nullptr;
}
napi_value NapiGLEndQuery(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    GLenum target = getGLenum(env, argv[0]);

    glEndQuery(target);
    return nullptr;
}

napi_value NapiGLBeginTransformFeedback(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLenum primitiveMode = getGLenum(env, argv[0]);
    glBeginTransformFeedback(primitiveMode);
    return nullptr;
}

napi_value NapiGLEndTransformFeedback(napi_env env, napi_callback_info info) {
    glEndTransformFeedback();
    return nullptr;
}

napi_value NapiGLVertexAttribFormat(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint attribindex = 0;
    GLint size = 0;
    GLenum type = 0;
    int normalized = 0;
    GLuint relativeoffset = 0;
    napi_get_value_uint32(env, argv[0], &attribindex);
    napi_get_value_int32(env, argv[1], &size);
    napi_get_value_uint32(env, argv[2], &type);
    napi_get_value_int32(env, argv[3], &normalized);
    napi_get_value_uint32(env, argv[4], &relativeoffset);
    glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);

    return nullptr;
}

napi_value NapiGLVertexAttribIFormat(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value argv[4];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint attribindex = 0;
    GLint size = 0;
    GLenum type = 0;
    GLuint relativeoffset = 0;
    napi_get_value_uint32(env, argv[0], &attribindex);
    napi_get_value_int32(env, argv[1], &size);
    napi_get_value_uint32(env, argv[2], &type);
    napi_get_value_uint32(env, argv[3], &relativeoffset);
    glVertexAttribIFormat(attribindex, size, type, relativeoffset);
    return nullptr;
}

napi_value NapiGLVertexAttribBinding(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    GLuint attribindex = 0;
    GLuint bindingindex = 0;
    napi_get_value_uint32(env, argv[0], &attribindex);
    napi_get_value_uint32(env, argv[1], &bindingindex);
    glVertexAttribBinding(attribindex, bindingindex);
    return nullptr;
}

// napi_value NapiGLMapBufferRange(napi_env env, napi_callback_info info) {
//     glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
// }


} // namespace GLES
