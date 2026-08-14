# Spell Bar

Contains UI presenting equipped spells and spell availability.

The spell bar may display:

- Equipped spells.
- Spell icons.
- Cooldowns.
- Resource requirements.
- Cast availability.
- Selection state.

## Authority

Displayed cooldown and availability state should reflect the authoritative spell system.

The Spell Bar may initiate player intent, but it must not independently decide that a spell is legally castable.

Final validation belongs to the spell-casting system and server.
