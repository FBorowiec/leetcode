#include <gtest/gtest.h>

#include "problems/0412_fizz_buzz.hpp"

namespace {

using namespace fizz_buzz;

class FizzBuzz : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol{};
  std::vector<std::string> expected_output{"1",    "2",    "Fizz", "4",    "Buzz", "Fizz", "7",       "8",
                                           "Fizz", "Buzz", "11",   "Fizz", "13",   "14",   "FizzBuzz"};
};

TEST_F(FizzBuzz, FizzBuzzTest) {
  auto result = sol.fizzBuzz(15);
  ASSERT_EQ(expected_output.size(), result.size());
  for (unsigned int i{0}; i < expected_output.size(); ++i) {
    EXPECT_STREQ(expected_output[i].c_str(), result[i].c_str());
  }
}

}  // namespace
