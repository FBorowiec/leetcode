cc_test(
  name = "unit_tests",
  srcs = glob(
    [
      "*_test.cpp",
    ]
  ),
  copts = [
    "-Werror",
    "-O0",
    "-ggdb",
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
