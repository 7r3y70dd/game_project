# Health

Contains health-state ownership.

The primary reusable implementation is expected to be `UHealthComponent`.

## Responsibilities

UHealthComponent should own:

- Maximum health.
- Current health.
- Damage reception.
- Healing.
- Death state.
- Invulnerability state.
- Health-change events.

## Boundaries

Health should not know:

- How a fireball travels.
- Which spell delivery method produced a hit.
- How dungeon generation works.
- How targeting selected an actor.

Health consumes approved combat results.

It should remain independent of spell and dungeon implementation details.
