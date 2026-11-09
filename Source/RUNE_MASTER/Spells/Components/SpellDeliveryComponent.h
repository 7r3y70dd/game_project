#pragma once

#include "../Casting/SpellCastContext.h"
#include "CoreMinimal.h"
#include "Engine/Components/ActorComponent.h"
#include "SpellCastingComponent.h"
#include "SpellDefinition.h"
#include "SpellDeliveryComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNE_MASTER_API USpellDeliveryComponent : public UActorComponent {
  GENERATED_BODY()
public:
  virtual void BeginPlay() override;

private:
  UFUNCTION()
  void HandleSpellCasted(const FSpellCastContext &Context, float ServerCastId);
};
