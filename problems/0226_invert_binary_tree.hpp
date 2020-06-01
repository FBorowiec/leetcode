#ifndef LEETCODE_PROBLEMS_0226_INVERT_BINARY_TREE_HPP
#define LEETCODE_PROBLEMS_0226_INVERT_BINARY_TREE_HPP

namespace invert_binary_tree {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  /**
   * Invert a binary tree.
   * Input:
   *      4
   *    /   \
   *   2     7
   *  / \   / \
   * 1   3 6   9
   *
   * Output:
   *      4
   *    /   \
   *   7     2
   *  / \   / \
   * 9   6 3   1
   *
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
   *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   * };
   */
 public:
  TreeNode *invertTree(TreeNode *root) {}
};

}  // namespace invert_binary_tree

#endif  // LEETCODE_PROBLEMS_0226_INVERT_BINARY_TREE_HPP
