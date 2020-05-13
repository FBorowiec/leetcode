/**
 * You are given a sorted array consisting of only integers where every element appears exactly twice,
 * except for one element which appears exactly once. Find this single element that appears only once.
 */
#include <vector>

namespace single_element_in_a_sorted_array
{

class Solution {
public:
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

// TEST---------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

TEST(SingleNonDuplicateTest, Number2_IsNonDuplicate)
{
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{1, 1, 2, 3, 3, 4, 4, 8, 8};
  int expected_result{2};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, Number10_IsNonDuplicate)
{
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{3, 3, 7, 7, 10, 11, 11};
  int expected_result{10};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, LastNumber_IsNonDuplicate)
{
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{3, 3, 7, 7, 11, 11, 20};
  int expected_result{20};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, FirstNumber_IsNonDuplicate)
{
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{0, 3, 3, 7, 7, 11, 11, 20, 20};
  int expected_result{0};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, OnlyOneNumber_ThenNumberIsNonDuplicate)
{
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{1};
  int expected_result{1};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

}  // namespace
