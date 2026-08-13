# Player

Contains player-character-specific behavior.

## Responsibilities

The player character may provide:

- Movement.
- Camera-related character behavior.
- Attachment points for reusable gameplay components.
- Character state needed by player-controlled gameplay.

Typical components may include:

- Spell casting.
- Health.
- Status effects.
- Team identity.
- Interaction.

## Critical Boundary

Adding a normal new spell should not require modifying the player character class.

Spell-specific behavior belongs in the spell system.

Damage resolution belongs in Combat.

Input coordination may originate from the player but authoritative gameplay must follow the standard server pipeline.
