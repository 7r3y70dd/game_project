# Menus

Contains menu-oriented Rune Mater UI.

## Scope

The current architecture does not define a large menu framework.

Keep menu implementation presentation-focused and avoid introducing gameplay ownership here.

## Rule

Menus may configure or request gameplay actions through stable system APIs.

They should not contain authoritative combat, spell, or dungeon logic.
