#include "gtest/gtest.h"

#include "cpp/0406_queue_reconstruction_by_height.hpp"

namespace {

using namespace queue_reconstruction_by_height;

class QueueReconstructionByHeightTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(QueueReconstructionByHeightTest, Test1) {
  std::vector<std::vector<int>> input{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  std::vector<std::vector<int>> expected_result{{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};

  auto result = sol.reconstructQueue(input);

  ASSERT_EQ(expected_result.size(), result.size());
  for (unsigned int i{0}; i < expected_result.size(); ++i) {
    EXPECT_EQ(result[i], expected_result[i]);
  }
}

}  // namespace
