#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RuneMasterPlayerController.generated.h"

UCLASS()
class RUNEMASTER_API ARuneMasterPlayerController : public APlayerController {
  GENERATED_BODY()

public:
  virtual void SetupInputComponent() override;
};
