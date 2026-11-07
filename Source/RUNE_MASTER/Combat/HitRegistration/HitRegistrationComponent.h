#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "HitRegistrationComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNEMASTER_API UHitRegistrationComponent : public UActorComponent {
  GENERATED_BODY()
public:
  virtual void BeginPlay() override;

  /** Register a hit on Target from the caster.
      Return true if the hit is considered valid for applying damage/effects. */
  UFUNCTION(BlueprintCallable, Category = "HitRegistration")
  bool RegisterHit(AActor *Caster, AActor *Target, const FVector &HitLocation);
};
