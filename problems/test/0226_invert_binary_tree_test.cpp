#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "problems/0226_invert_binary_tree.hpp"

namespace {

using namespace invert_binary_tree;

void Preorder(TreeNode* root, std::vector<int> results) {
  if (root == nullptr) return;

  results.push_back(root->val);
  Preorder(root->left, results);
  Preorder(root->right, results);
}

TEST(InvertBinaryTreeTest, InvertGivenTree) {
std::cout<<"Starting test...\n";
  Solution sol{};
  TreeNode* root = nullptr;
  /* Construct below tree
   *		    1
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

std::cout<<"Starting invertion...\n";

  sol.invertTree(root);

std::cout<<"Finished invertion!\n";

  std::vector<int> results{};
std::cout<<"Starting printing...\n";
  Preorder(root, results);

std::cout<<"Finished printing!\n";
  std::vector<int> expected_results{1, 3, 7, 6, 2, 5, 4};

std::cout<<"Starting assertion...\n";
  for (size_t i{0}; i < expected_results.size(); ++i) EXPECT_EQ(expected_results[i], results[i]);
std::cout<<"Finished assertion!\n";
}

}  // namespace
