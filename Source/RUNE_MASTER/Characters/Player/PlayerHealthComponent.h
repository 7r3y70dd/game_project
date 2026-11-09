#pragma once
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "PlayerHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNE_MASTER_API UPlayerHealthComponent : public UActorComponent {
  GENERATED_BODY()
public:
  UPlayerHealthComponent();

protected:
  virtual void BeginPlay() override;

public:
  /** Maximum health */
  UPROPERTY(EditDefaultsOnly, Category = "Health")
  float MaxHealth = 100.f;

  /** Current health */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
  float CurrentHealth;

  /** Broadcast when health changes */
  UPROPERTY(BlueprintAssignable, Category = "Events")
  FOnHealthChanged OnHealthChanged;

  /** Apply damage to the actor. */
  void TakeDamage(float Damage);
};
