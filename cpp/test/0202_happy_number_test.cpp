#include "gtest/gtest.h"

#include "cpp/0202_happy_number.hpp"

namespace {

TEST(HappyNumberTest, TwoIsNotHappy) {
  happy_number::Solution sol{};
  ASSERT_FALSE(sol.isHappy(4));
}

}  // namespace
