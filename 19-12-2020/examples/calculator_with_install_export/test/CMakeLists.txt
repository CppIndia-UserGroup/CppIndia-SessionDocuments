add_executable(calculator_unit_test)

target_sources(calculator_unit_test
			   PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp"
			   )

find_package(GTest CONFIG REQUIRED)

target_link_libraries(calculator_unit_test PRIVATE calculator GTest::gtest)

add_test(NAME calculator_tests COMMAND calculator_unit_test)