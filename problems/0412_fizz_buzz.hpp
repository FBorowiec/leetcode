#ifndef LEETCODE_PROBLEMS_0412_FIZZ_BUZZ_HPP
#define LEETCODE_PROBLEMS_0412_FIZZ_BUZZ_HPP

#include <string>
#include <vector>

namespace fizz_buzz {

class Solution {
 public:
  /**
   * Write a program that outputs the string representation of numbers from 1 to n.
   * But for multiples of three it should output “Fizz”
   * instead of the number and for the multiples of five output “Buzz”.
   * For numbers which are multiples of both three and five output “FizzBuzz”.
   */
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> ret;
    for (int i{1}; i <= n; ++i) {
      if (i % 3 == 0 && i % 5) ret.emplace_back("FizzBuzz");
      if (i % 3 == 0) ret.emplace_back("Fizz");
      if (i % 5 == 0) ret.emplace_back("Buzz");
      else ret.emplace_back(std::to_string(i));
    }
    return ret;
  }
};

}  // namespace fizz_buzz

#endif  // LEETCODE_PROBLEMS_0412_FIZZ_BUZZ_HPP
