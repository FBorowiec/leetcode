load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "unit_tests",
  srcs = glob(["*_test.cpp",]),
  copts = [
    "-ggdb",
    "-O0",
    "-Werror",
  ],
  features = [
    "extra_warnings",
    "test_warnings",
    "treat_warnings_as_errors",
  ],
  deps = [
    "//problems:leetcode",
    "@gtest//:gtest",
    "@gtest//:gtest_main",
  ],
)

cc_test(
  name = "remove_k_digits",
  srcs = ["0402_remove_k_digits_test.cpp",],
  copts = [
    "-ggdb",
    "-O0",
    "-Werror",
  ],
  features = [
    "extra_warnings",
    "test_warnings",
    "treat_warnings_as_errors",
  ],
  deps = [
    "//problems:leetcode",
    "@gtest//:gtest",
    "@gtest//:gtest_main",
  ],
)
