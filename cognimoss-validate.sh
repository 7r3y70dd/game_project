#!/usr/bin/env bash

# ============================================================
# RUNE_MATER - Cognimoss Validation Script
# ============================================================
#
# Purpose:
#   Validate changes made by the Cognimoss coding agent.
#
# Validation order:
#   1. Repository sanity checks
#   2. Unreal project structure checks
#   3. Git diff checks
#   4. Merge-conflict checks
#   5. Unreal C++ build, if Unreal Engine is available
#   6. Optional Unreal Automation Tests
#
# Environment variables:
#
#   UE_ROOT=/path/to/UnrealEngine
#       Explicit Unreal Engine installation/source directory.
#
#   COGNIMOSS_REQUIRE_UNREAL=1
#       Fail validation if Unreal Engine cannot be found.
#
#   COGNIMOSS_RUN_TESTS=1
#       Run Unreal Automation Tests after a successful build.
#
#   COGNIMOSS_TEST_FILTER=RUNE_MATER
#       Automation test filter. Defaults to RUNE_MATER.
#
# ============================================================

set -uo pipefail

# ------------------------------------------------------------
# Configuration
# ------------------------------------------------------------

PROJECT_NAME="RUNE_MATER"

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$SCRIPT_DIR"

cd "$ROOT"

PROJECT_FILE="$ROOT/${PROJECT_NAME}.uproject"
SOURCE_DIR="$ROOT/Source/${PROJECT_NAME}"

REQUIRE_UNREAL="${COGNIMOSS_REQUIRE_UNREAL:-0}"
RUN_TESTS="${COGNIMOSS_RUN_TESTS:-0}"
TEST_FILTER="${COGNIMOSS_TEST_FILTER:-$PROJECT_NAME}"

ERRORS=0
WARNINGS=0


# ------------------------------------------------------------
# Output helpers
# ------------------------------------------------------------

section() {
    echo
    echo "============================================================"
    echo "$1"
    echo "============================================================"
}

pass() {
    echo "[PASS] $1"
}

warn() {
    echo "[WARN] $1"
    WARNINGS=$((WARNINGS + 1))
}

fail() {
    echo "[FAIL] $1"
    ERRORS=$((ERRORS + 1))
}


# ------------------------------------------------------------
# 1. Repository sanity
# ------------------------------------------------------------

section "Repository sanity"

if [[ -f "$PROJECT_FILE" ]]; then
    pass "Found ${PROJECT_NAME}.uproject"
else
    fail "Missing ${PROJECT_NAME}.uproject"
fi

if [[ -d "$SOURCE_DIR" ]]; then
    pass "Found Source/${PROJECT_NAME}"
else
    fail "Missing Source/${PROJECT_NAME}"
fi

if [[ -f "$SOURCE_DIR/${PROJECT_NAME}.Build.cs" ]]; then
    pass "Found ${PROJECT_NAME}.Build.cs"
else
    fail "Missing ${PROJECT_NAME}.Build.cs"
fi

if [[ -f "$SOURCE_DIR/${PROJECT_NAME}.cpp" ]]; then
    pass "Found ${PROJECT_NAME}.cpp"
else
    fail "Missing ${PROJECT_NAME}.cpp"
fi

if [[ -f "$SOURCE_DIR/${PROJECT_NAME}.h" ]]; then
    pass "Found ${PROJECT_NAME}.h"
else
    fail "Missing ${PROJECT_NAME}.h"
fi


# ------------------------------------------------------------
# 2. Expected architecture
# ------------------------------------------------------------

section "Source architecture"

EXPECTED_DIRS=(
    "Core"
    "Characters"
    "Spells"
    "Combat"
    "Dungeon"
    "Interaction"
    "UI"
    "Shared"
)

for dir in "${EXPECTED_DIRS[@]}"; do
    if [[ -d "$SOURCE_DIR/$dir" ]]; then
        pass "Source/${PROJECT_NAME}/${dir}"
    else
        warn "Expected directory is missing: Source/${PROJECT_NAME}/${dir}"
    fi
done


# ------------------------------------------------------------
# 3. Git diff sanity
# ------------------------------------------------------------

section "Git checks"

if command -v git >/dev/null 2>&1 && git rev-parse --is-inside-work-tree >/dev/null 2>&1; then

    if git diff --check; then
        pass "git diff --check"
    else
        fail "Whitespace/error markers detected by git diff --check"
    fi

else
    warn "Git repository unavailable; skipping git checks"
fi


# ------------------------------------------------------------
# 4. Merge conflict detection
# ------------------------------------------------------------

section "Conflict marker scan"

CONFLICT_RESULTS="$(
    grep \
        -RIn \
        --exclude-dir=.git \
        --exclude-dir=Binaries \
        --exclude-dir=DerivedDataCache \
        --exclude-dir=Intermediate \
        --exclude-dir=Saved \
        --exclude='cognimoss-validate.sh' \
        -E '^(<<<<<<< |=======|>>>>>>> )' \
        "$ROOT/Source" \
        2>/dev/null || true
)"

if [[ -n "$CONFLICT_RESULTS" ]]; then
    echo "$CONFLICT_RESULTS"
    fail "Unresolved merge conflict markers found"
else
    pass "No unresolved merge conflict markers"
fi


# ------------------------------------------------------------
# Stop before expensive checks if repository is invalid
# ------------------------------------------------------------

if (( ERRORS > 0 )); then
    section "Validation failed"

    echo "Errors:   $ERRORS"
    echo "Warnings: $WARNINGS"

    exit 1
fi


# ------------------------------------------------------------
# 5. Locate Unreal Engine
# ------------------------------------------------------------

section "Unreal Engine discovery"

UE_PATH=""

CANDIDATES=(
    "${UE_ROOT:-}"
    "${UE_ENGINE_ROOT:-}"
    "${UNREAL_ENGINE_ROOT:-}"
    "$HOME/UnrealEngine"
    "$HOME/UnrealEngine-5"
    "/opt/UnrealEngine"
    "/opt/unreal-engine"
)

for candidate in "${CANDIDATES[@]}"; do

    [[ -z "$candidate" ]] && continue

    if [[ -f "$candidate/Engine/Build/BatchFiles/Linux/Build.sh" ]]; then
        UE_PATH="$candidate"
        break
    fi

done


if [[ -z "$UE_PATH" ]]; then

    if [[ "$REQUIRE_UNREAL" == "1" ]]; then
        fail "Unreal Engine was not found and COGNIMOSS_REQUIRE_UNREAL=1"

        section "Validation failed"

        echo "Errors:   $ERRORS"
        echo "Warnings: $WARNINGS"

        exit 1
    fi

    warn "Unreal Engine not found"
    warn "Skipping C++ compilation"

    echo
    echo "Set UE_ROOT to enable full validation:"
    echo
    echo '    export UE_ROOT=/path/to/UnrealEngine'
    echo

else
    pass "Unreal Engine found: $UE_PATH"
fi


# ------------------------------------------------------------
# 6. Unreal C++ build
# ------------------------------------------------------------

if [[ -n "$UE_PATH" ]]; then

    section "Unreal C++ build"

    BUILD_SCRIPT="$UE_PATH/Engine/Build/BatchFiles/Linux/Build.sh"
    TARGET="${PROJECT_NAME}Editor"

    echo "Target:        $TARGET"
    echo "Platform:      Linux"
    echo "Configuration: Development"
    echo

    if "$BUILD_SCRIPT" \
        "$TARGET" \
        Linux \
        Development \
        "-Project=$PROJECT_FILE" \
        -WaitMutex \
        -NoHotReloadFromIDE
    then
        pass "Unreal C++ build completed successfully"
    else
        fail "Unreal C++ build failed"
    fi

fi


# ------------------------------------------------------------
# 7. Optional Unreal Automation Tests
# ------------------------------------------------------------

if [[ "$RUN_TESTS" == "1" ]]; then

    section "Unreal Automation Tests"

    if [[ -z "$UE_PATH" ]]; then

        fail "Automation tests requested but Unreal Engine is unavailable"

    else

        EDITOR_CMD="$UE_PATH/Engine/Binaries/Linux/UnrealEditor-Cmd"

        if [[ ! -x "$EDITOR_CMD" ]]; then

            warn "UnrealEditor-Cmd not found:"
            warn "$EDITOR_CMD"

        else

            echo "Test filter: $TEST_FILTER"
            echo

            if "$EDITOR_CMD" \
                "$PROJECT_FILE" \
                -unattended \
                -nop4 \
                -NullRHI \
                -NoSound \
                -stdout \
                -FullStdOutLogOutput \
                -ExecCmds="Automation RunTests ${TEST_FILTER}; Quit"
            then
                pass "Automation test process completed"
            else
                fail "Unreal Automation Tests failed"
            fi

        fi

    fi

fi


# ------------------------------------------------------------
# Final result
# ------------------------------------------------------------

section "Validation summary"

echo "Errors:   $ERRORS"
echo "Warnings: $WARNINGS"
echo

if (( ERRORS > 0 )); then
    echo "RESULT: FAILED"
    exit 1
fi

echo "RESULT: PASSED"
exit 0
