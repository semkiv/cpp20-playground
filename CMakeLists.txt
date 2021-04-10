cmake_minimum_required(VERSION 3.10.0)

project(cpp20-playground)

# General settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(IWYU_PATH NAMES include-what-you-use iwyu)
if(IWYU_PATH)
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "${IWYU_PATH}")
else()
  message(WARNING "Could not find `include-what-you-use` (`iwyu`)")
endif()

find_program(CLANG_TIDY_PATH NAMES clang-tidy)
if(CLANG_TIDY_PATH)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_PATH}" "--extra-arg=-Wno-unknown-warning-option")
else()
  message(WARNING "Could not find `clang-tidy`")
endif()

# Debug optimization options
set(MSVC_DEBUG_FLAGS "/Od /Zi")
set(CLANG_GCC_DEBUG_FLAGS "-O0 -g")

# Release optimization options
set(MSVC_RELEASE_FLAGS "/O2 /GL /Gw /Gy /D NDEBUG")
set(CLANG_GCC_RELEASE_FLAGS "-O3 -flto -DNDEBUG")

# Microsoft Visual C++ compilation options
set(
    MSVC_FLAGS
    "/utf-8"
    "/EHsc"
    "/MP"
    "/WX"
    "/W4"
    "/analyze"
    # "/fsanitize=address" # breaks incremental builds
)

# Clang compilation options
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

# GCC compilation options
set(
    GCC_FLAGS
    "${CLANG_FLAGS}"
    "-Wduplicated-branches"
    "-Wduplicated-cond"
    "-Wlogical-op"
    "-Wcast-align=strict"
    # "-fanalyzer" # requires GCC 10
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "${MSVC_DEBUG_FLAGS}")
    set(CMAKE_CXX_FLAGS_RELEASE "${MSVC_RELEASE_FLAGS}")
    add_compile_options("${MSVC_FLAGS}")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CLANG_GCC_DEBUG_FLAGS}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CLANG_GCC_RELEASE_FLAGS}")
    add_compile_options("${CLANG_FLAGS}")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "${CLANG_GCC_DEBUG_FLAGS}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CLANG_GCC_RELEASE_FLAGS}")
    add_compile_options("${GCC_FLAGS}")
endif()

if (UNIX)
    add_link_options("-lpthread")
endif (UNIX)

add_executable(cpp20-playground src/main.cpp)
