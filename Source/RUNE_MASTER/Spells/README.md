# Spell System

The Rune Mater spell system converts player casting intent into validated, authoritative gameplay effects.

## Spell Lifecycle

Idle
→ Cast Requested
→ Local Precheck
→ Server Validation
→ Cast Started
→ Delivery Spawned or Executed
→ Target or Surface Hit
→ Impact Resolved
→ Effects Applied
→ Cooldown Started
→ Cast Completed

Each stage should have one narrow responsibility.

## Ownership

Spell Definition
- Describes the spell.

Casting
- Determines whether and when it may be cast.

Targeting
- Determines intended target or location.

Delivery
- Determines how the spell reaches the target.

Hit Registration
- Determines what was actually hit.

Impact
- Determines what follows from a valid hit.

Combat
- Applies authoritative damage, healing, and status changes.

## Critical Rule

Never add spell-specific branching to central casting code.

Bad:

if (SpellName == "Fireball")
{
    // Fireball behavior
}

Spell-specific behavior belongs in:

- Data assets.
- Reusable behavior classes.
- Dedicated extension classes when genuinely necessary.

## Community Goal

A typical community spell should be created by:

1. Creating a spell definition.
2. Selecting reusable casting behavior.
3. Selecting delivery behavior.
4. Selecting impact behavior.
5. Configuring numeric values.
6. Assigning presentation assets.
7. Testing the spell.

Normal spell creation should not require modifying the central casting component.
