# Spell Delivery

Delivery determines how a validated spell reaches or affects a target location.

## Initial Delivery Types

- Hitscan.
- Projectile.
- Area at location.
- Area attached to actor.

Future types may include:

- Beam.
- Chain.
- Cone.
- Returning projectile.
- Orbiting projectile.
- Trap.
- Persistent field.

## Separation

Delivery should determine movement, tracing, or overlap behavior.

Examples:

Projectile delivery
→ Spawn and initialize projectile.

Hitscan delivery
→ Perform authoritative trace.

Area delivery
→ Perform authoritative overlap.

Delivery should not normally perform final health mutation.

A delivery result should be converted into normalized hit information and passed onward for impact resolution.
