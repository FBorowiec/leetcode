#include "gtest/gtest.h"

#include "cpp/0468_validate_ip_address.hpp"

namespace {

using namespace validate_id_address;

class ValidateIpAddressTest : public ::testing::Test {
 public:
  void SetUp() override {}

 protected:
  Solution solution{};
};

TEST_F(ValidateIpAddressTest, ValidIpv4IsIdentified) {
  std::string input{"172.16.254.1"};
  std::string expected_output{"IPv4"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, ValidIpv6IsIdentified) {
  std::string input{"2001:0db8:85a3:0:0:8A2E:0370:7334"};
  std::string expected_output{"IPv6"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv4IsDetected) {
  std::string input{"256.256.256.256"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv6IsDetected) {
  std::string input{"2001:0db8:85a3:0:0:8A2E:0370:7334:"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv4withAlphaCharIsDetected) {
  std::string input{"1e1.4.5.6"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv4withFrontZeroesIsDetected) {
  std::string input{"01.01.01.01"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv4withDoubleDotsIsDetected) {
  std::string input{"12..33.4"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv4withMoreThan4TokensIsDetected) {
  std::string input{"12.12.12.12.12"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv6WithFiveLeadingZeroesIsDetected) {
  std::string input{"2001:0db8:85a3:00000:0:8A2E:0370:7334"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, ValidIpv6WithOneLeadingZeroIsIdentified) {
  std::string input{"2001:0db8:85a3:0:0:8A2E:0370:7334"};
  std::string expected_output{"IPv6"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv6WithTooManyTokensIsDetected) {
  std::string input{"2001:0db8:85a3:0:0:8A2E:0370:7334:1a76"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, ValidIpv6WithFourLeadingZeroIsIdentified) {
  std::string input{"2001:0db8:85a3:0000:0:8A2E:0370:733a"};
  std::string expected_output{"IPv6"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv6WithFrontZeroIsDetected) {
  std::string input{"02001:0db8:85a3:0000:0000:8a2e:0370:7334"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv6WithTwoCommasIsDetected) {
  std::string input{"2001:0db8:85a3::8A2E:0370:7334"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, ValidIpv6WithTwoAlphaNumericalInSecondTokenIsIdentified) {
  std::string input{"2001:db8:85a3:0:0:8A2E:0370:7334"};
  std::string expected_output{"IPv6"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

TEST_F(ValidateIpAddressTest, InvalidIpv6WithTwoAlphasInFirstTokenIsDetected) {
  std::string input{"20EE:FGb8:85a3:0:0:8A2E:0370:7334"};
  std::string expected_output{"Neither"};

  auto result = solution.validIPAddress(input);
  EXPECT_STREQ(expected_output.c_str(), result.c_str());
}

}  // namespace
