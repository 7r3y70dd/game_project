#pragma once

// Export macro for the RuneMaster module.
#if PLATFORM_WINDOWS
#if BUILDING_RUNE_MASTER_DLL
#define RUNE_MASTER_API __declspec(dllexport)
#else
#define RUNE_MASTER_API __declspec(dllimport)
#endif
#else
  // Non-Windows platforms do not require explicit export/import.
#define RUNE_MASTER_API
#endif
