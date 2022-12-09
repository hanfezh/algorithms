/*
 * =====================================================================================
 *
 *       Filename:  bubble_sort_test.cpp
 *
 *    Description:  Unit test for bubble sort.
 *
 *        Version:  1.0
 *        Created:  12/09/2022 14:01:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include "bubble_sort.h"

#include <array>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(BubbleSort, Int1) {
  std::array<int, 1> nums{1};
  BubbleSort(nums);
  EXPECT_THAT(nums, testing::ElementsAreArray<int>({1}));
}

TEST(BubbleSort, Int5) {
  std::array<int, 5> nums = {0, 4, 3, 2, 1};
  BubbleSort(nums);
  EXPECT_THAT(nums, testing::ElementsAreArray<int>({0, 1, 2, 3, 4}));
};

TEST(BubbleSort, Int10) {
  std::array<int, 10> nums = {8, 7, 0, 1, 2, 9, 4, 5, 3, 6};
  BubbleSort(nums);
  EXPECT_THAT(nums, testing::ElementsAreArray<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST(BubbleSort, Duplicated) {
  std::array<int, 6> nums = {3, 0, 1, 5, 3, 0};
  BubbleSort(nums);
  EXPECT_THAT(nums, testing::ElementsAreArray<int>({0, 0, 1, 3, 3, 5}));
}
