# Shared Types

Contains small data types used across multiple independent subsystems.

## Appropriate Types

Examples may include:

- Stable value objects.
- Shared identifiers.
- Generic result structures.
- Closed enums needed by several systems.

## Rules

Types should:

- Have clear ownership and meaning.
- Avoid hidden gameplay behavior.
- Avoid dependencies on concrete actors when unnecessary.

Use:

- Gameplay Tags for expandable categories.
- Enums for closed and stable state sets.

If a type belongs primarily to one subsystem, keep it in that subsystem instead.
