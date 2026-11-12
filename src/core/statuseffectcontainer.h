#pragma once

#include "statuseffect.h"
typedef struct StatusEffectContainerItem StatusEffectContainerItem;
typedef struct StatusEffectContainerItem {
    StatusEffect value;
    StatusEffectContainerItem *prev, *next;
} StatusEffectContainerItem;

typedef struct StatusEffectContainer {
    StatusEffectContainerItem *start;
    int count;
} StatusEffectContainer;

void StatusEffectContainerOnHit(StatusEffectContainer *self, Battler *owner,
                                Battler *from);
void StatusEffectContainerUpdate(StatusEffectContainer *self, Battler *owner);

void StatusEffectContainerApply(StatusEffectContainer *self,
                                StatusEffect value);
