# GameInstance

Contains state and coordination whose lifetime must survive individual maps or dungeon levels.

## Appropriate Responsibilities

Use this directory for genuinely game-instance-level concerns such as persistent runtime coordination.

## Boundaries

Do not store here:

- Individual spell cast state.
- Per-projectile state.
- Per-enemy state.
- Room actor state.
- Temporary combat state.
- Logic owned by another subsystem.

Prefer subsystem-owned state whenever GameInstance lifetime is unnecessary.

The GameInstance should coordinate systems, not absorb them.
