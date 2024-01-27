#include <gtest/gtest.h>

#include "cpp/0461_hamming_distance.hpp"

namespace {

class HammingDistance : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  hamming_distance::Solution sol{};
};

TEST_F(HammingDistance, HammingDistanceTest1) {
  auto result = sol.hammingDistance(1, 4);
  ASSERT_EQ(result, 2);
}

TEST_F(HammingDistance, HammingDistanceTest2) {
  auto result = sol.hammingDistance(3, 1);
  ASSERT_EQ(result, 1);
}

}  // namespace
