#pragma once
#include "RuneMaster/Public/RuneMaster.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerHealthComponent.h"
#include "Spells/Components/SpellCastingComponent.h"

UCLASS()
class RUNE_MASTER_API ARuneMasterPlayerCharacter : public ACharacter {
  GENERATED_BODY()

public:
  /** Constructor */
  ARuneMasterPlayerCharacter();

protected:
  virtual void BeginPlay() override;
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;

private:
  /** Health component attached to the player. */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
            meta = (AllowPrivateAccess = true))
  UPlayerHealthComponent *HealthComp;
  /** Spell casting component attached to the player. */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
            meta = (AllowPrivateAccess = true))
  USpellCastingComponent *SpellCastingComp;

  // Input handlers
  void MoveForward(float Value);
  void MoveRight(float Value);
  void OnCastSpell();
};
