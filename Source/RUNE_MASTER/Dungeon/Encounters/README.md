# Dungeon Encounters

Contains dungeon encounter placement and encounter-state behavior.

## Generation Relationship

Encounter placement occurs after core layout generation.

Encounter generation should use its own deterministic derived seed so encounter balancing can change without unnecessarily changing physical dungeon layout.

Example conceptual seed:

EncounterSeed = Hash(RunSeed, "Encounters")

## Responsibilities

This subsystem may own:

- Encounter selection.
- Encounter budgets.
- Encounter placement.
- Encounter completion state.

## Boundaries

Encounter generation should not silently modify room topology.

Enemies spawned by encounters should use the normal shared character and combat systems.

The server owns authoritative encounter state.
