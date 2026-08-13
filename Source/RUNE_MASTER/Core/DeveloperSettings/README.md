# DeveloperSettings

Contains centralized project-level developer configuration.

Use Unreal Developer Settings for configuration that is genuinely global to the project.

## Appropriate Uses

Settings should be:

- Explicit.
- Inspectable.
- Project-wide.
- Stable enough to justify centralized configuration.

## Boundaries

Do not move subsystem-owned content here merely to make it globally accessible.

Individual spell configuration belongs in spell definitions.

Dungeon room configuration belongs in dungeon data.

Subsystem-specific tuning should remain close to the subsystem that owns it.
