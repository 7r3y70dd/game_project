# Enemies

Contains enemy character implementations.

## Design Principle

Enemies should use the same combat interfaces as players wherever practical.

An enemy may compose systems such as:

- Health Component.
- Status Effect Component.
- Team Component.
- Targeting Component.
- Combat Component.
- AI Controller.

## Spell Independence

Enemy behavior should not depend on individual spell classes.

Prefer reactions to generalized information such as:

Damage.Fire
Damage.Frost
Effect.Stun
Effect.Knockback

rather than:

Fireball
IceBolt
SpecificSpellClass

## Damage

Enemy damage must pass through the shared combat pipeline.

Do not create enemy-specific bypasses around normal damage, status-effect, or team validation.
