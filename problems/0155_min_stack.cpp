/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *   push(x) -- Push element x onto stack.
 *   pop() -- Removes the element on top of the stack.
 *   top() -- Get the top element.
 *   getMin() -- Retrieve the minimum element in the stack.
 */
#include <algorithm>
#include <vector>

namespace min_stack
{

class MinStack {
 public:
  MinStack() {}

  void push(int x) {
      v.push_back(x);
      size++;
  }

  void pop() {
    if (v.size() != 0)
    {
      v.pop_back();
      size--;
    }
  }

  int top() {
    if (size)
      return v[size-1];
    return 0;
  }

  int getMin() {
    if (size)
    {
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

// TEST---------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

TEST(MinStackTest, AllFunctionsYieldExpectedResults)
{
  min_stack::MinStack min_stack{};
  min_stack.push(5);
  min_stack.push(6);
  min_stack.push(7);
  min_stack.push(2);
  min_stack.push(88);
  min_stack.pop();
  min_stack.push(8);

  ASSERT_EQ(min_stack.getMin(), 2);
  ASSERT_EQ(min_stack.top(), 8);
}

}  // namespace
