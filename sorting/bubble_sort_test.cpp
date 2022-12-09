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

#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

template <std::size_t N>
std::array<int, N> GenRandArray() {
  std::array<int, N> arr;
  for (int i = 0; i < N; i++) {
    arr[i] = std::rand();
  }
  return arr;
}

TEST(BubbleSort, Int1) {
  std::array<int, 1> nums{1};
  BubbleSort(nums);
  EXPECT_THAT(nums, testing::ElementsAreArray<int>({1}));
}

TEST(BubbleSort, Int5) {
  std::array<int, 5> nums = {0, 4, 3, 2, 1};
  std::array<int, 5> copy = nums;
  BubbleSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
};

TEST(BubbleSort, Int10) {
  std::array<int, 10> nums = {8, 7, 0, 1, 2, 9, 4, 5, 3, 6};
  std::array<int, 10> copy = nums;
  BubbleSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}

TEST(BubbleSort, Duplicated) {
  std::array<int, 6> nums = {3, 0, 1, 5, 3, 0};
  std::array<int, 6> copy = nums;
  BubbleSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}

class BubbleSortTest : public testing::Test {
 protected:
  void SetUp() override { std::srand(std::time(nullptr)); }
};

TEST_F(BubbleSortTest, Random) {
  std::array<int, 100> nums = GenRandArray<100>();
  std::array<int, 100> copy = nums;
  BubbleSort(nums);
  std::sort(copy.begin(), copy.end());
  EXPECT_THAT(nums, testing::ElementsAreArray(copy));
}
