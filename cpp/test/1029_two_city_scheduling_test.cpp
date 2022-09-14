#include <vector>

#include "gtest/gtest.h"

#include "cpp/1029_two_city_scheduling.hpp"

namespace {

using namespace two_city_scheduling;

class TwoCitySchedulingTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution sol;
};

TEST_F(TwoCitySchedulingTest, MinValuesAlternateEvenly) {
  /*
   * Input: [[10,20],[30,200],[400,50],[30,20]]
   * Output: 110
   * Explanation:
   * The first person goes to city A for a cost of 10.
   * The second person goes to city A for a cost of 30.
   * The third person goes to city B for a cost of 50.
   * The fourth person goes to city B for a cost of 20.
   *
   * The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
   */
  std::vector<std::vector<int>> input{{10, 20}, {30, 200}, {400, 50}, {30, 20}};
  int expected_result = 110;

  auto result = sol.twoCitySchedCost(input);

  EXPECT_EQ(result, expected_result);
}

TEST_F(TwoCitySchedulingTest, MinValuesAlternateOddly) {
  std::vector<std::vector<int>> input{{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}};
  int expected_result = 1859;

  auto result = sol.twoCitySchedCost(input);

  EXPECT_EQ(result, expected_result);
}

}  // namespace
