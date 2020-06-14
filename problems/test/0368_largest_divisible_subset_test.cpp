#include "gtest/gtest.h"

#include "problems/0368_largest_divisible_subset.hpp"

namespace {

using namespace largest_divisible_subset;

class LargestDivisibleSubsetTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(LargestDivisibleSubsetTest, Test1) {
  std::vector<int> input{1, 2, 3};
  std::vector<int> expected_result{1, 3};

  auto result = sol.largestDivisibleSubset(input);

  for (unsigned int i{0}; i < expected_result.size(); ++i) {
    EXPECT_EQ(result[i], expected_result[i]);
  }
}

TEST_F(LargestDivisibleSubsetTest, Test2) {
  std::vector<int> input{1, 2, 4, 8};
  std::vector<int> expected_result{1, 2, 4, 8};

  auto result = sol.largestDivisibleSubset(input);

  for (unsigned int i{0}; i < expected_result.size(); ++i) {
    EXPECT_EQ(result[i], expected_result[i]);
  }
}

}  // namespace
