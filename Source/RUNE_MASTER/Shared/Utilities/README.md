# Shared Utilities

Contains small reusable helpers with legitimate cross-system use.

## Requirements

A shared utility should:

- Have a narrow purpose.
- Be deterministic when used by deterministic gameplay.
- Avoid mutable global gameplay state.
- Avoid dependencies on concrete player, enemy, spell, or dungeon classes.

## Rule

Do not move code here merely because it is inconvenient to decide where it belongs.

Subsystem-specific helpers should remain inside their subsystem.

Shared utilities should simplify stable primitives, not become a hidden gameplay framework.
