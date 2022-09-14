#include <vector>

#include "gtest/gtest.h"

#include "cpp/0392_is_subsequence.hpp"

namespace {

using namespace is_subsequence;

class IsSubsequenceTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(IsSubsequenceTest, ahbgdcIsSubsequenceOfabc) {
  std::string input{"abc"};
  std::string subs{"ahbgdc"};

  EXPECT_TRUE(sol.isSubsequence(input, subs));
}

TEST_F(IsSubsequenceTest, ahbgdcIsNotSubsequenceOfaxc) {
  std::string input{"axc"};
  std::string subs{"ahbgdc"};

  EXPECT_FALSE(sol.isSubsequence(input, subs));
}

TEST_F(IsSubsequenceTest, emptyStringIsSubsequenceOfAnyString) {
  std::string input{""};
  std::string subs{"ahbgdc"};

  EXPECT_TRUE(sol.isSubsequence(input, subs));
}

TEST_F(IsSubsequenceTest, bbIsNotSubsequenceOfahbgdc) {
  std::string input{"bb"};
  std::string subs{"ahbgdc"};

  EXPECT_FALSE(sol.isSubsequence(input, subs));
}

}  // namespace
