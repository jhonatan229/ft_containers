cmake_minimum_required(VERSION 3.8) 
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../includes ${CMAKE_CURRENT_SOURCE_DIR}/../iterators ${CMAKE_CURRENT_SOURCE_DIR}/googletest)

add_subdirectory(googletest)

enable_testing()
project(tests_container VERSION 1.0.0)

add_executable(my_test_container
	test.cpp check_type_test.cpp utility_test.cpp my_vector_test.cpp my_map_test.cpp
)
target_link_libraries(my_test_container gtest_main)
target_include_directories(my_test_container PUBLIC ${HEADERS})
add_test(NAME my_test_container COMMAND my_test_container)

add_executable(original_test_container
	o_test.cpp original_map.cpp
)
target_link_libraries(original_test_container gtest_main)
target_include_directories(original_test_container PUBLIC ${HEADERS})
add_test(NAME original_test_container COMMAND original_test_container)

include(GoogleTest)
gtest_discover_tests(my_test_container original_test_container)