cmake_minimum_required(VERSION 2.8)

set(PROJECT openlf2)

project(${PROJECT})

file(GLOB_RECURSE OPENLF2_SOURCES "src/*.c")

set(COMPILER_PREFIX i686-w64-mingw32)
set(CMAKE_C_COMPILER ${COMPILER_PREFIX}-gcc)
set(CMAKE_C_FLAGS "-m32 -masm=intel -std=gnu11")

add_library(${PROJECT} SHARED ${OPENLF2_SOURCES})

# libopenlf2.dll -> openlf2.dll
set_target_properties(${PROJECT} PROPERTIES
    PREFIX ""
    SUFFIX ".dll")
