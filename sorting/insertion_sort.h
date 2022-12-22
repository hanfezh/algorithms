/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.h
 *
 *    Description:  Insertion sort.
 *
 *        Version:  1.0
 *        Created:  12/22/2022 22:31:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include <array>

template <typename T, std::size_t N>
void InsertionSort(std::array<T, N>& arr) {
  for (int i = 1; i < N; i++) {
    int k = arr[i];
    int j = i;
    while (j > 0 && k < arr[j - 1]) {
      arr[j] = arr[j - 1];
      j--;
    }
    if (j != i) {
      arr[j] = k;
    }
  }
}
