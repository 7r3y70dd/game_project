# RUNE_MATER Source Architecture

Rune Mater is a modular spell-casting dungeon crawler built with Unreal Engine 5 and C++.

This directory contains the primary gameplay module.

## Core Priorities

1. Casting must feel immediate and reliable.
2. Hit registration must be simple, consistent, and server-authoritative.
3. Community-created spells should primarily require data configuration rather than engine rewrites.
4. Dungeon generation must be deterministic and reproducible.
5. Gameplay systems should remain small, explicit, testable, and understandable.

## Architectural Principles

Prefer:

- Composition over deep inheritance.
- Data-driven spell definitions.
- Small components with narrow responsibilities.
- Stable interfaces between systems.
- Gameplay Tags for expandable categories.
- Enums for closed state sets.
- Server-authoritative gameplay.
- Deterministic seeded randomness.
- Incremental development over large framework rewrites.

Avoid:

- Spell-specific branching in central systems.
- Deep gameplay inheritance trees.
- Unnecessary generic frameworks.
- Authoritative gameplay implemented only in Blueprint.
- Direct dependencies between unrelated subsystems.
- Global random functions for deterministic dungeon behavior.
- Trusting client-provided gameplay results.

## Spell Runtime Flow

Player Input
→ Cast Request
→ Server Validation
→ Cast Execution
→ Delivery
→ Hit Resolution
→ Impact Resolution
→ Gameplay Effects

Each stage owns one responsibility.

## Dungeon Runtime Flow

Run Configuration
→ Seed Resolution
→ Abstract Layout Generation
→ Room Assembly
→ Encounter Placement
→ Navigation
→ Run Initialization

Spell and dungeon systems must remain independently usable.

## Multiplayer Authority

Clients may own:

- Local input.
- Camera.
- Crosshair.
- Targeting previews.
- Immediate cosmetic feedback.

The server owns:

- Spell availability.
- Cooldowns.
- Resource costs.
- Cast validation.
- Authoritative aim validation.
- Projectile spawning.
- Traces and overlaps.
- Damage.
- Healing.
- Status effects.
- Enemy state.
- Dungeon run state.

Clients may predict presentation but must not decide authoritative gameplay outcomes.

## Dependency Rule

Systems should communicate through stable interfaces, normalized data structures, components, and gameplay tags.

Do not reach into unrelated concrete classes when an interface or subsystem API is sufficient.

## Definition of Done

A gameplay feature is complete when:

- It functions in single-player.
- It functions correctly under server authority when networking is involved.
- Failure states are handled.
- Debugging information is available.
- Core behavior has automated test coverage.
- Configuration is documented.
- It does not introduce spell-specific logic into unrelated systems.
- It does not break deterministic dungeon generation.
- Networked behavior has been tested under simulated latency when relevant.

## Non-Goals

Do not prematurely introduce:

- Massive skill trees.
- Hundreds of attributes.
- MMO-scale networking.
- Runtime AI-generated dungeon geometry.
- Advanced rollback networking.
- Perfect projectile prediction.
- Complex crafting or marketplaces.
- Large gameplay frameworks without a concrete requirement.

Build the smallest reliable foundation first.
