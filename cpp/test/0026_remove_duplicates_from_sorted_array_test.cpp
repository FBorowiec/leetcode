#include "gtest/gtest.h"

#include "cpp/0026_remove_duplicates_from_sorted_array.hpp"

namespace {

/**
 * Example 1:
 * Input: nums = [1,1,2]
 * Output: 2, nums = [1,2,_]
 * Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 * Example 2:
 *
 * Input: nums = [0,0,1,1,1,2,2,3,3,4]
 * Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 * Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4
 * respectively. It does not matter what you leave beyond the returned k (hence they are underscores).
 */
TEST(RemoveDuplicatesFromSortedArrayTest, RemoveDuplicatesTest1) {
  remove_duplicates_from_sorted_array::Solution sol{};
  std::vector<int> nums{1, 1, 2};
  int expected_result{2};
  int res = sol.removeDuplicates(nums);

  EXPECT_EQ(res, expected_result);
}

TEST(RemoveDuplicatesFromSortedArrayTest, RemoveDuplicatesTest2) {
  remove_duplicates_from_sorted_array::Solution sol{};
  std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int expected_result{5};
  int res = sol.removeDuplicates(nums);

  EXPECT_EQ(res, expected_result);
}

}  // namespace
