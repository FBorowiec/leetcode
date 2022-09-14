#ifndef CPP_0001_TWO_SUM_HPP
#define CPP_0001_TWO_SUM_HPP

#include <vector>

namespace two_sum {

class Solution {
 public:
  /**
   * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
   * You may assume that each input would have exactly one solution, and you may not use the same element twice.
   */
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for (unsigned int i = 0; i < nums.size(); ++i) {
      for (unsigned int j = 0; j < nums.size(); ++j) {
        if (i == j) continue;
        int sum = nums[i] + nums[j];
        if (sum == target) {
          std::vector<int> vec{(int)i, (int)j};
          return vec;
        }
      }
    }
    return {0};
  }
};

}  // namespace two_sum

#endif  // CPP_0001_TWO_SUM_HPP
