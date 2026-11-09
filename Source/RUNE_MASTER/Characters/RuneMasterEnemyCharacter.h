#pragma once
#include "RuneMasterBaseCharacter.h"
#include "RuneMasterEnemyCharacter.generated.h"

/**
 * Basic enemy character that reuses the shared health system.
 */
UCLASS()
class RUNE_MASTER_API ARuneMasterEnemyCharacter
    : public ARuneMasterBaseCharacter {
  GENERATED_BODY()

public:
  ARuneMasterEnemyCharacter();

protected:
  virtual void BeginPlay() override;
};
