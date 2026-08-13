# Spell Components

Contains reusable ActorComponents used by spell-capable actors.

The primary component is expected to be `USpellCastingComponent`.

## USpellCastingComponent Responsibilities

It may own:

- Equipped spells.
- Cast input handling.
- Cast state.
- Basic local validation.
- Server cast requests.
- Cooldown tracking.
- Resource-cost tracking.
- Cast animation initiation.
- Delivery execution.
- Cast interruption and cancellation.
- Cast events.

## Critical Boundary

The casting component must remain generic.

Do not add branches such as:

if (SpellId == Fireball)
if (SpellId == FrostField)

Individual spell behavior belongs in spell definitions or reusable behavior classes.
