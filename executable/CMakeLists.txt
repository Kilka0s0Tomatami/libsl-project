cmake_minimum_required(VERSION 3.29)
project(executable)
set(EXECUTABLE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/executable)

add_executable(executable main.cpp)
target_link_libraries(executable PRIVATE libsl-parser)
