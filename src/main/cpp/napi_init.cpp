#include "GLES.h"
#include "napi/native_api.h"


EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    GLES::Export(env, exports);
    /*    napi_property_descriptor desc[] = {
            { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr }
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);*/
    napi_property_descriptor desc[] = {
        {"glActiveShaderProgram", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glActiveTexture", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glAttachShader", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBindAttribLocation", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBindBuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBindFramebuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBindRenderbuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBindTexture", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBlendColor", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBlendEquation", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBlendEquationi", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBlendEquationSeparate", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBlendFunc", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBlendFuncSeparate", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBufferData", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBufferSubData", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBeginTransformFeedback", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glEndTransformFeedback", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glBeginQuery", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glEndQuery", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCheckFramebufferStatus", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glClear", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glClearColor", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glClearDepthf", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glClearStencil", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glColorMask", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCompileShader", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCompressedTexImage2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCompressedTexSubImage2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCopyTexImage2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCopyTexSubImage2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCreateProgram", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCreateShader", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glCullFace", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDeleteBuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDeleteFramebuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDeleteProgram", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDeleteRenderbuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDeleteShader", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDeleteTextures", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDepthFunc", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDepthMask", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDepthRangef", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDetachShader", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDisable", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDisableVertexAttribArray", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDrawArrays", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glDrawElements", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glEnable", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glEnableVertexAttribArray", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glFinish", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glFlush", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glFramebufferRenderbuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glFramebufferTexture2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glFrontFace", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGenBuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGenerateMipmap", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGenFramebuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGenRenderbuffers", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGenTextures", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetActiveAttrib", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetActiveUniform", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetAttachedShaders", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetAttribLocation", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetBooleanv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetBufferParameteriv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetError", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetFloatv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetFramebufferAttachmentParameteriv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetIntegerv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetProgramiv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetProgramInfoLog", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetRenderbufferParameteriv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetShaderiv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetShaderInfoLog", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetShaderPrecisionFormat", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetShaderSource", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetString", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetTexParameterfv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetTexParameteriv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetUniformfv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetUniformiv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetUniformLocation", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetVertexAttribfv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetVertexAttribiv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glGetVertexAttribPointerv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glHint", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glIsBuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glIsEnabled", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glIsFramebuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glIsProgram", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glIsRenderbuffer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glIsShader", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glIsTexture", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glLineWidth", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glLinkProgram", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glPixelStorei", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glPolygonOffset", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glReadPixels", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glReleaseShaderCompiler", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glRenderbufferStorage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glSampleCoverage", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glScissor", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glShaderBinary", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glShaderSource", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glStencilFunc", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glStencilFuncSeparate", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glStencilMask", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glStencilMaskSeparate", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glStencilOp", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glStencilOpSeparate", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glTexImage2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glTexParameterf", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glTexParameterfv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glTexParameteri", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glTexParameteriv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glTexSubImage2D", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform1f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform1fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform1i", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform1iv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform2f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform2fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform2i", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform2iv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform3f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform3fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform3i", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform3iv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform4f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform4fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform4i", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniform4iv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniformMatrix2fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniformMatrix3fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUniformMatrix4fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glUseProgram", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glValidateProgram", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib1f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib1fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib2f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib2fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib3f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib3fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib4f", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttrib4fv", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glVertexAttribPointer", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"glViewport", nullptr, nullptr, nullptr, nullptr, nullptr, napi_static, nullptr},

    };
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
