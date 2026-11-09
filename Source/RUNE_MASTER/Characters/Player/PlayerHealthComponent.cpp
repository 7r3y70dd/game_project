#include "PlayerHealthComponent.h"

UPlayerHealthComponent::UPlayerHealthComponent() {
  PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerHealthComponent::BeginPlay() {
  Super::BeginPlay();
  CurrentHealth = MaxHealth;
}

void UPlayerHealthComponent::TakeDamage(float Damage) {
  if (Damage <= 0.f || !IsValid(this))
    return;
  CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
  OnHealthChanged.Broadcast(CurrentHealth);
}
