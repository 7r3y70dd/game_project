# Combat

Combat owns authoritative gameplay-state changes resulting from valid hits and effects.

## Subsystems

Combat includes:

- Damage.
- Health.
- Teams.
- Hit Registration.
- Status Effects.

## Core Flow

Spell Delivery
→ Hit Registration
→ Impact
→ Damage / Healing / Status Request
→ Combat Validation
→ Health or Effect State

## Critical Rules

- Damage is applied only by the server.
- Players and enemies should use the same combat pipeline where practical.
- Friendly-fire rules must be evaluated consistently.
- Spell delivery must not directly own health mutation.
- Presentation effects must never determine gameplay results.

Combat APIs should remain reusable by both built-in and community-created spells.
