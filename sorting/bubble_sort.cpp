/*
 * =====================================================================================
 *
 *       Filename:  bubble_sort.cpp
 *
 *    Description:  Bubble sort.
 *
 *        Version:  1.0
 *        Created:  12/09/2022 11:47:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include <array>
#include <cstdio>

template <typename T, std::size_t N>
void BubbleSort(std::array<T, N>& arr) {
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < (N - i); j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main(int argc, char* argv[]) {
  std::array<int, 10> nums = {8, 7, 0, 1, 2, 9, 4, 5, 3, 6};
  BubbleSort(nums);
  for (const int n : nums) {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
