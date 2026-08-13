# Character Components

Contains reusable components associated with character behavior.

## Rule

Components in this directory should have a narrow, clearly defined responsibility.

Before adding a new component here, check whether it actually belongs in:

- Spells/
- Combat/
- Interaction/

Subsystem-specific components should remain inside their subsystem.

## Design

Prefer components that can be reused by both player and enemy characters when practical.

Avoid "manager" components that accumulate unrelated gameplay responsibilities.
