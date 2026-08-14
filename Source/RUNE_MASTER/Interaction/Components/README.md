# Interaction Components

Contains reusable interaction-oriented ActorComponents.

Use components when interaction behavior should be composed onto multiple actor types.

## Design Rules

Components should:

- Own one clear interaction responsibility.
- Communicate through stable interfaces.
- Remain independent of specific player subclasses when possible.

## Boundaries

Do not place spell logic, combat calculations, or dungeon-generation algorithms here.

Do not create a broad interaction framework beyond current gameplay needs.
