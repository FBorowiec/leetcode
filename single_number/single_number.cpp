/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
#include <algorithm>
#include <iostream>
#include <vector>

class Solution{
	public:
		int singleNumber(std::vector<int>& nums)
		{
			std::sort(nums.begin(), nums.end(), [](int a, int b){return a<b;});

			for (unsigned int i = 0; i<nums.size()-2; i+=2)
			{
				if (nums[i] != nums[i+1])
				{
					return nums[i];
				}
			}
			return nums.back();
		}

};

int main()
{
	Solution s;
	std::vector<int> test_vec{17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6};
	int ans = s.singleNumber(test_vec);
	std::cout<<"Input vector: 17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6nAnswer: "<<ans<<std::endl;
	return 0;
}
