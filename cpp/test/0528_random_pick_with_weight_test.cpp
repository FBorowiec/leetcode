#include <iostream>

#include "gtest/gtest.h"

#include "cpp/0528_random_pick_with_weight.hpp"

namespace {

using namespace random_pick_with_weight;

TEST(RandomPickWithWeightTest, Input1OutputNull) {
  std::vector<int> w{{{1}}, {}};
  Solution* obj = new Solution(w);
  int param_1 = obj->pickIndex();

  EXPECT_EQ(param_1, 0);

  delete obj;
}

}  // namespace
