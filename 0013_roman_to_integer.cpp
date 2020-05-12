/**
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        int result{0};
        for(unsigned int i = s.length(); i>0; --i)
        {
            switch(s.at(i-1)){
                case 'I':
                    result += (result>=5 ? -1 : 1);
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += (result>=50 ? -10 : 10);
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += (result>=500 ? -100 : 100);
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }
        return result;
    }
};

// TEST---------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

TEST(romanToIntTest, RandomRomanNumbersToInt)
{
    Solution sol{};
    ASSERT_EQ(sol.romanToInt("MCVII"), 1107);
    ASSERT_EQ(sol.romanToInt("IX"), 9);
    ASSERT_EQ(sol.romanToInt("MCMXCIII"), 1993);
}

}  // namespace
