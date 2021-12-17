#ifndef LEETCODE_PROBLEMS_0002_ADD_TWO_NUMBER
#define LEETCODE_PROBLEMS_0002_ADD_TWO_NUMBER

#include <cmath>
#include <vector>

namespace add_two_number {
//
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* AddNode(const int num, ListNode* head) {
  ListNode* tmp = new ListNode;
  tmp->val = num;
  tmp->next = nullptr;

  if (head == nullptr) {
    head = tmp;
    head->next = tmp;
  } else {
    head->next = tmp;
    head = head->next;
  }

  return head;
}

class Solution {
 public:
  std::vector<int> CalcVec(ListNode* l) {
    std::vector<int> vec;

    while (l != nullptr) {
      vec.emplace_back(l->val);
      l = l->next;
    }
    return vec;
  }

  unsigned long CalcSum(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    unsigned long num{0};
    for (size_t i{0}; i < vec1.size(); ++i) {
      num += (vec1[i] + vec2[i]) * std::pow(10, vec1.size() - (i + 1));
    }
    return num;
  }

  unsigned long CountDigits(long num) {
    unsigned long count{0};
    while (num != 0) {
      num /= 10;
      ++count;
    }
    return count;
  }

  std::vector<int> GetVectorRepresentationOfNum(const long num) {
    std::vector<int> res{};
    auto size = CountDigits(num);
    auto tmp = num;
    for (size_t i{0}; i < size; ++i) {
      long power = std::pow(10, size - (i + 1));
      res.push_back(tmp / power);
      tmp -= (tmp / power) * power;
    }
    return res;
  }

  /**
   * You are given two non-empty linked lists representing two non-negative integers.
   * The digits are stored in reverse order, and each of their nodes contains a single digit.
   * Add the two numbers and return the sum as a linked list.
   * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
   * Constraints:
   *   The number of nodes in each linked list is in the range [1, 100].
   *   0 <= Node.val <= 9
   *   It is guaranteed that the list represents a number that does not have leading zeros.
   */
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    std::vector<int> vec1 = CalcVec(l1);
    std::vector<int> vec2 = CalcVec(l2);

    auto num = CalcSum(vec1, vec2);
    auto res_vec = GetVectorRepresentationOfNum(num);

    ListNode* result = new ListNode;
    for (size_t i{0}; i < res_vec.size(); ++i) {
      AddNode(res_vec[i], result);
    }

    return result;
  }
};

}  // namespace add_two_number

#endif  // LEETCODE_PROBLEMS_0002_ADD_TWO_NUMBER
