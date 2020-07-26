#ifndef LEETCODE_PROBLEMS_0275_H_INDEX_II_HPP
#define LEETCODE_PROBLEMS_0275_H_INDEX_II_HPP

#include <algorithm>
#include <cmath>
#include <vector>

namespace h_index_ii {

class Solution {
 public:
  /**
   * Given an array of citations sorted in ascending order (each citation is a non-negative integer)
   * of a researcher, write a function to compute the researcher's h-index.
   * According to the definition of h-index on Wikipedia:
   * "A scientist has index h if h of his/her N papers have at least h citations each,
   * and the other N − h papers have no more than h citations each."
   *
   * Note:
   * If there are several possible values for h, the maximum one is taken as the h-index.
   *
   * Follow up:
   * This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
   * Could you solve it in logarithmic time complexity?
   */
  int hIndex(std::vector<int>& citations) {
    if (citations.size() == 0) return 0;
    for (int i = 0; i < static_cast<int>(citations.size()); ++i) {
      if (citations[i] >= static_cast<int>(citations.size()) - i) {
        return citations.size() - i;
      }
    }
    return 0;
  }
};

}  // namespace h_index_ii

#endif  // LEETCODE_PROBLEMS_0275_H_INDEX_II_HPP
