//UNSOLVED!
#ifndef LEETCODE_PROBLEMS_0402_REMOVE_K_DIGITS_HPP
#define LEETCODE_PROBLEMS_0402_REMOVE_K_DIGITS_HPP

#include <unordered_map>
#include <string>

namespace remove_k_digits
{

class Solution {
 public:
  /**
   * Given a non-negative integer num represented as a string,
   * remove k digits from the number so that the new number is the smallest possible.
   *
   * The length of num is less than 10002 and will be ≥ k.
   * The given num does not contain any leading zero.
   */
  std::string removeKdigits(std::string num, int k) {
    if (num.length() > 10002 || num.length() < (unsigned int)k) return "0";

    return "-1";
  }
};

}  // namespace remove_k_digits

#endif  // LEETCODE_PROBLEMS_0402_REMOVE_K_DIGITS_HPP
