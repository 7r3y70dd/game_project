#include "SpellDeliveryComponent.h"
#include "../Casting/SpellCastContext.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"

void USpellDeliveryComponent::BeginPlay() {
  Super::BeginPlay();
  if (USpellCastingComponent *CastingComp =
          GetOwner()->FindComponentByClass<USpellCastingComponent>()) {
    CastingComp->OnSpellCasted.AddDynamic(
        this, &USpellDeliveryComponent::HandleSpellCasted);
  }
}

void USpellDeliveryComponent::HandleSpellCasted(
    const FSpellCastContext &Context, float ServerCastId) {
  if (!Context.Spell)
    return;

  switch (Context.Spell->DeliveryType) {
  case ESpellDeliveryType::Projectile: {
    if (!Context.Spell->ProjectileClass)
      return;
    FVector StartLocation = Context.Origin;
    FActorSpawnParameters Params;
    Params.Owner = GetOwner();
    if (APawn *Pawn = Cast<APawn>(GetOwner())) {
      Params.Instigator = Pawn;
    }
    AActor *Projectile = GetWorld()->SpawnActor<AActor>(
        Context.Spell->ProjectileClass, StartLocation,
        Context.AimDirection.Rotation(), Params);
    if (Projectile) {
      UE_LOG(LogTemp, Log,
             TEXT("[SpellDelivery] Spawned projectile %s for spell %s"),
             *Projectile->GetName(), *Context.Spell->SpellId.ToString());
    }
  } break;

  case ESpellDeliveryType::Instant: {
    UE_LOG(LogTemp, Log,
           TEXT("[SpellDelivery] Applying instant effect for spell %s at %s"),
           *Context.Spell->SpellId.ToString(), *Context.Origin.ToString());
  } break;

  default:
    UE_LOG(LogTemp, Warning,
           TEXT("[SpellDelivery] Unhandled delivery type for spell %s"),
           *Context.Spell->SpellId.ToString());
    break;
  }
}
