# GameStates

Contains replicated high-level state describing the current game or dungeon run.

## Responsibilities

GameState may expose authoritative session information that clients need to observe.

Examples may include:

- Run state.
- Encounter state.
- Dungeon seed.
- Dungeon generation version.

## Boundaries

GameState should not become a general gameplay service.

Do not move into GameState:

- Spell execution.
- Damage calculations.
- Health ownership.
- Status-effect processing.
- Dungeon generation algorithms.

Subsystems should own their behavior and replicate only the state that other systems or clients require.
