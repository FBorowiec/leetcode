#ifndef LEETCODE_PROBLEMS_0518_COIN_CHANGE_2_HPP
#define LEETCODE_PROBLEMS_0518_COIN_CHANGE_2_HPP

#include <iostream>
#include <vector>

namespace coin_change_2 {

class Solution {
 public:
  /**
   * You are given coins of different denominations and a total amount of money.
   * Write a function to compute the number of combinations that make up that amount.
   * You may assume that you have infinite number of each kind of coin.
   *
   * You can assume that:
   * - 0 <= amount <= 5000
   * - 1 <= coin <= 5000
   * - the number of coins is less than 500
   * - the answer is guaranteed to fit into signed 32-bit integer
   */
  int change(int amount, std::vector<int>& coins) {
    std::vector<int> res(amount + 1);  // max size is amount
    res[0] = 1;                        // there is one way of not achieving 0 - by not using any coins

    for (unsigned int i = 0; i < coins.size(); ++i) {
      for (int j = 0; j <= amount; ++j) {
        if (j - coins[i] >= 0) {
          res[j] += res[j - coins[i]];
        }
      }
    }

    return res[amount];
  }
};

}  // namespace coin_change_2

#endif  // LEETCODE_PROBLEMS_0518_COIN_CHANGE_2_HPP
