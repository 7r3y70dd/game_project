#include "RuneMasterBaseCharacter.h"
#include "Characters/Player/PlayerHealthComponent.h"

ARuneMasterBaseCharacter::ARuneMasterBaseCharacter() {
  PrimaryActorTick.bCanEverTick = false;
  HealthComp = CreateDefaultSubobject<UPlayerHealthComponent>(TEXT("Health"));
}

void ARuneMasterBaseCharacter::BeginPlay() { Super::BeginPlay(); }

float ARuneMasterBaseCharacter::GetMaxHealth() const {
  return HealthComp ? HealthComp->GetMaxHealth() : 0.f;
}
float ARuneMasterBaseCharacter::GetCurrentHealth() const {
  return HealthComp ? HealthComp->GetCurrentHealth() : 0.f;
}
void ARuneMasterBaseCharacter::ApplyDamage(float Damage) {
  if (HealthComp)
    HealthComp->ApplyDamage(Damage);
}
void ARuneMasterBaseCharacter::Heal(float Amount) {
  if (HealthComp)
    HealthComp->Heal(Amount);
}
