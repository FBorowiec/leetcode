#include <vector>

#include "gtest/gtest.h"

#include "cpp/0700_search_in_a_binary_search_tree.hpp"

namespace {

using namespace search_in_a_binary_search_tree;

/**
 * Given the tree:
 *         4
 *        / \
 *       2   7
 *      / \
 *     1   3
 *
 * And the value to search: 2
 *
 * You should return this subtree:
 *       2
 *      / \
 *     1   3
 */

class SearchInABinarySearchTreeTest : public ::testing::Test {
 public:
  void SetUp() override { SetLinkedList(); }

  void SetLinkedList() {
    root = new TreeNode(4);
    n1 = new TreeNode(7);
    root->right = n1;
    n2 = new TreeNode(2);
    root->left = n2;
    n3 = new TreeNode(1);
    n2->left = n3;
    n4 = new TreeNode(3);
    n2->right = n4;
  }

  void TearDown() override {
    delete root;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
  }

 protected:
  TreeNode *root, *n1, *n2, *n3, *n4;
  Solution solution{};
  std::vector<int> results{};
};

TEST_F(SearchInABinarySearchTreeTest, Test1) {
  auto res = solution.searchBST(root, 2);
  ASSERT_TRUE(res != nullptr);
  EXPECT_EQ(res->val, 2);
  EXPECT_EQ(res->left->val, 1);
  EXPECT_EQ(res->right->val, 3);
  int a = 0;
  (void)a;
  (void)res;
}

}  // namespace
