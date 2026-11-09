#include "RuneMasterEnemyCharacter.h"

ARuneMasterEnemyCharacter::ARuneMasterEnemyCharacter() {
  // Ensure the health component is attached. The base class will create it in
  // its constructor.
}

void ARuneMasterEnemyCharacter::BeginPlay() {
  Super::BeginPlay();
  // Enemy-specific initialization can go here.
}
