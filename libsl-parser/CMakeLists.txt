cmake_minimum_required(VERSION 3.24)
project(libsl-parser)
set(LIBSL-PARSER_SOURCE_DIR ${CMAKE_SOURCE_DIR}/libsl-parser)

add_library(libsl-parser SHARED lib.cpp)