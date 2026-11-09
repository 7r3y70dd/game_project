#include "SimpleSpellProjectile.h"

ASimpleSpellProjectile::ASimpleSpellProjectile() {
  PrimaryActorTick.bCanEverTick = true;
}

void ASimpleSpellProjectile::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
  // Simple forward movement as placeholder
  FVector NewLocation =
      GetActorLocation() + GetActorForwardVector() * 1000.f * DeltaTime;
  SetActorLocation(NewLocation);
}
