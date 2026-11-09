#pragma once
#include "CoreMinimal.h"

/**
 * Interface describing basic health capabilities.
 * Designed to be implemented by any component or actor that owns health state.
 */
class IHealth {
public:
  virtual ~IHealth() = default;
  /** Return maximum health value. */
  virtual float GetMaxHealth() const = 0;
  /** Return current health value. */
  virtual float GetCurrentHealth() const = 0;
  /** Apply damage to the entity, reducing current health. */
  virtual void ApplyDamage(float Damage) = 0;
  /** Heal the entity by Amount, clamped to MaxHealth. */
  virtual void Heal(float Amount) = 0;
};
