#include "atomic/Atomic.h"
#include "gles/GLES.h"
#include "gles/GLESExtends.h"
#include "nativeimage/NativeImage.h"
#include "napi/native_api.h"


EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
//     GLES::Export(env, exports);
    /*    napi_property_descriptor desc[] = {
            { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr }
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);*/

    /***
     * defined AtomicInt
     */
    napi_property_descriptor atomicDesc[] = {
        {"sub", nullptr, Atomic::NapiAtomicIntSub, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"value", nullptr, nullptr, Atomic::NapiGetIntValue, nullptr, nullptr, napi_default, nullptr},
    };
    napi_value atomicIntCons = nullptr;
    napi_define_sendable_class(env, "AtomicInt", NAPI_AUTO_LENGTH, Atomic::NapiCreateAtomicInt, nullptr,
                               sizeof(atomicDesc) / sizeof(atomicDesc[0]), atomicDesc, nullptr, &atomicIntCons);
    napi_set_named_property(env, exports, "AtomicInt", atomicIntCons);

    /***
     * defined NativeImage
     */

    napi_property_descriptor nativeImageDesc[] = {
        {"surfaceId", nullptr, nullptr, NativeImage::NapiGetSurfaceId, nullptr, nullptr, napi_default, nullptr},
        {"isAvailable", nullptr, nullptr, NativeImage::NapiGetIsAvailable, nullptr, nullptr, napi_default, nullptr},
        {"attachContext", nullptr, NativeImage::NapiAttachContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"detachContext", nullptr, NativeImage::NapiDetachContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"updateSurfaceImage", nullptr, NativeImage::NapiUpdateSurfaceImage, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"destroy", nullptr, NativeImage::NapiDestroyNativeImage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"setOnFrameAvailableListener", nullptr, NativeImage::NapiSetOnFrameAvailableListener, nullptr, nullptr,
         nullptr, napi_default, nullptr},
        {"unSetOnFrameAvailableListener", nullptr, NativeImage::NapiUnSetOnFrameAvailableListener, nullptr, nullptr,
         nullptr, napi_default, nullptr},
    };
    napi_value nativeImageCons = nullptr;
    napi_define_sendable_class(env, "NativeImage", NAPI_AUTO_LENGTH, NativeImage::NapiBindNativeImage, nullptr,
                               sizeof(nativeImageDesc) / sizeof(nativeImageDesc[0]), nativeImageDesc, nullptr,
                               &nativeImageCons);
    napi_set_named_property(env, exports, "NativeImage", nativeImageCons);


    /***
     * defined property
     */
    napi_property_descriptor desc[] = {
        {"glActiveShaderProgram", nullptr, GLES::NapiGLActiveShaderProgram, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glActiveTexture", nullptr, GLES::NapiGLActiveTexture, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glAttachShader", nullptr, GLES::NapiGLAttachShader, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBindAttribLocation", nullptr, GLES::NapiGLBindAttribLocation, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glBindBuffer", nullptr, GLES::NapiGLBindBuffer, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBindFramebuffer", nullptr, GLES::NapiGLBindFramebuffer, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBindRenderbuffer", nullptr, GLES::NapiGLBindRenderbuffer, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBindTexture", nullptr, GLES::NapiGLBindTexture, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBlendColor", nullptr, GLES::NapiGLBlendColor, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBlendEquation", nullptr, GLES::NapiGLBlendEquation, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBlendEquationi", nullptr, GLES::NapiGLBlendEquationi, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBlendEquationSeparate", nullptr, GLES::NapiGLBlendEquationSeparate, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glBeginTransformFeedback", nullptr, GLES::NapiGLBeginTransformFeedback, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glEndTransformFeedback", nullptr, GLES::NapiGLEndTransformFeedback, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glBeginQuery", nullptr, GLES::NapiGLBeginQuery, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glEndQuery", nullptr, GLES::NapiGLEndQuery, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBlendFunc", nullptr, GLES::NapiGLBlendFunc, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBlendFuncSeparate", nullptr, GLES::NapiGLBlendFuncSeparate, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glBlendFuncSeparatei", nullptr, GLES::NapiGLBlendFuncSeparatei, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glBufferData", nullptr, GLES::NapiGLBufferData, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBufferSubData", nullptr, GLES::NapiGLBufferSubData, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glCheckFramebufferStatus", nullptr, GLES::NapiGLCheckFramebufferStatus, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glClear", nullptr, GLES::NapiGLClear, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glClearColor", nullptr, GLES::NapiGLClearColor, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glClearDepthf", nullptr, GLES::NapiGLClearDepthf, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glClearStencil", nullptr, GLES::NapiGLClearStencil, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glColorMask", nullptr, GLES::NapiGLColorMask, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glCompileShader", nullptr, GLES::NapiGLCompileShader, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glCompressedTexImage2D", nullptr, GLES::NapiGLCompressedTexImage2D, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glCompressedTexSubImage2D", nullptr, GLES::NapiGLCompressedTexSubImage2D, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glCopyTexImage2D", nullptr, GLES::NapiGLCopyTexImage2D, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glCopyTexSubImage2D", nullptr, GLES::NapiGLCopyTexSubImage2D, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glCreateProgram", nullptr, GLES::NapiGLCreateProgram, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glCreateShader", nullptr, GLES::NapiGLCreateShader, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glCullFace", nullptr, GLES::NapiGLCullFace, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDeleteBuffers", nullptr, GLES::NapiGLDeleteBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDeleteVertexArrays", nullptr, GLES::NapiGLDeleteVertexArrays, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glDeleteFramebuffers", nullptr, GLES::NapiGLDeleteFramebuffers, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glDeleteProgram", nullptr, GLES::NapiGLDeleteProgram, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDeleteRenderbuffers", nullptr, GLES::NapiGLDeleteRenderbuffers, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glDeleteShader", nullptr, GLES::NapiGLDeleteShader, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDeleteTextures", nullptr, GLES::NapiGLDeleteTextures, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDepthFunc", nullptr, GLES::NapiGLDepthFunc, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDepthMask", nullptr, GLES::NapiGLDepthMask, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDepthRangef", nullptr, GLES::NapiGLDepthRangef, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDetachShader", nullptr, GLES::NapiGLDetachShader, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDisable", nullptr, GLES::NapiGLDisable, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDisableVertexAttribArray", nullptr, GLES::NapiGLDisableVertexAttribArray, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glDrawArrays", nullptr, GLES::NapiGLDrawArrays, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glDrawElements", nullptr, GLES::NapiGLDrawElements, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glEnable", nullptr, GLES::NapiGLEnable, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glEnableVertexAttribArray", nullptr, GLES::NapiGLEnableVertexAttribArray, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glFinish", nullptr, GLES::NapiGLFinish, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glFlush", nullptr, GLES::NapiGLFlush, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glFramebufferRenderbuffer", nullptr, GLES::NapiGLFramebufferRenderbuffer, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glFramebufferTexture2D", nullptr, GLES::NapiGLFramebufferTexture2D, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glFrontFace", nullptr, GLES::NapiGLFrontFace, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGenBuffers", nullptr, GLES::NapiGLGenBuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGenVertexArrays", nullptr, GLES::NapiGLGenVertexArrays, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGenerateMipmap", nullptr, GLES::NapiGLGenerateMipmap, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGenFramebuffers", nullptr, GLES::NapiGLGenFramebuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGenRenderbuffers", nullptr, GLES::NapiGLGenRenderbuffers, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGenTextures", nullptr, GLES::NapiGLGenTextures, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetActiveAttrib", nullptr, GLES::NapiGLGetActiveAttrib, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetActiveUniform", nullptr, GLES::NapiGLGetActiveUniform, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetAttachedShaders", nullptr, GLES::NapiGLGetAttachedShaders, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetAttribLocation", nullptr, GLES::NapiGLGetAttribLocation, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetBooleanv", nullptr, GLES::NapiGLGetBooleanv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetBufferParameteriv", nullptr, GLES::NapiGLGetBufferParameteriv, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetBufferParameteri64v", nullptr, GLES::NapiGLGetBufferParameteri64v, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glGetError", nullptr, GLES::NapiGLGetError, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetFloatv", nullptr, GLES::NapiGLGetFloatv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetFramebufferAttachmentParameteriv", nullptr, GLES::NapiGLGetFramebufferAttachmentParameteriv, nullptr,
         nullptr, nullptr, napi_default, nullptr},
        {"glGetIntegerv", nullptr, GLES::NapiGLGetIntegerv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetInteger64v", nullptr, GLES::NapiGLGetInteger64v, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetProgramiv", nullptr, GLES::NapiGLGetProgramiv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetProgramInfoLog", nullptr, GLES::NapiGLGetProgramInfoLog, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetRenderbufferParameteriv", nullptr, GLES::NapiGLGetRenderbufferParameteriv, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glGetShaderiv", nullptr, GLES::NapiGLGetShaderiv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetShaderInfoLog", nullptr, GLES::NapiGLGetShaderInfoLog, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetShaderPrecisionFormat", nullptr, GLES::NapiGLGetShaderPrecisionFormat, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glGetShaderSource", nullptr, GLES::NapiGLGetShaderSource, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetString", nullptr, GLES::NapiGLGetString, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetTexParameterfv", nullptr, GLES::NapiGLGetTexParameterfv, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetTexParameteriv", nullptr, GLES::NapiGLGetTexParameteriv, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetUniformfv", nullptr, GLES::NapiGLGetUniformfv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetUniformiv", nullptr, GLES::NapiGLGetUniformiv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glGetUniformLocation", nullptr, GLES::NapiGLGetUniformLocation, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetVertexAttribfv", nullptr, GLES::NapiGLGetVertexAttribfv, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetVertexAttribiv", nullptr, GLES::NapiGLGetVertexAttribiv, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glGetVertexAttribPointerv", nullptr, GLES::NapiGLGetVertexAttribPointerv, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glHint", nullptr, GLES::NapiGLHint, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glIsBuffer", nullptr, GLES::NapiGLIsBuffer, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glIsEnabled", nullptr, GLES::NapiGLIsEnabled, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glIsFramebuffer", nullptr, GLES::NapiGLIsFramebuffer, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glIsProgram", nullptr, GLES::NapiGLIsProgram, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glIsRenderbuffer", nullptr, GLES::NapiGLIsRenderbuffer, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glIsShader", nullptr, GLES::NapiGLIsShader, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glIsTexture", nullptr, GLES::NapiGLIsTexture, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glLineWidth", nullptr, GLES::NapiGLLineWidth, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glLinkProgram", nullptr, GLES::NapiGLLinkProgram, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glPixelStorei", nullptr, GLES::NapiGLPixelStorei, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glPolygonOffset", nullptr, GLES::NapiGLPolygonOffset, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glReadPixels", nullptr, GLES::NapiGLReadPixels, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glReleaseShaderCompiler", nullptr, GLES::NapiGLReleaseShaderCompiler, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glRenderbufferStorage", nullptr, GLES::NapiGLRenderbufferStorage, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glSampleCoverage", nullptr, GLES::NapiGLSampleCoverage, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glScissor", nullptr, GLES::NapiGLScissor, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glShaderBinary", nullptr, GLES::NapiGLShaderBinary, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glShaderSource", nullptr, GLES::NapiGLShaderSource, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glStencilFunc", nullptr, GLES::NapiGLStencilFunc, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glStencilFuncSeparate", nullptr, GLES::NapiGLStencilFuncSeparate, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glStencilMask", nullptr, GLES::NapiGLStencilMask, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glStencilMaskSeparate", nullptr, GLES::NapiGLStencilMaskSeparate, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glStencilOp", nullptr, GLES::NapiGLStencilOp, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glStencilOpSeparate", nullptr, GLES::NapiGLStencilOpSeparate, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glTexImage2D", nullptr, GLES::NapiGLTexImage2D, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glTexParameterf", nullptr, GLES::NapiGLTexParameterf, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glTexParameterfv", nullptr, GLES::NapiGLTexParameterfv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glTexParameteri", nullptr, GLES::NapiGLTexParameteri, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glTexParameteriv", nullptr, GLES::NapiGLTexParameteriv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glTexSubImage2D", nullptr, GLES::NapiGLTexSubImage2D, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform1f", nullptr, GLES::NapiGLUniform1f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform1fv", nullptr, GLES::NapiGLUniform1fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform1i", nullptr, GLES::NapiGLUniform1i, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform1iv", nullptr, GLES::NapiGLUniform1iv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform2f", nullptr, GLES::NapiGLUniform2f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform2fv", nullptr, GLES::NapiGLUniform2fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform2i", nullptr, GLES::NapiGLUniform2i, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform2iv", nullptr, GLES::NapiGLUniform2iv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform3f", nullptr, GLES::NapiGLUniform3f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform3fv", nullptr, GLES::NapiGLUniform3fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform3i", nullptr, GLES::NapiGLUniform3i, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform3iv", nullptr, GLES::NapiGLUniform3iv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform4f", nullptr, GLES::NapiGLUniform4f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform4fv", nullptr, GLES::NapiGLUniform4fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform4i", nullptr, GLES::NapiGLUniform4i, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniform4iv", nullptr, GLES::NapiGLUniform4iv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniformMatrix2fv", nullptr, GLES::NapiGLUniformMatrix2fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniformMatrix3fv", nullptr, GLES::NapiGLUniformMatrix3fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUniformMatrix4fv", nullptr, GLES::NapiGLUniformMatrix4fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glUseProgram", nullptr, GLES::NapiGLUseProgram, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glValidateProgram", nullptr, GLES::NapiGLValidateProgram, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib1f", nullptr, GLES::NapiGLVertexAttrib1f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib1fv", nullptr, GLES::NapiGLVertexAttrib1fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib2f", nullptr, GLES::NapiGLVertexAttrib2f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib2fv", nullptr, GLES::NapiGLVertexAttrib2fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib3f", nullptr, GLES::NapiGLVertexAttrib3f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib3fv", nullptr, GLES::NapiGLVertexAttrib3fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib4f", nullptr, GLES::NapiGLVertexAttrib4f, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttrib4fv", nullptr, GLES::NapiGLVertexAttrib4fv, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttribPointer", nullptr, GLES::NapiGLVertexAttribPointer, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glViewport", nullptr, GLES::NapiGLViewport, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBindVertexArray", nullptr, GLES::NapiGLBindVertexArray, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glBindVertexBuffer", nullptr, GLES::NapiGLBindVertexBuffer, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"glVertexAttribFormat", nullptr, GLES::NapiGLVertexAttribFormat, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glVertexAttribIFormat", nullptr, GLES::NapiGLVertexAttribIFormat, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"glVertexAttribBinding", nullptr, GLES::NapiGLVertexAttribBinding, nullptr, nullptr, nullptr, napi_default,
         nullptr},

        {"bindNativeImage_", nullptr, NativeImage::NapiBindNativeImage, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"updateSurfaceImage_", nullptr, NativeImage::NapiUpdateSurfaceImage, nullptr, nullptr, nullptr, napi_default,
         nullptr},
        {"attachContext_", nullptr, NativeImage::NapiAttachContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"detachContext_", nullptr, NativeImage::NapiDetachContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"destroyNativeImage_", nullptr, NativeImage::NapiDestroyNativeImage, nullptr, nullptr, nullptr, napi_default,
         nullptr},

        // extends
        //  extend
        {"createShaderWithSource_", nullptr, GLESExtends::NapiCreateShaderWidthSource, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        {"glTexParameteriGroup_", nullptr, GLESExtends::NapiGLTexParameteriGroup, nullptr, nullptr, nullptr,
         napi_default, nullptr},

        // Atomic
//         {"createAtomicBool_", nullptr, Atomic::NapiCreateAtomicBool, nullptr, nullptr, nullptr, napi_default,
//         nullptr},
//         {"getAtomicBoolValue_", nullptr, Atomic::NapiGetBoolValue, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"setAtomicBoolValue_", nullptr, Atomic::NapiSetBoolValue, nullptr, nullptr, nullptr, napi_default, nullptr},
//
//         {"createAtomicInt_", nullptr, Atomic::NapiCreateAtomicInt, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"subAtomicIntValue_", nullptr, Atomic::NapiAtomicIntSub, nullptr, nullptr, nullptr, napi_default, nullptr},
//         {"getAtomicIntValue_", nullptr, Atomic::NapiGetIntValue, nullptr, nullptr, nullptr, napi_default, nullptr},

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
