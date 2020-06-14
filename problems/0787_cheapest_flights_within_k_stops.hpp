// UNSOLVED!
#ifndef LEETCODE_PROBLEMS_0787_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_HPP
#define LEETCODE_PROBLEMS_0787_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_HPP

#include <queue>
#include <unordered_map>
#include <vector>

namespace cheapest_flights_within_k_stops {

class Solution {
 public:
  /**
   * There are n cities connected by m flights.
   * Each flight starts from city u and arrives at v with a price w.
   * now given all the cities and flights, together with starting city src and the destination dst,
   * your task is to find the cheapest price from src to dst with up to k stops.
   * If there is no such route, output -1.
   *
   * Constraints:
   * The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
   * The size of flights will be in range [0, n * (n - 1) / 2].
   * The format of each flight will be (src, dst, price).
   * The price of each flight will be in the range [1, 10000].
   * k is in the range of [0, n - 1].
   * There will not be any duplicated flights or self cycles.
   */
  int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) {
    std::vector<int> price_vec(n, -1);
    std::queue<std::pair<int, int>> queue;
    queue.push({src, 0});
    K++;

    std::unordered_map<int, std::vector<std::pair<int, int>>> paths;
    for (auto e : flights) {
      paths[e[0]].push_back({e[1], e[2]});
    }

    while (!queue.empty()) {
      if (!K) break;
      int len = queue.size();
      for (int i = 0; i < len; i++) {
        auto q = queue.front();
        queue.pop();
        for (auto e : paths[q.first]) {
          int price = q.second + e.second;
          if (price_vec[e.first] == -1 || price < price_vec[e.first]) {
            price_vec[e.first] = price;
            queue.push({e.first, price});
          }
        }
      }
      K--;
    }
    return price_vec[dst];
  }
};

}  // namespace cheapest_flights_within_k_stops

#endif  // LEETCODE_PROBLEMS_0787_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_HPP
