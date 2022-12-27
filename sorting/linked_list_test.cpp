/*
 * =====================================================================================
 *
 *       Filename:  linked_list_test.cpp
 *
 *    Description:  Unit test for linked list.
 *
 *        Version:  1.0
 *        Created:  12/27/2022 13:25:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include "linked_list.h"
#include "array_helper.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(LinkedList, Int1) {
  LinkedList<int> list = {1};
  list.MergeSort();
  EXPECT_EQ("1", list.String());
}

TEST(LinkedList, Int5) {
  LinkedList<int> list = {0, 4, 3, 2, 1};
  list.MergeSort();
  EXPECT_EQ("0 -> 1 -> 2 -> 3 -> 4", list.String());
};

TEST(LinkedList, Int10) {
  LinkedList<int> list = {8, 7, 0, 1, 2, 9, 4, 5, 3, 6};
  list.MergeSort();
  EXPECT_EQ("0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9", list.String());
}

TEST(LinkedList, Duplicated) {
  LinkedList<int> list = {3, 0, 1, 5, 3, 0};
  list.MergeSort();
  EXPECT_EQ("0 -> 0 -> 1 -> 3 -> 3 -> 5", list.String());
}

class LinkedListTest: public testing::Test {
 protected:
  void SetUp() override { std::srand(std::time(nullptr)); }
};

TEST_F(LinkedListTest, Random) {
  std::vector<int> nums = GenRandVector(100);
  std::vector<int> copy = nums;
  LinkedList<int> list1(nums);
  list1.MergeSort();
  std::sort(copy.begin(), copy.end());
  LinkedList<int> list2(copy);
  EXPECT_EQ(list2.String(), list1.String());
}
