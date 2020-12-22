cmake_minimum_required(VERSION 3.15)
project(Calculator)

option(BUILD_TESTS "build unit tests" OFF)

add_library(calculator STATIC)
target_sources(calculator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/calculator.cpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/calculator.h"
	)

target_include_directories(calculator PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	PUBLIC $<INSTALL_INTERFACE:include>
	)

set(PACKAGE_NAME Calculator)
set(PACKAGE_VERSION 1.0.0)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/Calculator.h"
	DESTINATION include
	)

set(TARGET_EXPORT_NAME ${PACKAGE_NAME}Targets)
		
install(TARGETS calculator
	EXPORT ${TARGET_EXPORT_NAME}
	ARCHIVE DESTINATION lib
	)

export(TARGETS calculator
	NAMESPACE ${PACKAGE_NAME}::
	FILE ${TARGET_EXPORT_NAME}.cmake
	)

install(EXPORT ${TARGET_EXPORT_NAME}
	FILE ${TARGET_EXPORT_NAME}.cmake
	DESTINATION cmake
	NAMESPACE ${PACKAGE_NAME}::
	)

set(CONFIG_INPUT ${PACKAGE_NAME}Config.cmake.in)
set(CONFIG_FILE ${PACKAGE_NAME}Config.cmake)
set(VERSION_FILE ${PACKAGE_NAME}ConfigVersion.cmake)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	cmake/${CONFIG_INPUT}
	${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_FILE}
	NO_SET_AND_CHECK_MACRO
	NO_CHECK_REQUIRED_COMPONENTS_MACRO
	INSTALL_DESTINATION cmake
	PATH_VARS TARGET_EXPORT_NAME
	)
	
write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/${VERSION_FILE}
	VERSION ${PACKAGE_VERSION}
	COMPATIBILITY AnyNewerVersion
		)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${VERSION_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_FILE}
	DESTINATION cmake
	)	

########################## unit tests ########################

if(BUILD_TESTS)
	enable_testing()
	add_subdirectory(test)
endif()