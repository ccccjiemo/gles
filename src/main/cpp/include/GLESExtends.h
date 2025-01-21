//
// Created on 2024/12/23.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef GLTEST_GLESEXTENDS_H
#define GLTEST_GLESEXTENDS_H

#include <napi/native_api.h>

namespace GLESExtends {
napi_value NapiCreateShaderWidthSource(napi_env env, napi_callback_info info);
napi_value NapiGLTexParameteriGroup(napi_env env, napi_callback_info info);
}


#endif //GLTEST_GLESEXTENDS_H
