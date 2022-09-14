#include <limits>

#include "gtest/gtest.h"

#include "cpp/0344_reverse_string.hpp"

namespace {

TEST(ReverseStringTest, helloBecomesolleh) {
  reverse_string::Solution sol{};
  std::vector<char> input = {'h', 'e', 'l', 'l', 'o'}, expected_result{'o', 'l', 'l', 'e', 'h'};

  sol.reverseString(input);

  ASSERT_EQ(input.size(), expected_result.size());
  for (unsigned int i{0}; i < expected_result.size(); ++i) {
    EXPECT_EQ(input[i], expected_result[i]);
  }
}

TEST(ReverseStringTest, HannahBecomeshannaH) {
  reverse_string::Solution sol{};
  std::vector<char> input{'H', 'a', 'n', 'n', 'a', 'h'}, expected_result{'h', 'a', 'n', 'n', 'a', 'H'};

  sol.reverseString(input);

  ASSERT_EQ(input.size(), expected_result.size());
  for (unsigned int i{0}; i < expected_result.size(); ++i) {
    EXPECT_EQ(input[i], expected_result[i]);
  }
}

}  // namespace
