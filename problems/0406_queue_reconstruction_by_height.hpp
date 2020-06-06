#ifndef LEETCODE_PROBLEMS_0406_QUEUE_RECONSTRUCTION_BY_HEIGHT_HPP
#define LEETCODE_PROBLEMS_0406_QUEUE_RECONSTRUCTION_BY_HEIGHT_HPP

#include <algorithm>
#include <vector>

namespace queue_reconstruction_by_height {

class Solution {
 public:
  /**
   * Suppose you have a random list of people standing in a queue.
   * Each person is described by a pair of integers (h, k),
   * where h is the height of the person and k is the number of people in front of this person
   * who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
   *
   * Note:
   * The number of people is less than 1,100.
   */
  std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
    std::sort(people.begin(), people.end(), [&](const std::vector<int> person1, const std::vector<int> person2) {
      return (person1[0] > person2[0] || (person1[0] == person2[0] && person1[1] < person2[1]));
    });

    std::vector<std::vector<int>> sorted_people;
    for (auto& person : people) {
      sorted_people.insert(std::begin(sorted_people) + person[1], person);
    }

    return sorted_people;
  }
};

}  // namespace queue_reconstruction_by_height

#endif  // LEETCODE_PROBLEMS_0406_QUEUE_RECONSTRUCTION_BY_HEIGHT_HPP
