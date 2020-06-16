#ifndef LEETCODE_PROBLEMS_0468_VALIDATE_IP_ADDRESS_HPP
#define LEETCODE_PROBLEMS_0468_VALIDATE_IP_ADDRESS_HPP

//#include <cmath>
#include <regex>
//#include <sstream>
//#include <string>
//#include <vector>

namespace validate_id_address {

/**
 * Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
 *
 * IPv4 addresses are canonically represented in dot-decimal notation,
 * which consists of four decimal numbers, each ranging from 0 to 255,
 * separated by dots ("."), e.g.,172.16.254.1;
 * Besides, leading zeros in the IPv4 is invalid.
 * For example, the address 172.16.254.01 is invalid.
 *
 * IPv6 addresses are represented as eight groups of four hexadecimal digits,
 * each group representing 16 bits. The groups are separated by colons (":").
 * For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one.
 * Also, we could omit some leading zeros among four hexadecimal digits
 * and some low-case characters in the address to upper-case ones,
 * so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address
 * (Omit leading zeros and using upper cases).
 * However, we don't replace a consecutive group of zero value with a single empty group
 * using two consecutive colons (::) to pursue simplicity.
 * For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
 * Besides, extra leading zeros in the IPv6 is also invalid.
 * For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
 *
 * Note: You may assume there is no extra space or special characters in the input string.
 */
class Solution {
 public:
  std::string validIPAddress(std::string IP) {
    std::regex ipv4(
        "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"),
        ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");  // create regex object for regulare expression
    if (std::regex_match(IP, ipv4))                              // match regex expression with given IP string for IPv4
      return "IPv4";
    else if (std::regex_match(IP, ipv6))  // match regex expression with given IP string for IPv6
      return "IPv6";
    return "Neither";  // Otherwise return "Neither"
  }
};

// BAD!!
/*
class Solution {
 public:
  std::vector<int> tokensToInt(const std::vector<std::string>& IP) {
    std::vector<int> IP_int;
    for (unsigned int i = 0; i < IP.size(); i++) {
      int num = atoi(IP.at(i).c_str());
      IP_int.push_back(num);
    }
    return IP_int;
  }

  std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
    }
    return tokens;
  }

  std::string evalIPv4(const std::vector<std::string>& ip_vec_str) {
    auto IP_vec_int = tokensToInt(ip_vec_str);
      for (unsigned int i{0}; i < ip_vec_str.size(); ++i) {
        bool is_above_255{IP_vec_int[i] > 255};
        bool is_no_front_zero{ip_vec_str[i].length() > 1 && ip_vec_str[i][0] == '0'};
        bool is_size_valid{IP_vec_int[i] > 0 && IP_vec_int.size() == 4};
        if (is_above_255 || is_no_front_zero || !is_size_valid) return "Neither";
      }
      return "IPv4";
  }

  std::string evalIPv6(const std::vector<std::string>& ip_vec_str) {
      bool is_size_valid{ip_vec_str.size() == 8};
      if (!is_size_valid) return "Neither";
      for (unsigned int i{0}; i < ip_vec_str.size(); ++i) {
        if (ip_vec_str[i].length() == 0) return "Neither";
        bool is_valid_length{ip_vec_str[i].length() < 5};
        if (!is_valid_length) return "Neither";
      }
      return "IPv6";
  }

  std::string validIPAddress(std::string IP) {
    if (IP.back() == '.' || IP.back() == ':') return "Neither";
    std::size_t delimiter_pos = IP.find_first_not_of("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (delimiter_pos == std::string::npos) return "Neither";
    auto delimiter = (char)IP[delimiter_pos];
    auto ip_vec_str = split(IP, IP[delimiter_pos]);
    if (delimiter == '.') {  // IPv4
      if (IP.find_first_not_of("0123456789.") != std::string::npos) return "Neither";
      return evalIPv4(ip_vec_str);
    } else {
      if (IP[0] == '0') return "Neither";
      return evalIPv6(ip_vec_str);
    }
  }
};
*/

}  // namespace validate_id_address

#endif  // LEETCODE_PROBLEMS_0468_VALIDATE_IP_ADDRESS_HPP
