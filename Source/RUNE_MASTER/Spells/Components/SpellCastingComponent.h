#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "SpellCastingComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNEMASTER_API USpellCastingComponent : public UActorComponent {
  GENERATED_BODY()

public:
  /** Called when the game starts or when spawned */
  virtual void BeginPlay() override;

  /** Bind inputs on the owning character's controller (if any) */
  void SetupPlayerInputComponent();

  /** Stub for casting a spell – to be implemented later */
  UFUNCTION(BlueprintCallable, Category = "Spell")
  void CastSpell();
};
