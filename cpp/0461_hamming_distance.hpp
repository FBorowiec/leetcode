#ifndef CPP_0461_HAMMING_DISTANCE_HPP
#define CPP_0461_HAMMING_DISTANCE_HPP

namespace hamming_distance {

class Solution {
 public:
  /**
   * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
   * Given two integers x and y, return the Hamming distance between them.
   *
   * Example 1:
   * Input: x = 1, y = 4
   * Output: 2
   * Explanation:
   * 1   (0 0 0 1)
   * 4   (0 1 0 0)
   *        ↑   ↑
   * The above arrows point to positions where the corresponding bits are different.
   *
   * Example 2:
   * Input: x = 3, y = 1
   * Output: 1
   *
   * Constraints:
   *     0 <= x, y <= 231 - 1
   */
  int hammingDistance(int x, int y) {
    int ret{0};
    for (int i{0}; i < 32; ++i) {
      if ((x & 1) != (y & 1)) ++ret;
      x >>= 1;
      y >>= 1;
    }
    return ret;
  }
};

}  // namespace hamming_distance

#endif  // CPP_0461_HAMMING_DISTANCE_HPP
