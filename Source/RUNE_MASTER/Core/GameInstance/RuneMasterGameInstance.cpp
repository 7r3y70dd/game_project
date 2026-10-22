#include "RuneMasterGameInstance.h"

URuneMasterGameInstance::URuneMasterGameInstance()
    : bIsGameInitialized(false), CurrentDungeonSeed(0) {}

void URuneMasterGameInstance::Init() { Super::Init(); }

void URuneMasterGameInstance::Shutdown() { Super::Shutdown(); }
