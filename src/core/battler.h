#pragma once

#include "ability.h"
#include "weapon.h"

#include "attributes.h"

typedef struct Fight Fight;
typedef struct Battler Battler;
typedef struct Battler {
    const char *name;
    int health, stamina;
    StatAttributes attributes;
    Ability ultimate;
    Weapon weapon;
    void (*update)(Battler *s, Battler *t, Fight *ctx);
} Battler;

StatAttributes BattlerGetAttributes(Battler *self);

void BattlerUpdate(Battler *self, Battler *target, Fight *context);
