# Dungeon System

Contains deterministic dungeon-run generation and runtime dungeon structure.

## Goals

The generator should produce:

- Reproducible layouts.
- Valid connected paths.
- Guaranteed entrance.
- Guaranteed objective or exit.
- Configurable room counts.
- Encounter placement.
- Loot placement.
- Optional branches.
- Theme variation.

## Architecture

Use a graph-first generator.

Seed
→ Abstract Room Graph
→ Entrance / Exit Selection
→ Room Type Assignment
→ Grid Placement
→ Door and Corridor Connections
→ Connectivity Validation
→ Encounter Population
→ Navigation

Gameplay topology should be determined before physical room actors are spawned.

## Determinism

The same:

- Seed.
- Generator version.
- Dungeon configuration.
- Room library.

should produce the same dungeon layout.

Do not use global random functions for deterministic generation.

Use seeded `FRandomStream` instances or deterministic derived seeds.
