#ifndef LEETCODE_PROBLEMS_1426_COUNTING_ELEMENTS_HPP
#define LEETCODE_PROBLEMS_1426_COUNTING_ELEMENTS_HPP

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace counting_elements
{

class Solution {
	public:
  /**
   * Count an element in a vector if the element preceding is either equal or smaller by 1.
   */
	int countElements(std::vector<int>& arr)
		{
			if (arr.size()<1 || arr.size()>1000) return 0;
			std::unordered_set<int> st(arr.begin(), arr.end());
			int count{0};
			for (size_t i{0}; i<arr.size(); ++i)
				st.find(arr[i]) == st.end() ? count : st.find(arr[i] + 1) == st.end() ? count : count++;
			return count;
	}
};

}  // namespace counting_elements

#endif  // LEETCODE_PROBLEMS_1426_COUNTING_ELEMENTS_HPP
