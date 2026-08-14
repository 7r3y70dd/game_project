# Hit Registration

Contains authoritative determination of what a spell actually hit.

## Supported Hit Sources

Initial hit sources include:

- Hitscan traces.
- Projectile collision.
- Area overlaps.

All delivery types should produce the same normalized hit representation.

## Normalized Hit Information

A hit may contain:

- Blocking-hit state.
- Hit actor.
- Hit component.
- Impact point.
- Impact normal.
- Distance.
- Bone name.
- Physical surface.
- Server cast ID.

## Invariants

1. Damage is only applied by the server.
2. Every cast has a unique server cast ID.
3. Projectiles track already-affected actors when necessary.
4. Single-impact projectiles cannot damage one target twice.
5. Area effects deduplicate overlap results.
6. Dead or invalid actors are ignored.
7. Friendly-fire rules are checked.
8. World impacts are distinguishable from actor impacts.
9. Presentation does not determine gameplay.
10. Rejected hits should be debuggable.

## Collision

Prefer dedicated collision channels such as:

SpellTrace
SpellProjectile
SpellTarget
DungeonGeometry
Interactable

Do not overload generic visibility collision for core spell gameplay without a deliberate reason.
