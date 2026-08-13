# Spell Definitions

Contains data-driven definitions describing individual spells.

The primary spell definition is expected to derive from `UPrimaryDataAsset`.

Example declaration:

UCLASS(BlueprintType)
class RUNE_MATER_API USpellDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()
};

## Definition Groups

A spell definition may contain:

- Identity.
- Tags.
- Cast requirements.
- Resource cost.
- Cooldown.
- Targeting.
- Delivery.
- Impact.
- Effects.
- Presentation.
- Community metadata.

## Identity

Typical identity fields include:

- Stable spell ID.
- Display name.
- Description.
- Icon.
- Author.
- Version.
- Compatibility version.

## Rule

Definitions describe a spell.

They should not become large procedural gameplay implementations.

## Community Goal

A data-only community spell should be possible when existing targeting, delivery, impact, and effect behaviors are sufficient.
