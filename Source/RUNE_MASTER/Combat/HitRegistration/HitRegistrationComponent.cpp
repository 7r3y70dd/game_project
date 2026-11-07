#include "HitRegistrationComponent.h"

void UHitRegistrationComponent::BeginPlay() { Super::BeginPlay(); }

bool UHitRegistrationComponent::RegisterHit(AActor *Caster, AActor *Target,
                                            const FVector &HitLocation) {
  // Stub: always valid for now.
  return true;
}
