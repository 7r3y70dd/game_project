#pragma once
#include "GameFramework/Character.h"
#include "Interfaces/IHealth.h"
class UPlayerHealthComponent;
#include "RuneMasterBaseCharacter.generated.h"

/**
 * Abstract base class for all player and enemy characters.
 * Provides a health component and implements the IHealth interface by
 * delegating to it.
 */
UCLASS(Abstract)
class RUNE_MASTER_API ARuneMasterBaseCharacter : public ACharacter,
                                                 public IHealth {
  GENERATED_BODY()

public:
  ARuneMasterBaseCharacter();
  virtual void BeginPlay() override;

public:
  /** Health component attached to the character. */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
            meta = (AllowPrivateAccess = true))
  class UPlayerHealthComponent *HealthComp;

  // IHealth interface
  virtual float GetMaxHealth() const override;
  virtual float GetCurrentHealth() const override;
  virtual void ApplyDamage(float Damage) override;
  virtual void Heal(float Amount) override;
};
