#ifndef LEETCODE_PROBLEMS_0540_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_HPP
#define LEETCODE_PROBLEMS_0540_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_HPP

#include <vector>

namespace single_element_in_a_sorted_array
{

class Solution {
 public:
  /**
   * You are given a sorted array consisting of only integers where every element appears exactly twice,
   * except for one element which appears exactly once. Find this single element that appears only once.
   */
  int singleNonDuplicate(std::vector<int>& nums)
  {
    if (nums.size() < 2) return nums[0];
    for (size_t i{0}; i<nums.size(); i=i+2)
    {
      if (nums[i+1] == nums[i]) continue;
      else return nums[i];
    }
    return 0;
  }
};

}  // namespace single_element_in_a_sorted_array

#endif  // LEETCODE_PROBLEMS_0540_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_HPP