cmake_minimum_required(VERSION 2.8)

set(PROJECT openlf2)

SET(CMAKE_SYSTEM_NAME Windows)
set(COMPILER_PREFIX i686-w64-mingw32)
set(CMAKE_C_COMPILER /usr/bin/${COMPILER_PREFIX}-gcc)
set(CMAKE_C_FLAGS "-B /usr/${COMPILER_PREFIX} -std=gnu11")

# here is the target environment located
set(CMAKE_FIND_ROOT_PATH ${COMPILER_PREFIX})

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search 
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

file(GLOB_RECURSE OPENLF2_SOURCES "src/*.c")
add_library(${PROJECT} SHARED ${OPENLF2_SOURCES})

# libopenlf2.so -> openlf2.dll
set_target_properties(${PROJECT} PROPERTIES
    PREFIX ""
    SUFFIX ".dll")
