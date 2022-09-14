#ifndef CPP_0700_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP
#define CPP_0700_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP

namespace search_in_a_binary_search_tree {

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
   * Given the root node of a binary search tree (BST) and a value.
   * You need to find the node in the BST that the node's value equals the given value.
   * Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
   */
  TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr || root->val == val) return root;
    if (root->val > val) return searchBST(root->left, val);
    return searchBST(root->right, val);
  }
};

}  // namespace search_in_a_binary_search_tree

#endif  // CPP_0700_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP
