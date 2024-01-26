#!/usr/bin/env bash

echo "Installing pre-commit.." && pip3 install pre-commit &>/dev/null
pre-commit --version

set -eu
toplevel=${1:-$(git rev-parse --show-toplevel)}
cd ${toplevel}

echo "Removing any previous installation.." && pre-commit uninstall
echo "Installing pre-commit git hooks in ${toplevel}.." && pre-commit install --hook-type commit-msg
echo "Running pre-commit hooks.." && pre-commit run --all-files
