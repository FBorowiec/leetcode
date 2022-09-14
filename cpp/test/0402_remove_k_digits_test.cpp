#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

#include "gtest/gtest.h"

#include "cpp/0402_remove_k_digits.hpp"

namespace {

using namespace remove_k_digits;

class RemoveKdigitsTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(RemoveKdigitsTest, DISABLED_LengthIsSuperiorThan10002_ThenInvalid) {
  std::vector<int> test_vec{std::vector<int>(10003, 1)};
  std::ostringstream input_string;
  std::copy(test_vec.begin(), test_vec.end(), std::ostream_iterator<int>(input_string, ""));

  int k = 3;
  std::string expected_output = "0";
  EXPECT_STREQ(sol.removeKdigits(input_string.str(), k).c_str(), expected_output.c_str());
}

TEST_F(RemoveKdigitsTest, DISABLED_LengthIsMinorThanK_ThenInvalid) {
  std::string input_num = "1";
  int k = 3;
  std::string expected_output = "0";
  EXPECT_STREQ(sol.removeKdigits(input_num, k).c_str(), expected_output.c_str());
}

TEST_F(RemoveKdigitsTest, DISABLED_Remove4and3and2_then1219isSmallest) {
  // Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
  std::string input_num = "1432219";
  int k = 3;
  std::string expected_output = "1219";
  EXPECT_STREQ(sol.removeKdigits(input_num, k).c_str(), expected_output.c_str());
}

TEST_F(RemoveKdigitsTest, DISABLED_Remove1_then200isSmallest) {
  // Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
  std::string input_num = "10200";
  int k = 1;
  std::string expected_output = "200";
  EXPECT_STREQ(sol.removeKdigits(input_num, k).c_str(), expected_output.c_str());
}

TEST_F(RemoveKdigitsTest, DISABLED_Remove2_then0isSmallest) {
  // Remove all the digits from the number and it is left with nothing which is 0.
  std::string input_num = "10";
  int k = 2;
  std::string expected_output = "0";
  EXPECT_STREQ(sol.removeKdigits(input_num, k).c_str(), expected_output.c_str());
}

}  // namespace
