#pragma once
#include "RuneMaster/Public/RuneMaster.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "SpellCastContext.generated.h"
#include "SpellDefinition.h"

/**
 * Minimal context sent to the server when a spell is cast.
 */
USTRUCT(BlueprintType)
struct RUNE_MASTER_API FSpellCastContext {
  GENERATED_BODY()

  /** The actor that initiated the cast. */
  UPROPERTY()
  TObjectPtr<AActor> Caster = nullptr;

  /** Optional controller that instigated the spell. */
  UPROPERTY()
  TObjectPtr<AController> InstigatorController = nullptr;

  /** Reference to the spell definition being used. */
  UPROPERTY()
  const USpellDefinition *Spell = nullptr;

  /** Origin location of the cast (usually actor location). */
  UPROPERTY()
  FVector Origin = FVector::ZeroVector;

  /** Direction that the spell is aimed in. */
  UPROPERTY()
  FVector AimDirection = FVector::ForwardVector;

  /** Target location or surface point used for delivery calculations. */
  UPROPERTY()
  FVector TargetLocation = FVector::ZeroVector;
};
