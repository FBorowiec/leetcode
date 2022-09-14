#include "gtest/gtest.h"

#include "cpp/0518_coin_change_2.hpp"

namespace {

using namespace coin_change_2;

class CoinChange2Test : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(CoinChange2Test, Given1and2and5_Output4) {
  std::vector<int> input{1, 2, 5};
  int input_amout{5};
  int expected_result{4};

  /**
   * Explanation: there are four ways to make up the amount:
   * 5=5
   * 5=2+2+1
   * 5=2+1+1+1
   * 5=1+1+1+1+1
   */
  auto res = sol.change(input_amout, input);

  EXPECT_EQ(expected_result, res);
}

TEST_F(CoinChange2Test, Given3_Output0) {
  std::vector<int> input{2};
  int input_amout{3};
  int expected_result{0};

  auto res = sol.change(input_amout, input);

  EXPECT_EQ(expected_result, res);
}

TEST_F(CoinChange2Test, Given10_Output1) {
  std::vector<int> input{10};
  int input_amout{10};
  int expected_result{1};

  auto res = sol.change(input_amout, input);

  EXPECT_EQ(expected_result, res);
}

}  // namespace
