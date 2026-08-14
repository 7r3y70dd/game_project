# Dungeon Rooms

Contains room definitions and modular physical room implementations.

## Room Metadata

A room module may define:

- Room bounds.
- Door sockets.
- Allowed rotations.
- Room tags.
- Selection weight.
- Minimum depth.
- Maximum depth.
- Supported themes.
- Encounter sockets.
- Loot sockets.
- Navigation validation data.

## Initial Room Types

Examples include:

Dungeon.Room.Entrance
Dungeon.Room.Combat
Dungeon.Room.Elite
Dungeon.Room.Treasure
Dungeon.Room.Event
Dungeon.Room.Rest
Dungeon.Room.Shop
Dungeon.Room.Boss
Dungeon.Room.Exit

## Assembly Rule

Room geometry should use standardized dimensions where practical to simplify deterministic assembly.

Physical room assets should represent graph decisions rather than secretly changing dungeon topology.
