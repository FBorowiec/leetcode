#ifndef CPP_0367_VALID_PERFECT_SQUARE_HPP
#define CPP_0367_VALID_PERFECT_SQUARE_HPP

#include <cstddef>
#include <limits>

namespace valid_perfect_square {

class Solution {
 public:
  /**
   * Given a positive integer num, write a function which returns True if num is a perfect square else False.
   * Note: Do not use any built-in library function such as sqrt.
   */
  bool isPerfectSquare(int num) {
    if (num == 1) return true;
    if (num < 1 || num > std::numeric_limits<int>::max()) return false;

    using ll = long long;
    for (ll i{static_cast<ll>(num) / 2}; i > 0; --i) {
      ll square_pow = i * i;
      if (square_pow > num) continue;
      if (square_pow == num) return true;
      if (square_pow < num) return false;
    }
    return false;
  }
};

}  // namespace valid_perfect_square

#endif  // CPP_0367_VALID_PERFECT_SQUARE_HPP
