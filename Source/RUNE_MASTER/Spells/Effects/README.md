# Spell Effects

Contains spell-side representation of gameplay effects produced by impact behavior.

Possible effects include:

- Damage requests.
- Healing requests.
- Status-effect application.
- Knockback.
- Persistent area effects.

## Separation

Spell effects describe what the spell intends to do.

Combat systems determine whether and how authoritative state is changed.

## Authority

Do not allow arbitrary spell content to:

- Directly set another actor's health.
- Bypass server authority.
- Send arbitrary gameplay RPCs.
- Spawn unlimited gameplay actors.
- Perform unbounded processing.

Effects should pass through approved gameplay APIs.
