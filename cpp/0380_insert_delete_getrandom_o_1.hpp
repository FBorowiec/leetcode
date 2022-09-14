#ifndef CPP_0380_INSERT_DELETE_GETRANDOM_O_1_HPP
#define CPP_0380_INSERT_DELETE_GETRANDOM_O_1_HPP

#include <stdlib.h>
#include <iterator>
#include <unordered_map>

namespace insert_delete_get_random_o_1 {

/**
 * Design a data structure that supports all following operations in average O(1) time.
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements.
 *            Each element must have the same probability of being returned.
 */
class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) { return dic.insert({val, 1}).second; }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) { return dic.find(val) != dic.end() ? dic.erase(val) : false; }

  /** Get a random element from the set. */
  int getRandom() { return std::next(std::begin(dic), rand() % dic.size())->first; }

 private:
  std::unordered_map<int, int> dic;
};

}  // namespace insert_delete_get_random_o_1

#endif  // CPP_0380_INSERT_DELETE_GETRANDOM_O_1_HPP
