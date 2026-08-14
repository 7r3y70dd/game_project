# Status Effects

Contains lightweight ongoing gameplay effects.

## Initial Examples

- Burning.
- Frozen.
- Slowed.
- Silenced.
- Stunned.
- Regenerating.

## Active Effect State

An active effect may contain:

- Effect ID.
- Source actor.
- Source spell.
- Start time.
- Duration.
- Stack count.
- Tick interval.
- Magnitude.

A reusable component such as `UStatusEffectComponent` should manage effect lifetime.

## Scope

Keep the first implementation small.

Do not introduce complex modifier aggregation until the number of interactions actually requires it.

Status effects remain server-authoritative.
