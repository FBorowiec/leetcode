#ifndef LEETCODE_PROBLEMS_0013_ROMAN_TO_INTEGER_HPP
#define LEETCODE_PROBLEMS_0013_ROMAN_TO_INTEGER_HPP

#include <string>

namespace roman_to_integer
{

class Solution {
 public:
  /**
   * Given a roman numeral, convert it to an integer.
   * Input is guaranteed to be within the range from 1 to 3999.
   */
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

}  // namespace roman_to_integer

#endif  // LEETCODE_PROBLEMS_0013_ROMAN_TO_INTEGER_HPP
