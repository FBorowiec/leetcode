load("@io_bazel_rules_go//go:def.bzl", "go_test")

go_test(
    name = "unit_tests",
    srcs = glob(["*_test.go"]),
    embed = ["//go:leetcode"],
)
