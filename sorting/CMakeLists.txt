cmake_minimum_required(VERSION 3.0)

add_executable(sorting_test 
    bubble_sort_test.cpp
    selection_sort_test.cpp
    insertion_sort_test.cpp
    merge_sort_test.cpp)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(sorting_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
