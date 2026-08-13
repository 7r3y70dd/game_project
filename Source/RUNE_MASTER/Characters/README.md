# Characters

Contains player and enemy actor implementations plus reusable character-oriented components and interfaces.

## Design Principle

Characters should primarily compose reusable gameplay systems rather than implement large gameplay systems directly.

A character may contain components for:

- Health.
- Status effects.
- Teams.
- Spell casting.
- Targeting.
- Interaction.

## Shared Combat

Players and enemies should use the same combat interfaces and effect pipeline wherever practical.

## Boundaries

Do not hard-code individual spell behavior into character classes.

Do not make combat systems depend unnecessarily on concrete player or enemy classes.

Prefer:

- Components.
- Interfaces.
- Gameplay Tags.
- Shared combat APIs.
