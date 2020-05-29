#include "gtest/gtest.h"

#include "problems/0013_roman_to_integer.hpp"

namespace {

TEST(RomanToIntegerTest, RandomRomanNumbersToInt) {
  roman_to_integer::Solution sol{};
  ASSERT_EQ(sol.romanToInt("MCVII"), 1107);
  ASSERT_EQ(sol.romanToInt("IX"), 9);
  ASSERT_EQ(sol.romanToInt("MCMXCIII"), 1993);
}

}  // namespace
