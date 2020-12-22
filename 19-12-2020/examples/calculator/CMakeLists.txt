cmake_minimum_required(VERSION 3.15)
project(Calculator)

add_library(calculator STATIC)
target_sources(calculator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/calculator.cpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/calculator.h"
	)

target_include_directories(calculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(main)
target_sources(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

target_link_libraries(main PRIVATE calculator)