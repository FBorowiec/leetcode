#include <algorithm>
#include <vector>

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

// TEST---------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

TEST(MinStackTest, AllFunctionsYieldExpectedResults)
{
  MinStack min_stack{};
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
