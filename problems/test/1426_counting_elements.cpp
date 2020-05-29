#include "gtest/gtest.h"

#include "problems/1426_counting_elements.hpp"

namespace {

TEST(CountingElementsTest, ConsecutiveNumbers_ThenCount) {
  std::vector<int> input{1, 2, 2, 2, 3};
  int expected_result{4};
  counting_elements::Solution sol{};
  auto res = sol.countElements(input);
  ASSERT_EQ(res, expected_result);
}

TEST(CountingElementsTest, NonConsecutiveNumbers_ThenDontCount) {
  std::vector<int> input{1, 3, 7, 9, 12};
  int expected_result{0};
  counting_elements::Solution sol{};
  auto res = sol.countElements(input);
  ASSERT_EQ(res, expected_result);
}

}  // namespace
