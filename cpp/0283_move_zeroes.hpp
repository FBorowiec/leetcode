#ifndef CPP_0283_MOVE_ZEROES_HPP
#define CPP_0283_MOVE_ZEROES_HPP

#include <algorithm>
#include <vector>

namespace move_zeroes {

class Solution {
 public:
  /**
   * Given an array nums, write a function to move all 0's to the end of it
   * while maintaining the relative order of the non-zero elements.
   */
  std::vector<int> moveZeroes(std::vector<int>& nums) {
    std::vector<int> nums2{};
    unsigned int count{0};
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums2.emplace_back(nums[i]);
      } else {
        ++count;
      }
    }
    for (size_t i = 0; i < count; ++i) {
      nums2.emplace_back(0);
    }
    return nums2;
  }
};

}  // namespace move_zeroes

#endif  // CPP_0283_MOVE_ZEROES_HPP
