#include "gtest/gtest.h"

#include "cpp/0035_search_insert_position.hpp"

namespace {

using namespace search_insert_position;

class SearchInsertPositionTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(SearchInsertPositionTest, 5isAtPos2) {
  std::vector<int> input{1, 3, 5, 6};
  int target{5};
  int expected_result{2};

  auto result = sol.searchInsert(input, target);
  EXPECT_EQ(expected_result, result);
}

TEST_F(SearchInsertPositionTest, 2isAtPos1) {
  std::vector<int> input{1, 3, 5, 6};
  int target{2};
  int expected_result{1};

  auto result = sol.searchInsert(input, target);
  EXPECT_EQ(expected_result, result);
}

TEST_F(SearchInsertPositionTest, 7isAtPos4) {
  std::vector<int> input{1, 3, 5, 6};
  int target{7};
  int expected_result{4};

  auto result = sol.searchInsert(input, target);
  EXPECT_EQ(expected_result, result);
}

TEST_F(SearchInsertPositionTest, 0isAtPos0) {
  std::vector<int> input{1, 3, 5, 6};
  int target{0};
  int expected_result{0};

  auto result = sol.searchInsert(input, target);
  EXPECT_EQ(expected_result, result);
}

}  // namespace
