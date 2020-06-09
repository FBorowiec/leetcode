#ifndef LEETCODE_PROBLEMS_0392_IS_SUBSEQUENCE_HPP
#define LEETCODE_PROBLEMS_0392_IS_SUBSEQUENCE_HPP

#include <string>

namespace is_subsequence {

class Solution {
 public:
  /**
   * Given a string s and a string t, check if s is subsequence of t.
   * A subsequence of a string is a new string which is formed from the original string
   * by deleting some (can be none) of the characters without disturbing the relative
   * positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
   *
   * Follow up:
   * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B,
   * and you want to check one by one to see if T has its subsequence.
   * In this scenario, how would you change your code?
   *
   * Constraints:
   * 0 <= s.length <= 100
   * 0 <= t.length <= 10^4
   * Both strings consists only of lowercase characters.
   */
  bool isSubsequence(std::string s, std::string t) {
    if (s.length() == 0) return true;
    unsigned int matches{0}, j{0};
    for (unsigned int i{0}; i < s.length(); ++i) {
      for (; j < t.length(); j++) {
        if (s[i] == t[j]) {
          matches++;
          if (s.length() == matches) return true;
          i++;
        }
      }
    }
    return false;
  }
};

}  // namespace is_subsequence

#endif  // LEETCODE_PROBLEMS_0392_IS_SUBSEQUENCE_HPP
