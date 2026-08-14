# Combat Tests

Contains automated tests for shared combat behavior.

## Priority Coverage

Test:

- Damage calculation.
- Friendly-fire validation.
- Health changes.
- Healing.
- Death state.
- Invulnerability.
- Hit deduplication.
- Invalid-actor rejection.
- Status-effect lifetime.
- Status-effect stacking when implemented.

## Hit Registration

Include functional coverage for:

- Hitscan against target.
- Hitscan blocked by wall.
- Projectile single-hit behavior.
- Area overlap deduplication.
- Team rejection.

Combat tests should exercise shared APIs rather than spell-specific shortcuts.
