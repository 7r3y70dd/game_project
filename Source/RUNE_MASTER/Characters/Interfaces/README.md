# Character Interfaces

Contains interfaces describing character capabilities.

## Design Rules

Interfaces should:

- Represent one clear capability.
- Remain small.
- Avoid assumptions about concrete character classes.
- Allow gameplay systems to communicate without unnecessary casts.

Avoid large interfaces combining unrelated systems.

Cross-system interfaces that are not specifically character-owned may belong with the subsystem they represent instead.
