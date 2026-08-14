# Logging

Contains Rune Mater logging categories and shared logging conventions.

## Recommended Categories

Examples include:

DECLARE_LOG_CATEGORY_EXTERN(LogSpellCasting, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogSpellHitRegistration, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogSpellEffects, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogDungeonGeneration, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogDungeonValidation, Log, All);

## Cast Logging

Logs related to a spell cast should include the server cast ID when available.

This should make the chain traceable through:

Input
→ Cast
→ Delivery
→ Hit
→ Effect

## Structured Failures

Do not rely on parsing log strings for gameplay state.

Gameplay failures should expose structured reasons that logs can report.

## Production

Verbose diagnostic logging should be reduced or disabled in production builds.
