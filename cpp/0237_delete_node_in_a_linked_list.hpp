#ifndef CPP_0237_DELETE_NODE_IN_A_LINED_LIST_HPP
#define CPP_0237_DELETE_NODE_IN_A_LINED_LIST_HPP

#include <iostream>

namespace delete_node_in_a_linked_list {

// Definition of a singly-linked list
struct ListNode {
  ListNode(int x) : val(x), next(nullptr) {}
  int val;
  ListNode* next;
};

class Solution {
 public:
  /**
   * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
   * Given linked list -- head = [4,5,1,9],
   * Note:
   * - The linked list will have at least two elements.
   * - All of the nodes' values will be unique.
   * - The given node will not be the tail and it will always be a valid node of the linked list.
   * - Do not return anything from your function.
   */
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

}  // namespace delete_node_in_a_linked_list

#endif  // CPP_0237_DELETE_NODE_IN_A_LINED_LIST_HPP
