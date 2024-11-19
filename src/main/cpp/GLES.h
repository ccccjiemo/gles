//
// Created on 2024/11/14.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_GLES_H
#define GLTEST_GLES_H
#include <js_native_api.h>


namespace GLES {
void Export(napi_env env, napi_value exports);
napi_value NapiGLActiveShaderProgram(napi_env env, napi_callback_info info);
napi_value NapiGLActiveTexture(napi_env env, napi_callback_info info);
napi_value NapiGLAttachShader(napi_env env, napi_callback_info info);
napi_value NapiGLBeginQuery(napi_env env, napi_callback_info info);
napi_value NapiGLEndQuery(napi_env env, napi_callback_info info);
napi_value NapiGLBeginTransformFeedback(napi_env env, napi_callback_info info);
napi_value NapiGLEndTransformFeedback(napi_env env, napi_callback_info info);
napi_value NapiGLBindAttribLocation(napi_env env, napi_callback_info info);
napi_value NapiGLBindBuffer(napi_env env, napi_callback_info info);
napi_value NapiGLBindFramebuffer(napi_env env, napi_callback_info info);
napi_value NapiGLBindRenderbuffer(napi_env env, napi_callback_info info);
napi_value NapiGLBindTexture(napi_env env, napi_callback_info info);
napi_value NapiGLBlendColor(napi_env env, napi_callback_info info);
napi_value NapiGLBlendEquation(napi_env env, napi_callback_info info);
napi_value NapiGLBlendEquationi(napi_env env, napi_callback_info info);
napi_value NapiGLBlendEquationSeparate(napi_env env, napi_callback_info info);
napi_value NapiGLBlendFunc(napi_env env, napi_callback_info info);
napi_value NapiGLBlendFuncSeparate(napi_env env, napi_callback_info info);
napi_value NapiGLBufferData(napi_env env, napi_callback_info info);
napi_value NapiGLBufferSubData(napi_env env, napi_callback_info info);
napi_value NapiGLCheckFramebufferStatus(napi_env env, napi_callback_info info);
napi_value NapiGLClear(napi_env env, napi_callback_info info);
napi_value NapiGLClearColor(napi_env env, napi_callback_info info);
napi_value NapiGLClearDepthf(napi_env env, napi_callback_info info);
napi_value NapiGLClearStencil(napi_env env, napi_callback_info info);
napi_value NapiGLColorMask(napi_env env, napi_callback_info info);
napi_value NapiGLCompileShader(napi_env env, napi_callback_info info);
napi_value NapiGLCompressedTexImage2D(napi_env env, napi_callback_info info);
napi_value NapiGLCompressedTexSubImage2D(napi_env env, napi_callback_info info);
napi_value NapiGLCopyTexImage2D(napi_env env, napi_callback_info info);
napi_value NapiGLCopyTexSubImage2D(napi_env env, napi_callback_info info);
napi_value NapiGLCreateProgram(napi_env env, napi_callback_info info);
napi_value NapiGLCreateShader(napi_env env, napi_callback_info info);
napi_value NapiGLCullFace(napi_env env, napi_callback_info info);
napi_value NapiGLDeleteBuffers(napi_env env, napi_callback_info info);
napi_value NapiGLDeleteFramebuffers(napi_env env, napi_callback_info info);
napi_value NapiGLDeleteProgram(napi_env env, napi_callback_info info);
napi_value NapiGLDeleteRenderbuffers(napi_env env, napi_callback_info info);
napi_value NapiGLDeleteShader(napi_env env, napi_callback_info info);
napi_value NapiGLDeleteTextures(napi_env env, napi_callback_info info);
napi_value NapiGLDepthFunc(napi_env env, napi_callback_info info);
napi_value NapiGLDepthMask(napi_env env, napi_callback_info info);
napi_value NapiGLDepthRangef(napi_env env, napi_callback_info info);
napi_value NapiGLDetachShader(napi_env env, napi_callback_info info);
napi_value NapiGLDisable(napi_env env, napi_callback_info info);
napi_value NapiGLDisableVertexAttribArray(napi_env env, napi_callback_info info);
napi_value NapiGLDrawArrays(napi_env env, napi_callback_info info);
napi_value NapiGLDrawElements(napi_env env, napi_callback_info info);
napi_value NapiGLEnable(napi_env env, napi_callback_info info);
napi_value NapiGLEnableVertexAttribArray(napi_env env, napi_callback_info info);
napi_value NapiGLFinish(napi_env env, napi_callback_info info);
napi_value NapiGLFlush(napi_env env, napi_callback_info info);
napi_value NapiGLFramebufferRenderbuffer(napi_env env, napi_callback_info info);
napi_value NapiGLFramebufferTexture2D(napi_env env, napi_callback_info info);
napi_value NapiGLFrontFace(napi_env env, napi_callback_info info);
napi_value NapiGLGenBuffers(napi_env env, napi_callback_info info);
napi_value NapiGLGenVertexArrays(napi_env env, napi_callback_info info);
napi_value NapiGLGenerateMipmap(napi_env env, napi_callback_info info);
napi_value NapiGLGenFramebuffers(napi_env env, napi_callback_info info);
napi_value NapiGLGenRenderbuffers(napi_env env, napi_callback_info info);
napi_value NapiGLGenTextures(napi_env env, napi_callback_info info);
napi_value NapiGLGetActiveAttrib(napi_env env, napi_callback_info info);
napi_value NapiGLGetActiveUniform(napi_env env, napi_callback_info info);
napi_value NapiGLGetAttachedShaders(napi_env env, napi_callback_info info);
napi_value NapiGLGetAttribLocation(napi_env env, napi_callback_info info);
napi_value NapiGLGetBooleanv(napi_env env, napi_callback_info info);
napi_value NapiGLGetBufferParameteriv(napi_env env, napi_callback_info info);
napi_value NapiGLGetError(napi_env env, napi_callback_info info);
napi_value NapiGLGetFloatv(napi_env env, napi_callback_info info);
napi_value NapiGLGetFramebufferAttachmentParameteriv(napi_env env, napi_callback_info info);
napi_value NapiGLGetIntegerv(napi_env env, napi_callback_info info);
napi_value NapiGLGetProgramiv(napi_env env, napi_callback_info info);
napi_value NapiGLGetProgramInfoLog(napi_env env, napi_callback_info info);
napi_value NapiGLGetRenderbufferParameteriv(napi_env env, napi_callback_info info);
napi_value NapiGLGetShaderiv(napi_env env, napi_callback_info info);
napi_value NapiGLGetShaderInfoLog(napi_env env, napi_callback_info info);
napi_value NapiGLGetShaderPrecisionFormat(napi_env env, napi_callback_info info);
napi_value NapiGLGetShaderSource(napi_env env, napi_callback_info info);
napi_value NapiGLGetString(napi_env env, napi_callback_info info);
napi_value NapiGLGetTexParameterfv(napi_env env, napi_callback_info info);
napi_value NapiGLGetTexParameteriv(napi_env env, napi_callback_info info);
napi_value NapiGLGetUniformfv(napi_env env, napi_callback_info info);
napi_value NapiGLGetUniformiv(napi_env env, napi_callback_info info);
napi_value NapiGLGetUniformLocation(napi_env env, napi_callback_info info);
napi_value NapiGLGetVertexAttribfv(napi_env env, napi_callback_info info);
napi_value NapiGLGetVertexAttribiv(napi_env env, napi_callback_info info);
napi_value NapiGLGetVertexAttribPointerv(napi_env env, napi_callback_info info);
napi_value NapiGLHint(napi_env env, napi_callback_info info);
napi_value NapiGLIsBuffer(napi_env env, napi_callback_info info);
napi_value NapiGLIsEnabled(napi_env env, napi_callback_info info);
napi_value NapiGLIsFramebuffer(napi_env env, napi_callback_info info);
napi_value NapiGLIsProgram(napi_env env, napi_callback_info info);
napi_value NapiGLIsRenderbuffer(napi_env env, napi_callback_info info);
napi_value NapiGLIsShader(napi_env env, napi_callback_info info);
napi_value NapiGLIsTexture(napi_env env, napi_callback_info info);
napi_value NapiGLLineWidth(napi_env env, napi_callback_info info);
napi_value NapiGLLinkProgram(napi_env env, napi_callback_info info);
napi_value NapiGLPixelStorei(napi_env env, napi_callback_info info);
napi_value NapiGLPolygonOffset(napi_env env, napi_callback_info info);
napi_value NapiGLReadPixels(napi_env env, napi_callback_info info);
napi_value NapiGLReleaseShaderCompiler(napi_env env, napi_callback_info info);
napi_value NapiGLRenderbufferStorage(napi_env env, napi_callback_info info);
napi_value NapiGLSampleCoverage(napi_env env, napi_callback_info info);
napi_value NapiGLScissor(napi_env env, napi_callback_info info);
napi_value NapiGLShaderBinary(napi_env env, napi_callback_info info);
napi_value NapiGLShaderSource(napi_env env, napi_callback_info info);
napi_value NapiGLStencilFunc(napi_env env, napi_callback_info info);
napi_value NapiGLStencilFuncSeparate(napi_env env, napi_callback_info info);
napi_value NapiGLStencilMask(napi_env env, napi_callback_info info);
napi_value NapiGLStencilMaskSeparate(napi_env env, napi_callback_info info);
napi_value NapiGLStencilOp(napi_env env, napi_callback_info info);
napi_value NapiGLStencilOpSeparate(napi_env env, napi_callback_info info);
napi_value NapiGLTexImage2D(napi_env env, napi_callback_info info);
napi_value NapiGLTexParameterf(napi_env env, napi_callback_info info);
napi_value NapiGLTexParameterfv(napi_env env, napi_callback_info info);
napi_value NapiGLTexParameteri(napi_env env, napi_callback_info info);
napi_value NapiGLTexParameteriv(napi_env env, napi_callback_info info);
napi_value NapiGLTexSubImage2D(napi_env env, napi_callback_info info);
napi_value NapiGLUniform1f(napi_env env, napi_callback_info info);
napi_value NapiGLUniform1fv(napi_env env, napi_callback_info info);
napi_value NapiGLUniform1i(napi_env env, napi_callback_info info);
napi_value NapiGLUniform1iv(napi_env env, napi_callback_info info);
napi_value NapiGLUniform2f(napi_env env, napi_callback_info info);
napi_value NapiGLUniform2fv(napi_env env, napi_callback_info info);
napi_value NapiGLUniform2i(napi_env env, napi_callback_info info);
napi_value NapiGLUniform2iv(napi_env env, napi_callback_info info);
napi_value NapiGLUniform3f(napi_env env, napi_callback_info info);
napi_value NapiGLUniform3fv(napi_env env, napi_callback_info info);
napi_value NapiGLUniform3i(napi_env env, napi_callback_info info);
napi_value NapiGLUniform3iv(napi_env env, napi_callback_info info);
napi_value NapiGLUniform4f(napi_env env, napi_callback_info info);
napi_value NapiGLUniform4fv(napi_env env, napi_callback_info info);
napi_value NapiGLUniform4i(napi_env env, napi_callback_info info);
napi_value NapiGLUniform4iv(napi_env env, napi_callback_info info);
napi_value NapiGLUniformMatrix2fv(napi_env env, napi_callback_info info);
napi_value NapiGLUniformMatrix3fv(napi_env env, napi_callback_info info);
napi_value NapiGLUniformMatrix4fv(napi_env env, napi_callback_info info);
napi_value NapiGLUseProgram(napi_env env, napi_callback_info info);
napi_value NapiGLValidateProgram(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib1f(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib1fv(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib2f(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib2fv(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib3f(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib3fv(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib4f(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttrib4fv(napi_env env, napi_callback_info info);
napi_value NapiGLVertexAttribPointer(napi_env env, napi_callback_info info);
napi_value NapiGLViewport(napi_env env, napi_callback_info info);
napi_value NapiGLBindVertexArray(napi_env env, napi_callback_info info);
napi_value NapiGLBindVertexBuffer(napi_env env, napi_callback_info info);

} // namespace GLES

#endif // GLTEST_GLES_H
