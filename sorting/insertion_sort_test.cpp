/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort_test.cpp
 *
 *    Description:  Unit test for insertion sort.
 *
 *        Version:  1.0
 *        Created:  12/22/2022 22:35:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include "insertion_sort.h"
#include "array_helper.h"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(InsertionSort, Int1) {
  std::array<int, 1> nums{1};
  InsertionSort(nums);
  EXPECT_THAT(nums, testing::ElementsAreArray<int>({1}));
}

TEST(InsertionSort, Int5) {
  std::array<int, 5> nums = {0, 4, 3, 2, 1};
  std::array<int, 5> copy = nums;
  InsertionSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
};

TEST(InsertionSort, Int10) {
  std::array<int, 10> nums = {8, 7, 0, 1, 2, 9, 4, 5, 3, 6};
  std::array<int, 10> copy = nums;
  InsertionSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}

TEST(InsertionSort, Duplicated) {
  std::array<int, 6> nums = {3, 0, 1, 5, 3, 0};
  std::array<int, 6> copy = nums;
  InsertionSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}

class InsertionSortTest : public testing::Test {
 protected:
  void SetUp() override { std::srand(std::time(nullptr)); }
};

TEST_F(InsertionSortTest, Random) {
  std::array<int, 100> nums = GenRandArray<100>();
  std::array<int, 100> copy = nums;
  InsertionSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}
