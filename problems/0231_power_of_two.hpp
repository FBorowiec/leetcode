#ifndef LEETCODE_PROBLEMS_0231_POWER_OF_TWO_HPP
#define LEETCODE_PROBLEMS_0231_POWER_OF_TWO_HPP

namespace power_of_two {

class Solution {
 public:
  /**
   * Given an integer, write a function to determine if it is a power of two.
   */
  bool isPowerOfTwo(int n) {
    if (n == 1) return true;
    while (n % 2 == 0 && n > 2) {
      n /= 2;
    }

    return n == 2.0 ? true : false;
  }
};

}  // namespace power_of_two

#endif  // LEETCODE_PROBLEMS_0231_POWER_OF_TWO_HPP
