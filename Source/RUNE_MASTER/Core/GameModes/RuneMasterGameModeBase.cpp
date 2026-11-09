#include "RuneMasterGameModeBase.h"
#include "Characters/Player/RuneMasterPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARuneMasterGameModeBase::ARuneMasterGameModeBase() {
  // Set default pawn class to our player character
  static ConstructorHelpers::FClassFinder<APawn> PlayerPawn(
      TEXT("/Script/RuneMaster.ARuneMasterPlayerCharacter"));
  DefaultPawnClass = PlayerPawn.Class;
}

void ARuneMasterGameModeBase::BeginPlay() { Super::BeginPlay(); }
