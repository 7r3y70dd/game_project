# GameModes

Contains authoritative high-level game and run rules.

## Responsibilities

Game modes may coordinate:

- Player spawning.
- Session initialization.
- Dungeon run initialization.
- High-level game rules.
- Run or level transitions.

## Authority

GameMode logic runs on the authoritative server.

## Boundaries

Do not implement directly inside a GameMode:

- Spell behavior.
- Damage calculations.
- Projectile behavior.
- Hit-registration algorithms.
- Dungeon topology generation.
- Enemy behavior.

Delegate those operations to their owning subsystems.

GameModes coordinate gameplay; they do not replace gameplay systems.
