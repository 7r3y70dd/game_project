# Spell Targeting

Contains reusable target acquisition and targeting logic.

## Initial Targeting Modes

- Camera direction.
- Crosshair trace.
- Actor target.
- Ground location.
- Self.
- Radial area around caster.

## Client vs Server

Clients may display targeting previews and provide requested targets or locations.

Those values remain requests.

The server must independently validate:

- Target validity.
- Range.
- Team restrictions.
- Cast location.
- Aim reasonableness.
- Caster state.

## Rule

Targeting determines candidate intent.

It does not grant authority to apply gameplay effects.
