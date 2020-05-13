#include "gtest/gtest.h"

#include "problems/0155_min_stack.hpp"

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
