# Shared

Contains small types and utilities genuinely shared across multiple Rune Mater subsystems.

## Appropriate Content

Shared may contain:

- Cross-subsystem value types.
- Small utilities.
- Logging definitions.
- Tests for shared infrastructure.

## Critical Rule

Shared must not become a miscellaneous dumping ground.

A type or utility should live here only when multiple independent subsystems legitimately require it.

Prefer placing implementation close to the subsystem that owns the concept.

## Dependency Rule

Shared code should remain low-level and avoid unnecessary dependencies on concrete gameplay systems.
