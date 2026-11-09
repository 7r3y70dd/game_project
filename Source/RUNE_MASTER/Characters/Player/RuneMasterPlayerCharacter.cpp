#include "RuneMasterPlayerCharacter.h"
#include "GameFramework/Controller.h"

ARuneMasterPlayerCharacter::ARuneMasterPlayerCharacter() {
  PrimaryActorTick.bCanEverTick = true;
  SpellCastingComp =
      CreateDefaultSubobject<USpellCastingComponent>(TEXT("SpellCasting"));
}

void ARuneMasterPlayerCharacter::BeginPlay() { Super::BeginPlay(); }

void ARuneMasterPlayerCharacter::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  PlayerInputComponent->BindAxis(TEXT("MoveForward"), this,
                                 &ARuneMasterPlayerCharacter::MoveForward);
  PlayerInputComponent->BindAxis(TEXT("MoveRight"), this,
                                 &ARuneMasterPlayerCharacter::MoveRight);
  PlayerInputComponent->BindAction(TEXT("CastSpell"), IE_Pressed, this,
                                   &ARuneMasterPlayerCharacter::OnCastSpell);
}

void ARuneMasterPlayerCharacter::MoveForward(float Value) {
  if (Controller && Value != 0.f) {
    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);
    const FVector Direction =
        FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    AddMovementInput(Direction, Value);
  }
}

void ARuneMasterPlayerCharacter::MoveRight(float Value) {
  if (Controller && Value != 0.f) {
    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);
    const FVector Direction =
        FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
  }
}

void ARuneMasterPlayerCharacter::OnCastSpell() {
  if (SpellCastingComp) {
    SpellCastingComp->CastSpell();
  }
}
