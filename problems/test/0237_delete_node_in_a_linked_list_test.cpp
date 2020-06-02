#include <vector>

#include "gtest/gtest.h"

#include "problems/0237_delete_node_in_a_linked_list.hpp"

namespace {

using namespace delete_node_in_a_linked_list;

class DeleteNodeInALinkedListTest : public ::testing::Test {
 public:
  void SetUp() override { SetLinkedList(); }

  void SetLinkedList() {
    root = new ListNode(4);
    n1 = new ListNode(5);
    root->next = n1;
    n2 = new ListNode(1);
    n1->next = n2;
    n3 = new ListNode(9);
    n2->next = n3;
  }

  void GetVectorOfResults(ListNode* node, std::vector<int>& results) {
    while (node != nullptr) {
      results.push_back(node->val);
      node = node->next;
    }
  }

 protected:
  ListNode *root, *n1, *n2, *n3;
  Solution solution{};
  std::vector<int> results{};
};

TEST_F(DeleteNodeInALinkedListTest, DeleteNodeOne) {
  solution.deleteNode(n1);
  GetVectorOfResults(root, results);

  std::vector<int> expected_results{4, 1, 9};

  ASSERT_EQ(results.size(), expected_results.size());
  for (unsigned int i{0}; i < expected_results.size(); ++i) {
    EXPECT_EQ(results[i], expected_results[i]);
  }
}

TEST_F(DeleteNodeInALinkedListTest, DeleteNodeTwo) {
  solution.deleteNode(n2);
  GetVectorOfResults(root, results);

  std::vector<int> expected_results{4, 5, 9};

  ASSERT_EQ(results.size(), expected_results.size());
  for (unsigned int i{0}; i < expected_results.size(); ++i) {
    EXPECT_EQ(results[i], expected_results[i]);
  }
}

}  // namespace
