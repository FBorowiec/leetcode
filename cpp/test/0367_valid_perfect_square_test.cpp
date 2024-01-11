#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

#include "gtest/gtest.h"

#include "cpp/0367_valid_perfect_square.hpp"

namespace {

class ValidPerfectSquareTest : public ::testing::Test {
 public:
  void SetUp() override {
    // Generate vector of powers of consecutive numbers
    std::iota(vec_perfect_squares_.begin(), vec_perfect_squares_.end(), 1);
    std::for_each(vec_perfect_squares_.begin(), vec_perfect_squares_.end(), [](int& a) { a *= a; });

    // Generate corrupted vector of powers of consecutive numbers
    std::iota(vec_corrupted_squares_.begin(), vec_corrupted_squares_.end(), 1);
    std::for_each(vec_corrupted_squares_.begin(), vec_corrupted_squares_.end(), [](int& a) { a = a * a + 2; });

    ASSERT_EQ(vec_perfect_squares_.size(), 100);
    ASSERT_EQ(vec_corrupted_squares_.size(), 100);
    ASSERT_EQ(vec_corrupted_squares_[2], 11);
    ASSERT_EQ(vec_perfect_squares_[99], 10000);
  }

 protected:
  valid_perfect_square::Solution solution{};
  std::vector<int> vec_perfect_squares_{(std::vector<int>(100))};
  std::vector<int> vec_corrupted_squares_{(std::vector<int>(100))};
};

TEST_F(ValidPerfectSquareTest, VectorOfSquares_ArePerfectSquares) {
  for (const auto val : vec_perfect_squares_) {
    bool is_perfect_using_stl{std::sqrt(val) == std::floor(std::sqrt(val))};
    ASSERT_EQ(solution.isPerfectSquare(val), is_perfect_using_stl);
  }
}

TEST_F(ValidPerfectSquareTest, VectorOfCorruptedSquares_AreNotPerfectSquares) {
  for (const auto val : vec_perfect_squares_) {
    bool is_perfect_using_stl{std::sqrt(val) == std::floor(std::sqrt(val))};
    ASSERT_EQ(solution.isPerfectSquare(val), is_perfect_using_stl);
  }
}

TEST_F(ValidPerfectSquareTest, OverflowValue_ThenIsNotPerfect) {
  ASSERT_EQ(std::numeric_limits<int>::max(), 2147483647);
  ASSERT_FALSE(solution.isPerfectSquare(2147483647));
}

TEST_F(ValidPerfectSquareTest, OverflowValueOfSquarePower_ThenIsPerfect) {
  int val{808201};
  ASSERT_TRUE(solution.isPerfectSquare(val));
}

}  // namespace
