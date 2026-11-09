#pragma once
#include "RuneMaster/Public/RuneMaster.h"

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "HitRegistrationComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNE_MASTER_API UHitRegistrationComponent : public UActorComponent {
  GENERATED_BODY()
public:
  virtual void BeginPlay() override;

  /** Register a hit on Target from the caster.
      Return true if the hit is considered valid for applying damage/effects. */
  UFUNCTION(BlueprintCallable, Category = "HitRegistration")
  bool RegisterHit(AActor *Caster, AActor *Target, const FVector &HitLocation);
};
