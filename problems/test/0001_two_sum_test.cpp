#include "gtest/gtest.h"

#include "problems/0001_two_sum.hpp"

namespace
{

TEST(twoSumTest, FirstTwoNumbersSumIsTarget)
{
  std::vector<int> nums{2, 7, 11, 15};
  std::vector<int> expected_result{0, 1};
  int target{9};
  two_sum::Solution sol{};
  auto res =sol.twoSum(nums, target);
  for (size_t i{0}; i<expected_result.size(); ++i)
  {
    ASSERT_EQ(res[i], expected_result[i]);
  }
}

}  // namespace
