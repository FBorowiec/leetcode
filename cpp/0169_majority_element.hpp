#ifndef CPP_0169_MAJORITY_ELEMENT_HPP
#define CPP_0169_MAJORITY_ELEMENT_HPP

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace majority_element {

class Solution {
 public:
  /**
   * Given an array of size n, find the majority element.
   * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
   * You may assume that the array is non-empty and the majority element always exist in the array.
   */
  int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, size_t> count{};

    for (int i : nums) {
      count[i]++;
    }

    std::sort(nums.begin(), nums.end(), [&count](const int& a, const int& b) {
      if (a == b)
        return false;
      else if (count[a] > count[b])
        return true;
      else if (count[a] < count[b])
        return false;
      return a < b;
    });
    return nums[0];
  }
};

}  // namespace majority_element

#endif  // CPP_0169_MAJORITY_ELEMENT_HPP
