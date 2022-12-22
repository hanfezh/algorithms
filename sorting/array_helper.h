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
#include <array>
#include <cstdlib>

template <std::size_t N>
std::array<int, N> GenRandArray() {
  std::array<int, N> arr;
  for (int i = 0; i < N; i++) {
    arr[i] = std::rand();
  }
  return arr;
}
