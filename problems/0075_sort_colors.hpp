#ifndef LEETCODE_PROBLEMS_0075_SORT_COLORS_HPP
#define LEETCODE_PROBLEMS_0075_SORT_COLORS_HPP

#include <algorithm>
#include <vector>

namespace sort_colors {

class Solution {
 public:
  /**
   * Given an array with n objects colored red, white or blue,
   * sort them in-place so that objects of the same color are adjacent,
   * with the colors in the order red, white and blue.
   *
   * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
   * Note: You are not suppose to use the library's sort function for this problem.
   *
   * Follow up:
   * A rather straight forward solution is a two-pass algorithm using counting sort.
   * First, iterate the array counting number of 0's, 1's, and 2's,
   * then overwrite array with total number of 0's, then 1's and followed by 2's.
   * Could you come up with a one-pass algorithm using only constant space?
   */
  void swap(int& a, int& b) {
    auto tmp = a;
    a = b;
    b = tmp;
  }

  void sortColors(std::vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    for (int i = 0; i <= r; ++i) {
      if (nums[i] == 0)
        swap(nums[i], nums[l++]);
      else if (nums[i] == 2)
        swap(nums[i--], nums[r--]);
    }
  }
};

}  // namespace sort_colors

#endif  // LEETCODE_PROBLEMS_0075_SORT_COLORS_HPP
