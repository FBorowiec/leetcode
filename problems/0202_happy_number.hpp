#ifndef LEETCODE_PROBLEMS_0202_HAPPY_NUMBER_HPP
#define LEETCODE_PROBLEMS_0202_HAPPY_NUMBER_HPP

#include <chrono>
#include <cmath>
#include <string>

namespace happy_number {

class Solution {
 public:
  /**
   * Write an algorithm to determine if a number n is "happy".
   * a happy number is a number defined by the following process:
   *   Starting with any positive integer, replace the number by the sum of the squares of its digits,
   *   and repeat the process until the number equals 1 (where it will stay),
   *   or it loops endlessly in a cycle which does not include 1.
   *
   * Those numbers for which this process ends in 1 are happy numbers.
   * Return True if n is a happy number, and False if not.
   */
  bool isHappy(int n) {
    if (n < 1) return false;
    int res = 0;
    auto start_time = std::chrono::high_resolution_clock::now();
    while (res != 1) {
      if ((std::chrono::high_resolution_clock::now() - start_time).count() > 2e9) return false;
      auto n_s{std::to_string(n)};
      n = 0;
      for (unsigned int i = 0; i < n_s.length(); ++i) {
        n += std::pow((int)n_s[i] - 48, 2);
      }
      res = n;
      n_s = std::to_string(n);
    }
    return true;
  }
};

}  // namespace happy_number

#endif  // LEETCODE_PROBLEMS_0202_HAPPY_NUMBER_HPP
