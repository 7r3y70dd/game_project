# Dungeon Debug

Contains developer visualization and diagnostics for dungeon generation.

## Debug Overlay

Useful information includes:

- Seed.
- Generator version.
- Room count.
- Critical path.
- Room IDs.
- Room types.
- Encounter budgets.
- Validation status.
- Retry index.

## Visualization

Debug tools may display:

- Abstract graph.
- Room connections.
- Critical path.
- Invalid overlaps.
- Failed door connections.
- Generation stages.

## Rule

Debug functionality must observe generation behavior rather than alter authoritative generation results.

Verbose debug behavior should be reduced or disabled in production builds.
