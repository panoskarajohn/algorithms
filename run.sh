#!/usr/bin/env bash
set -e

# Usage:
#   ./run.sh                    # run all tests
#   ./run.sh TestSuite          # run a test suite
#   ./run.sh TestSuite.TestName # run a single test
#   ./run.sh --list-tests       # list all discovered tests

# Configure + build
mkdir -p build
cmake -S . -B build
cmake --build build

# Run tests without cd
if [ "$#" -eq 0 ]; then
  ./build/bin/algorithms
elif [ "$1" = "--list-tests" ] || [ "$1" = "-l" ]; then
  ./build/bin/algorithms --gtest_list_tests
elif [[ "$1" == --* ]]; then
  ./build/bin/algorithms "$@"
else
  filter="$1"
  if [[ "$filter" != *.* && "$filter" != *:* ]]; then
    filter="${filter}.*"
  fi
  ./build/bin/algorithms "--gtest_filter=$filter"
fi
