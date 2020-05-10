#include <string>
#include <cmath>
#include <iostream>

class Solution {
public:
    bool isHappy(int n) {
        if (n<1) return false;
        int res = 0;
        while (res != 1)
        {
            auto n_s{std::to_string(n)};
            n=0;
            for (unsigned int i = 0; i<n_s.length(); ++i)
            {
		    n += std::pow((int)n_s[i] - 48, 2);
	    }
	    res = n;
	    n_s = std::to_string(n);
        }
        return true;
    }
};

int main()
{
	Solution s;
	bool happy = s.isHappy(2);

	std::cout<<happy<<std::endl;
	return 0;
}
