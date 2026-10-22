#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RuneMasterGameInstance.generated.h"

UCLASS()
class RUNEMASTER_API URuneMasterGameInstance : public UGameInstance {
  GENERATED_BODY()

public:
  URuneMasterGameInstance();

  virtual void Init() override;
  virtual void Shutdown() override;

private:
  bool bIsGameInitialized;
  int32 CurrentDungeonSeed;
};
