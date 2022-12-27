/*
 * =====================================================================================
 *
 *       Filename:  array_helper.cpp
 *
 *    Description:  Helper functions for array.
 *
 *        Version:  1.0
 *        Created:  12/27/2022 14:42:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hanfezh<xianfeng.zhu@gmail.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include "array_helper.h"

std::vector<int> GenRandVector(const std::size_t n) {
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = std::rand();
  }
  return arr;
}
