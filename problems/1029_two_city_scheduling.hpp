#ifndef LEETCODE_PROBLEMS_1029_TWO_CITY_SCHEDULING_HPP
#define LEETCODE_PROBLEMS_1029_TWO_CITY_SCHEDULING_HPP

#include <algorithm>
#include <cmath>
#include <vector>

namespace two_city_scheduling {

class Solution {
 public:
  /**
   * There are 2N people a company is planning to interview.
   * The cost of flying the i-th person to city A is costs[i][0],
   * and the cost of flying the i-th person to city B is costs[i][1].
   * Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
   *
   * Notes:
   * 1. 1 <= costs.length <= 100
   * 2. It is guaranteed that costs.length is even.
   * 3. 1 <= costs[i][0], costs[i][1] <= 1000
   */
  int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
    if (1 > costs.size() && costs.size() > 100) return 0;
    int price{0};

    std::nth_element(
        costs.begin(), costs.begin() + costs.size() / 2 - 1, costs.end(),
        [](const std::vector<int>& c1, const std::vector<int>& c2) { return (c1[0] - c1[1]) < (c2[0] - c2[1]); });

    for (int i = 0, j = costs.size() - 1; i < j; ++i, --j) {
      price += costs[i][0] + costs[j][1];
    }

    return price;
  }
};

}  // namespace two_city_scheduling

#endif  // LEETCODE_PROBLEMS_1029_TWO_CITY_SCHEDULING_HPP
