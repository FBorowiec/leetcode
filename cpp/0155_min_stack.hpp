#ifndef CPP_0155_MIN_STACK_HPP
#define CPP_0155_MIN_STACK_HPP

#include <algorithm>
#include <vector>

namespace min_stack {

/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *   push(x) -- Push element x onto stack.
 *   pop() -- Removes the element on top of the stack.
 *   top() -- Get the top element.
 *   getMin() -- Retrieve the minimum element in the stack.
 */
class MinStack {
 public:
  MinStack() {}

  void push(int x) {
    v.push_back(x);
    size++;
  }

  void pop() {
    if (v.size() != 0) {
      v.pop_back();
      size--;
    }
  }

  int top() {
    if (size) return v[size - 1];
    return 0;
  }

  int getMin() {
    if (size) {
      auto min = std::min_element(std::begin(v), std::end(v));
      return *min;
    }
    return 0;
  }

 private:
  std::vector<int> v{};
  int size{0};
};

}  // namespace min_stack

#endif  // CPP_0155_MIN_STACK_HPP
