#include "gtest/gtest.h"

#include "cpp/0997_find_the_town_judge.hpp"

namespace {

using Matrix = std::vector<std::vector<int>>;

class FindTheTownJudgeTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  find_the_town_judge::Solution solution{};
  Matrix oversize_vector{(Matrix(10001, {std::vector<int>(2, 1)}))};
  Matrix same_people{(Matrix(100, {std::vector<int>(2, 1)}))};
  Matrix more_people_than_declared{{1000, 1}, {1234, 987}, {324892, 98}};
};

TEST_F(FindTheTownJudgeTest, PairOfPeopleOneIsJudge_ThenTrust) {
  // Given
  int n{2};
  Matrix trust{{1, 2}};
  // When
  int expected_output{2};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, TwoPairOfPeopleOneIsJudge_ThenTrust) {
  // Given
  int n{3};
  Matrix trust{{1, 3}, {2, 3}};
  // When
  int expected_output{3};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, ThreePairOfPeopleNooneIsJudge_ThenDontTrust) {
  // Given
  int n{3};
  Matrix trust{{1, 3}, {2, 3}, {3, 1}};
  // When
  int expected_output{-1};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, TwoPairOfPeopleNooneIsJudge_ThenDontTrust) {
  // Given
  int n{3};
  Matrix trust{{1, 3}, {2, 3}, {3, 1}};
  // When
  int expected_output{-1};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, FivePairOfPeople3IsJudge_ThenTrust) {
  // Given
  int n{4};
  Matrix trust{{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
  // When
  int expected_output{3};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, OversizeVector_ThenDontTrust) { ASSERT_EQ(solution.findJudge(1, oversize_vector), -1); }

TEST_F(FindTheTownJudgeTest, VectorWithSamePeople_ThenDontTrust) { ASSERT_EQ(solution.findJudge(1, same_people), -1); }

TEST_F(FindTheTownJudgeTest, MorePeopleThanDeclared_ThenDontTrust) {
  ASSERT_EQ(solution.findJudge(1, more_people_than_declared), -1);
}

TEST_F(FindTheTownJudgeTest, DISABLED_WithGivenPopulation_ThenPerson3IsJudge) {
  // Given
  int n{3};
  Matrix trust{{1, 3}, {2, 3}, {3, 1}};
  // When
  int expected_output{3};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

}  // namespace
