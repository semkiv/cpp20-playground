cmake_minimum_required(VERSION 3.10.0)

project(cpp20-playground)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

set(
    CLANG_FLAGS
    "-pedantic-errors"
    "-Werror"
    "-Wpedantic"
    "-Wall"
    "-Wextra"
    "-Wctor-dtor-privacy"
    "-Wnon-virtual-dtor"
    "-Wold-style-cast"
    "-Woverloaded-virtual"
    "-Wsign-promo"
    "-Wfloat-equal"
    "-Wshadow"
    "-Wcast-qual"
    "-Wconversion"
    "-Wzero-as-null-pointer-constant"
    "-Wextra-semi"
    "-Wsign-conversion"
    "-Wredundant-decls"
)

set(
    GCC_FLAGS
    "${CLANG_FLAGS}"
    "-Wduplicated-branches"
    "-Wduplicated-cond"
    "-Wlogical-op"
    "-Wcast-align=strict"
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options("${CLANG_FLAGS}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options("${GCC_FLAGS}")
endif()

add_executable(cpp20-playground src/main.cpp)
