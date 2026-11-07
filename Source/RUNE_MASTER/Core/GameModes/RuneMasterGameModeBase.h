#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RuneMasterGameModeBase.generated.h"

UCLASS()
class RUNEMASTER_API ARuneMasterGameModeBase : public AGameModeBase {
  GENERATED_BODY()

public:
  virtual void BeginPlay() override;
};
