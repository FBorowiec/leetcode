#include "gtest/gtest.h"

#include "problems/0275_h_index_ii.hpp"

namespace {

using namespace h_index_ii;

class HIndexIITest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(HIndexIITest, Test1) {
  /**
   * Input: citations = [0,1,3,5,6]
   * Output: 3
   * Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had
   *             received 0, 1, 3, 5, 6 citations respectively.
   *             Since the researcher has 3 papers with at least 3 citations each and the remaining
   *             two with no more than 3 citations each, her h-index is 3.
   */
  std::vector<int> input{0, 1, 3, 5, 6};
  int expected_result{3};

  auto result = sol.hIndex(input);
  EXPECT_EQ(expected_result, result);
}

TEST_F(HIndexIITest, Test2) {
  std::vector<int> input{};
  int expected_result{0};

  auto result = sol.hIndex(input);
  EXPECT_EQ(expected_result, result);
}

TEST_F(HIndexIITest, Test3) {
  std::vector<int> input{100};
  int expected_result{1};

  auto result = sol.hIndex(input);
  EXPECT_EQ(expected_result, result);
}

TEST_F(HIndexIITest, Test4) {
  std::vector<int> input{0};
  int expected_result{0};

  auto result = sol.hIndex(input);
  EXPECT_EQ(expected_result, result);
}

TEST_F(HIndexIITest, Test5) {
  std::vector<int> input{0, 0};
  int expected_result{0};

  auto result = sol.hIndex(input);
  EXPECT_EQ(expected_result, result);
}

}  // namespace
