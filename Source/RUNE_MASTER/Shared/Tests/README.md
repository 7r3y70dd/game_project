# Shared Tests

Contains automated tests for genuinely shared Rune Mater infrastructure.

## Appropriate Coverage

Examples include tests for:

- Shared value types.
- Generic deterministic utilities.
- Common serialization.
- Stable hashing helpers.
- Shared validation utilities.

## Boundaries

Spell tests belong in:

Spells/Tests/

Combat tests belong in:

Combat/Tests/

Dungeon tests belong in:

Dungeon/Tests/

Keep tests close to the subsystem whose behavior they verify.

Only cross-system primitives should normally be tested here.
