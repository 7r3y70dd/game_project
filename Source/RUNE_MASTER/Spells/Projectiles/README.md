# Spell Projectiles

Contains spell projectile actors and projectile configuration.

The base projectile is expected to be `ASpellProjectile`.

## Base Projectile Responsibilities

- Server movement.
- Collision.
- Lifetime.
- Hit deduplication.
- Impact notification.
- Replicated presentation state.
- Destruction.

## Generic Projectile Rule

The base projectile must not contain hard-coded:

- Fire behavior.
- Frost behavior.
- Poison behavior.
- Healing behavior.
- Individual spell rules.

A projectile should receive configuration describing how it behaves.

## Authority

The server spawns authoritative gameplay projectiles.

Clients may receive replicated:

- Projectile actor.
- Transform.
- Initial velocity.
- Presentation ID.
- Cast ID.

Favor correctness before advanced projectile prediction.

## Hit Deduplication

A single-impact projectile must not damage the same target multiple times.

Projectiles capable of multiple hits must explicitly track actors they have already affected.
