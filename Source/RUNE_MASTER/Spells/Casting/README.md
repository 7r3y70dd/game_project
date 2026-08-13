# Spell Casting

Contains cast requests, validation, cast state, authoritative cast contexts, and reusable casting behavior.

## Client Flow

The owning client may:

- Receive local input.
- Perform basic local prechecks.
- Display immediate cosmetic feedback.
- Construct a cast request.
- Send cast intent to the server.

A client cast request contains intent, not authority.

## Server Validation

The server independently verifies:

- Spell is equipped.
- Caster may currently cast.
- Resources are sufficient.
- Spell is not on cooldown.
- Aim values are reasonable.
- Requested target is valid.
- Target is within legal range.
- Cast does not violate rate limits.

## Cast Context

After validation, create an authoritative cast context.

It may contain:

- Caster.
- Instigator controller.
- Spell definition.
- Cast origin.
- Aim direction.
- Target location.
- Server cast ID.
- Dungeon run seed.

## Traceability

The server cast ID should follow the action through:

Cast
→ Delivery
→ Hit Registration
→ Impact
→ Effects

Debug logs related to a cast should include this ID.

## Failure Handling

Use structured failure reasons.

Do not require UI, tests, or analytics to parse log strings to determine why a cast failed.
