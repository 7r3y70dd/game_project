#include "SpellCastingComponent.h"
#include "../Definitions/SpellDefinition.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "TimerManager.h"

USpellCastingComponent::USpellCastingComponent() {
  PrimaryComponentTick.bCanEverTick = true;
}

void USpellCastingComponent::BeginPlay() { Super::BeginPlay(); }

void USpellCastingComponent::TickComponent(
    float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  // Reduce cooldown timers
  TArray<FName> KeysToRemove;
  for (auto &Pair : SpellCooldowns) {
    Pair.Value -= DeltaTime;
    if (Pair.Value <= 0.f) {
      KeysToRemove.Add(Pair.Key);
    }
  }
  for (const FName &Key : KeysToRemove) {
    SpellCooldowns.Remove(Key);
  }
}

bool USpellCastingComponent::CanCastSpell(
    const class USpellDefinition *Spell) const {
  if (!Spell)
    return false;
  // Cooldown check
  if (SpellCooldowns.Contains(Spell->SpellId))
    return false;
  // TODO: resource, equip etc. For now just cooldown.
  return true;
}

void USpellCastingComponent::StartCooldown(
    const class USpellDefinition *Spell) {
  if (!Spell)
    return;
  SpellCooldowns.Add(Spell->SpellId, Spell->CooldownDuration);
}

void USpellCastingComponent::CastSpell(int32 SpellIndex) {
  if (!EquippedSpells.IsValidIndex(SpellIndex)) {
    UE_LOG(LogTemp, Warning,
           TEXT("[USpellCastingComponent] Invalid spell index %d"), SpellIndex);
    return;
  }

  const USpellDefinition *Spell = EquippedSpells[SpellIndex];
  if (!CanCastSpell(Spell)) {
    UE_LOG(LogTemp, Warning,
           TEXT("[USpellCastingComponent] Cannot cast spell %s"),
           *Spell->SpellId.ToString());
    return;
  }

  // Build cast context
  FSpellCastContext Context;
  Context.Caster = GetOwner();
  if (AActor *Owner = Cast<AActor>(GetOwner())) {
    Context.Origin = Owner->GetActorLocation();
    Context.AimDirection = Owner->GetActorForwardVector();
  }

  // Find controller if any
  AController *Controller = nullptr;
  if (APawn *Pawn = Cast<APawn>(GetOwner())) {
    Controller = Pawn->GetController();
  }
  Context.InstigatorController = Controller;
  Context.Spell = Spell;
  Context.TargetLocation =
      Context.Origin + Context.AimDirection * 1000.f; // placeholder

  // Broadcast event (server cast id placeholder 0)
  OnSpellCasted.Broadcast(Context, 0.f);

  UE_LOG(LogTemp, Log, TEXT("[USpellCastingComponent] Cast spell %s"),
         *Spell->SpellId.ToString());

  // Start cooldown
  StartCooldown(Spell);
}
