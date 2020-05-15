#include "gtest/gtest.h"

#include "problems/0169_majority_element.hpp"

namespace
{

TEST(MajorityElementTest, WithGivenInputVector_Then3IsMajority)
{
  std::vector<int> input_vec{3, 2, 3};
  int expected_result{3};
  majority_element::Solution sol{};

  EXPECT_EQ(sol.majorityElement(input_vec), expected_result);
}

TEST(MajorityElementTest, WithGivenInputVector_Then2IsMajority)
{
  std::vector<int> input_vec{2, 2, 1, 1, 1, 2, 2};
  int expected_result{2};
  majority_element::Solution sol{};

  EXPECT_EQ(sol.majorityElement(input_vec), expected_result);
}

}  // namespace
