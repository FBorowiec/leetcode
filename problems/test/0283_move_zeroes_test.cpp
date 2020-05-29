#include "gtest/gtest.h"

#include "problems/0283_move_zeroes.hpp"
namespace {

TEST(MoveZeroesTest, ZeroesInVectorAreMovedToTheEnd) {
  std::vector<int> input_nums{0, 0, 0, 1, 2, 3, 1, 2, 3, 1, 5, 0, 0, 2, 3};
  std::vector<int> expected_v{1, 2, 3, 1, 2, 3, 1, 5, 2, 3, 0, 0, 0, 0, 0};
  move_zeroes::Solution sol{};
  auto res = sol.moveZeroes(input_nums);
  for (size_t i{0}; i < expected_v.size(); ++i) {
    ASSERT_EQ(res[i], expected_v[i]);
  }
}

}  // namespace
