/*
 * =====================================================================================
 *
 *       Filename:  selection_sort.h
 *
 *    Description:  Selection sort.
 *
 *        Version:  1.0
 *        Created:  12/22/2022 15:34:30
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
void SelectionSort(std::array<T, N>& arr) {
  for (int i = 0; i < N; i++) {
    int min_idx = i;
    for (int j = i + 1; j < N; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (i != min_idx) {
      std::swap(arr[i], arr[min_idx]);
    }
  }
}
