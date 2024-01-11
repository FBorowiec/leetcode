# C++
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_googletest",
    strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
    urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
)

http_archive(
    name = "com_grail_bazel_compdb",
    strip_prefix = "bazel-compilation-database-0.5.2",
    urls = ["https://github.com/grailbio/bazel-compilation-database/archive/0.5.2.tar.gz"],
)

load("@com_grail_bazel_compdb//:deps.bzl", "bazel_compdb_deps")

bazel_compdb_deps()

# # GO
# http_archive(
#     name = "io_bazel_rules_go",
#     sha256 = "16e9fca53ed6bd4ff4ad76facc9b7b651a89db1689a2877d6fd7b82aa824e366",
#     urls = [
#         "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.34.0/rules_go-v0.34.0.zip",
#         "https://github.com/bazelbuild/rules_go/releases/download/v0.34.0/rules_go-v0.34.0.zip",
#     ],
# )
#
# load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")
#
# go_rules_dependencies()
#
# go_register_toolchains(version = "1.18.4")

# # PYTHON
# http_archive(
#     name = "rules_python",
#     sha256 = "cdf6b84084aad8f10bf20b46b77cb48d83c319ebe6458a18e9d2cebf57807cdd",
#     strip_prefix = "rules_python-0.8.1",
#     url = "https://github.com/bazelbuild/rules_python/archive/refs/tags/0.8.1.tar.gz",
# )
#
# load("@rules_python//python:repositories.bzl", "python_register_toolchains")
#
# python_register_toolchains(
#     name = "python",
#     python_version = "3.9",
# )
