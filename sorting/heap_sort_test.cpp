/*
 * =====================================================================================
 *
 *       Filename:  heap_sort_test.cpp
 *
 *    Description:  Unit test for heap sort.
 *
 *        Version:  1.0
 *        Created:  02/28/23 09:05:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "heap_sort.h"
#include "array_helper.h"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(HeapSort, Int1) {
  std::array<int, 1> nums{1};
  HeapSort(nums);
  EXPECT_THAT(nums, testing::ElementsAreArray<int>({1}));
}

TEST(HeapSort, Int5) {
  std::array<int, 5> nums = {0, 4, 3, 2, 1};
  std::array<int, 5> copy = nums;
  HeapSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
};

TEST(HeapSort, Int10) {
  std::array<int, 10> nums = {8, 7, 0, 1, 2, 9, 4, 5, 3, 6};
  std::array<int, 10> copy = nums;
  HeapSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}

TEST(HeapSort, Duplicated) {
  std::array<int, 6> nums = {3, 0, 1, 5, 3, 0};
  std::array<int, 6> copy = nums;
  HeapSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}

class HeapSortTest : public testing::Test {
 protected:
  void SetUp() override { std::srand(std::time(nullptr)); }
};

TEST_F(HeapSortTest, Random) {
  std::array<int, 100> nums = GenRandArray<100>();
  std::array<int, 100> copy = nums;
  HeapSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}
