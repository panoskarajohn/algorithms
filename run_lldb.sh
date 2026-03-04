#!/usr/bin/env bash
set -euo pipefail

# ===== Hardcoded config =====
BIN="./build/tests/my_tests"
TEST="WordDictionary2.VeryBasic"

# Format: "file:line" or "symbol"
BREAKPOINTS=(
  "tests/word_dictionary_test.cpp:42"
  "tests/word_dictionary_test.cpp:57"
  # "WordDictionary::search"
)
# ============================

if [[ ! -x "$BIN" ]]; then
  echo "Error: '$BIN' is not executable"
  exit 1
fi

# If user provides args, treat them as breakpoints; else use hardcoded array
if [[ $# -gt 0 ]]; then
  BPS=( "$@" )
else
  BPS=( "${BREAKPOINTS[@]}" )
fi

LLDB_ARGS=()

for BP in "${BPS[@]}"; do
  if [[ "$BP" == *:* ]]; then
    FILE="${BP%%:*}"
    LINE="${BP##*:}"
    if [[ -f "$FILE" ]]; then
      FILE="$(python3 -c 'import os,sys; print(os.path.realpath(sys.argv[1]))' "$FILE")"
    fi
    LLDB_ARGS+=( -o "breakpoint set --file $FILE --line $LINE" )
  else
    LLDB_ARGS+=( -o "breakpoint set --name $BP" )
  fi
done

LLDB_ARGS+=( -o "breakpoint list" )
LLDB_ARGS+=( -o "run" )

lldb "${LLDB_ARGS[@]}" -- "$BIN" "--gtest_filter=$TEST"
