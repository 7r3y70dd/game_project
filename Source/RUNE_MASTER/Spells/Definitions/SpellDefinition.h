#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SpellDefinition.generated.h"

UCLASS(BlueprintType)
class RUNE_MATER_API USpellDefinition : public UPrimaryDataAsset {
  GENERATED_BODY()

public:
  /** Unique identifier for the spell */
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
  FName SpellId;

  /** Human readable name */
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
  FText DisplayName;

  /** How long the spell is on cooldown after a cast (seconds). */
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Casting")
  float CooldownDuration = 2.f;

  /** Resource cost in arbitrary units. */
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Casting")
  int32 ResourceCost = 10;
};
