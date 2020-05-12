/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Note: Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */
#include <algorithm>
#include <cstdint>
#include <string>

#include <iostream>

namespace reverse_integer
{

class Solution {
public:
    int reverse(int x)
    {
      if (x > std::numeric_limits<int>::max()) return 0;  // prevent overflows
      while (x % 10 == 0) x = x/10;  // discard zeroes at end of x
      std::string x_str = std::to_string(x);
      int i{0}, j{x_str.length()-1};
      while(i<j)
      {
        auto temp=x_str[i];
        x_str[i]=x_str[j];
        x_str[j]=temp;
        i++;
        j--;
      }
      return std::stoi(x_str);
    }
};

}  // namespace reverse_integer

// TEST---------------------------------------------------------------------------------------------------------------|
#include <limits>
#include "gtest/gtest.h"

namespace
{

TEST(ReverseTest, Pos123becomesPos321)
{
  reverse_integer::Solution sol{};
  int input{123}, expected_result{321};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseTest, Neg123becomesNeg321)
{
  reverse_integer::Solution sol{};
  int input{-123}, expected_result{-321};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseTest, Pos120becomesPos21)
{
  reverse_integer::Solution sol{};
  int input{120}, expected_result{21};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseTest, PositiveOverflow_ThenReturnsZero)
{
  reverse_integer::Solution sol{};
  size_t input{std::numeric_limits<int>::max() + 1}, expected_result{0};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseTest, NegativeOverflow_ThenReturnsZero)
{
  reverse_integer::Solution sol{};
  int input{std::numeric_limits<int>::min()}, expected_result{0};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

}  // namespace