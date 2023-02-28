/*
 * =====================================================================================
 *
 *       Filename:  heap_sort.h
 *
 *    Description:  Heap sort.
 *
 *        Version:  1.0
 *        Created:  02/28/23 08:27:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef SORTING_HEAP_SORT_H__
#define SORTING_HEAP_SORT_H__

#include <algorithm>
#include <array>

template <typename T, std::size_t N>
void HeapSort(std::array<T, N>& arr);

template <typename T, std::size_t N>
void HeapifyDown(std::array<T, N>& arr, int size, int i) {
  int l = i * 2 + 1;
  int r = i * 2 + 2;
  int m = i;
  if (l < size && arr[l] > arr[m]) {
    m = l;
  }
  if (r < size && arr[r] > arr[m]) {
    m = r;
  }
  if (i != m) {
    std::swap(arr[i], arr[m]);
    HeapifyDown(arr, size, m);
  }
}

template <typename T, std::size_t N>
void HeapSort(std::array<T, N>& arr) {
  for (int i = (N - 1) / 2; i >= 0; i--) {
    HeapifyDown(arr, N, i);
  }
  for (int i = N - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);
    HeapifyDown(arr, i, 0);
  }
}

#endif  // SORTING_HEAP_SORT_H__
