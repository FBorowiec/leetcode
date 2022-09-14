#include <gtest/gtest.h>

#include "cpp/1232_check_if_it_is_a_straight_line.hpp"

namespace {

using Coordinates = std::vector<std::vector<int>>;

class CheckIfItIsAStraightLineTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  check_if_it_is_a_straight_line::Solution sol{};
  Coordinates good_line_{{1, 1}, {2, 2}, {33, 33}, {4, 4}, {5, 5}, {7, 7}};
  Coordinates bad_line_{{1, 1}, {2, 2}, {3, 5}, {4, 5}, {1, 6}, {7, 7}};
  Coordinates one_point_{{0, 1}};
  Coordinates two_points_{{0, 1}, {12354, 7457354}};
};

TEST_F(CheckIfItIsAStraightLineTest, IfLinesPointsVectorTooSmall_ThenReturnsFalse) {
  ASSERT_FALSE(sol.checkStraightLine(one_point_));
}

TEST_F(CheckIfItIsAStraightLineTest, IfLinesPointsVectorEqualsTwo_ThenReturnsTrue) {
  ASSERT_TRUE(sol.checkStraightLine(two_points_));
}

TEST_F(CheckIfItIsAStraightLineTest, IfValidLine_ThenReturnsTrue) { ASSERT_TRUE(sol.checkStraightLine(good_line_)); }

TEST_F(CheckIfItIsAStraightLineTest, IfInvalidLine_ThenReturnsFalse) { ASSERT_FALSE(sol.checkStraightLine(bad_line_)); }

}  // namespace
