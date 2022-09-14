#include <vector>

#include "gtest/gtest.h"

#include "cpp/0226_invert_binary_tree.hpp"

namespace {

using namespace invert_binary_tree;

void Preorder(TreeNode* root, std::vector<int>& results) {
  if (root == nullptr) return;

  auto val = root->val;
  results.push_back(val);
  Preorder(root->left, results);
  Preorder(root->right, results);
}

TEST(InvertBinaryTreeTest, InvertGivenTree) {
  Solution sol{};
  TreeNode* root = nullptr;

  /* Construct below tree
   *		    1
   *       / \
   *	  	/   \
   *	   /     \
   *	  2       3
   *	 / \     / \
   *	4   5   6   7
   */
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  sol.invertTree(root);

  std::vector<int> results{};
  Preorder(root, results);
  std::vector<int> expected_results{1, 3, 7, 6, 2, 5, 4};

  ASSERT_EQ(expected_results.size(), results.size());
  for (size_t i{0}; i < expected_results.size(); ++i) EXPECT_EQ(expected_results[i], results[i]);
}

}  // namespace
