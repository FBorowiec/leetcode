// UNSOLVED!
#ifndef LEETCODE_PROBLEMS_0368_LARGEST_DIVISIBLE_SUBSET_HPP
#define LEETCODE_PROBLEMS_0368_LARGEST_DIVISIBLE_SUBSET_HPP

#include <algorithm>
#include <memory>
#include <unordered_set>
#include <vector>

namespace largest_divisible_subset {

/**
 * Given a set of distinct positive integers,
 * find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
 * Si % Sj = 0 or Sj % Si = 0.
 * If there are multiple solutions, return any subset is fine.
 */
class Solution {
 public:
  struct Node {
    Node(int val) : val_(val) {}

    std::unordered_set<std::shared_ptr<Node>> children_;
    int val_;
  };

  std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    if (nums.empty()) return result;
    result.clear();

    sort(nums.begin(), nums.end());

    std::shared_ptr<Node> root = std::make_shared<Node>(1);
    for (int num : nums) {
      std::shared_ptr<Node> curr = std::make_shared<Node>(num);
      update(root, curr);
    }
    std::vector<int> subset;
    dfs(root, subset);
    if (nums[0] == 1) return result;
    for (int i = 0; i != static_cast<int>(result.size()); ++i) {
      if (result[i] == 1) {
        result.erase(result.begin() + i);
        break;
      }
    }
    return result;
  }

  void dfs(std::shared_ptr<Node> root, std::vector<int>& subset) {
    subset.push_back(root->val_);

    if (root->children_.empty()) {
      if (subset.size() > result.size()) {
        result = subset;
      }
    }

    for (auto kid : root->children_) {
      dfs(kid, subset);
    }
    subset.pop_back();
  }

  bool update(std::shared_ptr<Node> root, std::shared_ptr<Node> curr) {
    int num = curr->val_, rum = root->val_;
    if (num % rum != 0 || num == rum) return false;
    bool found = false;
    for (auto branch : root->children_) {
      if (update(branch, curr)) found = true;
    }
    if (!found) root->children_.insert(curr);

    return true;
  }

  std::vector<int> result;
};

}  // namespace largest_divisible_subset

#endif  // LEETCODE_PROBLEMS_0368_LARGEST_DIVISIBLE_SUBSET_HPP
