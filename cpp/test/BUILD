load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "unit_test",
    srcs = ["0026_remove_duplicates_from_sorted_array_test.cpp"],
    copts = [
        "-ggdb",
        "-O0",
        "-Werror",
        "-std=c++17",
    ],
    features = [
        "extra_warnings",
        "test_warnings",
        "treat_warnings_as_errors",
    ],
    deps = [
        "//cpp:leetcode",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "unit_tests",
    srcs = glob(["*_test.cpp"]),
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
        "//cpp:leetcode",
        "@com_google_googletest//:gtest_main",
    ],
)
