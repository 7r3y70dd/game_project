# Teams

Contains team identity and friendly-fire relationship logic.

## Responsibilities

Provide a consistent answer to questions such as:

- What team does this actor belong to?
- Are two actors friendly?
- Are two actors hostile?
- May this source affect this target?
- Is friendly fire allowed?

## Rule

Spell delivery, targeting, damage, and hit registration should use shared team logic.

Do not implement slightly different friendly-fire checks independently throughout the codebase.

Team information should be accessible through stable interfaces or components rather than concrete character-class casts.
