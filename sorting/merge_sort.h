/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.h
 *
 *    Description:  Merge sort.
 *
 *        Version:  1.0
 *        Created:  12/22/2022 22:55:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef SORTING_MERGE_SORT_H__
#define SORTING_MERGE_SORT_H__

#include <array>

template <typename T, std::size_t N>
void MergeSort(std::array<T, N>& arr);

template <typename T, std::size_t N>
void _MergeArray(std::array<T, N>& arr, std::array<T, N>& copy, int left, int right, int end) {
  for (int i = left; i < end; i++) {
    copy[i] = arr[i];
  }

  int i = left;
  int j = right;
  int k = left;
  while (i < right && j < end) {
    if (copy[i] < copy[j]) {
      arr[k++] = copy[i++];
    } else {
      arr[k++] = copy[j++];
    }
  }
  while (i < right) {
    arr[k++] = copy[i++];
  }
  while (j < end) {
    arr[k++] = copy[j++];
  }
}

template <typename T, std::size_t N>
void _MergeSort(std::array<T, N>& arr, std::array<T, N>& copy, int start, int end) {
  if (start >= (end - 1)) {
    return;
  }

  int mid = (start + end) / 2;
  _MergeSort(arr, copy, start, mid);
  _MergeSort(arr, copy, mid, end);
  _MergeArray(arr, copy, start, mid, end);
}

template <typename T, std::size_t N>
void MergeSort(std::array<T, N>& arr) {
  std::array<T, N> copy;
  _MergeSort(arr, copy, 0, N);
}

#endif  // SORTING_MERGE_SORT_H__
