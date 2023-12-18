#ifndef CPP_0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
#define CPP_0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP

#include <vector>

namespace remove_duplicates_rom_sorted_array {

class Solution {
 public:
  /**
   * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique
   * element appears only once. The relative order of the elements should be kept the same. Then return the number of
   * unique elements in nums.
   *
   * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
   *     Change the array nums such that the first k elements of nums contain the unique elements in the order they were
   *     present in nums initially. The remaining elements of nums are not important as well as the size of nums.
   *     Return k.
   *
   * Custom Judge:
   * The judge will test your solution with the following code:
   *
   * int[] nums = [...]; // Input array
   * int[] expectedNums = [...]; // The expected answer with correct length
   *
   * int k = removeDuplicates(nums); // Calls your implementation
   *
   * assert k == expectedNums.length;
   * for (int i = 0; i < k; i++) {
   *     assert nums[i] == expectedNums[i];
   * }
   *
   * If all assertions pass, then your solution will be accepted.
   *
   * Constraints:
   *  -  1 <= nums.length <= 3 * 104
   *  -  -100 <= nums[i] <= 100
   *  -  nums is sorted in non-decreasing order.
   */
  int removeDuplicates(std::vector<int>& nums) {
    int last_element{nums[0]};
    unsigned int current_index{0};
    unsigned int counter{1};

    for (unsigned int i = 1; i < nums.size(); ++i) {
      if (nums[i] != last_element) {
        last_element = nums[i];
        nums[++current_index] = nums[i];
        counter++;
      }
    }
    return counter;
  }
};

}  // namespace remove_duplicates_rom_sorted_array

#endif  // CPP_0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
