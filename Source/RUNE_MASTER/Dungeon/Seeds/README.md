# Dungeon Seeds

Contains deterministic seed handling and run identity.

## Run Identity

A dungeon run should include information such as:

- Seed.
- Generator version.
- Dungeon configuration ID.
- Room library version.
- Encounter table version.
- Game-build compatibility.

A numeric seed alone is not enough to guarantee long-term reproducibility.

## Randomness

Use `FRandomStream`.

Example:

FRandomStream RandomStream(RunConfig.Seed);

Do not use global random functions for authoritative generation.

## Derived Seeds

Different stages should use deterministic sub-seeds.

Example:

Layout Seed     = Hash(RunSeed, "Layout")
Room Seed       = Hash(RunSeed, "Rooms")
Encounter Seed  = Hash(RunSeed, "Encounters")
Loot Seed       = Hash(RunSeed, "Loot")
Decoration Seed = Hash(RunSeed, "Decoration")

## Versioning

When an algorithm change intentionally changes output compatibility, update the generator version.

Shared seed codes should include or communicate generator version information.
