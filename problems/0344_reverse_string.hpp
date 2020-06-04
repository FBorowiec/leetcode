#ifndef LEETCODE_PROBLEMS_0344_REVERSE_STGRING_HPP
#define LEETCODE_PROBLEMS_0344_REVERSE_STGRING_HPP

#include <algorithm>
#include <string>
#include <vector>

namespace reverse_string {

class Solution {
 public:
  /**
   * Write a function that reverses a string. The input string is given as an array of characters char[].
   * Do not allocate extra space for another array,
   * you must do this by modifying the input array in-place with O(1) extra memory.
   * You may assume all the characters consist of printable ascii characters.
   */
  void reverseString(std::vector<char>& s) { std::reverse(s.begin(), s.end()); }
};

}  // namespace reverse_string

#endif  // LEETCODE_PROBLEMS_0344_REVERSE_STGRING_HPP
