#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
	public:
    int countElements(std::vector<int>& arr)
		{
			if (arr.size()<1 || arr.size()>1000) {return 0;}
			std::unordered_set<int> st(arr.begin(), arr.end());
			int count{0};
			for (size_t i{0}; i<arr.size(); ++i)
			  st.find(arr[i]) == st.end() ? : st.find(arr[i] + 1) == st.end() ? : count++;
			return count;
    }
};

int main()
{
	Solution s;
	std::vector<int> v{1,2,3};
	std::cout<<s.countElements(v)<<std::endl;

	return 0;
}
