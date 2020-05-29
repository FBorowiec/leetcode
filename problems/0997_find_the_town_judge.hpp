// UNSOLVED!
#ifndef LEETCODE_PROBLEMS_0997_FIND_THE_TOWN_JUDGE_HPP
#define LEETCODE_PROBLEMS_0997_FIND_THE_TOWN_JUDGE_HPP

#include <vector>

namespace find_the_town_judge {

class Solution {
 public:
  /**
   * In a town, there are N people labelled from 1 to N.\
   * There is a rumor that one of these people is secretly the town judge.
   *
   * If the town judge exists, then:
   *
   * - The town judge trusts nobody.
   * - Everybody (except for the town judge) trusts the town judge.
   * - There is exactly one person that satisfies properties 1 and 2.
   *
   * You are given trust, an array of pairs trust[i] = [a, b]
   * representing that the person labelled a trusts the person labelled b.
   *
   * If the town judge exists and can be identified, return the label of the town judge.
   * Otherwise, return -1.
   */
  int findJudge(int N, std::vector<std::vector<int>>& trust) {
    if (N < 1 || N > 1000) return -1;
    if (trust.size() > 10000) return -1;

    std::vector<int> probable_judge(N, 0);
    std::vector<int> unprobable_judge(N, 0);

    for (std::vector<int>& persons_pair : trust) {
      if (persons_pair[0] == persons_pair[1]) return -1;
      if ((persons_pair[0] < 1 || persons_pair[0] > N) || (persons_pair[1] < 1 || persons_pair[1] > N)) return -1;

      probable_judge[persons_pair[1] - 1]++;
      unprobable_judge[persons_pair[0] - 1]++;
    }

    for (int i = 1; i <= N; i++) {
      if ((probable_judge[i] == N - 1) && (unprobable_judge[i] == 0)) return i + 1;
    }

    return -1;
  }
};

}  // namespace find_the_town_judge

#endif  // LEETCODE_PROBLEMS_0997_FIND_THE_TOWN_JUDGE_HPP
