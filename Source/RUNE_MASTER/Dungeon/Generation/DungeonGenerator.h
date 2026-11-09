#pragma once
#include "RuneMaster/Public/RuneMaster.h"

#include "CoreMinimal.h"
#include "DungeonGenerator.generated.h"
#include "UObject/NoExportTypes.h"

/** Simple room data structure for demo purposes */
USTRUCT(BlueprintType)
struct RUNE_MASTER_API FDungeonRoom {
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadOnly)
  FString RoomName;

  UPROPERTY(EditAnywhere, BlueprintReadOnly)
  int32 RoomID;
};

/**
 * Minimal dungeon generator.
 * GenerateFromSeed returns an array of room data. Implementation is a stub.
 */
UCLASS()
class RUNE_MASTER_API UDungeonGenerator : public UObject {
  GENERATED_BODY()
public:
  /**
   * Deterministically generate rooms based on the provided seed.
   * For now, returns an empty array.
   */
  UFUNCTION(BlueprintCallable, Category = "Dungeon")
  TArray<FDungeonRoom> GenerateFromSeed(const FString &Seed);
};
