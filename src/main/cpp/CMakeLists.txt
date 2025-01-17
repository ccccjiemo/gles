# the minimum version of CMake.
cmake_minimum_required(VERSION 3.5.0)
project(myNpmLib)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(DEFINED PACKAGE_FIND_FILE)
    include(${PACKAGE_FIND_FILE})
endif()

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include
                    ${NATIVERENDER_ROOT_PATH}/glm)

add_library(gles SHARED napi_init.cpp gles/GLES.cpp nativeimage/NativeImage.cpp  gles/GLESExtends.cpp)
target_link_libraries(gles PUBLIC libace_napi.z.so libGLESv3.so libnative_image.so )