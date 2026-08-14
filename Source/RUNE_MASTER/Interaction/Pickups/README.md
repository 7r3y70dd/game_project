# Pickups

Contains interactable world objects that represent collectible gameplay items or resources.

## Current Scope

The architecture reserves this folder but does not yet define a complete inventory or item framework.

Keep pickup behavior simple until those requirements exist.

## Rules

Pickups should:

- Use the normal interaction system.
- Respect server authority for gameplay-changing collection.
- Avoid directly modifying unrelated system internals.

If a pickup grants a gameplay effect, route that result through the appropriate owning subsystem rather than duplicating its logic here.
