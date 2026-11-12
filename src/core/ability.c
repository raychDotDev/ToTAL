#include "ability.h"
#include "battler.h"

bool AbilityTryCast(Ability *self, Battler *user, Battler *target) {
    if (!user || !target || user->stamina < self->cost)
        return false;
    user->stamina -= self->cost;
    self->cast(self, user, target);
    return true;
}
