#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RuneMasterPlayerCharacter.generated.h"
#include "SpellCastingComponent.h"

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
  /** Spell casting component attached to the player. */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
            meta = (AllowPrivateAccess = true))
  USpellCastingComponent *SpellCastingComp;

  // Input handlers
  void MoveForward(float Value);
  void MoveRight(float Value);
  void OnCastSpell();
};
