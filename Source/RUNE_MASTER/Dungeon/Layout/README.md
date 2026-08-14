# Dungeon Layout

Contains abstract dungeon topology and structural layout data.

## Graph Model

The dungeon graph consists of:

- Room nodes.
- Connections between nodes.

A room node may contain:

- Node ID.
- Room type.
- Grid position.
- Connected node IDs.
- Distance from entrance.

A connection may contain:

- Source node.
- Destination node.
- Connection type.

## Rule

Layout describes dungeon gameplay structure independently of spawned room actors.

Do not make graph generation depend on transient Actor pointers.

Stable layout data should be serializable or hashable for determinism testing.
