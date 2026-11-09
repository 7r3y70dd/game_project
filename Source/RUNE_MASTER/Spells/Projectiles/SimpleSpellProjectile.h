#pragma once
#include "RuneMaster/Public/RuneMaster.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleSpellProjectile.generated.h"

UCLASS()
class RUNE_MASTER_API ASimpleSpellProjectile : public AActor {
  GENERATED_BODY()
public:
  ASimpleSpellProjectile();
  virtual void Tick(float DeltaTime) override;
};
