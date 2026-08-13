# Core

Contains high-level Rune Mater runtime infrastructure and session coordination.

## Responsibilities

Core contains:

- Game instance behavior.
- Game modes.
- Game states.
- Player controllers.
- Project-wide developer settings.

Core coordinates gameplay systems but should not implement their internal mechanics.

## Boundaries

Do not place here:

- Individual spell behavior.
- Damage calculations.
- Hit-registration algorithms.
- Projectile implementation.
- Dungeon generation algorithms.
- Enemy-specific combat logic.
- UI presentation logic.

Prefer calling subsystem APIs rather than implementing subsystem behavior in Core.

Core must not become a miscellaneous dumping ground.
