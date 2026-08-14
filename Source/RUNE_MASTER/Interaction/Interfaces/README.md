# Interaction Interfaces

Contains interfaces representing interaction capabilities.

The primary initial interface is:

IInteractableInterface

It supports interaction with objects such as:

- Doors.
- Chests.
- Shrines.
- Dungeon objects.

## Interface Rules

Keep interfaces:

- Small.
- Capability-focused.
- Independent of concrete actor classes.

Do not create one large interface containing unrelated gameplay responsibilities.

Interaction interfaces should expose what an object can do, not force unrelated systems to know its implementation.
