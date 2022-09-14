#include "gtest/gtest.h"

#include "cpp/0540_single_element_in_a_sorted_array.hpp"

namespace {

TEST(SingleNonDuplicateTest, Number2_IsNonDuplicate) {
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{1, 1, 2, 3, 3, 4, 4, 8, 8};
  int expected_result{2};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, Number10_IsNonDuplicate) {
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{3, 3, 7, 7, 10, 11, 11};
  int expected_result{10};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, LastNumber_IsNonDuplicate) {
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{3, 3, 7, 7, 11, 11, 20};
  int expected_result{20};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, FirstNumber_IsNonDuplicate) {
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{0, 3, 3, 7, 7, 11, 11, 20, 20};
  int expected_result{0};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

TEST(SingleNonDuplicateTest, OnlyOneNumber_ThenNumberIsNonDuplicate) {
  single_element_in_a_sorted_array::Solution sol{};
  std::vector<int> input_vec{1};
  int expected_result{1};

  ASSERT_EQ(sol.singleNonDuplicate(input_vec), expected_result);
}

}  // namespace
