#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleSpellProjectile.generated.h"

UCLASS()
class RUNE_MATER_API ASimpleSpellProjectile : public AActor {
  GENERATED_BODY()
public:
  ASimpleSpellProjectile();
  virtual void Tick(float DeltaTime) override;
};
