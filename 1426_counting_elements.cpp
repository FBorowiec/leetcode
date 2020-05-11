#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
	public:
	int countElements(std::vector<int>& arr)
		{
			if (arr.size()<1 || arr.size()>1000) return 0;
			std::unordered_set<int> st(arr.begin(), arr.end());
			int count{0};
			for (size_t i{0}; i<arr.size(); ++i)
				st.find(arr[i]) == st.end() ? : st.find(arr[i] + 1) == st.end() ? : count++;
			return count;
	}
};

// TEST---------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

TEST(countElementsTest, ConsecutiveNumbers_ThenCount)
{
  std::vector<int> input{1, 2, 2, 2, 3};
  int expected_result{4};
  Solution sol{};
  auto res = sol.countElements(input);
  ASSERT_EQ(res, expected_result);
}

TEST(countElementsTest, NonConsecutiveNumbers_ThenDontCount)
{
  std::vector<int> input{1, 3, 7, 9, 12};
  int expected_result{0};
  Solution sol{};
  auto res = sol.countElements(input);
  ASSERT_EQ(res, expected_result);
}

}  // namespace
