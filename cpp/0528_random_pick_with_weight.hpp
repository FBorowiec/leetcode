#ifndef CPP_0528_RANDOM_PICK_WITH_WEIGHT_HPP
#define CPP_0528_RANDOM_PICK_WITH_WEIGHT_HPP

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace random_pick_with_weight {

class Solution {
 public:
  /**
   * Given an array w of positive integers, where w[i] describes the weight of index i,
   * write a function pickIndex which randomly picks an index in proportion to its weight.
   * Note:
   *  - 1 <= w.length <= 10000
   *  - 1 <= w[i] <= 10^5
   *  - pickIndex will be called at most 10000 times.
   *
   * Explanation of Input Syntax:
   * The input is two lists: the subroutines called and their arguments.
   * Solution's constructor has one argument, the array w. pickIndex has no arguments.
   * Arguments are always wrapped with a list, even if there aren't any.
   */
  Solution(std::vector<int>& w) {
    int accumulated_weights{0};
    for (int weight : w) {
      accumulated_weights += weight;
      weights_.emplace_back(accumulated_weights);
    }
  }

  int pickIndex() {
    int random_num = std::rand() % weights_.back() + 1;
    return binarySearch(random_num);
  }

  int binarySearch(int target) {
    int lower_bound = 0, higher_bound = weights_.size(), middle_element;
    while (lower_bound < higher_bound) {
      middle_element = (lower_bound + (higher_bound - 1)) / 2;
      if (weights_[middle_element] < target) {
        lower_bound = middle_element + 1;
      } else {
        higher_bound = middle_element;
      }
    }
    return lower_bound;
  }

 private:
  std::vector<int> weights_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

}  // namespace random_pick_with_weight

#endif  // CPP_0528_RANDOM_PICK_WITH_WEIGHT_HPP
