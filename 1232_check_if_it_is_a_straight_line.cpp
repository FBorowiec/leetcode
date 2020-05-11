#include <vector>

using Coordinates=std::vector<std::vector<int>>;

class Solution
{
 public:
  bool checkStraightLine(Coordinates& coordinates) {
    if (coordinates.size() == 2) return true;
    if (coordinates.size() < 2 || coordinates.size() > 1000) return false;
    if (coordinates[0][0] == coordinates[1][0]) return false;

    double a  = (coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
    double b = coordinates[0][1] - a*coordinates[0][0];

    for (size_t i{2}; i<coordinates.size(); ++i) {
        if (coordinates[i][1] != a*coordinates[i][0] + b) { //y != ax + b
          return false;
        }
    }
    return true;
  }
};

// TEST
#include <gtest/gtest.h>
namespace
{
class CheckIfItIsAStraightLine : public ::testing::Test
{
 public:
  void SetUp() override {}

 protected:
  Solution sol{};
  Coordinates good_line_{{1,1},{2,2},{33,33},{4,4},{5,5},{7,7}};
  Coordinates bad_line_{{1,1},{2,2},{3,5},{4,5},{1,6},{7,7}};
  Coordinates one_point_{{0, 1}};
  Coordinates two_points_{{0, 1}, {12354, 7457354}};
};

TEST_F(CheckIfItIsAStraightLine, IfLinesPointsVectorTooSmall_ThenReturnsFalse)
{
  ASSERT_FALSE(sol.checkStraightLine(one_point_));
}

TEST_F(CheckIfItIsAStraightLine, IfLinesPointsVectorEqualsTwo_ThenReturnsTrue)
{
  ASSERT_TRUE(sol.checkStraightLine(two_points_));
}

TEST_F(CheckIfItIsAStraightLine, IfValidLine_ThenReturnsTrue)
{
  ASSERT_TRUE(sol.checkStraightLine(good_line_));
}

TEST_F(CheckIfItIsAStraightLine, IfInvalidLine_ThenReturnsFalse)
{
  ASSERT_FALSE(sol.checkStraightLine(bad_line_));
}
}  // namespace