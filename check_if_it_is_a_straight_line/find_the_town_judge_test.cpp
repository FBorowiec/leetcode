/**
 * In a town, there are N people labelled from 1 to N.\
 * There is a rumor that one of these people is secretly the town judge.
 *
 * If the town judge exists, then:
 *
 *     The town judge trusts nobody.
 *     Everybody (except for the town judge) trusts the town judge.
 *     There is exactly one person that satisfies properties 1 and 2.
 *
 * You are given trust, an array of pairs trust[i] = [a, b]
 * representing that the person labelled a trusts the person labelled b.
 *
 * If the town judge exists and can be identified, return the label of the town judge.
 * Otherwise, return -1.
 */
#include <vector>

class Solution {
public:
    int findJudge(int N, std::vector<std::vector<int>>& trust) {
      if (N < 1 || N > 1000) return -1;
      if (trust.size() > 10000) return -1;
      for (size_t i{0}; i < trust.size(); ++i) {
        if (trust[i][0] == trust [i][1]) return -1;
        if ((trust[i][0] < 1 || trust [i][0] > N) || (trust[i][1] < 1 || trust [i][1] > N)) return -1;
      }
      return -1;
    }
};

// TEST --------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

using Matrix = std::vector<std::vector<int>>;

class FindTheTownJudgeTest : public ::testing::Test
{
 public:
  void SetUp() override {}

 protected:
  Solution solution{};
  Matrix oversize_vector{(Matrix(10001, {std::vector<int>(2, 1)}))};
  Matrix same_people{(Matrix(100, {std::vector<int>(2, 1)}))};
  Matrix more_people_than_declared{{1000, 1}, {1234, 987}, {324892, 98}};
};

TEST_F(FindTheTownJudgeTest, PairOfPeopleOneIsJudge_ThenTrust)
{
  // Given
  int n{2};
  Matrix trust{{1, 2}};
  // When
  int expected_output{2};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, TwoPairOfPeopleOneIsJudge_ThenTrust)
{
  // Given
  int n{3};
  Matrix trust{{1, 3}, {2, 3}};
  // When
  int expected_output{3};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, ThreePairOfPeopleNooneIsJudge_ThenDontTrust)
{
  // Given
  int n{3};
  Matrix trust{{1, 3}, {2, 3}, {3, 1}};
  // When
  int expected_output{-1};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, TwoPairOfPeopleNooneIsJudge_ThenDontTrust)
{
  // Given
  int n{3};
  Matrix trust{{1, 3}, {2, 3}, {3, 1}};
  // When
  int expected_output{-1};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, FivePairOfPeople3IsJudge_ThenTrust)
{
  // Given
  int n{4};
  Matrix trust{{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
  // When
  int expected_output{3};
  // Then
  ASSERT_EQ(solution.findJudge(n, trust), expected_output);
}

TEST_F(FindTheTownJudgeTest, OversizeVector_ThenDontTrust)
{
  ASSERT_EQ(solution.findJudge(1, oversize_vector), -1);
}

TEST_F(FindTheTownJudgeTest, VectorWithSamePeople_ThenDontTrust)
{
  ASSERT_EQ(solution.findJudge(1, same_people), -1);
}

TEST_F(FindTheTownJudgeTest, MorePeopleThanDeclared_ThenDontTrust)
{
  ASSERT_EQ(solution.findJudge(1, more_people_than_declared), -1);
}

}  // namespace
