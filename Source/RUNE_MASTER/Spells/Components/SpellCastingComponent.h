#pragma once
#include "RuneMaster/Public/RuneMaster.h"

#include "../Casting/SpellCastContext.h"
#include "../Definitions/SpellDefinition.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNE_MASTER_API USpellCastingComponent : public UActorComponent {
  GENERATED_BODY()

public:
  USpellCastingComponent();

protected:
  virtual void BeginPlay() override;
  virtual void
  TickComponent(float DeltaTime, ELevelTick TickType,
                FActorComponentTickFunction *ThisTickFunction) override;

public:
  /**
   * Initiate casting of the spell at the given index in the EquippedSpells
   * array.
   */
  UFUNCTION(BlueprintCallable)
  void CastSpell(int32 SpellIndex);

private:
  // List of spells currently equipped. These are data assets that can be
  // assigned via editor or code.
  UPROPERTY(EditDefaultsOnly, Category = "Spells")
  TArray<TObjectPtr<class USpellDefinition>> EquippedSpells;

  // Current cooldown timers for each spell ID. A value <= 0 means the spell is
  // ready.
  TMap<FName, float> SpellCooldowns;

  bool CanCastSpell(const class USpellDefinition *Spell) const;
  void StartCooldown(const class USpellDefinition *Spell);

  /**
   * Broadcasted when a spell has successfully entered the cast state.
   */
  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpellCastedSignature,
                                               const FSpellCastContext &,
                                               Context, float, ServerCastId);

public:
  UPROPERTY(BlueprintAssignable, Category = "Spells|Events")
  FOnSpellCastedSignature OnSpellCasted;
};
