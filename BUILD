cc_library(
  name = "leetcode",
  hdrs=glob(["*.hpp"]),
  srcs = glob(["*.cpp"]),
  visibility = ["//visibility:public"],
)

cc_binary(
    name = "leetcode_binary",
  srcs = glob(["*.cpp"]),
    deps = ["//:leetcode"],
)

cc_test(
  name = "leetcode_tests",
  srcs = glob(["*.cpp"]),
  deps = [
      "//:leetcode",
      "@googletest//:gtest",
      "@googletest//:gtest_main",
    ],
)