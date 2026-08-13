# Spell Impact

Contains reusable behavior describing what happens after a valid spell hit.

## Examples

Impact behavior may request:

- Direct damage.
- Radial damage.
- Healing.
- Knockback.
- Status effects.
- Projectile splitting.
- Secondary-area creation.

## Normalized Input

Impact should operate on normalized cast and hit information.

Impact code should not need to care whether the hit originally came from:

- Hitscan.
- Projectile.
- Area overlap.

unless the mechanic explicitly depends on that distinction.

## Combat Boundary

Impact decides what gameplay consequence is requested.

Combat owns authoritative application of health, damage, healing, team, and status-effect rules.

Do not bypass Combat by directly modifying arbitrary target health.
