#include "attributes.h"

StatAttributes StatAttributesAdd(StatAttributes a, StatAttributes b) {
    return (StatAttributes){
        a.strength + b.strength,
        a.endurance + b.endurance,
        a.agility + b.agility,
        a.luck + b.luck,
    };
}

int StatAttributesGetMaxHealth(StatAttributes self) {
    return self.endurance * 1.5f;
}

int StatAttributesGetMaxStamina(StatAttributes self) {
    return self.endurance * 0.8f + self.strength * 0.2f;
}

int StatAttributesGetAttack(StatAttributes self) { return self.strength * 2; }

int StatAttributesGetDefence(StatAttributes self) { return self.endurance * 2; }

int StatAttributesGetCrit(StatAttributes self) { return self.luck * 2.5f; }

int StatAttributesGetSpeed(StatAttributes self) {
    return self.agility + self.strength * 0.2f;
}
