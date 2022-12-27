/*
 * =====================================================================================
 *
 *       Filename:  bubble_sort.h
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
#ifndef SORTING_BUBBLE_SORT_H__
#define SORTING_BUBBLE_SORT_H__

#include <array>

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

#endif  // SORTING_BUBBLE_SORT_H__
