# Spell Tags

Contains Gameplay Tags used to classify spell behavior and metadata.

Use Gameplay Tags for expandable categories rather than string comparisons.

## Example Spell Tags

Spell.Element.Fire
Spell.Element.Frost
Spell.Element.Arcane

Spell.Cast.Instant
Spell.Cast.Channeled
Spell.Cast.Charged

Spell.Delivery.Hitscan
Spell.Delivery.Projectile
Spell.Delivery.Area

Spell.Impact.Damage
Spell.Impact.Heal
Spell.Impact.Control

## Rule

Tags describe categories and capabilities.

Do not use tags as a substitute for authoritative gameplay validation.

Avoid introducing raw string comparisons when an established Gameplay Tag category already exists.
