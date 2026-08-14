# HUD

Contains in-game player HUD presentation.

Possible HUD information includes:

- Health.
- Current spell state.
- Target information.
- Crosshair.
- Run information.
- Relevant status effects.

## Rule

HUD widgets display gameplay state.

They should not calculate authoritative gameplay outcomes.

Gameplay data should come from the subsystem that owns that state.

Avoid duplicating spell, health, or dungeon rules inside UI code.
