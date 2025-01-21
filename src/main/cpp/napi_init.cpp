#include "GLES.h"
#include "GLESExtends.h"
#include "NativeImage.h"
#include "napi/native_api.h"
#include "utils.h"


EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {

    /***
     * defined NativeImage
     */


    napi_property_descriptor nativeImageDesc[] = {
        DEFINE_NAPI_FUNCTION("surfaceId", nullptr, NativeImage::NapiGetSurfaceId, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("isAvailable", nullptr, NativeImage::NapiGetIsAvailable, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("attachContext", NativeImage::NapiAttachContext, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("detachContext", NativeImage::NapiDetachContext, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("destroy", NativeImage::NapiDestroyNativeImage, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("updateSurfaceImage", NativeImage::NapiUpdateSurfaceImage, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("setOnFrameAvailableListener", NativeImage::NapiSetOnFrameAvailableListener, nullptr,
                             nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("unSetOnFrameAvailableListener", NativeImage::NapiUnSetOnFrameAvailableListener, nullptr,
                             nullptr, nullptr),
    };
    DEFINE_SENDABLE_CLASS(env, exports, "NativeImage", NativeImage::NapiBindNativeImage, nativeImageDesc)


    /***
     * defined property
     */
    napi_property_descriptor desc[] = {
        DEFINE_NAPI_FUNCTION("glActiveShaderProgram", GLES::NapiGLActiveShaderProgram, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glActiveTexture", GLES::NapiGLActiveTexture, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glAttachShader", GLES::NapiGLAttachShader, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBindAttribLocation", GLES::NapiGLBindAttribLocation, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBindBuffer", GLES::NapiGLBindBuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBindFramebuffer", GLES::NapiGLBindFramebuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBindRenderbuffer", GLES::NapiGLBindRenderbuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBindTexture", GLES::NapiGLBindTexture, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBlendColor", GLES::NapiGLBlendColor, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBlendEquation", GLES::NapiGLBlendEquation, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBlendEquationi", GLES::NapiGLBlendEquationi, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBlendEquationSeparate", GLES::NapiGLBlendEquationSeparate, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBeginTransformFeedback", GLES::NapiGLBeginTransformFeedback, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glEndTransformFeedback", GLES::NapiGLEndTransformFeedback, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBeginQuery", GLES::NapiGLBeginQuery, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glEndQuery", GLES::NapiGLEndQuery, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBlendFunc", GLES::NapiGLBlendFunc, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBlendFuncSeparate", GLES::NapiGLBlendFuncSeparate, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBlendFuncSeparatei", GLES::NapiGLBlendFuncSeparatei, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBufferData", GLES::NapiGLBufferData, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBufferSubData", GLES::NapiGLBufferSubData, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCheckFramebufferStatus", GLES::NapiGLCheckFramebufferStatus, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glClear", GLES::NapiGLClear, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glClearColor", GLES::NapiGLClearColor, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glClearDepthf", GLES::NapiGLClearDepthf, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glClearStencil", GLES::NapiGLClearStencil, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glColorMask", GLES::NapiGLColorMask, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCompileShader", GLES::NapiGLCompileShader, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCompressedTexImage2D", GLES::NapiGLCompressedTexImage2D, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCompressedTexSubImage2D", GLES::NapiGLCompressedTexSubImage2D, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glCopyTexImage2D", GLES::NapiGLCopyTexImage2D, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCopyTexSubImage2D", GLES::NapiGLCopyTexSubImage2D, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCreateProgram", GLES::NapiGLCreateProgram, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCreateShader", GLES::NapiGLCreateShader, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glCullFace", GLES::NapiGLCullFace, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDeleteBuffers", GLES::NapiGLDeleteBuffers, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDeleteVertexArrays", GLES::NapiGLDeleteVertexArrays, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDeleteFramebuffers", GLES::NapiGLDeleteFramebuffers, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDeleteProgram", GLES::NapiGLDeleteProgram, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDeleteRenderbuffers", GLES::NapiGLDeleteRenderbuffers, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDeleteShader", GLES::NapiGLDeleteShader, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDeleteTextures", GLES::NapiGLDeleteTextures, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDepthFunc", GLES::NapiGLDepthFunc, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDepthMask", GLES::NapiGLDepthMask, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDepthRangef", GLES::NapiGLDepthRangef, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDetachShader", GLES::NapiGLDetachShader, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDisable", GLES::NapiGLDisable, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDisableVertexAttribArray", GLES::NapiGLDisableVertexAttribArray, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glDrawArrays", GLES::NapiGLDrawArrays, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glDrawElements", GLES::NapiGLDrawElements, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glEnable", GLES::NapiGLEnable, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glEnableVertexAttribArray", GLES::NapiGLEnableVertexAttribArray, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glFinish", GLES::NapiGLFinish, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glFlush", GLES::NapiGLFlush, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glFramebufferRenderbuffer", GLES::NapiGLFramebufferRenderbuffer, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glFramebufferTexture2D", GLES::NapiGLFramebufferTexture2D, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glFrontFace", GLES::NapiGLFrontFace, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGenBuffers", GLES::NapiGLGenBuffers, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGenVertexArrays", GLES::NapiGLGenVertexArrays, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGenerateMipmap", GLES::NapiGLGenerateMipmap, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGenFramebuffers", GLES::NapiGLGenFramebuffers, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGenRenderbuffers", GLES::NapiGLGenRenderbuffers, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGenTextures", GLES::NapiGLGenTextures, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetActiveAttrib", GLES::NapiGLGetActiveAttrib, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetActiveUniform", GLES::NapiGLGetActiveUniform, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetAttachedShaders", GLES::NapiGLGetAttachedShaders, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetAttribLocation", GLES::NapiGLGetAttribLocation, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetBooleanv", GLES::NapiGLGetBooleanv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetBufferParameteriv", GLES::NapiGLGetBufferParameteriv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetBufferParameteri64v", GLES::NapiGLGetBufferParameteri64v, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetError", GLES::NapiGLGetError, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetFloatv", GLES::NapiGLGetFloatv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetFramebufferAttachmentParameteriv", GLES::NapiGLGetFramebufferAttachmentParameteriv,
                             nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetIntegerv", GLES::NapiGLGetIntegerv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetInteger64v", GLES::NapiGLGetInteger64v, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetProgramiv", GLES::NapiGLGetProgramiv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetProgramInfoLog", GLES::NapiGLGetProgramInfoLog, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetRenderbufferParameteriv", GLES::NapiGLGetRenderbufferParameteriv, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glGetShaderiv", GLES::NapiGLGetShaderiv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetShaderInfoLog", GLES::NapiGLGetShaderInfoLog, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetShaderPrecisionFormat", GLES::NapiGLGetShaderPrecisionFormat, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glGetShaderSource", GLES::NapiGLGetShaderSource, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetString", GLES::NapiGLGetString, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetTexParameterfv", GLES::NapiGLGetTexParameterfv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetTexParameteriv", GLES::NapiGLGetTexParameteriv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetUniformfv", GLES::NapiGLGetUniformfv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetUniformiv", GLES::NapiGLGetUniformiv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetUniformLocation", GLES::NapiGLGetUniformLocation, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetVertexAttribfv", GLES::NapiGLGetVertexAttribfv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetVertexAttribiv", GLES::NapiGLGetVertexAttribiv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glGetVertexAttribPointerv", GLES::NapiGLGetVertexAttribPointerv, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glHint", GLES::NapiGLHint, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glIsBuffer", GLES::NapiGLIsBuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glIsEnabled", GLES::NapiGLIsEnabled, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glIsFramebuffer", GLES::NapiGLIsFramebuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glIsProgram", GLES::NapiGLIsProgram, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glIsRenderbuffer", GLES::NapiGLIsRenderbuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glIsShader", GLES::NapiGLIsShader, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glIsTexture", GLES::NapiGLIsTexture, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glLineWidth", GLES::NapiGLLineWidth, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glLinkProgram", GLES::NapiGLLinkProgram, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glPixelStorei", GLES::NapiGLPixelStorei, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glPolygonOffset", GLES::NapiGLPolygonOffset, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glReadPixels", GLES::NapiGLReadPixels, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glReleaseShaderCompiler", GLES::NapiGLReleaseShaderCompiler, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glRenderbufferStorage", GLES::NapiGLRenderbufferStorage, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glSampleCoverage", GLES::NapiGLSampleCoverage, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glScissor", GLES::NapiGLScissor, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glShaderBinary", GLES::NapiGLShaderBinary, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glShaderSource", GLES::NapiGLShaderSource, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glStencilFunc", GLES::NapiGLStencilFunc, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glStencilFuncSeparate", GLES::NapiGLStencilFuncSeparate, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glStencilMask", GLES::NapiGLStencilMask, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glStencilMaskSeparate", GLES::NapiGLStencilMaskSeparate, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glStencilOp", GLES::NapiGLStencilOp, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glStencilOpSeparate", GLES::NapiGLStencilOpSeparate, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glTexImage2D", GLES::NapiGLTexImage2D, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glTexParameterf", GLES::NapiGLTexParameterf, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glTexParameterfv", GLES::NapiGLTexParameterfv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glTexParameteri", GLES::NapiGLTexParameteri, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glTexParameteriv", GLES::NapiGLTexParameteriv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glTexSubImage2D", GLES::NapiGLTexSubImage2D, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform1f", GLES::NapiGLUniform1f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform1fv", GLES::NapiGLUniform1fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform1i", GLES::NapiGLUniform1i, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform1iv", GLES::NapiGLUniform1iv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform2f", GLES::NapiGLUniform2f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform2fv", GLES::NapiGLUniform2fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform2i", GLES::NapiGLUniform2i, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform2iv", GLES::NapiGLUniform2iv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform3f", GLES::NapiGLUniform3f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform3fv", GLES::NapiGLUniform3fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform3i", GLES::NapiGLUniform3i, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform3iv", GLES::NapiGLUniform3iv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform4f", GLES::NapiGLUniform4f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform4fv", GLES::NapiGLUniform4fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform4i", GLES::NapiGLUniform4i, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniform4iv", GLES::NapiGLUniform4iv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniformMatrix2fv", GLES::NapiGLUniformMatrix2fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniformMatrix3fv", GLES::NapiGLUniformMatrix3fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUniformMatrix4fv", GLES::NapiGLUniformMatrix4fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUseProgram", GLES::NapiGLUseProgram, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glValidateProgram", GLES::NapiGLValidateProgram, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib1f", GLES::NapiGLVertexAttrib1f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib1fv", GLES::NapiGLVertexAttrib1fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib2f", GLES::NapiGLVertexAttrib2f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib2fv", GLES::NapiGLVertexAttrib2fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib3f", GLES::NapiGLVertexAttrib3f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib3fv", GLES::NapiGLVertexAttrib3fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib4f", GLES::NapiGLVertexAttrib4f, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttrib4fv", GLES::NapiGLVertexAttrib4fv, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttribPointer", GLES::NapiGLVertexAttribPointer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glViewport", GLES::NapiGLViewport, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBindVertexArray", GLES::NapiGLBindVertexArray, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glBindVertexBuffer", GLES::NapiGLBindVertexBuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttribFormat", GLES::NapiGLVertexAttribFormat, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttribIFormat", GLES::NapiGLVertexAttribIFormat, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glVertexAttribBinding", GLES::NapiGLVertexAttribBinding, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glMapBufferRange", GLES::NapiGLMapBufferRange, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("glUnmapBuffer", GLES::NapiGLUnmapBuffer, nullptr, nullptr, nullptr),
        DEFINE_NAPI_FUNCTION("createShaderWithSource", GLESExtends::NapiCreateShaderWidthSource, nullptr, nullptr,
                             nullptr),
        DEFINE_NAPI_FUNCTION("glTexParameteriGroup", GLESExtends::NapiGLTexParameteriGroup, nullptr, nullptr, nullptr),

        /***
         * define constants
         */

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_BUFFER_BIT", 0x00000100),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BUFFER_BIT", 0x00000400),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_BUFFER_BIT", 0x00004000),

        DEFINE_NAPI_CONSTANTS("GL_FALSE", 0),

        DEFINE_NAPI_CONSTANTS("GL_TRUE", 1),

        DEFINE_NAPI_CONSTANTS("GL_POINTS", 0x0000),

        DEFINE_NAPI_CONSTANTS("GL_LINES", 0x0001),

        DEFINE_NAPI_CONSTANTS("GL_LINE_LOOP", 0x0002),

        DEFINE_NAPI_CONSTANTS("GL_LINE_STRIP", 0x0003),

        DEFINE_NAPI_CONSTANTS("GL_TRIANGLES", 0x0004),

        DEFINE_NAPI_CONSTANTS("GL_TRIANGLE_STRIP", 0x0005),

        DEFINE_NAPI_CONSTANTS("GL_TRIANGLE_FAN", 0x0006),

        DEFINE_NAPI_CONSTANTS("GL_ZERO", 0),

        DEFINE_NAPI_CONSTANTS("GL_ONE", 1),

        DEFINE_NAPI_CONSTANTS("GL_SRC_COLOR", 0x0300),

        DEFINE_NAPI_CONSTANTS("GL_ONE_MINUS_SRC_COLOR", 0x0301),

        DEFINE_NAPI_CONSTANTS("GL_SRC_ALPHA", 0x0302),

        DEFINE_NAPI_CONSTANTS("GL_ONE_MINUS_SRC_ALPHA", 0x0303),

        DEFINE_NAPI_CONSTANTS("GL_DST_ALPHA", 0x0304),

        DEFINE_NAPI_CONSTANTS("GL_ONE_MINUS_DST_ALPHA", 0x0305),

        DEFINE_NAPI_CONSTANTS("GL_DST_COLOR", 0x0306),

        DEFINE_NAPI_CONSTANTS("GL_ONE_MINUS_DST_COLOR", 0x0307),

        DEFINE_NAPI_CONSTANTS("GL_SRC_ALPHA_SATURATE", 0x0308),

        DEFINE_NAPI_CONSTANTS("GL_FUNC_ADD", 0x8006),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_EQUATION", 0x8009),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_EQUATION_RGB", 0x8009),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_EQUATION_ALPHA", 0x883D),

        DEFINE_NAPI_CONSTANTS("GL_FUNC_SUBTRACT", 0x800A),

        DEFINE_NAPI_CONSTANTS("GL_FUNC_REVERSE_SUBTRACT", 0x800B),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_DST_RGB", 0x80C8),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_SRC_RGB", 0x80C9),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_DST_ALPHA", 0x80CA),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_SRC_ALPHA", 0x80CB),

        DEFINE_NAPI_CONSTANTS("GL_CONSTANT_COLOR", 0x8001),

        DEFINE_NAPI_CONSTANTS("GL_ONE_MINUS_CONSTANT_COLOR", 0x8002),

        DEFINE_NAPI_CONSTANTS("GL_CONSTANT_ALPHA", 0x8003),

        DEFINE_NAPI_CONSTANTS("GL_ONE_MINUS_CONSTANT_ALPHA", 0x8004),

        DEFINE_NAPI_CONSTANTS("GL_BLEND_COLOR", 0x8005),

        DEFINE_NAPI_CONSTANTS("GL_ARRAY_BUFFER", 0x8892),

        DEFINE_NAPI_CONSTANTS("GL_ELEMENT_ARRAY_BUFFER", 0x8893),

        DEFINE_NAPI_CONSTANTS("GL_ARRAY_BUFFER_BINDING", 0x8894),

        DEFINE_NAPI_CONSTANTS("GL_ELEMENT_ARRAY_BUFFER_BINDING", 0x8895),

        DEFINE_NAPI_CONSTANTS("GL_STREAM_DRAW", 0x88E0),

        DEFINE_NAPI_CONSTANTS("GL_STATIC_DRAW", 0x88E4),

        DEFINE_NAPI_CONSTANTS("GL_DYNAMIC_DRAW", 0x88E8),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_SIZE", 0x8764),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_USAGE", 0x8765),

        DEFINE_NAPI_CONSTANTS("GL_CURRENT_VERTEX_ATTRIB", 0x8626),

        DEFINE_NAPI_CONSTANTS("GL_FRONT", 0x0404),

        DEFINE_NAPI_CONSTANTS("GL_BACK", 0x0405),

        DEFINE_NAPI_CONSTANTS("GL_FRONT_AND_BACK", 0x0408),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_2D", 0x0DE1),

        DEFINE_NAPI_CONSTANTS("GL_CULL_FACE", 0x0B44),

        DEFINE_NAPI_CONSTANTS("GL_BLEND", 0x0BE2),

        DEFINE_NAPI_CONSTANTS("GL_DITHER", 0x0BD0),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_TEST", 0x0B90),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_TEST", 0x0B71),

        DEFINE_NAPI_CONSTANTS("GL_SCISSOR_TEST", 0x0C11),

        DEFINE_NAPI_CONSTANTS("GL_POLYGON_OFFSET_FILL", 0x8037),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_ALPHA_TO_COVERAGE", 0x809E),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_COVERAGE", 0x80A0),

        DEFINE_NAPI_CONSTANTS("GL_NO_ERROR", 0),

        DEFINE_NAPI_CONSTANTS("GL_INVALID_ENUM", 0x0500),

        DEFINE_NAPI_CONSTANTS("GL_INVALID_VALUE", 0x0501),

        DEFINE_NAPI_CONSTANTS("GL_INVALID_OPERATION", 0x0502),

        DEFINE_NAPI_CONSTANTS("GL_OUT_OF_MEMORY", 0x0505),

        DEFINE_NAPI_CONSTANTS("GL_CW", 0x0900),

        DEFINE_NAPI_CONSTANTS("GL_CCW", 0x0901),

        DEFINE_NAPI_CONSTANTS("GL_LINE_WIDTH", 0x0B21),

        DEFINE_NAPI_CONSTANTS("GL_ALIASED_POINT_SIZE_RANGE", 0x846D),

        DEFINE_NAPI_CONSTANTS("GL_ALIASED_LINE_WIDTH_RANGE", 0x846E),

        DEFINE_NAPI_CONSTANTS("GL_CULL_FACE_MODE", 0x0B45),

        DEFINE_NAPI_CONSTANTS("GL_FRONT_FACE", 0x0B46),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_RANGE", 0x0B70),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_WRITEMASK", 0x0B72),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_CLEAR_VALUE", 0x0B73),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_FUNC", 0x0B74),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_CLEAR_VALUE", 0x0B91),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_FUNC", 0x0B92),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_FAIL", 0x0B94),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_PASS_DEPTH_FAIL", 0x0B95),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_PASS_DEPTH_PASS", 0x0B96),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_REF", 0x0B97),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_VALUE_MASK", 0x0B93),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_WRITEMASK", 0x0B98),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BACK_FUNC", 0x8800),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BACK_FAIL", 0x8801),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BACK_PASS_DEPTH_FAIL", 0x8802),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BACK_PASS_DEPTH_PASS", 0x8803),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BACK_REF", 0x8CA3),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BACK_VALUE_MASK", 0x8CA4),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BACK_WRITEMASK", 0x8CA5),

        DEFINE_NAPI_CONSTANTS("GL_VIEWPORT", 0x0BA2),

        DEFINE_NAPI_CONSTANTS("GL_SCISSOR_BOX", 0x0C10),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_CLEAR_VALUE", 0x0C22),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_WRITEMASK", 0x0C23),

        DEFINE_NAPI_CONSTANTS("GL_UNPACK_ALIGNMENT", 0x0CF5),

        DEFINE_NAPI_CONSTANTS("GL_PACK_ALIGNMENT", 0x0D05),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TEXTURE_SIZE", 0x0D33),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VIEWPORT_DIMS", 0x0D3A),

        DEFINE_NAPI_CONSTANTS("GL_SUBPIXEL_BITS", 0x0D50),

        DEFINE_NAPI_CONSTANTS("GL_RED_BITS", 0x0D52),

        DEFINE_NAPI_CONSTANTS("GL_GREEN_BITS", 0x0D53),

        DEFINE_NAPI_CONSTANTS("GL_BLUE_BITS", 0x0D54),

        DEFINE_NAPI_CONSTANTS("GL_ALPHA_BITS", 0x0D55),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_BITS", 0x0D56),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_BITS", 0x0D57),

        DEFINE_NAPI_CONSTANTS("GL_POLYGON_OFFSET_UNITS", 0x2A00),

        DEFINE_NAPI_CONSTANTS("GL_POLYGON_OFFSET_FACTOR", 0x8038),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_2D", 0x8069),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_BUFFERS", 0x80A8),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLES", 0x80A9),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_COVERAGE_VALUE", 0x80AA),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_COVERAGE_INVERT", 0x80AB),

        DEFINE_NAPI_CONSTANTS("GL_NUM_COMPRESSED_TEXTURE_FORMATS", 0x86A2),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_TEXTURE_FORMATS", 0x86A3),

        DEFINE_NAPI_CONSTANTS("GL_DONT_CARE", 0x1100),

        DEFINE_NAPI_CONSTANTS("GL_FASTEST", 0x1101),

        DEFINE_NAPI_CONSTANTS("GL_NICEST", 0x1102),

        DEFINE_NAPI_CONSTANTS("GL_GENERATE_MIPMAP_HINT", 0x8192),

        DEFINE_NAPI_CONSTANTS("GL_BYTE", 0x1400),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_BYTE", 0x1401),

        DEFINE_NAPI_CONSTANTS("GL_SHORT", 0x1402),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_SHORT", 0x1403),

        DEFINE_NAPI_CONSTANTS("GL_INT", 0x1404),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT", 0x1405),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT", 0x1406),

        DEFINE_NAPI_CONSTANTS("GL_FIXED", 0x140C),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_COMPONENT", 0x1902),

        DEFINE_NAPI_CONSTANTS("GL_ALPHA", 0x1906),

        DEFINE_NAPI_CONSTANTS("GL_RGB", 0x1907),

        DEFINE_NAPI_CONSTANTS("GL_RGBA", 0x1908),

        DEFINE_NAPI_CONSTANTS("GL_LUMINANCE", 0x1909),

        DEFINE_NAPI_CONSTANTS("GL_LUMINANCE_ALPHA", 0x190A),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_SHORT_4_4_4_4", 0x8033),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_SHORT_5_5_5_1", 0x8034),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_SHORT_5_6_5", 0x8363),

        DEFINE_NAPI_CONSTANTS("GL_FRAGMENT_SHADER", 0x8B30),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_SHADER", 0x8B31),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_ATTRIBS", 0x8869),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_UNIFORM_VECTORS", 0x8DFB),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VARYING_VECTORS", 0x8DFC),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS", 0x8B4D),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS", 0x8B4C),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TEXTURE_IMAGE_UNITS", 0x8872),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_UNIFORM_VECTORS", 0x8DFD),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_TYPE", 0x8B4F),

        DEFINE_NAPI_CONSTANTS("GL_DELETE_STATUS", 0x8B80),

        DEFINE_NAPI_CONSTANTS("GL_LINK_STATUS", 0x8B82),

        DEFINE_NAPI_CONSTANTS("GL_VALIDATE_STATUS", 0x8B83),

        DEFINE_NAPI_CONSTANTS("GL_ATTACHED_SHADERS", 0x8B85),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_UNIFORMS", 0x8B86),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_UNIFORM_MAX_LENGTH", 0x8B87),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_ATTRIBUTES", 0x8B89),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_ATTRIBUTE_MAX_LENGTH", 0x8B8A),

        DEFINE_NAPI_CONSTANTS("GL_SHADING_LANGUAGE_VERSION", 0x8B8C),

        DEFINE_NAPI_CONSTANTS("GL_CURRENT_PROGRAM", 0x8B8D),

        DEFINE_NAPI_CONSTANTS("GL_NEVER", 0x0200),

        DEFINE_NAPI_CONSTANTS("GL_LESS", 0x0201),

        DEFINE_NAPI_CONSTANTS("GL_EQUAL", 0x0202),

        DEFINE_NAPI_CONSTANTS("GL_LEQUAL", 0x0203),

        DEFINE_NAPI_CONSTANTS("GL_GREATER", 0x0204),

        DEFINE_NAPI_CONSTANTS("GL_NOTEQUAL", 0x0205),

        DEFINE_NAPI_CONSTANTS("GL_GEQUAL", 0x0206),

        DEFINE_NAPI_CONSTANTS("GL_ALWAYS", 0x0207),

        DEFINE_NAPI_CONSTANTS("GL_KEEP", 0x1E00),

        DEFINE_NAPI_CONSTANTS("GL_REPLACE", 0x1E01),

        DEFINE_NAPI_CONSTANTS("GL_INCR", 0x1E02),

        DEFINE_NAPI_CONSTANTS("GL_DECR", 0x1E03),

        DEFINE_NAPI_CONSTANTS("GL_INVERT", 0x150A),

        DEFINE_NAPI_CONSTANTS("GL_INCR_WRAP", 0x8507),

        DEFINE_NAPI_CONSTANTS("GL_DECR_WRAP", 0x8508),

        DEFINE_NAPI_CONSTANTS("GL_VENDOR", 0x1F00),

        DEFINE_NAPI_CONSTANTS("GL_RENDERER", 0x1F01),

        DEFINE_NAPI_CONSTANTS("GL_VERSION", 0x1F02),

        DEFINE_NAPI_CONSTANTS("GL_EXTENSIONS", 0x1F03),

        DEFINE_NAPI_CONSTANTS("GL_NEAREST", 0x2600),

        DEFINE_NAPI_CONSTANTS("GL_LINEAR", 0x2601),

        DEFINE_NAPI_CONSTANTS("GL_NEAREST_MIPMAP_NEAREST", 0x2700),

        DEFINE_NAPI_CONSTANTS("GL_LINEAR_MIPMAP_NEAREST", 0x2701),

        DEFINE_NAPI_CONSTANTS("GL_NEAREST_MIPMAP_LINEAR", 0x2702),

        DEFINE_NAPI_CONSTANTS("GL_LINEAR_MIPMAP_LINEAR", 0x2703),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_MAG_FILTER", 0x2800),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_MIN_FILTER", 0x2801),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_WRAP_S", 0x2802),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_WRAP_T", 0x2803),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE", 0x1702),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP", 0x8513),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_CUBE_MAP", 0x8514),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP_POSITIVE_X", 0x8515),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP_NEGATIVE_X", 0x8516),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP_POSITIVE_Y", 0x8517),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP_NEGATIVE_Y", 0x8518),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP_POSITIVE_Z", 0x8519),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP_NEGATIVE_Z", 0x851A),

        DEFINE_NAPI_CONSTANTS("GL_MAX_CUBE_MAP_TEXTURE_SIZE", 0x851C),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE0", 0x84C0),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE1", 0x84C1),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE2", 0x84C2),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE3", 0x84C3),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE4", 0x84C4),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE5", 0x84C5),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE6", 0x84C6),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE7", 0x84C7),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE8", 0x84C8),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE9", 0x84C9),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE10", 0x84CA),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE11", 0x84CB),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE12", 0x84CC),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE13", 0x84CD),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE14", 0x84CE),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE15", 0x84CF),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE16", 0x84D0),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE17", 0x84D1),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE18", 0x84D2),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE19", 0x84D3),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE20", 0x84D4),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE21", 0x84D5),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE22", 0x84D6),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE23", 0x84D7),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE24", 0x84D8),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE25", 0x84D9),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE26", 0x84DA),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE27", 0x84DB),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE28", 0x84DC),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE29", 0x84DD),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE30", 0x84DE),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE31", 0x84DF),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_TEXTURE", 0x84E0),

        DEFINE_NAPI_CONSTANTS("GL_REPEAT", 0x2901),

        DEFINE_NAPI_CONSTANTS("GL_CLAMP_TO_EDGE", 0x812F),

        DEFINE_NAPI_CONSTANTS("GL_MIRRORED_REPEAT", 0x8370),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_VEC2", 0x8B50),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_VEC3", 0x8B51),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_VEC4", 0x8B52),

        DEFINE_NAPI_CONSTANTS("GL_INT_VEC2", 0x8B53),

        DEFINE_NAPI_CONSTANTS("GL_INT_VEC3", 0x8B54),

        DEFINE_NAPI_CONSTANTS("GL_INT_VEC4", 0x8B55),

        DEFINE_NAPI_CONSTANTS("GL_BOOL", 0x8B56),

        DEFINE_NAPI_CONSTANTS("GL_BOOL_VEC2", 0x8B57),

        DEFINE_NAPI_CONSTANTS("GL_BOOL_VEC3", 0x8B58),

        DEFINE_NAPI_CONSTANTS("GL_BOOL_VEC4", 0x8B59),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT2", 0x8B5A),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT3", 0x8B5B),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT4", 0x8B5C),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_2D", 0x8B5E),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_CUBE", 0x8B60),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_ENABLED", 0x8622),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_SIZE", 0x8623),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_STRIDE", 0x8624),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_TYPE", 0x8625),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_NORMALIZED", 0x886A),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_POINTER", 0x8645),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING", 0x889F),

        DEFINE_NAPI_CONSTANTS("GL_IMPLEMENTATION_COLOR_READ_TYPE", 0x8B9A),

        DEFINE_NAPI_CONSTANTS("GL_IMPLEMENTATION_COLOR_READ_FORMAT", 0x8B9B),

        DEFINE_NAPI_CONSTANTS("GL_COMPILE_STATUS", 0x8B81),

        DEFINE_NAPI_CONSTANTS("GL_INFO_LOG_LENGTH", 0x8B84),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_SOURCE_LENGTH", 0x8B88),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_COMPILER", 0x8DFA),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_BINARY_FORMATS", 0x8DF8),

        DEFINE_NAPI_CONSTANTS("GL_NUM_SHADER_BINARY_FORMATS", 0x8DF9),

        DEFINE_NAPI_CONSTANTS("GL_LOW_FLOAT", 0x8DF0),

        DEFINE_NAPI_CONSTANTS("GL_MEDIUM_FLOAT", 0x8DF1),

        DEFINE_NAPI_CONSTANTS("GL_HIGH_FLOAT", 0x8DF2),

        DEFINE_NAPI_CONSTANTS("GL_LOW_INT", 0x8DF3),

        DEFINE_NAPI_CONSTANTS("GL_MEDIUM_INT", 0x8DF4),

        DEFINE_NAPI_CONSTANTS("GL_HIGH_INT", 0x8DF5),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER", 0x8D40),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER", 0x8D41),

        DEFINE_NAPI_CONSTANTS("GL_RGBA4", 0x8056),

        DEFINE_NAPI_CONSTANTS("GL_RGB5_A1", 0x8057),

        DEFINE_NAPI_CONSTANTS("GL_RGB565", 0x8D62),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_COMPONENT16", 0x81A5),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_INDEX8", 0x8D48),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_WIDTH", 0x8D42),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_HEIGHT", 0x8D43),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_INTERNAL_FORMAT", 0x8D44),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_RED_SIZE", 0x8D50),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_GREEN_SIZE", 0x8D51),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_BLUE_SIZE", 0x8D52),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_ALPHA_SIZE", 0x8D53),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_DEPTH_SIZE", 0x8D54),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_STENCIL_SIZE", 0x8D55),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", 0x8CD0),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME", 0x8CD1),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", 0x8CD2),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE", 0x8CD3),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT0", 0x8CE0),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_ATTACHMENT", 0x8D00),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_ATTACHMENT", 0x8D20),

        DEFINE_NAPI_CONSTANTS("GL_NONE", 0),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_COMPLETE", 0x8CD5),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT", 0x8CD6),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT", 0x8CD7),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS", 0x8CD9),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_UNSUPPORTED", 0x8CDD),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_BINDING", 0x8CA6),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_BINDING", 0x8CA7),

        DEFINE_NAPI_CONSTANTS("GL_MAX_RENDERBUFFER_SIZE", 0x84E8),

        DEFINE_NAPI_CONSTANTS("GL_INVALID_FRAMEBUFFER_OPERATION", 0x0506),

        DEFINE_NAPI_CONSTANTS("GL_READ_BUFFER", 0x0C02),

        DEFINE_NAPI_CONSTANTS("GL_UNPACK_ROW_LENGTH", 0x0CF2),

        DEFINE_NAPI_CONSTANTS("GL_UNPACK_SKIP_ROWS", 0x0CF3),

        DEFINE_NAPI_CONSTANTS("GL_UNPACK_SKIP_PIXELS", 0x0CF4),

        DEFINE_NAPI_CONSTANTS("GL_PACK_ROW_LENGTH", 0x0D02),

        DEFINE_NAPI_CONSTANTS("GL_PACK_SKIP_ROWS", 0x0D03),

        DEFINE_NAPI_CONSTANTS("GL_PACK_SKIP_PIXELS", 0x0D04),

        DEFINE_NAPI_CONSTANTS("GL_COLOR", 0x1800),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH", 0x1801),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL", 0x1802),

        DEFINE_NAPI_CONSTANTS("GL_RED", 0x1903),

        DEFINE_NAPI_CONSTANTS("GL_RGB8", 0x8051),

        DEFINE_NAPI_CONSTANTS("GL_RGBA8", 0x8058),

        DEFINE_NAPI_CONSTANTS("GL_RGB10_A2", 0x8059),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_3D", 0x806A),

        DEFINE_NAPI_CONSTANTS("GL_UNPACK_SKIP_IMAGES", 0x806D),

        DEFINE_NAPI_CONSTANTS("GL_UNPACK_IMAGE_HEIGHT", 0x806E),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_3D", 0x806F),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_WRAP_R", 0x8072),

        DEFINE_NAPI_CONSTANTS("GL_MAX_3D_TEXTURE_SIZE", 0x8073),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_2_10_10_10_REV", 0x8368),

        DEFINE_NAPI_CONSTANTS("GL_MAX_ELEMENTS_VERTICES", 0x80E8),

        DEFINE_NAPI_CONSTANTS("GL_MAX_ELEMENTS_INDICES", 0x80E9),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_MIN_LOD", 0x813A),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_MAX_LOD", 0x813B),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BASE_LEVEL", 0x813C),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_MAX_LEVEL", 0x813D),

        DEFINE_NAPI_CONSTANTS("GL_MIN", 0x8007),

        DEFINE_NAPI_CONSTANTS("GL_MAX", 0x8008),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_COMPONENT24", 0x81A6),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TEXTURE_LOD_BIAS", 0x84FD),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_COMPARE_MODE", 0x884C),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_COMPARE_FUNC", 0x884D),

        DEFINE_NAPI_CONSTANTS("GL_CURRENT_QUERY", 0x8865),

        DEFINE_NAPI_CONSTANTS("GL_QUERY_RESULT", 0x8866),

        DEFINE_NAPI_CONSTANTS("GL_QUERY_RESULT_AVAILABLE", 0x8867),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_MAPPED", 0x88BC),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_MAP_POINTER", 0x88BD),

        DEFINE_NAPI_CONSTANTS("GL_STREAM_READ", 0x88E1),

        DEFINE_NAPI_CONSTANTS("GL_STREAM_COPY", 0x88E2),

        DEFINE_NAPI_CONSTANTS("GL_STATIC_READ", 0x88E5),

        DEFINE_NAPI_CONSTANTS("GL_STATIC_COPY", 0x88E6),

        DEFINE_NAPI_CONSTANTS("GL_DYNAMIC_READ", 0x88E9),

        DEFINE_NAPI_CONSTANTS("GL_DYNAMIC_COPY", 0x88EA),

        DEFINE_NAPI_CONSTANTS("GL_MAX_DRAW_BUFFERS", 0x8824),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER0", 0x8825),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER1", 0x8826),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER2", 0x8827),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER3", 0x8828),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER4", 0x8829),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER5", 0x882A),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER6", 0x882B),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER7", 0x882C),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER8", 0x882D),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER9", 0x882E),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER10", 0x882F),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER11", 0x8830),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER12", 0x8831),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER13", 0x8832),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER14", 0x8833),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_BUFFER15", 0x8834),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_UNIFORM_COMPONENTS", 0x8B49),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_UNIFORM_COMPONENTS", 0x8B4A),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_3D", 0x8B5F),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_2D_SHADOW", 0x8B62),

        DEFINE_NAPI_CONSTANTS("GL_FRAGMENT_SHADER_DERIVATIVE_HINT", 0x8B8B),

        DEFINE_NAPI_CONSTANTS("GL_PIXEL_PACK_BUFFER", 0x88EB),

        DEFINE_NAPI_CONSTANTS("GL_PIXEL_UNPACK_BUFFER", 0x88EC),

        DEFINE_NAPI_CONSTANTS("GL_PIXEL_PACK_BUFFER_BINDING", 0x88ED),

        DEFINE_NAPI_CONSTANTS("GL_PIXEL_UNPACK_BUFFER_BINDING", 0x88EF),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT2x3", 0x8B65),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT2x4", 0x8B66),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT3x2", 0x8B67),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT3x4", 0x8B68),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT4x2", 0x8B69),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_MAT4x3", 0x8B6A),

        DEFINE_NAPI_CONSTANTS("GL_SRGB", 0x8C40),

        DEFINE_NAPI_CONSTANTS("GL_SRGB8", 0x8C41),

        DEFINE_NAPI_CONSTANTS("GL_SRGB8_ALPHA8", 0x8C43),

        DEFINE_NAPI_CONSTANTS("GL_COMPARE_REF_TO_TEXTURE", 0x884E),

        DEFINE_NAPI_CONSTANTS("GL_MAJOR_VERSION", 0x821B),

        DEFINE_NAPI_CONSTANTS("GL_MINOR_VERSION", 0x821C),

        DEFINE_NAPI_CONSTANTS("GL_NUM_EXTENSIONS", 0x821D),

        DEFINE_NAPI_CONSTANTS("GL_RGBA32F", 0x8814),

        DEFINE_NAPI_CONSTANTS("GL_RGB32F", 0x8815),

        DEFINE_NAPI_CONSTANTS("GL_RGBA16F", 0x881A),

        DEFINE_NAPI_CONSTANTS("GL_RGB16F", 0x881B),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_INTEGER", 0x88FD),

        DEFINE_NAPI_CONSTANTS("GL_MAX_ARRAY_TEXTURE_LAYERS", 0x88FF),

        DEFINE_NAPI_CONSTANTS("GL_MIN_PROGRAM_TEXEL_OFFSET", 0x8904),

        DEFINE_NAPI_CONSTANTS("GL_MAX_PROGRAM_TEXEL_OFFSET", 0x8905),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VARYING_COMPONENTS", 0x8B4B),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_2D_ARRAY", 0x8C1A),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_2D_ARRAY", 0x8C1D),

        DEFINE_NAPI_CONSTANTS("GL_R11F_G11F_B10F", 0x8C3A),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_10F_11F_11F_REV", 0x8C3B),

        DEFINE_NAPI_CONSTANTS("GL_RGB9_E5", 0x8C3D),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_5_9_9_9_REV", 0x8C3E),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH", 0x8C76),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_BUFFER_MODE", 0x8C7F),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS", 0x8C80),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_VARYINGS", 0x8C83),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_BUFFER_START", 0x8C84),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_BUFFER_SIZE", 0x8C85),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN", 0x8C88),

        DEFINE_NAPI_CONSTANTS("GL_RASTERIZER_DISCARD", 0x8C89),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS", 0x8C8A),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS", 0x8C8B),

        DEFINE_NAPI_CONSTANTS("GL_INTERLEAVED_ATTRIBS", 0x8C8C),

        DEFINE_NAPI_CONSTANTS("GL_SEPARATE_ATTRIBS", 0x8C8D),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_BUFFER", 0x8C8E),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_BUFFER_BINDING", 0x8C8F),

        DEFINE_NAPI_CONSTANTS("GL_RGBA32UI", 0x8D70),

        DEFINE_NAPI_CONSTANTS("GL_RGB32UI", 0x8D71),

        DEFINE_NAPI_CONSTANTS("GL_RGBA16UI", 0x8D76),

        DEFINE_NAPI_CONSTANTS("GL_RGB16UI", 0x8D77),

        DEFINE_NAPI_CONSTANTS("GL_RGBA8UI", 0x8D7C),

        DEFINE_NAPI_CONSTANTS("GL_RGB8UI", 0x8D7D),

        DEFINE_NAPI_CONSTANTS("GL_RGBA32I", 0x8D82),

        DEFINE_NAPI_CONSTANTS("GL_RGB32I", 0x8D83),

        DEFINE_NAPI_CONSTANTS("GL_RGBA16I", 0x8D88),

        DEFINE_NAPI_CONSTANTS("GL_RGB16I", 0x8D89),

        DEFINE_NAPI_CONSTANTS("GL_RGBA8I", 0x8D8E),

        DEFINE_NAPI_CONSTANTS("GL_RGB8I", 0x8D8F),

        DEFINE_NAPI_CONSTANTS("GL_RED_INTEGER", 0x8D94),

        DEFINE_NAPI_CONSTANTS("GL_RGB_INTEGER", 0x8D98),

        DEFINE_NAPI_CONSTANTS("GL_RGBA_INTEGER", 0x8D99),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_2D_ARRAY", 0x8DC1),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_2D_ARRAY_SHADOW", 0x8DC4),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_CUBE_SHADOW", 0x8DC5),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_VEC2", 0x8DC6),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_VEC3", 0x8DC7),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_VEC4", 0x8DC8),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_2D", 0x8DCA),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_3D", 0x8DCB),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_CUBE", 0x8DCC),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_2D_ARRAY", 0x8DCF),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_2D", 0x8DD2),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_3D", 0x8DD3),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_CUBE", 0x8DD4),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_2D_ARRAY", 0x8DD7),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_ACCESS_FLAGS", 0x911F),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_MAP_LENGTH", 0x9120),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_MAP_OFFSET", 0x9121),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_COMPONENT32F", 0x8CAC),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH32F_STENCIL8", 0x8CAD),

        DEFINE_NAPI_CONSTANTS("GL_FLOAT_32_UNSIGNED_INT_24_8_REV", 0x8DAD),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING", 0x8210),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE", 0x8211),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE", 0x8212),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE", 0x8213),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE", 0x8214),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE", 0x8215),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE", 0x8216),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE", 0x8217),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_DEFAULT", 0x8218),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_UNDEFINED", 0x8219),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_STENCIL_ATTACHMENT", 0x821A),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_STENCIL", 0x84F9),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_24_8", 0x84FA),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH24_STENCIL8", 0x88F0),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_NORMALIZED", 0x8C17),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_FRAMEBUFFER_BINDING", 0x8CA6),

        DEFINE_NAPI_CONSTANTS("GL_READ_FRAMEBUFFER", 0x8CA8),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_FRAMEBUFFER", 0x8CA9),

        DEFINE_NAPI_CONSTANTS("GL_READ_FRAMEBUFFER_BINDING", 0x8CAA),

        DEFINE_NAPI_CONSTANTS("GL_RENDERBUFFER_SAMPLES", 0x8CAB),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER", 0x8CD4),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COLOR_ATTACHMENTS", 0x8CDF),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT1", 0x8CE1),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT2", 0x8CE2),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT3", 0x8CE3),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT4", 0x8CE4),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT5", 0x8CE5),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT6", 0x8CE6),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT7", 0x8CE7),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT8", 0x8CE8),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT9", 0x8CE9),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT10", 0x8CEA),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT11", 0x8CEB),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT12", 0x8CEC),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT13", 0x8CED),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT14", 0x8CEE),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT15", 0x8CEF),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT16", 0x8CF0),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT17", 0x8CF1),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT18", 0x8CF2),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT19", 0x8CF3),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT20", 0x8CF4),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT21", 0x8CF5),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT22", 0x8CF6),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT23", 0x8CF7),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT24", 0x8CF8),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT25", 0x8CF9),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT26", 0x8CFA),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT27", 0x8CFB),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT28", 0x8CFC),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT29", 0x8CFD),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT30", 0x8CFE),

        DEFINE_NAPI_CONSTANTS("GL_COLOR_ATTACHMENT31", 0x8CFF),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE", 0x8D56),

        DEFINE_NAPI_CONSTANTS("GL_MAX_SAMPLES", 0x8D57),

        DEFINE_NAPI_CONSTANTS("GL_HALF_FLOAT", 0x140B),

        DEFINE_NAPI_CONSTANTS("GL_MAP_READ_BIT", 0x0001),

        DEFINE_NAPI_CONSTANTS("GL_MAP_WRITE_BIT", 0x0002),

        DEFINE_NAPI_CONSTANTS("GL_MAP_INVALIDATE_RANGE_BIT", 0x0004),

        DEFINE_NAPI_CONSTANTS("GL_MAP_INVALIDATE_BUFFER_BIT", 0x0008),

        DEFINE_NAPI_CONSTANTS("GL_MAP_FLUSH_EXPLICIT_BIT", 0x0010),

        DEFINE_NAPI_CONSTANTS("GL_MAP_UNSYNCHRONIZED_BIT", 0x0020),

        DEFINE_NAPI_CONSTANTS("GL_RG", 0x8227),

        DEFINE_NAPI_CONSTANTS("GL_RG_INTEGER", 0x8228),

        DEFINE_NAPI_CONSTANTS("GL_R8", 0x8229),

        DEFINE_NAPI_CONSTANTS("GL_RG8", 0x822B),

        DEFINE_NAPI_CONSTANTS("GL_R16F", 0x822D),

        DEFINE_NAPI_CONSTANTS("GL_R32F", 0x822E),

        DEFINE_NAPI_CONSTANTS("GL_RG16F", 0x822F),

        DEFINE_NAPI_CONSTANTS("GL_RG32F", 0x8230),

        DEFINE_NAPI_CONSTANTS("GL_R8I", 0x8231),

        DEFINE_NAPI_CONSTANTS("GL_R8UI", 0x8232),

        DEFINE_NAPI_CONSTANTS("GL_R16I", 0x8233),

        DEFINE_NAPI_CONSTANTS("GL_R16UI", 0x8234),

        DEFINE_NAPI_CONSTANTS("GL_R32I", 0x8235),

        DEFINE_NAPI_CONSTANTS("GL_R32UI", 0x8236),

        DEFINE_NAPI_CONSTANTS("GL_RG8I", 0x8237),

        DEFINE_NAPI_CONSTANTS("GL_RG8UI", 0x8238),

        DEFINE_NAPI_CONSTANTS("GL_RG16I", 0x8239),

        DEFINE_NAPI_CONSTANTS("GL_RG16UI", 0x823A),

        DEFINE_NAPI_CONSTANTS("GL_RG32I", 0x823B),

        DEFINE_NAPI_CONSTANTS("GL_RG32UI", 0x823C),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ARRAY_BINDING", 0x85B5),

        DEFINE_NAPI_CONSTANTS("GL_R8_SNORM", 0x8F94),

        DEFINE_NAPI_CONSTANTS("GL_RG8_SNORM", 0x8F95),

        DEFINE_NAPI_CONSTANTS("GL_RGB8_SNORM", 0x8F96),

        DEFINE_NAPI_CONSTANTS("GL_RGBA8_SNORM", 0x8F97),

        DEFINE_NAPI_CONSTANTS("GL_SIGNED_NORMALIZED", 0x8F9C),

        DEFINE_NAPI_CONSTANTS("GL_PRIMITIVE_RESTART_FIXED_INDEX", 0x8D69),

        DEFINE_NAPI_CONSTANTS("GL_COPY_READ_BUFFER", 0x8F36),

        DEFINE_NAPI_CONSTANTS("GL_COPY_WRITE_BUFFER", 0x8F37),

        DEFINE_NAPI_CONSTANTS("GL_COPY_READ_BUFFER_BINDING", 0x8F36),

        DEFINE_NAPI_CONSTANTS("GL_COPY_WRITE_BUFFER_BINDING", 0x8F37),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BUFFER", 0x8A11),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BUFFER_BINDING", 0x8A28),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BUFFER_START", 0x8A29),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BUFFER_SIZE", 0x8A2A),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_UNIFORM_BLOCKS", 0x8A2B),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_UNIFORM_BLOCKS", 0x8A2D),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_UNIFORM_BLOCKS", 0x8A2E),

        DEFINE_NAPI_CONSTANTS("GL_MAX_UNIFORM_BUFFER_BINDINGS", 0x8A2F),

        DEFINE_NAPI_CONSTANTS("GL_MAX_UNIFORM_BLOCK_SIZE", 0x8A30),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS", 0x8A31),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS", 0x8A33),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT", 0x8A34),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH", 0x8A35),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_UNIFORM_BLOCKS", 0x8A36),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_TYPE", 0x8A37),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_SIZE", 0x8A38),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_NAME_LENGTH", 0x8A39),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_INDEX", 0x8A3A),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_OFFSET", 0x8A3B),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_ARRAY_STRIDE", 0x8A3C),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_MATRIX_STRIDE", 0x8A3D),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_IS_ROW_MAJOR", 0x8A3E),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_BINDING", 0x8A3F),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_DATA_SIZE", 0x8A40),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_NAME_LENGTH", 0x8A41),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS", 0x8A42),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES", 0x8A43),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER", 0x8A44),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER", 0x8A46),

        DEFINE_NAPI_CONSTANTS("GL_INVALID_INDEX", 0xFFFFFFFF),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_OUTPUT_COMPONENTS", 0x9122),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_INPUT_COMPONENTS", 0x9125),

        DEFINE_NAPI_CONSTANTS("GL_MAX_SERVER_WAIT_TIMEOUT", 0x9111),

        DEFINE_NAPI_CONSTANTS("GL_OBJECT_TYPE", 0x9112),

        DEFINE_NAPI_CONSTANTS("GL_SYNC_CONDITION", 0x9113),

        DEFINE_NAPI_CONSTANTS("GL_SYNC_STATUS", 0x9114),

        DEFINE_NAPI_CONSTANTS("GL_SYNC_FLAGS", 0x9115),

        DEFINE_NAPI_CONSTANTS("GL_SYNC_FENCE", 0x9116),

        DEFINE_NAPI_CONSTANTS("GL_SYNC_GPU_COMMANDS_COMPLETE", 0x9117),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNALED", 0x9118),

        DEFINE_NAPI_CONSTANTS("GL_SIGNALED", 0x9119),

        DEFINE_NAPI_CONSTANTS("GL_ALREADY_SIGNALED", 0x911A),

        DEFINE_NAPI_CONSTANTS("GL_TIMEOUT_EXPIRED", 0x911B),

        DEFINE_NAPI_CONSTANTS("GL_CONDITION_SATISFIED", 0x911C),

        DEFINE_NAPI_CONSTANTS("GL_WAIT_FAILED", 0x911D),

        DEFINE_NAPI_CONSTANTS("GL_SYNC_FLUSH_COMMANDS_BIT", 0x00000001),

        DEFINE_NAPI_CONSTANTS("GL_TIMEOUT_IGNORED", -1),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_DIVISOR", 0x88FE),

        DEFINE_NAPI_CONSTANTS("GL_ANY_SAMPLES_PASSED", 0x8C2F),

        DEFINE_NAPI_CONSTANTS("GL_ANY_SAMPLES_PASSED_CONSERVATIVE", 0x8D6A),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_BINDING", 0x8919),

        DEFINE_NAPI_CONSTANTS("GL_RGB10_A2UI", 0x906F),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_SWIZZLE_R", 0x8E42),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_SWIZZLE_G", 0x8E43),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_SWIZZLE_B", 0x8E44),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_SWIZZLE_A", 0x8E45),

        DEFINE_NAPI_CONSTANTS("GL_GREEN", 0x1904),

        DEFINE_NAPI_CONSTANTS("GL_BLUE", 0x1905),

        DEFINE_NAPI_CONSTANTS("GL_INT_2_10_10_10_REV", 0x8D9F),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK", 0x8E22),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_PAUSED", 0x8E23),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_ACTIVE", 0x8E24),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_BINDING", 0x8E25),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_BINARY_RETRIEVABLE_HINT", 0x8257),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_BINARY_LENGTH", 0x8741),

        DEFINE_NAPI_CONSTANTS("GL_NUM_PROGRAM_BINARY_FORMATS", 0x87FE),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_BINARY_FORMATS", 0x87FF),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_R11_EAC", 0x9270),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SIGNED_R11_EAC", 0x9271),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RG11_EAC", 0x9272),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SIGNED_RG11_EAC", 0x9273),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGB8_ETC2", 0x9274),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ETC2", 0x9275),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2", 0x9276),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2", 0x9277),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA8_ETC2_EAC", 0x9278),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC", 0x9279),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_IMMUTABLE_FORMAT", 0x912F),

        DEFINE_NAPI_CONSTANTS("GL_MAX_ELEMENT_INDEX", 0x8D6B),

        DEFINE_NAPI_CONSTANTS("GL_NUM_SAMPLE_COUNTS", 0x9380),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_IMMUTABLE_LEVELS", 0x82DF),

        DEFINE_NAPI_CONSTANTS("GL_COMPUTE_SHADER", 0x91B9),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_UNIFORM_BLOCKS", 0x91BB),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS", 0x91BC),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_IMAGE_UNIFORMS", 0x91BD),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_SHARED_MEMORY_SIZE", 0x8262),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_UNIFORM_COMPONENTS", 0x8263),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS", 0x8264),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_ATOMIC_COUNTERS", 0x8265),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS", 0x8266),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS", 0x90EB),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_WORK_GROUP_COUNT", 0x91BE),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_WORK_GROUP_SIZE", 0x91BF),

        DEFINE_NAPI_CONSTANTS("GL_COMPUTE_WORK_GROUP_SIZE", 0x8267),

        DEFINE_NAPI_CONSTANTS("GL_DISPATCH_INDIRECT_BUFFER", 0x90EE),

        DEFINE_NAPI_CONSTANTS("GL_DISPATCH_INDIRECT_BUFFER_BINDING", 0x90EF),

        DEFINE_NAPI_CONSTANTS("GL_COMPUTE_SHADER_BIT", 0x00000020),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_INDIRECT_BUFFER", 0x8F3F),

        DEFINE_NAPI_CONSTANTS("GL_DRAW_INDIRECT_BUFFER_BINDING", 0x8F43),

        DEFINE_NAPI_CONSTANTS("GL_MAX_UNIFORM_LOCATIONS", 0x826E),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_DEFAULT_WIDTH", 0x9310),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_DEFAULT_HEIGHT", 0x9311),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_DEFAULT_SAMPLES", 0x9313),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS", 0x9314),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAMEBUFFER_WIDTH", 0x9315),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAMEBUFFER_HEIGHT", 0x9316),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAMEBUFFER_SAMPLES", 0x9318),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM", 0x92E1),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BLOCK", 0x92E2),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_INPUT", 0x92E3),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_OUTPUT", 0x92E4),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_VARIABLE", 0x92E5),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_STORAGE_BLOCK", 0x92E6),

        DEFINE_NAPI_CONSTANTS("GL_ATOMIC_COUNTER_BUFFER", 0x92C0),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_VARYING", 0x92F4),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_RESOURCES", 0x92F5),

        DEFINE_NAPI_CONSTANTS("GL_MAX_NAME_LENGTH", 0x92F6),

        DEFINE_NAPI_CONSTANTS("GL_MAX_NUM_ACTIVE_VARIABLES", 0x92F7),

        DEFINE_NAPI_CONSTANTS("GL_NAME_LENGTH", 0x92F9),

        DEFINE_NAPI_CONSTANTS("GL_TYPE", 0x92FA),

        DEFINE_NAPI_CONSTANTS("GL_ARRAY_SIZE", 0x92FB),

        DEFINE_NAPI_CONSTANTS("GL_OFFSET", 0x92FC),

        DEFINE_NAPI_CONSTANTS("GL_BLOCK_INDEX", 0x92FD),

        DEFINE_NAPI_CONSTANTS("GL_ARRAY_STRIDE", 0x92FE),

        DEFINE_NAPI_CONSTANTS("GL_MATRIX_STRIDE", 0x92FF),

        DEFINE_NAPI_CONSTANTS("GL_IS_ROW_MAJOR", 0x9300),

        DEFINE_NAPI_CONSTANTS("GL_ATOMIC_COUNTER_BUFFER_INDEX", 0x9301),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_BINDING", 0x9302),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_DATA_SIZE", 0x9303),

        DEFINE_NAPI_CONSTANTS("GL_NUM_ACTIVE_VARIABLES", 0x9304),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_VARIABLES", 0x9305),

        DEFINE_NAPI_CONSTANTS("GL_REFERENCED_BY_VERTEX_SHADER", 0x9306),

        DEFINE_NAPI_CONSTANTS("GL_REFERENCED_BY_FRAGMENT_SHADER", 0x930A),

        DEFINE_NAPI_CONSTANTS("GL_REFERENCED_BY_COMPUTE_SHADER", 0x930B),

        DEFINE_NAPI_CONSTANTS("GL_TOP_LEVEL_ARRAY_SIZE", 0x930C),

        DEFINE_NAPI_CONSTANTS("GL_TOP_LEVEL_ARRAY_STRIDE", 0x930D),

        DEFINE_NAPI_CONSTANTS("GL_LOCATION", 0x930E),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_SHADER_BIT", 0x00000001),

        DEFINE_NAPI_CONSTANTS("GL_FRAGMENT_SHADER_BIT", 0x00000002),

        DEFINE_NAPI_CONSTANTS("GL_ALL_SHADER_BITS", 0xFFFFFFFF),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_SEPARABLE", 0x8258),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_PROGRAM", 0x8259),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_PIPELINE_BINDING", 0x825A),

        DEFINE_NAPI_CONSTANTS("GL_ATOMIC_COUNTER_BUFFER_BINDING", 0x92C1),

        DEFINE_NAPI_CONSTANTS("GL_ATOMIC_COUNTER_BUFFER_START", 0x92C2),

        DEFINE_NAPI_CONSTANTS("GL_ATOMIC_COUNTER_BUFFER_SIZE", 0x92C3),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS", 0x92CC),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS", 0x92D0),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS", 0x92D1),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_ATOMIC_COUNTERS", 0x92D2),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_ATOMIC_COUNTERS", 0x92D6),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_ATOMIC_COUNTERS", 0x92D7),

        DEFINE_NAPI_CONSTANTS("GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE", 0x92D8),

        DEFINE_NAPI_CONSTANTS("GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS", 0x92DC),

        DEFINE_NAPI_CONSTANTS("GL_ACTIVE_ATOMIC_COUNTER_BUFFERS", 0x92D9),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_ATOMIC_COUNTER", 0x92DB),

        DEFINE_NAPI_CONSTANTS("GL_MAX_IMAGE_UNITS", 0x8F38),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_IMAGE_UNIFORMS", 0x90CA),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_IMAGE_UNIFORMS", 0x90CE),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_IMAGE_UNIFORMS", 0x90CF),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_BINDING_NAME", 0x8F3A),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_BINDING_LEVEL", 0x8F3B),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_BINDING_LAYERED", 0x8F3C),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_BINDING_LAYER", 0x8F3D),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_BINDING_ACCESS", 0x8F3E),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_BINDING_FORMAT", 0x906E),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT", 0x00000001),

        DEFINE_NAPI_CONSTANTS("GL_ELEMENT_ARRAY_BARRIER_BIT", 0x00000002),

        DEFINE_NAPI_CONSTANTS("GL_UNIFORM_BARRIER_BIT", 0x00000004),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_FETCH_BARRIER_BIT", 0x00000008),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_IMAGE_ACCESS_BARRIER_BIT", 0x00000020),

        DEFINE_NAPI_CONSTANTS("GL_COMMAND_BARRIER_BIT", 0x00000040),

        DEFINE_NAPI_CONSTANTS("GL_PIXEL_BUFFER_BARRIER_BIT", 0x00000080),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_UPDATE_BARRIER_BIT", 0x00000100),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER_UPDATE_BARRIER_BIT", 0x00000200),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_BARRIER_BIT", 0x00000400),

        DEFINE_NAPI_CONSTANTS("GL_TRANSFORM_FEEDBACK_BARRIER_BIT", 0x00000800),

        DEFINE_NAPI_CONSTANTS("GL_ATOMIC_COUNTER_BARRIER_BIT", 0x00001000),

        DEFINE_NAPI_CONSTANTS("GL_ALL_BARRIER_BITS", 0xFFFFFFFF),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_2D", 0x904D),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_3D", 0x904E),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_CUBE", 0x9050),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_2D_ARRAY", 0x9053),

        DEFINE_NAPI_CONSTANTS("GL_INT_IMAGE_2D", 0x9058),

        DEFINE_NAPI_CONSTANTS("GL_INT_IMAGE_3D", 0x9059),

        DEFINE_NAPI_CONSTANTS("GL_INT_IMAGE_CUBE", 0x905B),

        DEFINE_NAPI_CONSTANTS("GL_INT_IMAGE_2D_ARRAY", 0x905E),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_IMAGE_2D", 0x9063),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_IMAGE_3D", 0x9064),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_IMAGE_CUBE", 0x9066),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_IMAGE_2D_ARRAY", 0x9069),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_FORMAT_COMPATIBILITY_TYPE", 0x90C7),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE", 0x90C8),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS", 0x90C9),

        DEFINE_NAPI_CONSTANTS("GL_READ_ONLY", 0x88B8),

        DEFINE_NAPI_CONSTANTS("GL_WRITE_ONLY", 0x88B9),

        DEFINE_NAPI_CONSTANTS("GL_READ_WRITE", 0x88BA),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_STORAGE_BUFFER", 0x90D2),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_STORAGE_BUFFER_BINDING", 0x90D3),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_STORAGE_BUFFER_START", 0x90D4),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_STORAGE_BUFFER_SIZE", 0x90D5),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS", 0x90D6),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS", 0x90DA),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS", 0x90DB),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS", 0x90DC),

        DEFINE_NAPI_CONSTANTS("GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS", 0x90DD),

        DEFINE_NAPI_CONSTANTS("GL_MAX_SHADER_STORAGE_BLOCK_SIZE", 0x90DE),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT", 0x90DF),

        DEFINE_NAPI_CONSTANTS("GL_SHADER_STORAGE_BARRIER_BIT", 0x00002000),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES", 0x8F39),

        DEFINE_NAPI_CONSTANTS("GL_DEPTH_STENCIL_TEXTURE_MODE", 0x90EA),

        DEFINE_NAPI_CONSTANTS("GL_STENCIL_INDEX", 0x1901),

        DEFINE_NAPI_CONSTANTS("GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET", 0x8E5E),

        DEFINE_NAPI_CONSTANTS("GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET", 0x8E5F),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_POSITION", 0x8E50),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_MASK", 0x8E51),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_MASK_VALUE", 0x8E52),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_2D_MULTISAMPLE", 0x9100),

        DEFINE_NAPI_CONSTANTS("GL_MAX_SAMPLE_MASK_WORDS", 0x8E59),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COLOR_TEXTURE_SAMPLES", 0x910E),

        DEFINE_NAPI_CONSTANTS("GL_MAX_DEPTH_TEXTURE_SAMPLES", 0x910F),

        DEFINE_NAPI_CONSTANTS("GL_MAX_INTEGER_SAMPLES", 0x9110),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_2D_MULTISAMPLE", 0x9104),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_SAMPLES", 0x9106),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_FIXED_SAMPLE_LOCATIONS", 0x9107),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_WIDTH", 0x1000),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_HEIGHT", 0x1001),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_DEPTH", 0x8071),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_INTERNAL_FORMAT", 0x1003),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_RED_SIZE", 0x805C),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_GREEN_SIZE", 0x805D),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BLUE_SIZE", 0x805E),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_ALPHA_SIZE", 0x805F),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_DEPTH_SIZE", 0x884A),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_STENCIL_SIZE", 0x88F1),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_SHARED_SIZE", 0x8C3F),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_RED_TYPE", 0x8C10),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_GREEN_TYPE", 0x8C11),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BLUE_TYPE", 0x8C12),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_ALPHA_TYPE", 0x8C13),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_DEPTH_TYPE", 0x8C16),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_COMPRESSED", 0x86A1),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_2D_MULTISAMPLE", 0x9108),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_2D_MULTISAMPLE", 0x9109),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE", 0x910A),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_BINDING", 0x82D4),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ATTRIB_RELATIVE_OFFSET", 0x82D5),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_BINDING_DIVISOR", 0x82D6),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_BINDING_OFFSET", 0x82D7),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_BINDING_STRIDE", 0x82D8),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_BINDING_BUFFER", 0x8F4F),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET", 0x82D9),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_ATTRIB_BINDINGS", 0x82DA),

        DEFINE_NAPI_CONSTANTS("GL_MAX_VERTEX_ATTRIB_STRIDE", 0x82E5),

        DEFINE_NAPI_CONSTANTS("GL_MULTISAMPLE_LINE_WIDTH_RANGE", 0x9381),

        DEFINE_NAPI_CONSTANTS("GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY", 0x9382),

        DEFINE_NAPI_CONSTANTS("GL_MULTIPLY", 0x9294),

        DEFINE_NAPI_CONSTANTS("GL_SCREEN", 0x9295),

        DEFINE_NAPI_CONSTANTS("GL_OVERLAY", 0x9296),

        DEFINE_NAPI_CONSTANTS("GL_DARKEN", 0x9297),

        DEFINE_NAPI_CONSTANTS("GL_LIGHTEN", 0x9298),

        DEFINE_NAPI_CONSTANTS("GL_COLORDODGE", 0x9299),

        DEFINE_NAPI_CONSTANTS("GL_COLORBURN", 0x929A),

        DEFINE_NAPI_CONSTANTS("GL_HARDLIGHT", 0x929B),

        DEFINE_NAPI_CONSTANTS("GL_SOFTLIGHT", 0x929C),

        DEFINE_NAPI_CONSTANTS("GL_DIFFERENCE", 0x929E),

        DEFINE_NAPI_CONSTANTS("GL_EXCLUSION", 0x92A0),

        DEFINE_NAPI_CONSTANTS("GL_HSL_HUE", 0x92AD),

        DEFINE_NAPI_CONSTANTS("GL_HSL_SATURATION", 0x92AE),

        DEFINE_NAPI_CONSTANTS("GL_HSL_COLOR", 0x92AF),

        DEFINE_NAPI_CONSTANTS("GL_HSL_LUMINOSITY", 0x92B0),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_OUTPUT_SYNCHRONOUS", 0x8242),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH", 0x8243),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_CALLBACK_FUNCTION", 0x8244),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_CALLBACK_USER_PARAM", 0x8245),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SOURCE_API", 0x8246),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SOURCE_WINDOW_SYSTEM", 0x8247),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SOURCE_SHADER_COMPILER", 0x8248),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SOURCE_THIRD_PARTY", 0x8249),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SOURCE_APPLICATION", 0x824A),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SOURCE_OTHER", 0x824B),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_ERROR", 0x824C),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR", 0x824D),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR", 0x824E),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_PORTABILITY", 0x824F),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_PERFORMANCE", 0x8250),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_OTHER", 0x8251),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_MARKER", 0x8268),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_PUSH_GROUP", 0x8269),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_TYPE_POP_GROUP", 0x826A),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SEVERITY_NOTIFICATION", 0x826B),

        DEFINE_NAPI_CONSTANTS("GL_MAX_DEBUG_GROUP_STACK_DEPTH", 0x826C),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_GROUP_STACK_DEPTH", 0x826D),

        DEFINE_NAPI_CONSTANTS("GL_BUFFER", 0x82E0),

        DEFINE_NAPI_CONSTANTS("GL_SHADER", 0x82E1),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM", 0x82E2),

        DEFINE_NAPI_CONSTANTS("GL_VERTEX_ARRAY", 0x8074),

        DEFINE_NAPI_CONSTANTS("GL_QUERY", 0x82E3),

        DEFINE_NAPI_CONSTANTS("GL_PROGRAM_PIPELINE", 0x82E4),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER", 0x82E6),

        DEFINE_NAPI_CONSTANTS("GL_MAX_LABEL_LENGTH", 0x82E8),

        DEFINE_NAPI_CONSTANTS("GL_MAX_DEBUG_MESSAGE_LENGTH", 0x9143),

        DEFINE_NAPI_CONSTANTS("GL_MAX_DEBUG_LOGGED_MESSAGES", 0x9144),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_LOGGED_MESSAGES", 0x9145),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SEVERITY_HIGH", 0x9146),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SEVERITY_MEDIUM", 0x9147),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_SEVERITY_LOW", 0x9148),

        DEFINE_NAPI_CONSTANTS("GL_DEBUG_OUTPUT", 0x92E0),

        DEFINE_NAPI_CONSTANTS("GL_CONTEXT_FLAG_DEBUG_BIT", 0x00000002),

        DEFINE_NAPI_CONSTANTS("GL_STACK_OVERFLOW", 0x0503),

        DEFINE_NAPI_CONSTANTS("GL_STACK_UNDERFLOW", 0x0504),

        DEFINE_NAPI_CONSTANTS("GL_GEOMETRY_SHADER", 0x8DD9),

        DEFINE_NAPI_CONSTANTS("GL_GEOMETRY_SHADER_BIT", 0x00000004),

        DEFINE_NAPI_CONSTANTS("GL_GEOMETRY_VERTICES_OUT", 0x8916),

        DEFINE_NAPI_CONSTANTS("GL_GEOMETRY_INPUT_TYPE", 0x8917),

        DEFINE_NAPI_CONSTANTS("GL_GEOMETRY_OUTPUT_TYPE", 0x8918),

        DEFINE_NAPI_CONSTANTS("GL_GEOMETRY_SHADER_INVOCATIONS", 0x887F),

        DEFINE_NAPI_CONSTANTS("GL_LAYER_PROVOKING_VERTEX", 0x825E),

        DEFINE_NAPI_CONSTANTS("GL_LINES_ADJACENCY", 0x000A),

        DEFINE_NAPI_CONSTANTS("GL_LINE_STRIP_ADJACENCY", 0x000B),

        DEFINE_NAPI_CONSTANTS("GL_TRIANGLES_ADJACENCY", 0x000C),

        DEFINE_NAPI_CONSTANTS("GL_TRIANGLE_STRIP_ADJACENCY", 0x000D),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_UNIFORM_COMPONENTS", 0x8DDF),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_UNIFORM_BLOCKS", 0x8A2C),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS", 0x8A32),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_INPUT_COMPONENTS", 0x9123),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_OUTPUT_COMPONENTS", 0x9124),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_OUTPUT_VERTICES", 0x8DE0),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS", 0x8DE1),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_SHADER_INVOCATIONS", 0x8E5A),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS", 0x8C29),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS", 0x92CF),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_ATOMIC_COUNTERS", 0x92D5),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_IMAGE_UNIFORMS", 0x90CD),

        DEFINE_NAPI_CONSTANTS("GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS", 0x90D7),

        DEFINE_NAPI_CONSTANTS("GL_FIRST_VERTEX_CONVENTION", 0x8E4D),

        DEFINE_NAPI_CONSTANTS("GL_LAST_VERTEX_CONVENTION", 0x8E4E),

        DEFINE_NAPI_CONSTANTS("GL_UNDEFINED_VERTEX", 0x8260),

        DEFINE_NAPI_CONSTANTS("GL_PRIMITIVES_GENERATED", 0x8C87),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_DEFAULT_LAYERS", 0x9312),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAMEBUFFER_LAYERS", 0x9317),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS", 0x8DA8),

        DEFINE_NAPI_CONSTANTS("GL_FRAMEBUFFER_ATTACHMENT_LAYERED", 0x8DA7),

        DEFINE_NAPI_CONSTANTS("GL_REFERENCED_BY_GEOMETRY_SHADER", 0x9309),

        DEFINE_NAPI_CONSTANTS("GL_PRIMITIVE_BOUNDING_BOX", 0x92BE),

        DEFINE_NAPI_CONSTANTS("GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT", 0x00000004),

        DEFINE_NAPI_CONSTANTS("GL_CONTEXT_FLAGS", 0x821E),

        DEFINE_NAPI_CONSTANTS("GL_LOSE_CONTEXT_ON_RESET", 0x8252),

        DEFINE_NAPI_CONSTANTS("GL_GUILTY_CONTEXT_RESET", 0x8253),

        DEFINE_NAPI_CONSTANTS("GL_INNOCENT_CONTEXT_RESET", 0x8254),

        DEFINE_NAPI_CONSTANTS("GL_UNKNOWN_CONTEXT_RESET", 0x8255),

        DEFINE_NAPI_CONSTANTS("GL_RESET_NOTIFICATION_STRATEGY", 0x8256),

        DEFINE_NAPI_CONSTANTS("GL_NO_RESET_NOTIFICATION", 0x8261),

        DEFINE_NAPI_CONSTANTS("GL_CONTEXT_LOST", 0x0507),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLE_SHADING", 0x8C36),

        DEFINE_NAPI_CONSTANTS("GL_MIN_SAMPLE_SHADING_VALUE", 0x8C37),

        DEFINE_NAPI_CONSTANTS("GL_MIN_FRAGMENT_INTERPOLATION_OFFSET", 0x8E5B),

        DEFINE_NAPI_CONSTANTS("GL_MAX_FRAGMENT_INTERPOLATION_OFFSET", 0x8E5C),

        DEFINE_NAPI_CONSTANTS("GL_FRAGMENT_INTERPOLATION_OFFSET_BITS", 0x8E5D),

        DEFINE_NAPI_CONSTANTS("GL_PATCHES", 0x000E),

        DEFINE_NAPI_CONSTANTS("GL_PATCH_VERTICES", 0x8E72),

        DEFINE_NAPI_CONSTANTS("GL_TESS_CONTROL_OUTPUT_VERTICES", 0x8E75),

        DEFINE_NAPI_CONSTANTS("GL_TESS_GEN_MODE", 0x8E76),

        DEFINE_NAPI_CONSTANTS("GL_TESS_GEN_SPACING", 0x8E77),

        DEFINE_NAPI_CONSTANTS("GL_TESS_GEN_VERTEX_ORDER", 0x8E78),

        DEFINE_NAPI_CONSTANTS("GL_TESS_GEN_POINT_MODE", 0x8E79),

        DEFINE_NAPI_CONSTANTS("GL_ISOLINES", 0x8E7A),

        DEFINE_NAPI_CONSTANTS("GL_QUADS", 0x0007),

        DEFINE_NAPI_CONSTANTS("GL_FRACTIONAL_ODD", 0x8E7B),

        DEFINE_NAPI_CONSTANTS("GL_FRACTIONAL_EVEN", 0x8E7C),

        DEFINE_NAPI_CONSTANTS("GL_MAX_PATCH_VERTICES", 0x8E7D),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_GEN_LEVEL", 0x8E7E),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS", 0x8E7F),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS", 0x8E80),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS", 0x8E81),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS", 0x8E82),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS", 0x8E83),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_PATCH_COMPONENTS", 0x8E84),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS", 0x8E85),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS", 0x8E86),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS", 0x8E89),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS", 0x8E8A),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_INPUT_COMPONENTS", 0x886C),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS", 0x886D),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS", 0x8E1E),

        DEFINE_NAPI_CONSTANTS("GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS", 0x8E1F),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS", 0x92CD),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS", 0x92CE),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS", 0x92D3),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS", 0x92D4),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS", 0x90CB),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS", 0x90CC),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS", 0x90D8),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS", 0x90D9),

        DEFINE_NAPI_CONSTANTS("GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED", 0x8221),

        DEFINE_NAPI_CONSTANTS("GL_IS_PER_PATCH", 0x92E7),

        DEFINE_NAPI_CONSTANTS("GL_REFERENCED_BY_TESS_CONTROL_SHADER", 0x9307),

        DEFINE_NAPI_CONSTANTS("GL_REFERENCED_BY_TESS_EVALUATION_SHADER", 0x9308),

        DEFINE_NAPI_CONSTANTS("GL_TESS_CONTROL_SHADER", 0x8E88),

        DEFINE_NAPI_CONSTANTS("GL_TESS_EVALUATION_SHADER", 0x8E87),

        DEFINE_NAPI_CONSTANTS("GL_TESS_CONTROL_SHADER_BIT", 0x00000008),

        DEFINE_NAPI_CONSTANTS("GL_TESS_EVALUATION_SHADER_BIT", 0x00000010),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BORDER_COLOR", 0x1004),

        DEFINE_NAPI_CONSTANTS("GL_CLAMP_TO_BORDER", 0x812D),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BUFFER", 0x8C2A),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BUFFER_BINDING", 0x8C2A),

        DEFINE_NAPI_CONSTANTS("GL_MAX_TEXTURE_BUFFER_SIZE", 0x8C2B),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_BUFFER", 0x8C2C),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BUFFER_DATA_STORE_BINDING", 0x8C2D),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT", 0x919F),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_BUFFER", 0x8DC2),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_BUFFER", 0x8DD0),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_BUFFER", 0x8DD8),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_BUFFER", 0x9051),

        DEFINE_NAPI_CONSTANTS("GL_INT_IMAGE_BUFFER", 0x905C),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_IMAGE_BUFFER", 0x9067),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BUFFER_OFFSET", 0x919D),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BUFFER_SIZE", 0x919E),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_4x4", 0x93B0),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_5x4", 0x93B1),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_5x5", 0x93B2),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_6x5", 0x93B3),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_6x6", 0x93B4),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_8x5", 0x93B5),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_8x6", 0x93B6),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_8x8", 0x93B7),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_10x5", 0x93B8),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_10x6", 0x93B9),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_10x8", 0x93BA),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_10x10", 0x93BB),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_12x10", 0x93BC),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_RGBA_ASTC_12x12", 0x93BD),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4", 0x93D0),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4", 0x93D1),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5", 0x93D2),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5", 0x93D3),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6", 0x93D4),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5", 0x93D5),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6", 0x93D6),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8", 0x93D7),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5", 0x93D8),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6", 0x93D9),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8", 0x93DA),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10", 0x93DB),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10", 0x93DC),

        DEFINE_NAPI_CONSTANTS("GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12", 0x93DD),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_CUBE_MAP_ARRAY", 0x9009),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_CUBE_MAP_ARRAY", 0x900A),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_CUBE_MAP_ARRAY", 0x900C),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW", 0x900D),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_CUBE_MAP_ARRAY", 0x900E),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY", 0x900F),

        DEFINE_NAPI_CONSTANTS("GL_IMAGE_CUBE_MAP_ARRAY", 0x9054),

        DEFINE_NAPI_CONSTANTS("GL_INT_IMAGE_CUBE_MAP_ARRAY", 0x905F),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY", 0x906A),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_2D_MULTISAMPLE_ARRAY", 0x9102),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY", 0x9105),

        DEFINE_NAPI_CONSTANTS("GL_SAMPLER_2D_MULTISAMPLE_ARRAY", 0x910B),

        DEFINE_NAPI_CONSTANTS("GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY", 0x910C),

        DEFINE_NAPI_CONSTANTS("GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY", 0x910D),

        DEFINE_NAPI_CONSTANTS("GL_TEXTURE_EXTERNAL_OES", 0x8D65),

        /**
         * define enum
         */

        DEFINE_NAPI_STATIC_VALUE("BlendingFactors",
                                 createEnum(env,
                                            {
                                                {"GL_ZERO", GL_ZERO},
                                                {"GL_ONE", GL_ONE},
                                                {"GL_SRC_COLOR", GL_SRC_COLOR},
                                                {"GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR},
                                                {"GL_DST_COLOR", GL_DST_COLOR},
                                                {"GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR},
                                                {"GL_SRC_ALPHA", GL_SRC_ALPHA},
                                                {"GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA},
                                                {"GL_DST_ALPHA", GL_DST_ALPHA},
                                                {"GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA},
                                                {"GL_CONSTANT_COLOR", GL_CONSTANT_COLOR},
                                                {"GL_ONE_MINUS_CONSTANT_COLOR", GL_ONE_MINUS_CONSTANT_COLOR},
                                                {"GL_CONSTANT_ALPHA", GL_CONSTANT_ALPHA},
                                                {"GL_ONE_MINUS_CONSTANT_ALPHA", GL_ONE_MINUS_CONSTANT_ALPHA},
                                                {"GL_SRC_ALPHA_SATURATE", GL_SRC_ALPHA_SATURATE},
                                            })),

        DEFINE_NAPI_STATIC_VALUE("BlendMode", createEnum(env,
                                                         {
                                                             {"GL_FUNC_ADD", GL_FUNC_ADD},
                                                             {"GL_FUNC_SUBTRACT", GL_FUNC_SUBTRACT},
                                                             {"GL_FUNC_REVERSE_SUBTRACT", GL_FUNC_REVERSE_SUBTRACT},
                                                             {"GL_MIN", GL_MIN},
                                                             {"GL_MAX", GL_MAX},
                                                         })),

        DEFINE_NAPI_STATIC_VALUE("BufferAccessMode", createEnum(env,
                                                                {
                                                                    {"GL_READ_ONLY", GL_READ_ONLY},
                                                                    {"GL_WRITE_ONLY", GL_WRITE_ONLY},
                                                                    {"GL_READ_WRITE", GL_READ_WRITE},
                                                                })),

        DEFINE_NAPI_STATIC_VALUE("BufferParamName", createEnum(env,
                                                               {
                                                                   {"GL_BUFFER_ACCESS_FLAGS", GL_BUFFER_ACCESS_FLAGS},
                                                                   {"GL_BUFFER_MAPPED", GL_BUFFER_MAPPED},
                                                                   {"GL_BUFFER_MAP_LENGTH", GL_BUFFER_MAP_LENGTH},
                                                                   {"GL_BUFFER_MAP_OFFSET", GL_BUFFER_MAP_OFFSET},
                                                                   {"GL_BUFFER_SIZE", GL_BUFFER_SIZE},
                                                                   {"GL_BUFFER_USAGE", GL_BUFFER_USAGE},
                                                               })),

        DEFINE_NAPI_STATIC_VALUE("BufferType",
                                 createEnum(env,
                                            {
                                                {"GL_ARRAY_BUFFER", GL_ARRAY_BUFFER},
                                                {"GL_ATOMIC_COUNTER_BUFFER", GL_ATOMIC_COUNTER_BUFFER},
                                                {"GL_COPY_READ_BUFFER", GL_COPY_READ_BUFFER},
                                                {"GL_COPY_WRITE_BUFFER", GL_COPY_WRITE_BUFFER},
                                                {"GL_DISPATCH_INDIRECT_BUFFER", GL_DISPATCH_INDIRECT_BUFFER},
                                                {"GL_DRAW_INDIRECT_BUFFER", GL_DRAW_INDIRECT_BUFFER},
                                                {"GL_ELEMENT_ARRAY_BUFFER", GL_ELEMENT_ARRAY_BUFFER},
                                                {"GL_PIXEL_PACK_BUFFER", GL_PIXEL_PACK_BUFFER},
                                                {"GL_PIXEL_UNPACK_BUFFER", GL_PIXEL_UNPACK_BUFFER},
                                                {"GL_SHADER_STORAGE_BUFFER", GL_SHADER_STORAGE_BUFFER},
                                                {"GL_TEXTURE_BUFFER", GL_TEXTURE_BUFFER},
                                                {"GL_TRANSFORM_FEEDBACK_BUFFER", GL_TRANSFORM_FEEDBACK_BUFFER},
                                                {"GL_UNIFORM_BUFFER", GL_UNIFORM_BUFFER},
                                            })),

        DEFINE_NAPI_STATIC_VALUE("BufferUsage", createEnum(env,
                                                           {
                                                               {"GL_STREAM_DRAW", GL_STREAM_DRAW},
                                                               {"GL_STREAM_READ", GL_STREAM_READ},
                                                               {"GL_STREAM_COPY", GL_STREAM_COPY},
                                                               {"GL_STATIC_DRAW", GL_STATIC_DRAW},
                                                               {"GL_STATIC_READ", GL_STATIC_READ},
                                                               {"GL_STATIC_COPY", GL_STATIC_COPY},
                                                               {"GL_DYNAMIC_DRAW", GL_DYNAMIC_DRAW},
                                                               {"GL_DYNAMIC_READ", GL_DYNAMIC_READ},
                                                               {"GL_DYNAMIC_COPY", GL_DYNAMIC_COPY},
                                                           })),

        DEFINE_NAPI_STATIC_VALUE(
            "CompressedInternalFormat",
            createEnum(
                env,
                {
                    {"GL_COMPRESSED_R11_EAC", GL_COMPRESSED_R11_EAC},
                    {"GL_COMPRESSED_SIGNED_R11_EAC", GL_COMPRESSED_SIGNED_R11_EAC},
                    {"GL_COMPRESSED_RG11_EAC", GL_COMPRESSED_RG11_EAC},
                    {"GL_COMPRESSED_SIGNED_RG11_EAC", GL_COMPRESSED_SIGNED_RG11_EAC},
                    {"GL_COMPRESSED_RGB8_ETC2", GL_COMPRESSED_RGB8_ETC2},
                    {"GL_COMPRESSED_SRGB8_ETC2", GL_COMPRESSED_SRGB8_ETC2},
                    {"GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2", GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2},
                    {"GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2", GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2},
                    {"GL_COMPRESSED_RGBA8_ETC2_EAC", GL_COMPRESSED_RGBA8_ETC2_EAC},
                    {"GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC", GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC},
                    {"GL_COMPRESSED_RGBA_ASTC_4x4", GL_COMPRESSED_RGBA_ASTC_4x4},
                    {"GL_COMPRESSED_RGBA_ASTC_5x4", GL_COMPRESSED_RGBA_ASTC_5x4},
                    {"GL_COMPRESSED_RGBA_ASTC_5x5", GL_COMPRESSED_RGBA_ASTC_5x5},
                    {"GL_COMPRESSED_RGBA_ASTC_6x5", GL_COMPRESSED_RGBA_ASTC_6x5},
                    {"GL_COMPRESSED_RGBA_ASTC_6x6", GL_COMPRESSED_RGBA_ASTC_6x6},
                    {"GL_COMPRESSED_RGBA_ASTC_8x5", GL_COMPRESSED_RGBA_ASTC_8x5},
                    {"GL_COMPRESSED_RGBA_ASTC_8x6", GL_COMPRESSED_RGBA_ASTC_8x6},
                    {"GL_COMPRESSED_RGBA_ASTC_8x8", GL_COMPRESSED_RGBA_ASTC_8x8},
                    {"GL_COMPRESSED_RGBA_ASTC_10x5", GL_COMPRESSED_RGBA_ASTC_10x5},
                    {"GL_COMPRESSED_RGBA_ASTC_10x6", GL_COMPRESSED_RGBA_ASTC_10x6},
                    {"GL_COMPRESSED_RGBA_ASTC_10x8", GL_COMPRESSED_RGBA_ASTC_10x8},
                    {"GL_COMPRESSED_RGBA_ASTC_10x10", GL_COMPRESSED_RGBA_ASTC_10x10},
                    {"GL_COMPRESSED_RGBA_ASTC_12x10", GL_COMPRESSED_RGBA_ASTC_12x10},
                    {"GL_COMPRESSED_RGBA_ASTC_12x12", GL_COMPRESSED_RGBA_ASTC_12x12},
                })),

        DEFINE_NAPI_STATIC_VALUE("DrawMode",
                                 createEnum(env,
                                            {
                                                {"GL_POINTS", GL_POINTS},
                                                {"GL_LINE_STRIP", GL_LINE_STRIP},
                                                {"GL_LINE_LOOP", GL_LINE_LOOP},
                                                {"GL_LINES", GL_LINES},
                                                {"GL_LINE_STRIP_ADJACENCY", GL_LINE_STRIP_ADJACENCY},
                                                {"GL_LINES_ADJACENCY", GL_LINES_ADJACENCY},
                                                {"GL_TRIANGLE_STRIP", GL_TRIANGLE_STRIP},
                                                {"GL_TRIANGLE_FAN", GL_TRIANGLE_FAN},
                                                {"GL_TRIANGLES", GL_TRIANGLES},
                                                {"GL_TRIANGLE_STRIP_ADJACENCY", GL_TRIANGLE_STRIP_ADJACENCY},
                                                {"GL_TRIANGLES_ADJACENCY", GL_TRIANGLES_ADJACENCY},
                                                {"GL_PATCHES", GL_PATCHES},
                                            })),

        DEFINE_NAPI_STATIC_VALUE("FaceMode", createEnum(env,
                                                        {
                                                            {"GL_FRONT", GL_FRONT},
                                                            {"GL_BACK", GL_BACK},
                                                            {"GL_FRONT_AND_BACK", GL_FRONT_AND_BACK},
                                                        })),

        DEFINE_NAPI_STATIC_VALUE("FrameBufferAttachment",
                                 createEnum(env,
                                            {
                                                {"GL_DEPTH", GL_DEPTH},
                                                {"GL_BACK", GL_BACK},
                                                {"GL_STENCIL", GL_STENCIL},
                                                {"GL_DEPTH_ATTACHMENT", GL_DEPTH_ATTACHMENT},
                                                {"GL_COLOR_ATTACHMENT0", GL_COLOR_ATTACHMENT0},
                                                {"GL_COLOR_ATTACHMENT1", GL_COLOR_ATTACHMENT1},
                                                {"GL_COLOR_ATTACHMENT2", GL_COLOR_ATTACHMENT2},
                                                {"GL_COLOR_ATTACHMENT3", GL_COLOR_ATTACHMENT3},
                                                {"GL_COLOR_ATTACHMENT4", GL_COLOR_ATTACHMENT4},
                                                {"GL_COLOR_ATTACHMENT5", GL_COLOR_ATTACHMENT5},
                                                {"GL_COLOR_ATTACHMENT6", GL_COLOR_ATTACHMENT6},
                                                {"GL_COLOR_ATTACHMENT7", GL_COLOR_ATTACHMENT7},
                                                {"GL_COLOR_ATTACHMENT8", GL_COLOR_ATTACHMENT8},
                                                {"GL_COLOR_ATTACHMENT9", GL_COLOR_ATTACHMENT9},
                                                {"GL_COLOR_ATTACHMENT10", GL_COLOR_ATTACHMENT10},
                                                {"GL_COLOR_ATTACHMENT11", GL_COLOR_ATTACHMENT11},
                                                {"GL_COLOR_ATTACHMENT12", GL_COLOR_ATTACHMENT12},
                                                {"GL_COLOR_ATTACHMENT13", GL_COLOR_ATTACHMENT13},
                                                {"GL_COLOR_ATTACHMENT14", GL_COLOR_ATTACHMENT14},
                                                {"GL_COLOR_ATTACHMENT15", GL_COLOR_ATTACHMENT15},
                                                {"GL_COLOR_ATTACHMENT16", GL_COLOR_ATTACHMENT16},
                                                {"GL_COLOR_ATTACHMENT17", GL_COLOR_ATTACHMENT17},
                                                {"GL_COLOR_ATTACHMENT18", GL_COLOR_ATTACHMENT18},
                                                {"GL_COLOR_ATTACHMENT19", GL_COLOR_ATTACHMENT19},
                                                {"GL_COLOR_ATTACHMENT20", GL_COLOR_ATTACHMENT20},
                                                {"GL_COLOR_ATTACHMENT21", GL_COLOR_ATTACHMENT21},
                                                {"GL_COLOR_ATTACHMENT22", GL_COLOR_ATTACHMENT22},
                                                {"GL_COLOR_ATTACHMENT23", GL_COLOR_ATTACHMENT23},
                                                {"GL_COLOR_ATTACHMENT24", GL_COLOR_ATTACHMENT24},
                                                {"GL_COLOR_ATTACHMENT25", GL_COLOR_ATTACHMENT25},
                                                {"GL_COLOR_ATTACHMENT26", GL_COLOR_ATTACHMENT26},
                                                {"GL_COLOR_ATTACHMENT27", GL_COLOR_ATTACHMENT27},
                                                {"GL_COLOR_ATTACHMENT28", GL_COLOR_ATTACHMENT28},
                                                {"GL_COLOR_ATTACHMENT29", GL_COLOR_ATTACHMENT29},
                                                {"GL_COLOR_ATTACHMENT30", GL_COLOR_ATTACHMENT30},
                                                {"GL_COLOR_ATTACHMENT31", GL_COLOR_ATTACHMENT31},
                                                {"GL_DEPTH_STENCIL_ATTACHMENT", GL_DEPTH_STENCIL_ATTACHMENT},
                                            })),

        DEFINE_NAPI_STATIC_VALUE(
            "FrameBufferAttachmentParamName",
            createEnum(env,
                       {
                           {"GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME", GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME},
                           {"GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE", GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE", GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE", GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE", GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE", GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE", GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE", GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING", GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING},
                           {"GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL},
                           {"GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE",
                            GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE},
                           {"GL_FRAMEBUFFER_ATTACHMENT_LAYERED", GL_FRAMEBUFFER_ATTACHMENT_LAYERED},
                           {"GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER", GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER},
                       })),

        DEFINE_NAPI_STATIC_VALUE(
            "FrameBufferStatus",
            createEnum(
                env,
                {
                    {"GL_FRAMEBUFFER_COMPLETE", GL_FRAMEBUFFER_COMPLETE},
                    {"GL_FRAMEBUFFER_UNDEFINED", GL_FRAMEBUFFER_UNDEFINED},
                    {"GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT", GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT},
                    {"GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT", GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT},
                    {"GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS", GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS},
                })),

        DEFINE_NAPI_STATIC_VALUE("FrameBufferTarget", createEnum(env,
                                                                 {
                                                                     {"GL_DRAW_FRAMEBUFFER", GL_DRAW_FRAMEBUFFER},
                                                                     {"GL_READ_FRAMEBUFFER", GL_READ_FRAMEBUFFER},
                                                                     {"GL_FRAMEBUFFER", GL_FRAMEBUFFER},
                                                                 })),

        DEFINE_NAPI_STATIC_VALUE("FrontFaceMode", createEnum(env,
                                                             {
                                                                 {"GL_CW", GL_CW},
                                                                 {"GL_CCW", GL_CCW},
                                                             })),

        DEFINE_NAPI_STATIC_VALUE("Func", createEnum(env,
                                                    {
                                                        {"GL_NEVER", GL_NEVER},
                                                        {"GL_LESS", GL_LESS},
                                                        {"GL_EQUAL", GL_EQUAL},
                                                        {"GL_LEQUAL", GL_LEQUAL},
                                                        {"GL_GREATER", GL_GREATER},
                                                        {"GL_NOTEQUAL", GL_NOTEQUAL},
                                                        {"GL_GEQUAL", GL_GEQUAL},
                                                        {"GL_ALWAYS", GL_ALWAYS},
                                                    })),

        DEFINE_NAPI_STATIC_VALUE("GetStringName",
                                 createEnum(env,
                                            {
                                                {"GL_EXTENSIONS", GL_EXTENSIONS},
                                                {"GL_RENDERER", GL_RENDERER},
                                                {"GL_SHADING_LANGUAGE_VERSION", GL_SHADING_LANGUAGE_VERSION},
                                                {"GL_VENDOR", GL_VENDOR},
                                                {"GL_VERSION", GL_VERSION},
                                            })),

        DEFINE_NAPI_STATIC_VALUE("GLbitfield", createEnum(env,
                                                          {
                                                              {"GL_COLOR_BUFFER_BIT", GL_COLOR_BUFFER_BIT},
                                                              {"GL_DEPTH_BUFFER_BIT", GL_DEPTH_BUFFER_BIT},
                                                              {"GL_STENCIL_BUFFER_BIT", GL_STENCIL_BUFFER_BIT},
                                                          })),

        DEFINE_NAPI_STATIC_VALUE(
            "GLCapability", createEnum(env,
                                       {
                                           {"GL_BLEND", GL_BLEND},
                                           {"GL_CULL_FACE", GL_CULL_FACE},
                                           {"GL_DEBUG_OUTPUT", GL_DEBUG_OUTPUT},
                                           {"GL_DEBUG_OUTPUT_SYNCHRONOUS", GL_DEBUG_OUTPUT_SYNCHRONOUS},
                                           {"GL_DEPTH_TEST", GL_DEPTH_TEST},
                                           {"GL_DITHER", GL_DITHER},
                                           {"GL_POLYGON_OFFSET_FILL", GL_POLYGON_OFFSET_FILL},
                                           {"GL_PRIMITIVE_RESTART_FIXED_INDEX", GL_PRIMITIVE_RESTART_FIXED_INDEX},
                                           {"GL_RASTERIZER_DISCARD", GL_RASTERIZER_DISCARD},
                                           {"GL_SAMPLE_ALPHA_TO_COVERAGE", GL_SAMPLE_ALPHA_TO_COVERAGE},
                                           {"GL_SAMPLE_COVERAGE", GL_SAMPLE_COVERAGE},
                                           {"GL_SAMPLE_MASK", GL_SAMPLE_MASK},
                                           {"GL_SCISSOR_TEST", GL_SCISSOR_TEST},
                                           {"GL_STENCIL_TEST", GL_STENCIL_TEST},
                                       })),

        DEFINE_NAPI_STATIC_VALUE("GLError",
                                 createEnum(env,
                                            {
                                                {"GL_NO_ERROR", GL_NO_ERROR},
                                                {"GL_INVALID_ENUM", GL_INVALID_ENUM},
                                                {"GL_INVALID_VALUE", GL_INVALID_VALUE},
                                                {"GL_INVALID_OPERATION", GL_INVALID_OPERATION},
                                                {"GL_INVALID_FRAMEBUFFER_OPERATION", GL_INVALID_FRAMEBUFFER_OPERATION},
                                                {"GL_OUT_OF_MEMORY", GL_OUT_OF_MEMORY},
                                                {"GL_STACK_UNDERFLOW", GL_STACK_UNDERFLOW},
                                                {"GL_STACK_OVERFLOW", GL_STACK_OVERFLOW},
                                            })),

        DEFINE_NAPI_STATIC_VALUE(
            "GLTexture",
            createEnum(
                env,
                {
                    {"GL_TEXTURE0", GL_TEXTURE0},   {"GL_TEXTURE1", GL_TEXTURE1},   {"GL_TEXTURE2", GL_TEXTURE2},
                    {"GL_TEXTURE3", GL_TEXTURE3},   {"GL_TEXTURE4", GL_TEXTURE4},   {"GL_TEXTURE5", GL_TEXTURE5},
                    {"GL_TEXTURE6", GL_TEXTURE6},   {"GL_TEXTURE7", GL_TEXTURE7},   {"GL_TEXTURE8", GL_TEXTURE8},
                    {"GL_TEXTURE9", GL_TEXTURE9},   {"GL_TEXTURE10", GL_TEXTURE10}, {"GL_TEXTURE11", GL_TEXTURE11},
                    {"GL_TEXTURE12", GL_TEXTURE12}, {"GL_TEXTURE13", GL_TEXTURE13}, {"GL_TEXTURE14", GL_TEXTURE14},
                    {"GL_TEXTURE15", GL_TEXTURE15}, {"GL_TEXTURE16", GL_TEXTURE16}, {"GL_TEXTURE17", GL_TEXTURE17},
                    {"GL_TEXTURE18", GL_TEXTURE18}, {"GL_TEXTURE19", GL_TEXTURE19}, {"GL_TEXTURE20", GL_TEXTURE20},
                    {"GL_TEXTURE21", GL_TEXTURE21}, {"GL_TEXTURE22", GL_TEXTURE22}, {"GL_TEXTURE23", GL_TEXTURE23},
                    {"GL_TEXTURE24", GL_TEXTURE24}, {"GL_TEXTURE25", GL_TEXTURE25}, {"GL_TEXTURE26", GL_TEXTURE26},
                    {"GL_TEXTURE27", GL_TEXTURE27}, {"GL_TEXTURE28", GL_TEXTURE28}, {"GL_TEXTURE29", GL_TEXTURE29},
                    {"GL_TEXTURE30", GL_TEXTURE30}, {"GL_TEXTURE31", GL_TEXTURE31},
                })),

        DEFINE_NAPI_STATIC_VALUE("HintMode", createEnum(env,
                                                        {
                                                            {"GL_FASTEST", GL_FASTEST},
                                                            {"GL_NICEST", GL_NICEST},
                                                            {"GL_DONT_CARE", GL_DONT_CARE},
                                                        })),

        DEFINE_NAPI_STATIC_VALUE(
            "HintTarget", createEnum(env,
                                     {
                                         {"GL_FRAGMENT_SHADER_DERIVATIVE_HINT", GL_FRAGMENT_SHADER_DERIVATIVE_HINT},
                                         {"GL_GENERATE_MIPMAP_HINT", GL_GENERATE_MIPMAP_HINT},
                                     })),

        DEFINE_NAPI_STATIC_VALUE(
            "IndicesType", createEnum(env,
                                      {
                                          {"GL_UNSIGNED_BYTE", GL_UNSIGNED_BYTE},
                                          {"GL_UNSIGNED_SHORT", GL_UNSIGNED_SHORT},
                                          {"GL_UNSIGNED_INT", GL_UNSIGNED_INT},
                                          {"GL_UNSIGNED_INT_2_10_10_10_REV", GL_UNSIGNED_INT_2_10_10_10_REV},
                                          {"GL_INT", GL_INT},
                                          {"GL_FLOAT", GL_FLOAT},
                                          {"GL_BYTE", GL_BYTE},
                                          {"GL_SHORT", GL_SHORT},
                                          {"GL_HALF_FLOAT", GL_HALF_FLOAT},
                                          {"GL_UNSIGNED_SHORT_5_6_5", GL_UNSIGNED_SHORT_5_6_5},
                                          {"GL_UNSIGNED_SHORT_4_4_4_4", GL_UNSIGNED_SHORT_4_4_4_4},
                                          {"GL_UNSIGNED_SHORT_5_5_5_1", GL_UNSIGNED_SHORT_5_5_5_1},
                                          {"GL_UNSIGNED_INT_10F_11F_11F_REV", GL_UNSIGNED_INT_10F_11F_11F_REV},
                                          {"GL_UNSIGNED_INT_5_9_9_9_REV", GL_UNSIGNED_INT_5_9_9_9_REV},
                                          {"GL_UNSIGNED_INT_24_8", GL_UNSIGNED_INT_24_8},
                                          {"GL_FLOAT_32_UNSIGNED_INT_24_8_REV", GL_FLOAT_32_UNSIGNED_INT_24_8_REV},
                                      })),

        DEFINE_NAPI_STATIC_VALUE("InternalFormat", createEnum(env,
                                                              {
                                                                  {"GL_R8", GL_R8},
                                                                  {"GL_RED", GL_RED},
                                                                  {"GL_R8UI", GL_R8UI},
                                                                  {"GL_RED_INTEGER", GL_RED_INTEGER},
                                                                  {"GL_R8I", GL_R8I},
                                                                  {"GL_R16UI", GL_R16UI},
                                                                  {"GL_R16I", GL_R16I},
                                                                  {"GL_R32UI", GL_R32UI},
                                                                  {"GL_R32I", GL_R32I},
                                                                  {"GL_RG8", GL_RG8},
                                                                  {"GL_RG", GL_RG},
                                                                  {"GL_RG8UI", GL_RG8UI},
                                                                  {"GL_RG_INTEGER", GL_RG_INTEGER},
                                                                  {"GL_RG8I", GL_RG8I},
                                                                  {"GL_RG16UI", GL_RG16UI},
                                                                  {"GL_RG16I", GL_RG16I},
                                                                  {"GL_RG32UI", GL_RG32UI},
                                                                  {"GL_RG32I", GL_RG32I},
                                                                  {"GL_RGB8", GL_RGB8},
                                                                  {"GL_RGB", GL_RGB},
                                                                  {"GL_RGB565", GL_RGB565},
                                                                  {"GL_RGBA8", GL_RGBA8},
                                                                  {"GL_RGBA", GL_RGBA},
                                                                  {"GL_SRGB8_ALPHA8", GL_SRGB8_ALPHA8},
                                                                  {"GL_RGB5_A1", GL_RGB5_A1},
                                                                  {"GL_RGBA4", GL_RGBA4},
                                                                  {"GL_RGB10_A2", GL_RGB10_A2},
                                                                  {"GL_RGBA8UI", GL_RGBA8UI},
                                                                  {"GL_RGBA_INTEGER", GL_RGBA_INTEGER},
                                                                  {"GL_RGBA8I", GL_RGBA8I},
                                                                  {"GL_RGB10_A2UI", GL_RGB10_A2UI},
                                                                  {"GL_RGBA16UI", GL_RGBA16UI},
                                                                  {"GL_RGBA16I", GL_RGBA16I},
                                                                  {"GL_RGBA32I", GL_RGBA32I},
                                                                  {"GL_RGBA32UI", GL_RGBA32UI},
                                                                  {"GL_DEPTH_COMPONENT16", GL_DEPTH_COMPONENT16},
                                                                  {"GL_DEPTH_COMPONENT", GL_DEPTH_COMPONENT},
                                                                  {"GL_DEPTH_COMPONENT24", GL_DEPTH_COMPONENT24},
                                                                  {"GL_DEPTH_COMPONENT32F", GL_DEPTH_COMPONENT32F},
                                                                  {"GL_DEPTH24_STENCIL8", GL_DEPTH24_STENCIL8},
                                                                  {"GL_DEPTH_STENCIL", GL_DEPTH_STENCIL},
                                                                  {"GL_DEPTH32F_STENCIL8", GL_DEPTH32F_STENCIL8},
                                                                  {"GL_STENCIL_INDEX8", GL_STENCIL_INDEX8},
                                                                  {"GL_STENCIL", GL_STENCIL},
                                                              })),

        DEFINE_NAPI_STATIC_VALUE(
            "MipmapTarget", createEnum(env,
                                       {
                                           {"GL_TEXTURE_2D", GL_TEXTURE_2D},
                                           {"GL_TEXTURE_3D", GL_TEXTURE_3D},
                                           {"GL_TEXTURE_2D_ARRAY", GL_TEXTURE_2D_ARRAY},
                                           {"GL_TEXTURE_CUBE_MAP", GL_TEXTURE_CUBE_MAP},
                                           {"GL_TEXTURE_CUBE_MAP_ARRAY", GL_TEXTURE_CUBE_MAP_ARRAY},
                                       })),

        DEFINE_NAPI_STATIC_VALUE(
            "ParamName",
            createEnum(
                env,
                {
                    {"GL_ACTIVE_TEXTURE", GL_ACTIVE_TEXTURE},
                    {"GL_ALIASED_LINE_WIDTH_RANGE", GL_ALIASED_LINE_WIDTH_RANGE},
                    {"GL_ALIASED_POINT_SIZE_RANGE", GL_ALIASED_POINT_SIZE_RANGE},
                    {"GL_ALPHA_BITS", GL_ALPHA_BITS},
                    {"GL_ARRAY_BUFFER_BINDING", GL_ARRAY_BUFFER_BINDING},
                    {"GL_BLEND", GL_BLEND},
                    {"GL_BLEND_COLOR", GL_BLEND_COLOR},
                    {"GL_BLEND_DST_ALPHA", GL_BLEND_DST_ALPHA},
                    {"GL_BLEND_DST_RGB", GL_BLEND_DST_RGB},
                    {"GL_BLEND_EQUATION_ALPHA", GL_BLEND_EQUATION_ALPHA},
                    {"GL_BLEND_EQUATION_RGB", GL_BLEND_EQUATION_RGB},
                    {"GL_BLEND_SRC_ALPHA", GL_BLEND_SRC_ALPHA},
                    {"GL_BLEND_SRC_RGB", GL_BLEND_SRC_RGB},
                    {"GL_BLUE_BITS", GL_BLUE_BITS},
                    {"GL_COLOR_CLEAR_VALUE", GL_COLOR_CLEAR_VALUE},
                    {"GL_COLOR_WRITEMASK", GL_COLOR_WRITEMASK},
                    {"GL_COMPRESSED_TEXTURE_FORMATS", GL_COMPRESSED_TEXTURE_FORMATS},
                    {"GL_CONTEXT_FLAGS", GL_CONTEXT_FLAGS},
                    {"GL_COPY_READ_BUFFER_BINDING", GL_COPY_READ_BUFFER_BINDING},
                    {"GL_COPY_WRITE_BUFFER_BINDING", GL_COPY_WRITE_BUFFER_BINDING},
                    {"GL_CULL_FACE", GL_CULL_FACE},
                    {"GL_CULL_FACE_MODE", GL_CULL_FACE_MODE},
                    {"GL_CURRENT_PROGRAM", GL_CURRENT_PROGRAM},
                    {"GL_DEBUG_GROUP_STACK_DEPTH", GL_DEBUG_GROUP_STACK_DEPTH},
                    {"GL_DEBUG_LOGGED_MESSAGES", GL_DEBUG_LOGGED_MESSAGES},
                    {"GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH", GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH},
                    {"GL_DEPTH_BITS", GL_DEPTH_BITS},
                    {"GL_DEPTH_CLEAR_VALUE", GL_DEPTH_CLEAR_VALUE},
                    {"GL_DEPTH_FUNC", GL_DEPTH_FUNC},
                    {"GL_DEPTH_RANGE", GL_DEPTH_RANGE},
                    {"GL_DEPTH_TEST", GL_DEPTH_TEST},
                    {"GL_DEPTH_WRITEMASK", GL_DEPTH_WRITEMASK},
                    {"GL_DISPATCH_INDIRECT_BUFFER_BINDING", GL_DISPATCH_INDIRECT_BUFFER_BINDING},
                    {"GL_DITHER", GL_DITHER},
                    {"GL_DRAW_FRAMEBUFFER_BINDING", GL_DRAW_FRAMEBUFFER_BINDING},
                    {"GL_ELEMENT_ARRAY_BUFFER_BINDING", GL_ELEMENT_ARRAY_BUFFER_BINDING},
                    {"GL_FRAGMENT_INTERPOLATION_OFFSET_BITS", GL_FRAGMENT_INTERPOLATION_OFFSET_BITS},
                    {"GL_FRAGMENT_SHADER_DERIVATIVE_HINT", GL_FRAGMENT_SHADER_DERIVATIVE_HINT},
                    {"GL_FRONT_FACE", GL_FRONT_FACE},
                    {"GL_GENERATE_MIPMAP_HINT", GL_GENERATE_MIPMAP_HINT},
                    {"GL_GREEN_BITS", GL_GREEN_BITS},
                    {"GL_IMAGE_BINDING_LAYERED", GL_IMAGE_BINDING_LAYERED},
                    {"GL_IMPLEMENTATION_COLOR_READ_FORMAT", GL_IMPLEMENTATION_COLOR_READ_FORMAT},
                    {"GL_IMPLEMENTATION_COLOR_READ_TYPE", GL_IMPLEMENTATION_COLOR_READ_TYPE},
                    {"GL_LAYER_PROVOKING_VERTEX", GL_LAYER_PROVOKING_VERTEX},
                    {"GL_LINE_WIDTH", GL_LINE_WIDTH},
                    {"GL_MAJOR_VERSION", GL_MAJOR_VERSION},
                    {"GL_MAX_3D_TEXTURE_SIZE", GL_MAX_3D_TEXTURE_SIZE},
                    {"GL_MAX_ARRAY_TEXTURE_LAYERS", GL_MAX_ARRAY_TEXTURE_LAYERS},
                    {"GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS", GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS},
                    {"GL_MAX_COLOR_ATTACHMENTS", GL_MAX_COLOR_ATTACHMENTS},
                    {"GL_MAX_COLOR_TEXTURE_SAMPLES", GL_MAX_COLOR_TEXTURE_SAMPLES},
                    {"GL_MAX_COMBINED_ATOMIC_COUNTERS", GL_MAX_COMBINED_ATOMIC_COUNTERS},
                    {"GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS", GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS},
                    {"GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS", GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS},
                    {"GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS", GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS},
                    {"GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS", GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS},
                    {"GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS", GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS},
                    {"GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS",
                     GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS},
                    {"GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS",
                     GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS},
                    {"GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS", GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS},
                    {"GL_MAX_COMBINED_UNIFORM_BLOCKS", GL_MAX_COMBINED_UNIFORM_BLOCKS},
                    {"GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS", GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS},
                    {"GL_MAX_COMPUTE_ATOMIC_COUNTERS", GL_MAX_COMPUTE_ATOMIC_COUNTERS},
                    {"GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS", GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS},
                    {"GL_MAX_COMPUTE_IMAGE_UNIFORMS", GL_MAX_COMPUTE_IMAGE_UNIFORMS},
                    {"GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS", GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS},
                    {"GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS", GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS},
                    {"GL_MAX_COMPUTE_UNIFORM_BLOCKS", GL_MAX_COMPUTE_UNIFORM_BLOCKS},
                    {"GL_MAX_COMPUTE_UNIFORM_COMPONENTS", GL_MAX_COMPUTE_UNIFORM_COMPONENTS},
                    {"GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS", GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS},
                    {"GL_MAX_COMPUTE_WORK_GROUP_COUNT", GL_MAX_COMPUTE_WORK_GROUP_COUNT},
                    {"GL_MAX_COMPUTE_WORK_GROUP_SIZE", GL_MAX_COMPUTE_WORK_GROUP_SIZE},
                    {"GL_MAX_CUBE_MAP_TEXTURE_SIZE", GL_MAX_CUBE_MAP_TEXTURE_SIZE},
                    {"GL_MAX_DEBUG_GROUP_STACK_DEPTH", GL_MAX_DEBUG_GROUP_STACK_DEPTH},
                    {"GL_MAX_DEBUG_LOGGED_MESSAGES", GL_MAX_DEBUG_LOGGED_MESSAGES},
                    {"GL_MAX_DEBUG_MESSAGE_LENGTH", GL_MAX_DEBUG_MESSAGE_LENGTH},
                    {"GL_MAX_DEPTH_TEXTURE_SAMPLES", GL_MAX_DEPTH_TEXTURE_SAMPLES},
                    {"GL_MAX_DRAW_BUFFERS", GL_MAX_DRAW_BUFFERS},
                    {"GL_MAX_ELEMENT_INDEX", GL_MAX_ELEMENT_INDEX},
                    {"GL_MAX_ELEMENTS_INDICES", GL_MAX_ELEMENTS_INDICES},
                    {"GL_MAX_ELEMENTS_VERTICES", GL_MAX_ELEMENTS_VERTICES},
                    {"GL_MAX_FRAGMENT_ATOMIC_COUNTERS", GL_MAX_FRAGMENT_ATOMIC_COUNTERS},
                    {"GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS", GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS},
                    {"GL_MAX_FRAGMENT_IMAGE_UNIFORMS", GL_MAX_FRAGMENT_IMAGE_UNIFORMS},
                    {"GL_MAX_FRAGMENT_INPUT_COMPONENTS", GL_MAX_FRAGMENT_INPUT_COMPONENTS},
                    {"GL_MAX_FRAGMENT_INTERPOLATION_OFFSET", GL_MAX_FRAGMENT_INTERPOLATION_OFFSET},
                    {"GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS", GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS},
                    {"GL_MAX_FRAGMENT_UNIFORM_BLOCKS", GL_MAX_FRAGMENT_UNIFORM_BLOCKS},
                    {"GL_MAX_FRAGMENT_UNIFORM_COMPONENTS", GL_MAX_FRAGMENT_UNIFORM_COMPONENTS},
                    {"GL_MAX_FRAGMENT_UNIFORM_VECTORS", GL_MAX_FRAGMENT_UNIFORM_VECTORS},
                    {"GL_MAX_FRAMEBUFFER_HEIGHT", GL_MAX_FRAMEBUFFER_HEIGHT},
                    {"GL_MAX_FRAMEBUFFER_LAYERS", GL_MAX_FRAMEBUFFER_LAYERS},
                    {"GL_MAX_FRAMEBUFFER_SAMPLES", GL_MAX_FRAMEBUFFER_SAMPLES},
                    {"GL_MAX_FRAMEBUFFER_WIDTH", GL_MAX_FRAMEBUFFER_WIDTH},
                    {"GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS", GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS},
                    {"GL_MAX_GEOMETRY_ATOMIC_COUNTERS", GL_MAX_GEOMETRY_ATOMIC_COUNTERS},
                    {"GL_MAX_GEOMETRY_IMAGE_UNIFORMS", GL_MAX_GEOMETRY_IMAGE_UNIFORMS},
                    {"GL_MAX_GEOMETRY_INPUT_COMPONENTS", GL_MAX_GEOMETRY_INPUT_COMPONENTS},
                    {"GL_MAX_GEOMETRY_OUTPUT_COMPONENTS", GL_MAX_GEOMETRY_OUTPUT_COMPONENTS},
                    {"GL_MAX_GEOMETRY_OUTPUT_VERTICES", GL_MAX_GEOMETRY_OUTPUT_VERTICES},
                    {"GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS", GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS},
                    {"GL_MAX_GEOMETRY_SHADER_INVOCATIONS", GL_MAX_GEOMETRY_SHADER_INVOCATIONS},
                    {"GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS", GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS},
                    {"GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS", GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS},
                    {"GL_MAX_GEOMETRY_UNIFORM_BLOCKS", GL_MAX_GEOMETRY_UNIFORM_BLOCKS},
                    {"GL_MAX_GEOMETRY_UNIFORM_COMPONENTS", GL_MAX_GEOMETRY_UNIFORM_COMPONENTS},
                    {"GL_MAX_INTEGER_SAMPLES", GL_MAX_INTEGER_SAMPLES},
                    {"GL_MAX_LABEL_LENGTH", GL_MAX_LABEL_LENGTH},
                    {"GL_MAX_PROGRAM_TEXEL_OFFSET", GL_MAX_PROGRAM_TEXEL_OFFSET},
                    {"GL_MAX_RENDERBUFFER_SIZE", GL_MAX_RENDERBUFFER_SIZE},
                    {"GL_MAX_SAMPLE_MASK_WORDS", GL_MAX_SAMPLE_MASK_WORDS},
                    {"GL_MAX_SAMPLES", GL_MAX_SAMPLES},
                    {"GL_MAX_SERVER_WAIT_TIMEOUT", GL_MAX_SERVER_WAIT_TIMEOUT},
                    {"GL_MAX_SHADER_STORAGE_BLOCK_SIZE", GL_MAX_SHADER_STORAGE_BLOCK_SIZE},
                    {"GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS", GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS},
                    {"GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS", GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS},
                    {"GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS", GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS},
                    {"GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS", GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS},
                    {"GL_MAX_TESS_CONTROL_INPUT_COMPONENTS", GL_MAX_TESS_CONTROL_INPUT_COMPONENTS},
                    {"GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS", GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS},
                    {"GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS", GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS},
                    {"GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS", GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS},
                    {"GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS", GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS},
                    {"GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS", GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS},
                    {"GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS", GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS},
                    {"GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS", GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS},
                    {"GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS", GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS},
                    {"GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS", GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS},
                    {"GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS", GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS},
                    {"GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS", GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS},
                    {"GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS", GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS},
                    {"GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS", GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS},
                    {"GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS", GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS},
                    {"GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS", GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS},
                    {"GL_MAX_TESS_GEN_LEVEL", GL_MAX_TESS_GEN_LEVEL},
                    {"GL_MAX_TESS_PATCH_COMPONENTS", GL_MAX_TESS_PATCH_COMPONENTS},
                    {"GL_MAX_TEXTURE_BUFFER_SIZE", GL_MAX_TEXTURE_BUFFER_SIZE},
                    {"GL_MAX_TEXTURE_IMAGE_UNITS", GL_MAX_TEXTURE_IMAGE_UNITS},
                    {"GL_MAX_TEXTURE_LOD_BIAS", GL_MAX_TEXTURE_LOD_BIAS},
                    {"GL_MAX_TEXTURE_SIZE", GL_MAX_TEXTURE_SIZE},
                    {"GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS",
                     GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS},
                    {"GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS", GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS},
                    {"GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS", GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS},
                    {"GL_MAX_UNIFORM_BLOCK_SIZE", GL_MAX_UNIFORM_BLOCK_SIZE},
                    {"GL_MAX_UNIFORM_BUFFER_BINDINGS", GL_MAX_UNIFORM_BUFFER_BINDINGS},
                    {"GL_MAX_UNIFORM_LOCATIONS", GL_MAX_UNIFORM_LOCATIONS},
                    {"GL_MAX_VARYING_COMPONENTS", GL_MAX_VARYING_COMPONENTS},
                    {"GL_MAX_VARYING_VECTORS", GL_MAX_VARYING_VECTORS},
                    {"GL_MAX_VERTEX_ATOMIC_COUNTERS", GL_MAX_VERTEX_ATOMIC_COUNTERS},
                    {"GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS", GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS},
                    {"GL_MAX_VERTEX_ATTRIB_BINDINGS", GL_MAX_VERTEX_ATTRIB_BINDINGS},
                    {"GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET", GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET},
                    {"GL_MAX_VERTEX_ATTRIBS", GL_MAX_VERTEX_ATTRIBS},
                    {"GL_MAX_VERTEX_IMAGE_UNIFORMS", GL_MAX_VERTEX_IMAGE_UNIFORMS},
                    {"GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS", GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS},
                    {"GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS", GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS},
                    {"GL_MAX_VERTEX_OUTPUT_COMPONENTS", GL_MAX_VERTEX_OUTPUT_COMPONENTS},
                    {"GL_MAX_VERTEX_UNIFORM_BLOCKS", GL_MAX_VERTEX_UNIFORM_BLOCKS},
                    {"GL_MAX_VERTEX_UNIFORM_COMPONENTS", GL_MAX_VERTEX_UNIFORM_COMPONENTS},
                    {"GL_MAX_VERTEX_UNIFORM_VECTORS", GL_MAX_VERTEX_UNIFORM_VECTORS},
                    {"GL_MAX_VIEWPORT_DIMS", GL_MAX_VIEWPORT_DIMS},
                    {"GL_MIN_FRAGMENT_INTERPOLATION_OFFSET", GL_MIN_FRAGMENT_INTERPOLATION_OFFSET},
                    {"GL_MIN_PROGRAM_TEXEL_OFFSET", GL_MIN_PROGRAM_TEXEL_OFFSET},
                    {"GL_MIN_SAMPLE_SHADING_VALUE", GL_MIN_SAMPLE_SHADING_VALUE},
                    {"GL_MINOR_VERSION", GL_MINOR_VERSION},
                    {"GL_MULTISAMPLE_LINE_WIDTH_RANGE", GL_MULTISAMPLE_LINE_WIDTH_RANGE},
                    {"GL_NUM_COMPRESSED_TEXTURE_FORMATS", GL_NUM_COMPRESSED_TEXTURE_FORMATS},
                    {"GL_NUM_EXTENSIONS", GL_NUM_EXTENSIONS},
                    {"GL_NUM_PROGRAM_BINARY_FORMATS", GL_NUM_PROGRAM_BINARY_FORMATS},
                    {"GL_NUM_SHADER_BINARY_FORMATS", GL_NUM_SHADER_BINARY_FORMATS},
                    {"GL_PACK_ALIGNMENT", GL_PACK_ALIGNMENT},
                    {"GL_PACK_ROW_LENGTH", GL_PACK_ROW_LENGTH},
                    {"GL_PACK_SKIP_PIXELS", GL_PACK_SKIP_PIXELS},
                    {"GL_PACK_SKIP_ROWS", GL_PACK_SKIP_ROWS},
                    {"GL_PATCH_VERTICES", GL_PATCH_VERTICES},
                    {"GL_PIXEL_PACK_BUFFER_BINDING", GL_PIXEL_PACK_BUFFER_BINDING},
                    {"GL_PIXEL_UNPACK_BUFFER_BINDING", GL_PIXEL_UNPACK_BUFFER_BINDING},
                    {"GL_POLYGON_OFFSET_FACTOR", GL_POLYGON_OFFSET_FACTOR},
                    {"GL_POLYGON_OFFSET_FILL", GL_POLYGON_OFFSET_FILL},
                    {"GL_POLYGON_OFFSET_UNITS", GL_POLYGON_OFFSET_UNITS},
                    {"GL_PRIMITIVE_BOUNDING_BOX", GL_PRIMITIVE_BOUNDING_BOX},
                    {"GL_PRIMITIVE_RESTART_FIXED_INDEX", GL_PRIMITIVE_RESTART_FIXED_INDEX},
                    {"GL_PROGRAM_BINARY_FORMATS", GL_PROGRAM_BINARY_FORMATS},
                    {"GL_PROGRAM_PIPELINE_BINDING", GL_PROGRAM_PIPELINE_BINDING},
                    {"GL_RASTERIZER_DISCARD", GL_RASTERIZER_DISCARD},
                    {"GL_READ_BUFFER", GL_READ_BUFFER},
                    {"GL_READ_FRAMEBUFFER_BINDING", GL_READ_FRAMEBUFFER_BINDING},
                    {"GL_RED_BITS", GL_RED_BITS},
                    {"GL_RENDERBUFFER_BINDING", GL_RENDERBUFFER_BINDING},
                    {"GL_RESET_NOTIFICATION_STRATEGY", GL_RESET_NOTIFICATION_STRATEGY},
                    {"GL_SAMPLE_ALPHA_TO_COVERAGE", GL_SAMPLE_ALPHA_TO_COVERAGE},
                    {"GL_SAMPLE_BUFFERS", GL_SAMPLE_BUFFERS},
                    {"GL_SAMPLE_COVERAGE", GL_SAMPLE_COVERAGE},
                    {"GL_SAMPLE_COVERAGE_INVERT", GL_SAMPLE_COVERAGE_INVERT},
                    {"GL_SAMPLE_COVERAGE_VALUE", GL_SAMPLE_COVERAGE_VALUE},
                    {"GL_SAMPLE_MASK_VALUE", GL_SAMPLE_MASK_VALUE},
                    {"GL_SAMPLE_SHADING", GL_SAMPLE_SHADING},
                    {"GL_SAMPLER_BINDING", GL_SAMPLER_BINDING},
                    {"GL_SAMPLES", GL_SAMPLES},
                    {"GL_SCISSOR_BOX", GL_SCISSOR_BOX},
                    {"GL_SCISSOR_TEST", GL_SCISSOR_TEST},
                    {"GL_SHADER_BINARY_FORMATS", GL_SHADER_BINARY_FORMATS},
                    {"GL_SHADER_COMPILER", GL_SHADER_COMPILER},
                    {"GL_SHADER_STORAGE_BUFFER_BINDING", GL_SHADER_STORAGE_BUFFER_BINDING},
                    {"GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT", GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT},
                    {"GL_SHADER_STORAGE_BUFFER_SIZE", GL_SHADER_STORAGE_BUFFER_SIZE},
                    {"GL_SHADER_STORAGE_BUFFER_START", GL_SHADER_STORAGE_BUFFER_START},
                    {"GL_STENCIL_BACK_FAIL", GL_STENCIL_BACK_FAIL},
                    {"GL_STENCIL_BACK_FUNC", GL_STENCIL_BACK_FUNC},
                    {"GL_STENCIL_BACK_PASS_DEPTH_FAIL", GL_STENCIL_BACK_PASS_DEPTH_FAIL},
                    {"GL_STENCIL_BACK_PASS_DEPTH_PASS", GL_STENCIL_BACK_PASS_DEPTH_PASS},
                    {"GL_STENCIL_BACK_REF", GL_STENCIL_BACK_REF},
                    {"GL_STENCIL_BACK_VALUE_MASK", GL_STENCIL_BACK_VALUE_MASK},
                    {"GL_STENCIL_BACK_WRITEMASK", GL_STENCIL_BACK_WRITEMASK},
                    {"GL_STENCIL_BITS", GL_STENCIL_BITS},
                    {"GL_STENCIL_CLEAR_VALUE", GL_STENCIL_CLEAR_VALUE},
                    {"GL_STENCIL_FAIL", GL_STENCIL_FAIL},
                    {"GL_STENCIL_FUNC", GL_STENCIL_FUNC},
                    {"GL_STENCIL_PASS_DEPTH_FAIL", GL_STENCIL_PASS_DEPTH_FAIL},
                    {"GL_STENCIL_PASS_DEPTH_PASS", GL_STENCIL_PASS_DEPTH_PASS},
                    {"GL_STENCIL_REF", GL_STENCIL_REF},
                    {"GL_STENCIL_TEST", GL_STENCIL_TEST},
                    {"GL_STENCIL_VALUE_MASK", GL_STENCIL_VALUE_MASK},
                    {"GL_STENCIL_WRITEMASK", GL_STENCIL_WRITEMASK},
                    {"GL_SUBPIXEL_BITS", GL_SUBPIXEL_BITS},
                    {"GL_TEXTURE_BINDING_2D", GL_TEXTURE_BINDING_2D},
                    {"GL_TEXTURE_BINDING_2D_ARRAY", GL_TEXTURE_BINDING_2D_ARRAY},
                    {"GL_TEXTURE_BINDING_3D", GL_TEXTURE_BINDING_3D},
                    {"GL_TEXTURE_BINDING_BUFFER", GL_TEXTURE_BINDING_BUFFER},
                    {"GL_TEXTURE_BINDING_CUBE_MAP", GL_TEXTURE_BINDING_CUBE_MAP},
                    {"GL_TEXTURE_BINDING_2D_MULTISAMPLE", GL_TEXTURE_BINDING_2D_MULTISAMPLE},
                    {"GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY", GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY},
                    {"GL_TEXTURE_BINDING_CUBE_MAP_ARRAY", GL_TEXTURE_BINDING_CUBE_MAP_ARRAY},
                    {"GL_TEXTURE_BUFFER_BINDING", GL_TEXTURE_BUFFER_BINDING},
                    {"GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT", GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT},
                    {"GL_TRANSFORM_FEEDBACK_BINDING", GL_TRANSFORM_FEEDBACK_BINDING},
                    {"GL_TRANSFORM_FEEDBACK_ACTIVE", GL_TRANSFORM_FEEDBACK_ACTIVE},
                    {"GL_TRANSFORM_FEEDBACK_BUFFER_BINDING", GL_TRANSFORM_FEEDBACK_BUFFER_BINDING},
                    {"GL_TRANSFORM_FEEDBACK_PAUSED", GL_TRANSFORM_FEEDBACK_PAUSED},
                    {"GL_TRANSFORM_FEEDBACK_BUFFER_SIZE", GL_TRANSFORM_FEEDBACK_BUFFER_SIZE},
                    {"GL_TRANSFORM_FEEDBACK_BUFFER_START", GL_TRANSFORM_FEEDBACK_BUFFER_START},
                    {"GL_UNIFORM_BUFFER_BINDING", GL_UNIFORM_BUFFER_BINDING},
                    {"GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT", GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT},
                    {"GL_UNIFORM_BUFFER_SIZE", GL_UNIFORM_BUFFER_SIZE},
                    {"GL_UNIFORM_BUFFER_START", GL_UNIFORM_BUFFER_START},
                    {"GL_UNPACK_ALIGNMENT", GL_UNPACK_ALIGNMENT},
                    {"GL_UNPACK_IMAGE_HEIGHT", GL_UNPACK_IMAGE_HEIGHT},
                    {"GL_UNPACK_ROW_LENGTH", GL_UNPACK_ROW_LENGTH},
                    {"GL_UNPACK_SKIP_IMAGES", GL_UNPACK_SKIP_IMAGES},
                    {"GL_UNPACK_SKIP_PIXELS", GL_UNPACK_SKIP_PIXELS},
                    {"GL_UNPACK_SKIP_ROWS", GL_UNPACK_SKIP_ROWS},
                    {"GL_VERTEX_ARRAY_BINDING", GL_VERTEX_ARRAY_BINDING},
                    {"GL_VERTEX_BINDING_DIVISOR", GL_VERTEX_BINDING_DIVISOR},
                    {"GL_VERTEX_BINDING_OFFSET", GL_VERTEX_BINDING_OFFSET},
                    {"GL_VERTEX_BINDING_STRIDE", GL_VERTEX_BINDING_STRIDE},
                    {"GL_VIEWPORT", GL_VIEWPORT},
                })),

        DEFINE_NAPI_STATIC_VALUE("PixelFormat", createEnum(env,
                                                           {
                                                               {"GL_RGBA", GL_RGBA},
                                                               {"GL_RGBA_INTEGER", GL_RGBA_INTEGER},
                                                           })),

        DEFINE_NAPI_STATIC_VALUE("PixelStorageMode", createEnum(env,
                                                                {
                                                                    {"GL_PACK_ROW_LENGTH", GL_PACK_ROW_LENGTH},
                                                                    {"GL_PACK_SKIP_PIXELS", GL_PACK_SKIP_PIXELS},
                                                                    {"GL_PACK_SKIP_ROWS", GL_PACK_SKIP_ROWS},
                                                                    {"GL_PACK_ALIGNMENT", GL_PACK_ALIGNMENT},
                                                                    {"GL_UNPACK_ROW_LENGTH", GL_UNPACK_ROW_LENGTH},
                                                                    {"GL_UNPACK_IMAGE_HEIGHT", GL_UNPACK_IMAGE_HEIGHT},
                                                                    {"GL_UNPACK_SKIP_PIXELS", GL_UNPACK_SKIP_PIXELS},
                                                                    {"GL_UNPACK_SKIP_ROWS", GL_UNPACK_SKIP_ROWS},
                                                                    {"GL_UNPACK_SKIP_IMAGES", GL_UNPACK_SKIP_IMAGES},
                                                                    {"GL_UNPACK_ALIGNMENT", GL_UNPACK_ALIGNMENT},
                                                                })),

        DEFINE_NAPI_STATIC_VALUE("PrecisionType", createEnum(env,
                                                             {
                                                                 {"GL_LOW_FLOAT", GL_LOW_FLOAT},
                                                                 {"GL_MEDIUM_FLOAT", GL_MEDIUM_FLOAT},
                                                                 {"GL_HIGH_FLOAT", GL_HIGH_FLOAT},
                                                                 {"GL_LOW_INT", GL_LOW_INT},
                                                                 {"GL_MEDIUM_INT", GL_MEDIUM_INT},
                                                                 {"GL_HIGH_INT", GL_HIGH_INT},
                                                             })),

        DEFINE_NAPI_STATIC_VALUE("PrimitiveMode", createEnum(env,
                                                             {
                                                                 {"GL_POINTS", GL_POINTS},
                                                                 {"GL_LINES", GL_LINES},
                                                                 {"GL_TRIANGLES", GL_TRIANGLES},
                                                             })),

        DEFINE_NAPI_STATIC_VALUE(
            "ProgramParamName",
            createEnum(env,
                       {
                           {"GL_ACTIVE_ATOMIC_COUNTER_BUFFERS", GL_ACTIVE_ATOMIC_COUNTER_BUFFERS},
                           {"GL_ACTIVE_ATTRIBUTES", GL_ACTIVE_ATTRIBUTES},
                           {"GL_ACTIVE_ATTRIBUTE_MAX_LENGTH", GL_ACTIVE_ATTRIBUTE_MAX_LENGTH},
                           {"GL_ACTIVE_UNIFORMS", GL_ACTIVE_UNIFORMS},
                           {"GL_ACTIVE_UNIFORM_BLOCKS", GL_ACTIVE_UNIFORM_BLOCKS},
                           {"GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH", GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH},
                           {"GL_ACTIVE_UNIFORM_MAX_LENGTH", GL_ACTIVE_UNIFORM_MAX_LENGTH},
                           {"GL_ATTACHED_SHADERS", GL_ATTACHED_SHADERS},
                           {"GL_COMPUTE_WORK_GROUP_SIZE", GL_COMPUTE_WORK_GROUP_SIZE},
                           {"GL_DELETE_STATUS", GL_DELETE_STATUS},
                           {"GL_GEOMETRY_SHADER_INVOCATIONS", GL_GEOMETRY_SHADER_INVOCATIONS},
                           {"GL_INFO_LOG_LENGTH", GL_INFO_LOG_LENGTH},
                           {"GL_LINK_STATUS", GL_LINK_STATUS},
                           {"GL_PROGRAM_BINARY_RETRIEVABLE_HINT", GL_PROGRAM_BINARY_RETRIEVABLE_HINT},
                           {"GL_PROGRAM_SEPARABLE", GL_PROGRAM_SEPARABLE},
                           {"GL_TESS_CONTROL_OUTPUT_VERTICES", GL_TESS_CONTROL_OUTPUT_VERTICES},
                           {"GL_TESS_GEN_MODE", GL_TESS_GEN_MODE},
                           {"GL_TESS_GEN_POINT_MODE", GL_TESS_GEN_POINT_MODE},
                           {"GL_TESS_GEN_SPACING", GL_TESS_GEN_SPACING},
                           {"GL_TESS_GEN_VERTEX_ORDER", GL_TESS_GEN_VERTEX_ORDER},
                           {"GL_TRANSFORM_FEEDBACK_BUFFER_MODE", GL_TRANSFORM_FEEDBACK_BUFFER_MODE},
                           {"GL_TRANSFORM_FEEDBACK_VARYINGS", GL_TRANSFORM_FEEDBACK_VARYINGS},
                       })),

        DEFINE_NAPI_STATIC_VALUE(
            "QueryTarget",
            createEnum(env,
                       {
                           {"GL_ANY_SAMPLES_PASSED", GL_ANY_SAMPLES_PASSED},
                           {"GL_ANY_SAMPLES_PASSED_CONSERVATIVE", GL_ANY_SAMPLES_PASSED_CONSERVATIVE},
                           {"GL_PRIMITIVES_GENERATED", GL_PRIMITIVES_GENERATED},
                           {"GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN", GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN},
                       })),

        DEFINE_NAPI_STATIC_VALUE("RenderBufferTarget", createEnum(env,
                                                                  {
                                                                      {"GL_RENDERBUFFER", GL_RENDERBUFFER},
                                                                  })),

        DEFINE_NAPI_STATIC_VALUE("RenderBufferParamName",
                                 createEnum(env,
                                            {
                                                {"GL_RENDERBUFFER_WIDTH", GL_RENDERBUFFER_WIDTH},
                                                {"GL_RENDERBUFFER_HEIGHT", GL_RENDERBUFFER_HEIGHT},
                                                {"GL_RENDERBUFFER_INTERNAL_FORMAT", GL_RENDERBUFFER_INTERNAL_FORMAT},
                                                {"GL_RENDERBUFFER_RED_SIZE", GL_RENDERBUFFER_RED_SIZE},
                                                {"GL_RENDERBUFFER_GREEN_SIZE", GL_RENDERBUFFER_GREEN_SIZE},
                                                {"GL_RENDERBUFFER_BLUE_SIZE", GL_RENDERBUFFER_BLUE_SIZE},
                                                {"GL_RENDERBUFFER_ALPHA_SIZE", GL_RENDERBUFFER_ALPHA_SIZE},
                                                {"GL_RENDERBUFFER_DEPTH_SIZE", GL_RENDERBUFFER_DEPTH_SIZE},
                                                {"GL_RENDERBUFFER_STENCIL_SIZE", GL_RENDERBUFFER_STENCIL_SIZE},
                                                {"GL_RENDERBUFFER_SAMPLES", GL_RENDERBUFFER_SAMPLES},
                                            })),

        DEFINE_NAPI_STATIC_VALUE("ShaderParamName", createEnum(env,
                                                               {
                                                                   {"GL_SHADER_TYPE", GL_SHADER_TYPE},
                                                                   {"GL_DELETE_STATUS", GL_DELETE_STATUS},
                                                                   {"GL_COMPILE_STATUS", GL_COMPILE_STATUS},
                                                                   {"GL_INFO_LOG_LENGTH", GL_INFO_LOG_LENGTH},
                                                                   {"GL_SHADER_SOURCE_LENGTH", GL_SHADER_SOURCE_LENGTH},
                                                               })),

        DEFINE_NAPI_STATIC_VALUE("ShaderType", createEnum(env,
                                                          {
                                                              {"GL_COMPUTE_SHADER", GL_COMPUTE_SHADER},
                                                              {"GL_VERTEX_SHADER", GL_VERTEX_SHADER},
                                                              {"GL_TESS_CONTROL_SHADER", GL_TESS_CONTROL_SHADER},
                                                              {"GL_TESS_EVALUATION_SHADER", GL_TESS_EVALUATION_SHADER},
                                                              {"GL_GEOMETRY_SHADER", GL_GEOMETRY_SHADER},
                                                              {"GL_FRAGMENT_SHADER", GL_FRAGMENT_SHADER},
                                                          })),

        DEFINE_NAPI_STATIC_VALUE("TestFail", createEnum(env,
                                                        {
                                                            {"GL_KEEP", GL_KEEP},
                                                            {"GL_ZERO", GL_ZERO},
                                                            {"GL_REPLACE", GL_REPLACE},
                                                            {"GL_INCR", GL_INCR},
                                                            {"GL_INCR_WRAP", GL_INCR_WRAP},
                                                            {"GL_DECR", GL_DECR},
                                                            {"GL_DECR_WRAP", GL_DECR_WRAP},
                                                            {"GL_INVERT", GL_INVERT},
                                                        })),

        DEFINE_NAPI_STATIC_VALUE("TexImage2DTarget",
                                 createEnum(env,
                                            {
                                                {"GL_TEXTURE_2D", GL_TEXTURE_2D},
                                                {"GL_TEXTURE_CUBE_MAP_POSITIVE_X", GL_TEXTURE_CUBE_MAP_POSITIVE_X},
                                                {"GL_TEXTURE_CUBE_MAP_NEGATIVE_X", GL_TEXTURE_CUBE_MAP_NEGATIVE_X},
                                                {"GL_TEXTURE_CUBE_MAP_POSITIVE_Y", GL_TEXTURE_CUBE_MAP_POSITIVE_Y},
                                                {"GL_TEXTURE_CUBE_MAP_NEGATIVE_Y", GL_TEXTURE_CUBE_MAP_NEGATIVE_Y},
                                                {"GL_TEXTURE_CUBE_MAP_POSITIVE_Z", GL_TEXTURE_CUBE_MAP_POSITIVE_Z},
                                                {"GL_TEXTURE_CUBE_MAP_NEGATIVE_Z", GL_TEXTURE_CUBE_MAP_NEGATIVE_Z},
                                            })),

        DEFINE_NAPI_STATIC_VALUE(
            "TexParamName", createEnum(env,
                                       {
                                           {"GL_DEPTH_STENCIL_TEXTURE_MODE", GL_DEPTH_STENCIL_TEXTURE_MODE},
                                           {"GL_IMAGE_FORMAT_COMPATIBILITY_TYPE", GL_IMAGE_FORMAT_COMPATIBILITY_TYPE},
                                           {"GL_TEXTURE_BASE_LEVEL", GL_TEXTURE_BASE_LEVEL},
                                           {"GL_TEXTURE_COMPARE_FUNC", GL_TEXTURE_COMPARE_FUNC},
                                           {"GL_TEXTURE_COMPARE_MODE", GL_TEXTURE_COMPARE_MODE},
                                           {"GL_TEXTURE_IMMUTABLE_FORMAT", GL_TEXTURE_IMMUTABLE_FORMAT},
                                           {"GL_TEXTURE_IMMUTABLE_LEVELS", GL_TEXTURE_IMMUTABLE_LEVELS},
                                           {"GL_TEXTURE_MAG_FILTER", GL_TEXTURE_MAG_FILTER},
                                           {"GL_TEXTURE_MAX_LEVEL", GL_TEXTURE_MAX_LEVEL},
                                           {"GL_TEXTURE_MAX_LOD", GL_TEXTURE_MAX_LOD},
                                           {"GL_TEXTURE_MIN_FILTER", GL_TEXTURE_MIN_FILTER},
                                           {"GL_TEXTURE_MIN_LOD", GL_TEXTURE_MIN_LOD},
                                           {"GL_TEXTURE_SWIZZLE_R", GL_TEXTURE_SWIZZLE_R},
                                           {"GL_TEXTURE_SWIZZLE_G", GL_TEXTURE_SWIZZLE_G},
                                           {"GL_TEXTURE_SWIZZLE_B", GL_TEXTURE_SWIZZLE_B},
                                           {"GL_TEXTURE_SWIZZLE_A", GL_TEXTURE_SWIZZLE_A},
                                           {"GL_TEXTURE_WRAP_S", GL_TEXTURE_WRAP_S},
                                           {"GL_TEXTURE_WRAP_T", GL_TEXTURE_WRAP_T},
                                           {"GL_TEXTURE_WRAP_R", GL_TEXTURE_WRAP_R},
                                           {"GL_TEXTURE_BORDER_COLOR", GL_TEXTURE_BORDER_COLOR},
                                       })),

        DEFINE_NAPI_STATIC_VALUE("TextureTarget",
                                 createEnum(env,
                                            {
                                                {"GL_TEXTURE_2D", GL_TEXTURE_2D},
                                                {"GL_TEXTURE_3D", GL_TEXTURE_3D},
                                                {"GL_TEXTURE_2D_ARRAY", GL_TEXTURE_2D_ARRAY},
                                                {"GL_TEXTURE_CUBE_MAP", GL_TEXTURE_CUBE_MAP},
                                                {"GL_TEXTURE_CUBE_MAP_ARRAY", GL_TEXTURE_CUBE_MAP_ARRAY},
                                                {"GL_TEXTURE_BUFFER", GL_TEXTURE_BUFFER},
                                                {"GL_TEXTURE_2D_MULTISAMPLE", GL_TEXTURE_2D_MULTISAMPLE},
                                                {"GL_TEXTURE_2D_MULTISAMPLE_ARRAY", GL_TEXTURE_2D_MULTISAMPLE_ARRAY},
                                                {"GL_TEXTURE_EXTERNAL_OES", GL_TEXTURE_EXTERNAL_OES},
                                            })),

        DEFINE_NAPI_STATIC_VALUE(
            "VertexAttribParamName",
            createEnum(env,
                       {
                           {"GL_CURRENT_VERTEX_ATTRIB", GL_CURRENT_VERTEX_ATTRIB},
                           {"GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING", GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING},
                           {"GL_VERTEX_ATTRIB_ARRAY_ENABLED", GL_VERTEX_ATTRIB_ARRAY_ENABLED},
                           {"GL_VERTEX_ATTRIB_ARRAY_SIZE", GL_VERTEX_ATTRIB_ARRAY_SIZE},
                           {"GL_VERTEX_ATTRIB_ARRAY_STRIDE", GL_VERTEX_ATTRIB_ARRAY_STRIDE},
                           {"GL_VERTEX_ATTRIB_ARRAY_TYPE", GL_VERTEX_ATTRIB_ARRAY_TYPE},
                           {"GL_VERTEX_ATTRIB_ARRAY_NORMALIZED", GL_VERTEX_ATTRIB_ARRAY_NORMALIZED},
                           {"GL_VERTEX_ATTRIB_ARRAY_INTEGER", GL_VERTEX_ATTRIB_ARRAY_INTEGER},
                           {"GL_VERTEX_ATTRIB_ARRAY_DIVISOR", GL_VERTEX_ATTRIB_ARRAY_DIVISOR},
                           {"GL_VERTEX_ATTRIB_BINDING", GL_VERTEX_ATTRIB_BINDING},
                       })),


        DEFINE_NAPI_STATIC_VALUE(
            "OHNativeErrorCode",
            createEnum(
                env,
                {
                    {"NATIVE_ERROR_OK", NATIVE_ERROR_OK},
                    {"NATIVE_ERROR_INVALID_ARGUMENTS", NATIVE_ERROR_INVALID_ARGUMENTS},
                    {"NATIVE_ERROR_NO_PERMISSION", NATIVE_ERROR_NO_PERMISSION},
                    {"NATIVE_ERROR_NO_BUFFER", NATIVE_ERROR_NO_BUFFER},
                    {"NATIVE_ERROR_NO_CONSUMER", NATIVE_ERROR_NO_CONSUMER},
                    {"NATIVE_ERROR_NOT_INIT", NATIVE_ERROR_NOT_INIT},
                    {"NATIVE_ERROR_CONSUMER_CONNECTED", NATIVE_ERROR_CONSUMER_CONNECTED},
                    {"NATIVE_ERROR_BUFFER_STATE_INVALID", NATIVE_ERROR_BUFFER_STATE_INVALID},
                    {"NATIVE_ERROR_BUFFER_IN_CACHE", NATIVE_ERROR_BUFFER_IN_CACHE},
                    {"NATIVE_ERROR_BUFFER_QUEUE_FULL", NATIVE_ERROR_BUFFER_QUEUE_FULL},
                    {"NATIVE_ERROR_BUFFER_NOT_IN_CACHE", NATIVE_ERROR_BUFFER_NOT_IN_CACHE},
                    {"NATIVE_ERROR_CONSUMER_DISCONNECTED", NATIVE_ERROR_CONSUMER_DISCONNECTED},
                    {"NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED", NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED},
                    {"NATIVE_ERROR_UNSUPPORTED", NATIVE_ERROR_UNSUPPORTED},
                    {"NATIVE_ERROR_UNKNOWN", NATIVE_ERROR_UNKNOWN},
                    {"NATIVE_ERROR_HDI_ERROR", NATIVE_ERROR_HDI_ERROR},
                    {"NATIVE_ERROR_BINDER_ERROR", NATIVE_ERROR_BINDER_ERROR},
                    {"NATIVE_ERROR_EGL_STATE_UNKNOWN", NATIVE_ERROR_EGL_STATE_UNKNOWN},
                    {"NATIVE_ERROR_EGL_API_FAILED", NATIVE_ERROR_EGL_API_FAILED},
                })),


    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "gles",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterGlesModule(void) { napi_module_register(&demoModule); }
