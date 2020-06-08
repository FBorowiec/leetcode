#include "gtest/gtest.h"

#include "problems/0231_power_of_two.hpp"

namespace {

using namespace power_of_two;

class PowerOfTwoTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(PowerOfTwoTest, 1isPowerOf2) { EXPECT_EQ(sol.isPowerOfTwo(1), true); }

TEST_F(PowerOfTwoTest, 16isPowerOf2) { EXPECT_EQ(sol.isPowerOfTwo(16), true); }

TEST_F(PowerOfTwoTest, 218isNotPowerOf2) { EXPECT_EQ(sol.isPowerOfTwo(218), false); }

}  // namespace
