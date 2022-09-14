#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "cpp/0075_sort_colors.hpp"

namespace {

using namespace sort_colors;

class SortColorsTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(SortColorsTest, Test1) {
  std::vector<int> input{2, 0, 2, 1, 1, 0};
  std::vector<int> expected_output{0, 0, 1, 1, 2, 2};

  sol.sortColors(input);

  ASSERT_EQ(input.size(), expected_output.size());
  for (unsigned int i{0}; i < expected_output.size(); ++i) {
    EXPECT_EQ(input[i], expected_output[i]);
  }
}

}  // namespace
