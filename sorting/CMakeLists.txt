cmake_minimum_required(VERSION 3.0)

add_executable(bubble_sort_test bubble_sort_test.cpp)
add_executable(selection_sort_test selection_sort_test.cpp)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(bubble_sort_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_link_libraries(selection_sort_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
