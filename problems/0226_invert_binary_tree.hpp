#ifndef LEETCODE_PROBLEMS_0226_INVERT_BINARY_TREE_HPP
#define LEETCODE_PROBLEMS_0226_INVERT_BINARY_TREE_HPP

#include <algorithm>

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
   */
  TreeNode* invertTree(TreeNode* root) {
    // base case: if tree is empty
    if (root == nullptr) return root;

    // swap left subtree with right subtree
    std::swap(root->left, root->right);

    // invert left subtree
    invertTree(root->left);

    // invert right subtree
    invertTree(root->right);

    return root;
  }
};

}  // namespace invert_binary_tree

#endif  // LEETCODE_PROBLEMS_0226_INVERT_BINARY_TREE_HPP
