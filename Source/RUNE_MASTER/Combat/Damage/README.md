# Damage

Contains the shared authoritative damage pipeline.

## Normalized Damage Request

A damage request may contain:

- Source actor.
- Target actor.
- Source spell.
- Base damage.
- Damage type.
- Impact point.
- Server cast ID.

## Initial Damage Pipeline

Base Damage
→ Caster Modifiers
→ Target Resistance
→ Difficulty Modifier
→ Critical or Conditional Modifier
→ Final Damage
→ Health Component

Keep this pipeline intentionally small.

## Rule

Do not introduce a large generalized attribute framework until Rune Mater contains enough mechanics to justify one.

All spell damage should enter through the shared damage pipeline rather than directly modifying health.
