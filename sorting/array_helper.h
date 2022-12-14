/*
 * =====================================================================================
 *
 *       Filename:  array_helper.h
 *
 *    Description:  Helper functions for array.
 *
 *        Version:  1.0
 *        Created:  12/22/2022 16:00:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef SORTING_ARRAY_HELPER_H__
#define SORTING_ARRAY_HELPER_H__

#include <array>
#include <cstdlib>
#include <vector>

template <std::size_t N>
std::array<int, N> GenRandArray() {
  std::array<int, N> arr;
  for (int i = 0; i < N; i++) {
    arr[i] = std::rand();
  }
  return arr;
}

std::vector<int> GenRandVector(const std::size_t n);

#endif  // SORTING_ARRAY_HELPER_H__
