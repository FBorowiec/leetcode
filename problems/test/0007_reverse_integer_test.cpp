#include <limits>

#include "gtest/gtest.h"

#include "problems/0007_reverse_integer.hpp"

namespace
{

TEST(ReverseIntegerTest, Pos123becomesPos321)
{
  reverse_integer::Solution sol{};
  int input{123}, expected_result{321};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseIntegerTest, Neg123becomesNeg321)
{
  reverse_integer::Solution sol{};
  int input{-123}, expected_result{-321};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseIntegerTest, Pos120becomesPos21)
{
  reverse_integer::Solution sol{};
  int input{120}, expected_result{21};
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseIntegerTest, PositiveOverflow_ThenReturnsZero)
{
  reverse_integer::Solution sol{};
  size_t input{std::numeric_limits<int>::max()}, expected_result{0};
  input++;
  ASSERT_EQ(sol.reverse(input), expected_result);
}

TEST(ReverseIntegerTest, NegativeOverflow_ThenReturnsZero)
{
  reverse_integer::Solution sol{};
  int input{std::numeric_limits<int>::min()}, expected_result{0};
  input--;
  ASSERT_EQ(sol.reverse(input), expected_result);
}

}  // namespace
