#pragma once
#include "RuneMaster/Public/RuneMaster.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RuneMasterPlayerController.generated.h"

UCLASS()
class RUNE_MASTER_API ARuneMasterPlayerController : public APlayerController {
  GENERATED_BODY()

public:
  virtual void SetupInputComponent() override;
};
