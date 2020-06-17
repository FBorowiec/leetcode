#include "gtest/gtest.h"

#include "problems/0130_surrounded_regions.hpp"

namespace {

using namespace surrounded_regions;

class SurroundedRegionsTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution solution{};
};

TEST_F(SurroundedRegionsTest, ValidIpv4IsIdentified) {
  std::vector<std::vector<char>> input{
      {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
  std::vector<std::vector<char>> expected_output{
      {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}};

  solution.solve(input);

  for (unsigned int i{0}; i < expected_output.size(); ++i) {
    for (unsigned int j{0}; j < expected_output[0].size(); ++j) {
      EXPECT_EQ(input[i][j], expected_output[i][j]);
    }
  }
}

}  // namespace