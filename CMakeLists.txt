cmake_minimum_required(VERSION 3.5.1)
project(msl_clang_001)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c)

add_executable(msl_clang_001 ${SOURCE_FILES})