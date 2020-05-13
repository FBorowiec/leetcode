#ifndef LEETCODE_PROBLEMS_1232_CHECK_IF_IT_IS_A_STRAIGHT_LINE_HPP
#define LEETCODE_PROBLEMS_1232_CHECK_IF_IT_IS_A_STRAIGHT_LINE_HPP

#include <vector>

namespace check_if_it_is_a_straight_line
{

using Coordinates=std::vector<std::vector<int>>;

class Solution
{
 public:
  /**
   * You are given an array coordinates, coordinates[i] = [x, y],
   * where [x, y] represents the coordinate of a point.
   * Check if these points make a straight line in the XY plane.
   */
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

}  // namespace check_if_it_is_a_straight_line

#endif  // LEETCODE_PROBLEMS_1232_CHECK_IF_IT_IS_A_STRAIGHT_LINE_HPP
