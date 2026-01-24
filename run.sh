#!/usr/bin/env bash
set -e

# Configure + build
mkdir -p build
cmake -S . -B build
cmake --build build

# Run tests without cd
./build/bin/algorithms
