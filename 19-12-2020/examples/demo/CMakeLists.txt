cmake_minimum_required(VERSION 3.15)
project(Demo)

add_executable(Demo)
target_sources(Demo PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Demo.cpp")