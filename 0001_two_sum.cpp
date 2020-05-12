/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        for (int i = 0; i<nums.size(); ++i)
        {
            for (int j = 0; j<nums.size(); ++j)
            {
                if (i == j) continue;
                int sum = nums[i]+nums[j];
                if (sum == target)
                {
                    std::vector<int> vec{i, j};
                    return vec;
                }
            }
        }
        return {0};
    }
};

// TEST----------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

TEST(twoSumTest, FirstTwoNumbersSumIsTarget)
{
  std::vector<int> nums{2, 7, 11, 15};
  std::vector<int> expected_result{0, 1};
  int target{9};
  Solution sol{};
  auto res =sol.twoSum(nums, target);
  for (size_t i{0}; i<expected_result.size(); ++i)
  {
    ASSERT_EQ(res[i], expected_result[i]);
  }
}

}  // namespace
