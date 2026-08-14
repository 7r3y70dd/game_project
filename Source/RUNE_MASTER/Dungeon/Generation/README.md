# Dungeon Generation

Contains orchestration of deterministic dungeon-generation stages.

## Recommended Flow

Run Configuration
→ Seed Resolution
→ Generate Abstract Room Graph
→ Select Entrance and Exit
→ Assign Room Types
→ Place Rooms
→ Connect Doors and Corridors
→ Validate Layout
→ Populate Encounters
→ Build Navigation

## Design Rule

Keep abstract generation separate from physical Actor spawning.

The graph represents gameplay structure.

Physical room actors represent the generated result.

## Determinism

Every random decision must originate from:

- The run seed.
- A deterministic derived seed.
- A deterministic retry seed.

Never use uncontrolled global randomness.

## Failure Handling

Generation may retry after validation failure.

Retry behavior must:

- Be deterministic.
- Derive retry seeds from the base seed.
- Use a capped retry count.
