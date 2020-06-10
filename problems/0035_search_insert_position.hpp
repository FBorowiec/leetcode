#ifndef LEETCODE_PROBLEMS_0035_SEARCH_INSERT_POSITION_HPP
#define LEETCODE_PROBLEMS_0035_SEARCH_INSERT_POSITION_HPP

#include <vector>

namespace search_insert_position {

class Solution {
 public:
  /**
   * Given a sorted array and a target value, return the index if the target is found.
   * If not, return the index where it would be if it were inserted in order.
   * You may assume no duplicates in the array.
   */
  int searchInsert(std::vector<int>& nums, int target) {
    unsigned int i{0};
    for (; i<nums.size(); ++i) {
      if (target <= nums[i]) return i;
    }
    return i;
  }
};

}  // namespace search_insert_position

#endif  // LEETCODE_PROBLEMS_0035_SEARCH_INSERT_POSITION_HPP
