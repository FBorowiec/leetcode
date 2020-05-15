//UNSOLVED!
#ifndef LEETCODE_PROBLEMS_0007_REVERSE_INTEGER_HPP
#define LEETCODE_PROBLEMS_0007_REVERSE_INTEGER_HPP

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

namespace reverse_integer
{

class Solution {
 public:
  /**
   * Given a 32-bit signed integer, reverse digits of an integer.
   *
   * Note: Assume we are dealing with an environment which could only store integers
   * within the 32-bit signed integer range: [−231,  231 − 1].
   * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
   */
  int reverse(int x)
  {
    if (x > std::numeric_limits<int>::max()) return 0;  // prevent overflows
    while (x % 10 == 0) x = x/10;  // discard zeroes at end of x
    return 0;
  }
};

}  // namespace reverse_integer

#endif  // LEETCODE_PROBLEMS_0007_REVERSE_INTEGER_HPP
