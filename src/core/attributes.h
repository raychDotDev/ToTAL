#pragma once

typedef struct StatAttributes {
    unsigned int strength, endurance, agility, luck;
} StatAttributes;

StatAttributes StatAttributesAdd(StatAttributes a, StatAttributes b);

int StatAttributesGetMaxHealth(StatAttributes self);
int StatAttributesGetMaxStamina(StatAttributes self);
int StatAttributesGetAttack(StatAttributes self);
int StatAttributesGetDefence(StatAttributes self);
int StatAttributesGetCrit(StatAttributes self);
int StatAttributesGetSpeed(StatAttributes self);
