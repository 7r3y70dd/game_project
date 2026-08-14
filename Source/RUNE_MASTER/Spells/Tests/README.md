# Spell Tests

Contains automated tests for the Rune Mater spell system.

## Unit-Level Coverage

Test isolated behavior such as:

- Cooldown validation.
- Resource-cost validation.
- Gameplay Tag filtering.
- Cast failure reasons.
- Target validation.

## Functional Coverage

Test behaviors such as:

- Hitscan spell hits target.
- Hitscan stops at world geometry.
- Projectile damages target once.
- Projectile ignores caster when required.
- Area spell deduplicates actors.
- Friendly target is rejected.
- Cooldown prevents repeated casting.
- Server rejects illegal range.

## Multiplayer Coverage

Include:

- Listen-server testing.
- Dedicated-server testing.
- Simulated latency.
- Packet loss.
- Rapid cast input.
- Disconnect during cast.
- Projectile impact during lag.

Tests should verify gameplay outcomes rather than cosmetic presentation.
