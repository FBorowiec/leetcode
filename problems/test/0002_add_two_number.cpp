#include "gtest/gtest.h"

#include <iostream>
#include "problems/0002_add_two_number.hpp"

namespace {

using namespace add_two_number;

TEST(AddTwoNumberTest, SumTwoLinkedLists) {
  Solution sol{};

  ListNode l1;
  l1.val = 2;
  l1.next = new ListNode();
  l1.next->val = 4;
  l1.next->next = new ListNode();
  l1.next->next->val = 3;

  ListNode l2;
  l2.val = 7;
  l2.next = new ListNode();
  l2.next->val = 0;
  l2.next->next = new ListNode();
  l2.next->next->val = 8;

  auto res = sol.addTwoNumbers(&l1, &l2);
  auto next = res;
  while (next != nullptr) {
    std::cerr << next->val << " ";
    next = next->next;
  }
  std::cout << "\n";
}

}  // namespace
