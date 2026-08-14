# Interaction

Contains gameplay interaction between characters and interactable world objects.

Examples include:

- Doors.
- Chests.
- Shrines.
- Dungeon objects.
- Pickups.

## Design

Interaction should use capability-based interfaces and reusable components.

Prefer `IInteractableInterface` or similarly narrow contracts rather than concrete actor-class dependencies.

## Collision

Interactable objects may use the dedicated `Interactable` collision channel where appropriate.

## Authority

Gameplay-changing interaction results should respect server authority.

## Scope

The current architecture does not define a large inventory or interaction framework.

Do not introduce one implicitly without a concrete gameplay requirement.
