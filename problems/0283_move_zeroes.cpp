/**
 * Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 */
#include <algorithm>
#include <vector>

namespace move_zeroes
{

class Solution {
public:
	std::vector<int> moveZeroes(std::vector<int>& nums)
	{
		std::vector<int> nums2{};
		int count{0};
		for (size_t i = 0; i<nums.size(); ++i)
		{
			if(nums[i] != 0) {nums2.emplace_back(nums[i]);}
			else {++count;}
		}
		for (size_t i = 0; i < count; ++i)
		{
			nums2.emplace_back(0);
		}
		return nums2;
  }
};

}  // namespace move_zeroes

// TEST---------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

TEST(MoveZeroesTest, ZeroesInVectorAreMovedToTheEnd)
{
	std::vector<int> input_nums{0, 0, 0, 1, 2, 3, 1, 2, 3, 1, 5, 0, 0, 2, 3};
	std::vector<int> expected_v{1, 2, 3, 1, 2, 3, 1, 5, 2, 3, 0, 0, 0, 0, 0};
	move_zeroes::Solution sol{};
	auto res = sol.moveZeroes(input_nums);
	for(size_t i{0}; i<expected_v.size(); ++i)
	{
		ASSERT_EQ(res[i], expected_v[i]);
	}
}

}  // namespace
