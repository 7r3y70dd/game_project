# PROJECT_NAME

A modular spell-casting dungeon crawler built with **Unreal Engine 5 and C++**.

`PROJECT_NAME` is designed around three priorities:

1. **Casting must feel immediate and reliable.**
2. **Hit registration must be simple, consistent, and server-authoritative.**
3. **Community-created spells should require data configuration, not engine rewrites.**

The game combines a lightweight combat framework with deterministic, seed-based dungeon generation. The initial goal is not to build a massive RPG system. It is to create a small, understandable foundation that can be expanded without making spell logic fragile or difficult to debug.

---

## Project Status

This project is currently in the architecture and prototyping stage.

The first playable milestone will include:

* First-person or over-the-shoulder player movement
* Basic multiplayer-ready spell casting
* Hitscan, projectile, and area-of-effect spells
* Server-authoritative damage and hit validation
* Data-driven spell definitions
* Deterministic dungeon generation from a numeric or text seed
* Basic enemies and dungeon encounters
* Developer tools for testing spells and dungeon seeds

The project should remain playable throughout development. New systems should be introduced incrementally rather than through large framework rewrites.

---

## Core Design Principles

### Simple Before Flexible

A system should first be understandable, testable, and reliable.

Flexibility is valuable only when it does not obscure the main casting and damage flow. Avoid unnecessary inheritance trees, reflection-heavy abstractions, or highly generic systems before a concrete need exists.

### Data-Driven Spell Creation

A new spell should usually be created by:

1. Creating a spell definition asset
2. Selecting a casting behavior
3. Selecting an impact behavior
4. Assigning visual and audio assets
5. Configuring numeric values
6. Testing the spell in the spell sandbox

Community spell authors should not need to modify the core casting component.

### Server Authority

In multiplayer sessions:

* Clients request casts.
* The server validates casts.
* The server determines authoritative hits.
* The server applies damage and status effects.
* Clients display predicted animations and effects where appropriate.

The client may predict presentation, but it must not decide final damage.

### Deterministic Dungeon Generation

The same:

* Seed
* Generation version
* Dungeon configuration
* Room library

should generate the same dungeon layout.

This makes dungeon runs reproducible and simplifies multiplayer synchronization, debugging, automated tests, and community seed sharing.

### Composition Over Deep Inheritance

Gameplay behavior should be assembled from small components and strategy objects.

For example, a fireball is not represented by a long chain such as:

```text
Actor
└── MagicActor
    └── OffensiveMagicActor
        └── ProjectileMagicActor
            └── FireProjectileActor
                └── ExplodingFireProjectileActor
```

Instead, it should be represented by a spell definition containing:

```text
Cast Type: Projectile
Delivery: Fireball Projectile
Impact: Radial Damage
Damage Type: Fire
Status Effect: Burning
Visual Set: Fireball
```

---

## Technology

### Required

* Unreal Engine 5.x
* C++
* Unreal Build Tool
* Unreal Gameplay Tags
* Enhanced Input
* Unreal Automation Testing Framework

### Recommended

* Git
* Git LFS for large binary assets
* Visual Studio, Rider, or VS Code with Unreal support
* Blender for placeholder environment assets
* Unreal Insights for profiling
* Unreal Network Profiler for multiplayer debugging

### Optional Future Systems

* Epic Online Services
* Steam Online Subsystem
* Procedural Content Generation Framework
* Gameplay Ability System
* Mass Entity
* CommonUI

These systems should only be introduced when the project has a concrete requirement for them.

The first version of the spell system intentionally uses a smaller custom architecture instead of building directly on the Gameplay Ability System. GAS remains a possible future integration if the game develops complex attributes, effect stacking, prediction, cooldown interactions, or large-scale multiplayer requirements.

---

# High-Level Architecture

The project is divided into six primary gameplay areas:

```text
Player Input
    ↓
Spell Casting
    ↓
Cast Validation
    ↓
Spell Delivery
    ↓
Hit Resolution
    ↓
Gameplay Effects
```

Dungeon gameplay follows a separate but connected flow:

```text
Run Configuration
    ↓
Seed Resolution
    ↓
Dungeon Layout Generation
    ↓
Room Assembly
    ↓
Encounter Placement
    ↓
Run Initialization
```

The casting system should not depend directly on the dungeon generator. Both systems communicate through stable gameplay interfaces.

---

# Proposed Source Layout

```text
Source/
└── PROJECT_NAME/
    ├── PROJECT_NAME.Build.cs
    ├── PROJECT_NAME.cpp
    ├── PROJECT_NAME.h
    │
    ├── Core/
    │   ├── GameInstance/
    │   ├── GameModes/
    │   ├── GameStates/
    │   ├── PlayerControllers/
    │   └── DeveloperSettings/
    │
    ├── Characters/
    │   ├── Player/
    │   ├── Enemies/
    │   ├── Components/
    │   └── Interfaces/
    │
    ├── Spells/
    │   ├── Components/
    │   ├── Definitions/
    │   ├── Casting/
    │   ├── Delivery/
    │   ├── Impact/
    │   ├── Effects/
    │   ├── Targeting/
    │   ├── Projectiles/
    │   ├── Tags/
    │   └── Tests/
    │
    ├── Combat/
    │   ├── Damage/
    │   ├── Health/
    │   ├── Teams/
    │   ├── HitRegistration/
    │   ├── StatusEffects/
    │   └── Tests/
    │
    ├── Dungeon/
    │   ├── Generation/
    │   ├── Layout/
    │   ├── Rooms/
    │   ├── Encounters/
    │   ├── Navigation/
    │   ├── Seeds/
    │   ├── Debug/
    │   └── Tests/
    │
    ├── Interaction/
    │   ├── Interfaces/
    │   ├── Components/
    │   └── Pickups/
    │
    ├── UI/
    │   ├── HUD/
    │   ├── SpellBar/
    │   ├── Menus/
    │   └── Debug/
    │
    └── Shared/
        ├── Types/
        ├── Utilities/
        ├── Logging/
        └── Tests/
```

Content should mirror the source structure where practical:

```text
Content/
├── Core/
├── Characters/
├── Spells/
│   ├── Definitions/
│   ├── Projectiles/
│   ├── Materials/
│   ├── Niagara/
│   ├── Audio/
│   └── Community/
├── Dungeon/
│   ├── Rooms/
│   ├── Tiles/
│   ├── Encounters/
│   └── Themes/
├── UI/
└── Developer/
```

---

# Spell System

## Spell Lifecycle

Every spell follows the same high-level lifecycle:

```text
Idle
  ↓
Cast Requested
  ↓
Local Precheck
  ↓
Server Validation
  ↓
Cast Started
  ↓
Delivery Spawned or Executed
  ↓
Target or Surface Hit
  ↓
Impact Resolved
  ↓
Effects Applied
  ↓
Cooldown Started
  ↓
Cast Completed
```

Each stage should have a narrow responsibility.

A spell definition describes the spell.

The casting component manages whether the caster may use it.

The delivery object determines how it reaches a target.

The hit registration system determines what was hit.

The impact system determines what happens after a valid hit.

---

## Primary Spell Classes

### `USpellCastingComponent`

An actor component attached to characters capable of casting spells.

Responsibilities:

* Store equipped spells
* Receive cast input
* Track cast state
* Validate basic local conditions
* Send cast requests to the server
* Track cooldowns
* Track resource costs
* Start casting animations
* Execute delivery behavior
* Cancel interrupted casts
* Broadcast cast events

The casting component should not contain spell-specific branching such as:

```cpp
if (SpellName == "Fireball")
{
    // Fireball behavior
}
else if (SpellName == "IceBeam")
{
    // Ice beam behavior
}
```

Spell-specific behavior belongs in data assets or dedicated behavior classes.

---

### `USpellDefinition`

A `UPrimaryDataAsset` containing the configuration for one spell.

Example fields:

```cpp
UCLASS(BlueprintType)
class PROJECT_NAME_API USpellDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
    FName SpellId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
    FText Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")
    FGameplayTagContainer SpellTags;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Casting")
    float CastTimeSeconds = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Casting")
    float CooldownSeconds = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Casting")
    float ResourceCost = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Casting")
    float MaximumRange = 2000.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Behavior")
    TSubclassOf<class USpellCastBehavior> CastBehavior;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Behavior")
    TSubclassOf<class USpellImpactBehavior> ImpactBehavior;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Presentation")
    TObjectPtr<UNiagaraSystem> CastEffect;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Presentation")
    TObjectPtr<USoundBase> CastSound;
};
```

The final implementation may divide these properties into smaller structs.

---

## Spell Definition Structure

A spell definition should be composed from clearly separated configuration groups.

```text
Spell Definition
├── Identity
├── Tags
├── Cast Requirements
├── Resource Cost
├── Cooldown
├── Targeting
├── Delivery
├── Impact
├── Effects
├── Presentation
└── Community Metadata
```

### Identity

* Stable spell ID
* Display name
* Description
* Icon
* Author
* Version
* Compatibility version

### Tags

Gameplay tags provide searchable categories without relying on strings.

Examples:

```text
Spell.Element.Fire
Spell.Element.Frost
Spell.Element.Arcane

Spell.Cast.Instant
Spell.Cast.Channeled
Spell.Cast.Charged

Spell.Delivery.Hitscan
Spell.Delivery.Projectile
Spell.Delivery.Area

Spell.Impact.Damage
Spell.Impact.Heal
Spell.Impact.Control
```

### Cast Requirements

Possible requirements include:

* Caster is alive
* Caster is not stunned
* Caster has sufficient mana
* Spell is not on cooldown
* Required target exists
* Target is within range
* Target is on an allowed team
* Cast location is valid

### Targeting

Supported initial targeting modes:

* Camera direction
* Crosshair trace
* Actor target
* Ground location
* Self
* Radial area around caster

### Delivery

Supported initial delivery types:

* Hitscan
* Projectile
* Area at location
* Area attached to actor

Future delivery types may include:

* Beam
* Chain
* Cone
* Returning projectile
* Orbiting projectile
* Trap
* Persistent field

### Impact

An impact behavior receives a normalized hit context and determines which effects should occur.

Examples:

* Direct damage
* Radial damage
* Healing
* Knockback
* Status effect application
* Projectile split
* Secondary area creation

---

# Cast Request

A cast request represents the player’s intention to cast a spell.

```cpp
USTRUCT(BlueprintType)
struct FSpellCastRequest
{
    GENERATED_BODY()

    UPROPERTY()
    FName SpellId;

    UPROPERTY()
    FVector_NetQuantize AimOrigin;

    UPROPERTY()
    FVector_NetQuantizeNormal AimDirection;

    UPROPERTY()
    FVector_NetQuantize TargetLocation;

    UPROPERTY()
    TObjectPtr<AActor> RequestedTarget = nullptr;

    UPROPERTY()
    int32 ClientCastSequence = 0;
};
```

The request contains intent, not authority.

The client may report:

* Which equipped spell was requested
* Approximate aim origin
* Aim direction
* Target location
* Selected actor
* Local cast sequence number

The server independently verifies:

* The spell is equipped
* The caster can currently cast
* The caster has sufficient resources
* The spell is not on cooldown
* Aim values are reasonable
* The requested target is valid
* The target is within legal range
* The cast does not violate rate limits

---

# Cast Context

Once validated, the server creates a cast context.

```cpp
USTRUCT(BlueprintType)
struct FSpellCastContext
{
    GENERATED_BODY()

    UPROPERTY()
    TObjectPtr<AActor> Caster = nullptr;

    UPROPERTY()
    TObjectPtr<AController> InstigatorController = nullptr;

    UPROPERTY()
    TObjectPtr<const USpellDefinition> Spell = nullptr;

    UPROPERTY()
    FVector CastOrigin = FVector::ZeroVector;

    UPROPERTY()
    FVector AimDirection = FVector::ForwardVector;

    UPROPERTY()
    FVector TargetLocation = FVector::ZeroVector;

    UPROPERTY()
    int32 ServerCastId = 0;

    UPROPERTY()
    int32 DungeonRunSeed = 0;
};
```

The cast context is passed through delivery, hit registration, and impact resolution.

This creates a traceable chain from:

```text
Player input → cast → hit → effect
```

Every debug log related to a cast should include the server cast ID.

---

# Cast Behaviors

Cast behaviors represent reusable ways to execute a spell.

Initial behaviors:

```text
USpellCastBehavior
├── UInstantHitscanCastBehavior
├── UProjectileCastBehavior
├── UAreaCastBehavior
└── USelfCastBehavior
```

A behavior should not directly modify health unless direct modification is fundamental to that behavior.

For example:

* Projectile behavior spawns a projectile.
* Hitscan behavior performs a trace.
* Area behavior performs an overlap.
* Impact behavior applies damage or effects.

This separation allows the same projectile delivery to be reused for:

* Fireballs
* Ice bolts
* Healing orbs
* Knockback spheres
* Poison projectiles

---

# Hit Registration

Hit registration should have one shared result format regardless of delivery type.

## Supported Hit Types

### Hitscan

A server-side line trace or shape trace.

Best suited for:

* Arcane bolts
* Lightning
* Wands
* Instant beams
* Precision spells

### Projectile

A replicated or server-simulated actor with collision.

Best suited for:

* Fireballs
* Ice shards
* Magic missiles
* Throwable spell objects

### Area

A server-side overlap query at a location.

Best suited for:

* Explosions
* Ground effects
* Healing circles
* Frost fields

---

## Normalized Hit Result

```cpp
USTRUCT(BlueprintType)
struct FSpellHitResult
{
    GENERATED_BODY()

    UPROPERTY()
    bool bBlockingHit = false;

    UPROPERTY()
    TObjectPtr<AActor> HitActor = nullptr;

    UPROPERTY()
    TObjectPtr<UPrimitiveComponent> HitComponent = nullptr;

    UPROPERTY()
    FVector_NetQuantize ImpactPoint;

    UPROPERTY()
    FVector_NetQuantizeNormal ImpactNormal;

    UPROPERTY()
    float Distance = 0.0f;

    UPROPERTY()
    FName BoneName;

    UPROPERTY()
    TEnumAsByte<EPhysicalSurface> SurfaceType;

    UPROPERTY()
    int32 ServerCastId = 0;
};
```

All delivery implementations convert their result into `FSpellHitResult`.

Impact behaviors should not need to know whether the result originated from a projectile, hitscan trace, or overlap.

---

## Hit Registration Rules

The following rules should remain consistent:

1. Damage is only applied by the server.
2. Each cast has a unique server cast ID.
3. A projectile tracks which actors it has already affected.
4. A single-impact projectile cannot damage the same target more than once.
5. Area effects deduplicate overlap results.
6. Dead or invalid actors are ignored.
7. Friendly-fire rules are checked before effects are applied.
8. World geometry impacts are distinguished from actor impacts.
9. Presentation effects do not determine gameplay results.
10. Every rejected hit can be logged in a debug build.

---

## Collision Channels

Use dedicated project collision channels rather than overloading generic visibility traces.

Proposed channels:

```text
SpellTrace
SpellProjectile
SpellTarget
DungeonGeometry
Interactable
```

Example behavior:

* `SpellTrace` blocks against valid world geometry and targetable actors.
* `SpellProjectile` blocks against world geometry and targetable actors.
* Decorative particles ignore all gameplay collision.
* Trigger volumes do not block spell traces unless explicitly configured.
* The caster is ignored for an initial projectile grace period or until the projectile clears the caster capsule.

Collision behavior should be documented in the Unreal project settings and tested with automated maps.

---

# Damage and Gameplay Effects

## Damage Request

Damage should be applied through one shared combat service or component.

```cpp
USTRUCT(BlueprintType)
struct FSpellDamageRequest
{
    GENERATED_BODY()

    UPROPERTY()
    TObjectPtr<AActor> SourceActor = nullptr;

    UPROPERTY()
    TObjectPtr<AActor> TargetActor = nullptr;

    UPROPERTY()
    TObjectPtr<const USpellDefinition> Spell = nullptr;

    UPROPERTY()
    float BaseDamage = 0.0f;

    UPROPERTY()
    FGameplayTag DamageType;

    UPROPERTY()
    FVector ImpactPoint = FVector::ZeroVector;

    UPROPERTY()
    int32 ServerCastId = 0;
};
```

The damage pipeline should be:

```text
Base Damage
  ↓
Caster Modifiers
  ↓
Target Resistance
  ↓
Difficulty Modifier
  ↓
Critical or Conditional Modifier
  ↓
Final Damage
  ↓
Health Component
```

The initial implementation should keep this pipeline small.

Avoid adding a large attribute framework until the game has enough mechanics to justify it.

---

## Health Component

`UHealthComponent` should own:

* Maximum health
* Current health
* Damage reception
* Healing
* Death state
* Invulnerability state
* Health change events

The health component should not know how a fireball travels or how a dungeon was generated.

---

## Status Effects

Initial status effects can use lightweight definitions.

Examples:

* Burning
* Frozen
* Slowed
* Silenced
* Stunned
* Regenerating

Each active effect should contain:

* Effect ID
* Source actor
* Source spell
* Start time
* Duration
* Stack count
* Tick interval
* Magnitude

A target component such as `UStatusEffectComponent` should manage effect lifetimes.

Complex modifier aggregation can be introduced later if the number of interactions grows substantially.

---

# Projectile Architecture

## `ASpellProjectile`

The base projectile actor is responsible for:

* Server movement
* Collision
* Lifetime
* Hit deduplication
* Impact notification
* Replicated presentation state
* Destruction

It should not contain hard-coded fire, frost, poison, or healing behavior.

The projectile receives:

* Cast context
* Projectile configuration
* Impact behavior
* Visual configuration

Example initialization:

```cpp
FSpellProjectileInitData InitData;
InitData.CastContext = CastContext;
InitData.Speed = 2400.0f;
InitData.MaximumLifetime = 5.0f;
InitData.ImpactBehavior = Spell->ImpactBehavior;
```

---

## Projectile Replication

The server should spawn authoritative gameplay projectiles.

Clients may receive:

* Replicated projectile actor
* Initial transform
* Initial velocity
* Spell presentation ID
* Cast ID

The initial version should favor correctness over advanced client projectile prediction.

Prediction can be added after the authoritative path is stable and measurable.

---

# Multiplayer Model

The architecture should remain multiplayer-safe even if the earliest prototypes are tested in single-player.

## Casting Flow

```text
Owning Client
    |
    | Local input and optional cosmetic prediction
    v
Server RPC: RequestCast
    |
    | Validate spell, state, aim, cost, cooldown
    v
Server Executes Cast
    |
    ├── Apply authoritative resource cost
    ├── Start authoritative cooldown
    ├── Spawn projectile or execute trace
    └── Multicast or replicate presentation state
```

## Ownership Rules

### Client Owns

* Local input
* Crosshair
* Camera
* Immediate cosmetic feedback
* Local targeting preview

### Server Owns

* Spell availability
* Cooldowns
* Resource costs
* Authoritative aim validation
* Projectile spawning
* Traces
* Overlaps
* Damage
* Healing
* Status effects
* Enemy state
* Dungeon run state

### Replicated State

* Equipped spells
* Active cooldowns
* Health
* Status effects
* Projectiles
* Cast animations
* Dungeon seed
* Dungeon generation version
* Encounter state

---

## RPC Guidelines

RPCs should represent meaningful requests.

Good:

```cpp
ServerRequestCast(FSpellCastRequest Request);
ServerCancelCast(int32 CastSequence);
```

Avoid sending an RPC for every visual or internal calculation step.

Never accept a client RPC such as:

```cpp
ServerApplyDamage(Target, 5000.0f);
```

---

# Community Spell Creation

## Goals

A community spell author should be able to create a spell without changing:

* The player character class
* The central casting component
* The health component
* The dungeon generator
* Network authority rules

A typical community spell should be implemented through a data asset and existing behaviors.

---

## Spell Creation Levels

### Level 1: Data-Only Spell

Uses existing cast and impact behaviors.

Example:

```text
Name: Ember Bolt
Cast Type: Projectile
Projectile Speed: 2200
Damage: 20
Element: Fire
Cooldown: 0.8
Impact Effect: Small Fire Burst
```

No C++ required.

### Level 2: Blueprint Behavior

Uses a safe Blueprint-derived behavior class.

Appropriate for:

* Custom visual sequences
* Simple conditional effects
* Alternate projectile paths
* Additional impact presentation

Blueprint behavior should call approved gameplay APIs rather than modify health directly.

### Level 3: C++ Extension

Used for genuinely new mechanics.

Examples:

* Chain targeting algorithm
* Time-rewinding projectile
* Portal-linked spell
* New deterministic target selection method

C++ extensions must use the same cast, validation, hit, and effect interfaces as built-in spells.

---

## Community Content Boundaries

Community spell content should not be allowed to:

* Execute arbitrary external programs
* Access unrestricted files
* Bypass server authority
* Directly set another actor’s health
* Spawn unlimited actors
* Perform unbounded loops
* Send arbitrary RPCs
* Load unsupported native modules in normal sessions

Future mod support may require:

* Approved plugin packaging rules
* Mod manifests
* Dependency declarations
* Version compatibility checks
* Server allowlists
* Asset validation
* Resource budgets
* Signed packages for public servers

---

## Spell Manifest

Each community spell should include metadata similar to:

```json
{
  "spell_id": "community.author.ember_bolt",
  "display_name": "Ember Bolt",
  "author": "CommunityAuthor",
  "version": "1.0.0",
  "spell_api_version": 1,
  "description": "Launches a fast projectile that deals light fire damage.",
  "tags": [
    "Spell.Element.Fire",
    "Spell.Delivery.Projectile",
    "Spell.Impact.Damage"
  ]
}
```

The Unreal Data Asset remains the authoritative in-engine definition. A JSON manifest can be used for discovery, packaging, validation, and external tools.

---

# Dungeon Generation

## Goals

The dungeon generator should produce:

* Reproducible layouts
* Valid connected paths
* A guaranteed entrance
* A guaranteed objective or exit
* Configurable room counts
* Encounter placement
* Loot placement
* Optional branches
* Theme variation

The first generator should favor reliable room assembly over highly organic geometry.

---

## Recommended Initial Model

Use a graph-first room generator.

```text
Seed
  ↓
Generate Abstract Room Graph
  ↓
Choose Entrance and Exit
  ↓
Assign Room Types
  ↓
Place Rooms on Grid
  ↓
Connect Doors and Corridors
  ↓
Validate Connectivity
  ↓
Populate Encounters
  ↓
Build Navigation
```

The abstract graph determines gameplay structure before physical room actors are spawned.

This makes it easier to guarantee that the dungeon is completable.

---

## Dungeon Seed

A dungeon run should be identified by:

```cpp
USTRUCT(BlueprintType)
struct FDungeonRunConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Seed = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 GeneratorVersion = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TargetRoomCount = 12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag DungeonTheme;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Difficulty = 1.0f;
};
```

Use `FRandomStream` instead of global random functions.

```cpp
FRandomStream RandomStream(RunConfig.Seed);

const int32 RoomIndex = RandomStream.RandRange(0, CandidateRooms.Num() - 1);
```

Every generation subsystem should receive a deterministic stream or a derived sub-seed.

---

## Derived Seeds

Different generation stages should use derived seeds so changes in one stage do not unnecessarily change every later result.

Example:

```text
Run Seed: 123456

Layout Seed:       Hash(123456, "Layout")
Room Seed:         Hash(123456, "Rooms")
Encounter Seed:    Hash(123456, "Encounters")
Loot Seed:         Hash(123456, "Loot")
Decoration Seed:   Hash(123456, "Decoration")
```

This allows encounter balancing to change without always changing the physical dungeon layout.

---

## Generation Versioning

Determinism requires more than saving the numeric seed.

A complete shared run identity should include:

```text
Seed
Generator Version
Dungeon Configuration ID
Room Library Version
Encounter Table Version
Game Build Compatibility
```

A seed generated under version 1 may produce a different dungeon under version 2.

Shared seed codes should therefore encode or display the generator version.

Example:

```text
V1-CRYSTAL-7F32A9
```

---

## Dungeon Graph

The dungeon graph contains nodes and edges.

### Node

Represents a room.

```cpp
USTRUCT()
struct FDungeonRoomNode
{
    GENERATED_BODY()

    int32 NodeId = INDEX_NONE;
    FGameplayTag RoomType;
    FIntPoint GridPosition = FIntPoint::ZeroValue;
    TArray<int32> ConnectedNodeIds;
    int32 DistanceFromEntrance = 0;
};
```

### Edge

Represents a connection.

```cpp
USTRUCT()
struct FDungeonConnection
{
    GENERATED_BODY()

    int32 FromNodeId = INDEX_NONE;
    int32 ToNodeId = INDEX_NONE;
    FGameplayTag ConnectionType;
};
```

---

## Initial Room Types

```text
Dungeon.Room.Entrance
Dungeon.Room.Combat
Dungeon.Room.Elite
Dungeon.Room.Treasure
Dungeon.Room.Event
Dungeon.Room.Rest
Dungeon.Room.Shop
Dungeon.Room.Boss
Dungeon.Room.Exit
```

Initial generation rules may include:

* Exactly one entrance
* Exactly one exit or boss room
* At least one combat room
* No boss room directly connected to the entrance
* Treasure rooms are optional branches
* Rest rooms appear only after a minimum path distance
* Elite rooms require sufficient dungeon depth

---

## Room Assets

Each room module should define:

* Room bounds
* Door sockets
* Allowed rotations
* Room tags
* Weight
* Minimum depth
* Maximum depth
* Supported themes
* Encounter sockets
* Loot sockets
* Navigation validation data

Room geometry should use standardized dimensions to simplify deterministic assembly.

---

## Generation Validation

After layout generation, validate:

* Entrance exists
* Exit exists
* Exit is reachable
* All required rooms are reachable
* No illegal room overlaps exist
* Door connections align
* Critical path meets minimum length
* Room count is within allowed bounds
* Encounter budget is valid
* Navigation can be generated or loaded

If validation fails, the generator may retry using a deterministic retry seed.

```text
Retry Seed = Hash(Base Seed, Retry Index)
```

The retry count must be capped.

---

# AI-Assisted Dungeon Development

AI should not initially generate authoritative dungeon geometry during a live run.

Live generative AI introduces:

* Non-deterministic output
* Network synchronization problems
* Latency
* External service dependencies
* Moderation concerns
* Difficult automated testing
* Unbounded or invalid geometry
* Ongoing inference costs

The core runtime dungeon should be generated through deterministic algorithms.

AI can still be useful as an offline development tool.

Potential uses include:

* Suggesting room graph templates
* Generating encounter descriptions
* Proposing spell concepts
* Producing placeholder lore
* Classifying community spell metadata
* Suggesting room tags
* Generating test seeds
* Analyzing failed dungeon layouts
* Creating draft balancing configurations
* Converting natural-language spell ideas into validated draft manifests

Any AI-generated output should pass through validation before entering the game.

The recommended pipeline is:

```text
AI Suggestion
  ↓
Structured Draft
  ↓
Schema Validation
  ↓
Developer Review
  ↓
Automated Gameplay Validation
  ↓
Approved Content Asset
```

AI output should never bypass the deterministic generator or combat authority system.

---

# Enemy Architecture

Enemies should use the same combat interfaces as players where practical.

Core components:

```text
Enemy Character
├── Health Component
├── Status Effect Component
├── Team Component
├── Targeting Component
├── Combat Component
└── AI Controller
```

Enemies should receive spell damage through the same effect pipeline used for player damage.

Enemy behavior should not depend on a specific spell class.

An enemy may instead react to gameplay tags:

```text
Damage.Fire
Damage.Frost
Effect.Stun
Effect.Knockback
```

---

# Interfaces

Recommended initial interfaces:

## `ISpellTargetInterface`

Indicates that an actor may be targeted by spells.

Responsibilities:

* Return target location
* Return target team
* Report target validity
* Report targetable components

## `IDamageableInterface`

Receives normalized damage requests.

## `ITeamAgentInterface`

Reports team identity and friendly-fire relationship.

## `IInteractableInterface`

Supports doors, chests, shrines, and dungeon objects.

Avoid large interfaces containing unrelated gameplay responsibilities.

---

# Debugging Tools

Reliable combat requires strong visualization and logging tools.

## Spell Debug Overlay

Display:

* Equipped spell
* Cast state
* Cooldown
* Resource cost
* Current target
* Aim origin
* Aim direction
* Server cast ID
* Last hit actor
* Last hit rejection reason
* Network role

## Hit Debug Drawing

Optional debug drawing should show:

* Cast origin
* Hitscan trace
* Projectile path
* Impact point
* Impact normal
* Area radius
* Accepted targets
* Rejected targets

## Dungeon Debug Overlay

Display:

* Seed
* Generator version
* Room count
* Critical path
* Room IDs
* Room types
* Encounter budgets
* Validation status
* Retry index

## Logging Categories

```cpp
DECLARE_LOG_CATEGORY_EXTERN(LogSpellCasting, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogSpellHitRegistration, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogSpellEffects, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogDungeonGeneration, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogDungeonValidation, Log, All);
```

Production builds should reduce or disable verbose debug logging.

---

# Testing Strategy

## Unit Tests

Test deterministic and isolated logic.

Examples:

* Cooldown validation
* Resource-cost validation
* Friendly-fire validation
* Damage calculation
* Gameplay tag filtering
* Seed parsing
* Derived-seed calculation
* Dungeon graph connectivity
* Room selection constraints
* Encounter budget calculations

## Functional Tests

Use Unreal functional test maps.

Examples:

* Hitscan spell hits target
* Hitscan spell stops at wall
* Projectile damages target once
* Projectile ignores caster
* Explosion deduplicates actors
* Friendly target is rejected
* Cooldown prevents repeated cast
* Server rejects invalid range
* Same seed creates same dungeon
* Dungeon exit is reachable

## Multiplayer Tests

At minimum, test:

* Listen server with one client
* Dedicated server with two clients
* Simulated latency
* Packet loss
* Rapid cast input
* Client disconnect during cast
* Projectile impact during lag
* Late-joining client
* Dungeon seed synchronization

## Determinism Tests

Given a fixed generation version and content set:

```text
Seed 1001 → Expected graph hash A
Seed 1002 → Expected graph hash B
Seed 1003 → Expected graph hash C
```

Tests should compare a stable serialized graph representation or graph hash rather than rendered actor pointers.

---

# Performance Targets

Initial target budgets should remain conservative.

## Spell System

* No unbounded traces
* No per-frame allocation for idle spells
* No spell actor ticking unless required
* Projectiles use capped lifetimes
* Area effects use controlled tick intervals
* Duplicate target checks use sets or compact arrays
* Cosmetic effects are pooled when beneficial

## Dungeon System

* Generation runs in defined stages
* Expensive validation is measurable
* Room actor spawning is separated from graph generation
* Decoration does not change gameplay topology
* Generation can eventually move heavy non-UObject calculations off the game thread
* Actor spawning remains on the game thread

Performance optimization should be driven by profiling rather than speculation.

---

# Coding Standards

## General

* Prefer explicit names over abbreviations.
* Keep classes focused on one responsibility.
* Avoid casting to concrete player or enemy classes when an interface is sufficient.
* Validate pointers before use.
* Use gameplay tags for expandable categories.
* Use enums for closed, stable state sets.
* Use data assets for designer and community configuration.
* Keep authoritative gameplay logic in C++.
* Use Blueprint primarily for content composition and presentation.
* Document network ownership for replicated functions and properties.

## Naming

Follow Unreal conventions:

```text
A  Actor
U  UObject
F  Struct
E  Enum
I  Interface
T  Template
b  Boolean
```

Examples:

```text
ASpellProjectile
USpellCastingComponent
FSpellCastContext
ESpellCastState
ISpellTargetInterface
bIsCasting
```

## Blueprint Exposure

Do not expose every field to Blueprint by default.

Use:

* `BlueprintReadOnly` for data that Blueprint should inspect
* `BlueprintCallable` for safe operations
* `BlueprintImplementableEvent` for presentation extension points
* `BlueprintNativeEvent` when a safe C++ default exists

Avoid exposing unrestricted setters for health, authority state, or validated spell state.

---

# Error Handling

Gameplay failures should return structured reasons.

```cpp
UENUM(BlueprintType)
enum class ESpellCastFailureReason : uint8
{
    None,
    InvalidSpell,
    NotEquipped,
    OnCooldown,
    InsufficientResource,
    InvalidTarget,
    OutOfRange,
    CasterDisabled,
    ServerRejected
};
```

Structured failure reasons support:

* UI messages
* Debug logs
* Automated tests
* Analytics
* Community spell validation

Do not rely on parsing log strings to understand gameplay failures.

---

# Save and Run Data

A dungeon run save should include:

```text
Run ID
Seed
Generator Version
Dungeon Configuration ID
Current Room
Visited Rooms
Opened Chests
Defeated Encounters
Player Health
Player Resources
Equipped Spells
Active Modifiers
Elapsed Run Time
```

Avoid saving raw actor pointers or full generated actor state when the state can be reconstructed deterministically.

---

# Initial Development Milestones

## Milestone 1: Casting Sandbox

* Player movement
* Camera aiming
* Spell casting component
* One hitscan spell
* One projectile spell
* One area spell
* Health component
* Damage pipeline
* Spell debug overlay

## Milestone 2: Multiplayer Validation

* Server-authoritative cast requests
* Replicated projectiles
* Server-side hitscan
* Cooldown replication
* Resource replication
* Lag testing
* Hit deduplication

## Milestone 3: Data-Driven Spells

* Spell data assets
* Gameplay tags
* Reusable cast behaviors
* Reusable impact behaviors
* Spell manifest format
* Community spell folder
* Spell validation commandlet or editor utility

## Milestone 4: Dungeon Graph

* Seed handling
* Abstract room graph
* Entrance and exit generation
* Connectivity validation
* Debug graph rendering
* Stable graph hashing

## Milestone 5: Physical Dungeon Assembly

* Modular room actors
* Door alignment
* Room placement
* Corridor placement
* Navigation
* Spawn points
* Dungeon debug overlay

## Milestone 6: Encounters

* Basic enemy
* Enemy targeting
* Combat rooms
* Encounter completion
* Loot placement
* Run completion

## Milestone 7: Community Tooling

* Spell template assets
* Example spells
* Validation rules
* Documentation
* Packaging workflow
* Compatibility metadata
* In-game spell browser

---

# Example First Spells

## Arcane Dart

```text
Delivery: Hitscan
Impact: Direct Damage
Damage: 12
Range: 2500
Cooldown: 0.25 seconds
Purpose: Validate rapid and accurate hit registration
```

## Fireball

```text
Delivery: Projectile
Impact: Radial Damage
Direct Damage: 20
Explosion Damage: 15
Projectile Speed: 1800
Cooldown: 1.5 seconds
Purpose: Validate projectile replication and radial deduplication
```

## Frost Field

```text
Delivery: Area at Target Location
Impact: Persistent Area
Duration: 5 seconds
Tick Interval: 0.5 seconds
Effect: Slow
Cooldown: 6 seconds
Purpose: Validate persistent areas and status effects
```

## Healing Orb

```text
Delivery: Projectile
Impact: Direct Healing
Healing: 20
Friendly Targets Only: true
Purpose: Confirm that delivery and impact logic are not damage-specific
```

---

# Example Cast Flow: Fireball

```text
1. Player presses the fireball input.
2. The local casting component verifies basic availability.
3. The client plays an immediate cast-start animation.
4. The client sends a cast request to the server.
5. The server confirms that the fireball is equipped.
6. The server confirms that mana and cooldown requirements are valid.
7. The server calculates the authoritative cast origin.
8. The server spawns the fireball projectile.
9. The projectile replicates to relevant clients.
10. The server projectile collides with a wall or target.
11. Collision is converted into a normalized spell hit result.
12. The radial impact behavior performs a server overlap.
13. Invalid and duplicate targets are removed.
14. Damage requests are sent to valid targets.
15. Health components apply final damage.
16. The server replicates changed health state.
17. Clients play impact presentation.
18. The projectile is destroyed.
```

---

# Non-Goals for the First Version

The initial project does not need:

* A massive skill tree
* Hundreds of attributes
* Fully dynamic destructible environments
* AI-generated runtime geometry
* MMO-scale networking
* Complex crafting
* A marketplace
* Fully user-authored native code loading
* Advanced rollback networking
* Perfect projectile prediction
* Procedural generation without authored room modules

These features may be explored after the core casting and dungeon systems are stable.

---

# Contribution Guidelines

Contributions should preserve the following boundaries:

1. A spell must not bypass server cast validation.
2. Damage must use the shared combat pipeline.
3. Delivery and impact logic should remain separable.
4. New spell types should reuse existing behavior where possible.
5. Dungeon randomness must use seeded streams.
6. Generator changes must update the generator version when output compatibility changes.
7. New gameplay behavior should include tests.
8. Community-facing APIs should remain documented.
9. Blueprint assets should not duplicate authoritative C++ logic.
10. Large dependencies require a clear architectural justification.

Before submitting a change:

```text
- Build the editor target
- Run unit tests
- Run functional spell tests
- Generate known dungeon test seeds
- Test one multiplayer session
- Verify no new warnings appear in logs
```

---

# Definition of Done

A gameplay feature is complete when:

* It functions in single-player
* It functions under server authority
* Failure states are handled
* Debugging information is available
* Automated tests cover core behavior
* Configuration is documented
* It does not introduce spell-specific logic into unrelated systems
* It does not break deterministic dungeon generation
* It has been tested with simulated network latency when networking is involved

---

# Long-Term Direction

The long-term objective is a dungeon crawler in which players and community creators can build a broad spell library from a small number of reliable primitives.

The desired architecture is:

```text
Small Core
+ Stable Interfaces
+ Data-Driven Definitions
+ Reusable Behaviors
+ Deterministic Generation
= Expandable Community Game
```

The project should grow by adding new combinations and isolated behaviors, not by repeatedly rewriting the central casting and hit-registration systems.

---

# License

License information has not yet been selected.

Before accepting outside contributions, choose and document:

* Source code license
* Asset license
* Community spell license
* Third-party content policy
* Contributor agreement requirements

---

# Acknowledgements

This project is built with Unreal Engine.

Third-party libraries, plugins, assets, and community contributions should be listed here with their respective licenses.
