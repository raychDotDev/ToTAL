#pragma once

typedef struct Battler Battler;
typedef struct Ability Ability;
typedef struct Ability {
    const char *name;
    void (*cast)(Ability *s, Battler *u, Battler *t);
    int cost;
} Ability;

bool AbilityTryCast(Ability *self, Battler *user, Battler *target);
