#include "statuseffect.h"
#include "battler.h"

void StatusEffectUpdate(StatusEffect *self, Battler *owner) {
    if (!self || !owner || self->lifetime <= 0)
        return;
    if (self->update) {
        self->update(self, owner);
    }
    self->lifetime--;
}
void StatusEffectOnHit(StatusEffect *self, Battler *owner, Battler *from) {
    if (!self || !owner || !from || self->lifetime <= 0)
        return;
    if (self->onHit) {
        self->onHit(self, owner, from);
    }
}
