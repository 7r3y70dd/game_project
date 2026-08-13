# PlayerControllers

Contains player-controller-level coordination.

## Responsibilities

Player controllers may handle:

- Player input coordination.
- Controller-owned targeting interaction.
- Requests sent from the owning client.
- Player-facing session coordination.

## Multiplayer Rule

The client provides intent.

The server determines authoritative gameplay results.

## Boundaries

Do not apply authoritative damage here.

Do not perform spell-specific gameplay directly in the controller.

Spell requests should flow into the spell-casting system, where they can be validated and executed through the normal server-authoritative pipeline.
