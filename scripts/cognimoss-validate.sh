#!/usr/bin/env bash
set -Eeuo pipefail

echo "=== Game project validation ==="

TEST_DIR="tests"
TEST_RUNNER="$TEST_DIR/run-tests.sh"

if [[ ! -d "$TEST_DIR" ]]; then
  echo "[OK] No tests/ directory exists yet."
  exit 0
fi

if ! find "$TEST_DIR" -type f -print -quit | grep -q .; then
  echo "[OK] tests/ is empty; nothing to run."
  exit 0
fi

if [[ -f "$TEST_RUNNER" ]]; then
  echo "Running $TEST_RUNNER..."
  bash "$TEST_RUNNER"
  echo "[OK] All tests passed."
  exit 0
fi

echo "[ERROR] tests/ contains files, but $TEST_RUNNER is missing." >&2
exit 1
