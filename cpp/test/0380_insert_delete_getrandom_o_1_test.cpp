#include "gtest/gtest.h"

#include "cpp/0380_insert_delete_getrandom_o_1.hpp"

namespace {

using namespace insert_delete_get_random_o_1;

class InsertDeleteGetrandomO1Test : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  RandomizedSet randomSet{};
};

/**
 * Example:
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 *
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 *
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 *
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 *
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 *
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 *
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 *
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 */
TEST_F(InsertDeleteGetrandomO1Test, Test1) {
  EXPECT_TRUE(randomSet.insert(1));
  EXPECT_FALSE(randomSet.remove(2));
  EXPECT_TRUE(randomSet.insert(2));
  auto rnd1 = randomSet.getRandom();
  EXPECT_TRUE(rnd1 == 1 || rnd1 == 2);
  EXPECT_TRUE(randomSet.remove(1));
  EXPECT_FALSE(randomSet.insert(2));
  auto rnd2 = randomSet.getRandom();
  EXPECT_TRUE(rnd2 == 2);
}

}  // namespace
