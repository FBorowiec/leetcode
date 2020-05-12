/**
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 * Note: Do not use any built-in library function such as sqrt.
 */
#include <cstddef>
#include <limits>

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 1) return true;
    if (num < 1 || num > std::numeric_limits<int>::max()) return false;

    using ull = unsigned long long;
    for (ull i{static_cast<ull>(num)/2}; i > 0; --i) {
      ull square_pow = i*i;
      if (square_pow > num) continue;
      if (square_pow == num) return true;
      if (square_pow < num) return false;
    }
    return false;
  }
};

// TEST---------------------------------------------------------------------------------------------------------------|
#include <cmath>
#include <vector>
#include <numeric>
#include "gtest/gtest.h"

namespace
{

class isPerfectSquareTest : public ::testing::Test {
 public:
  void SetUp() override {
    // Generate vector of powers of consecutive numbers
    std::iota(vec_perfect_squares_.begin(), vec_perfect_squares_.end(), 1);
    std::for_each(vec_perfect_squares_.begin(), vec_perfect_squares_.end(), [](int& a){a *= a;});

    // Generate corrupted vector of powers of consecutive numbers
    std::iota(vec_corrupted_squares_.begin(), vec_corrupted_squares_.end(), 1);
    std::for_each(vec_corrupted_squares_.begin(), vec_corrupted_squares_.end(), [](int& a){a = a*a + 2;});

    ASSERT_EQ(vec_perfect_squares_.size(), 100);
    ASSERT_EQ(vec_corrupted_squares_.size(), 100);
    ASSERT_EQ(vec_corrupted_squares_[2], 11);
    ASSERT_EQ(vec_perfect_squares_[99], 10000);
  }

 protected:
  Solution solution{};
  std::vector<int> vec_perfect_squares_{(std::vector<int>(100))};
  std::vector<int> vec_corrupted_squares_{(std::vector<int>(100))};
};

TEST_F(isPerfectSquareTest, VectorOfSquares_ArePerfectSquares)
{
  for (const auto val : vec_perfect_squares_)
  {
    bool is_perfect_using_stl{std::sqrt(val) == std::floor(std::sqrt(val))};
    ASSERT_EQ(solution.isPerfectSquare(val), is_perfect_using_stl);
  }
}

TEST_F(isPerfectSquareTest, VectorOfCorruptedSquares_AreNotPerfectSquares)
{
  for (const auto val : vec_perfect_squares_)
  {
    bool is_perfect_using_stl{std::sqrt(val) == std::floor(std::sqrt(val))};
    ASSERT_EQ(solution.isPerfectSquare(val), is_perfect_using_stl);
  }
}

TEST_F(isPerfectSquareTest, OverflowValue_ThenIsNotPerfect)
{
  ASSERT_EQ(std::numeric_limits<int>::max(), 2147483647);
  ASSERT_FALSE(solution.isPerfectSquare(2147483647));
}

TEST_F(isPerfectSquareTest, OverflowValueOfSquarePower_ThenIsPerfect)
{
  int val{808201};
  ASSERT_TRUE(solution.isPerfectSquare(val));
}

}  // namespace
