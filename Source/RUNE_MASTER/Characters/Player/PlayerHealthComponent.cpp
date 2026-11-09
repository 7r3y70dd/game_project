#include "PlayerHealthComponent.h"

UPlayerHealthComponent::UPlayerHealthComponent() {
  PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerHealthComponent::BeginPlay() {
  Super::BeginPlay();
  CurrentHealth = MaxHealth;
}

float UPlayerHealthComponent::GetMaxHealth() const { return MaxHealth; }

float UPlayerHealthComponent::GetCurrentHealth() const { return CurrentHealth; }

void UPlayerHealthComponent::ApplyDamage(float Damage) { TakeDamage(Damage); }

void UPlayerHealthComponent::Heal(float Amount) {
  if (Amount <= 0.f || !IsValid(this))
    return;
  CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
  OnHealthChanged.Broadcast(CurrentHealth);
}
