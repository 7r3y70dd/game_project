# UI

Contains player-facing and developer-facing presentation.

## Presentation Rule

UI observes gameplay state and sends player intent.

UI does not own authoritative gameplay.

Do not place authoritative:

- Damage.
- Cooldowns.
- Resources.
- Cast validation.
- Hit registration.
- Dungeon generation.

inside widgets.

## Client-Owned Presentation

UI may display:

- Crosshair.
- Targeting preview.
- Spell state.
- Cooldowns.
- Health.
- Status effects.
- Dungeon state.
- Debug information.

The server remains the source of truth for gameplay state.
