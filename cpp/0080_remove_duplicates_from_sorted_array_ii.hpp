#ifndef CPP_0080_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_HPP
#define CPP_0080_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_HPP

#include <vector>

namespace remove_duplicates_from_sorted_array_ii {

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int last_element{nums[0]};
    unsigned int current_index{1};
    unsigned int current_el_count{1};

    for (unsigned int i = 1; i < nums.size(); ++i) {
      if (nums[i] == last_element) {
        current_el_count++;
        if (current_el_count <= 2) {
          nums[current_index++] = nums[i];
        }
      } else {
        last_element = nums[i];
        nums[current_index++] = nums[i];
        current_el_count = 1;
      }
    }
    return current_index;
  }
};

}  // namespace remove_duplicates_from_sorted_array_ii

#endif  // CPP_0080_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_HPP
