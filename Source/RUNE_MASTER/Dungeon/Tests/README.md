# Dungeon Tests

Contains deterministic and functional tests for dungeon generation.

## Unit Coverage

Test:

- Seed parsing.
- Derived-seed calculation.
- Graph connectivity.
- Room selection constraints.
- Encounter budget calculations.
- Generation validation.

## Determinism

For fixed:

- Generator version.
- Configuration.
- Content set.

a given seed should produce the same stable graph representation.

Tests should compare a stable serialized representation or graph hash rather than Actor pointers.

Example:

Seed 1001 → Expected Graph Hash A
Seed 1002 → Expected Graph Hash B
Seed 1003 → Expected Graph Hash C

## Functional Validation

Generated dungeons should verify:

- Entrance exists.
- Exit exists.
- Exit is reachable.
- Required rooms are reachable.
- Illegal overlaps do not exist.
- Door connections align.
- Critical path satisfies requirements.
- Room count is valid.
- Encounter budget is valid.
