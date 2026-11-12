#pragma once

#include "attributes.h"
#include "ability.h"

typedef struct Weapon {
    const char *name;
    StatAttributes attributes;
    Ability offensive;
    Ability defensive;
} Weapon;

typedef struct UniqueWeapon {
	Weapon base;
	Ability ultimate;
} UniqueWeapon;
