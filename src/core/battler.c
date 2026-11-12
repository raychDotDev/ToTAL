#include "battler.h"
#include "attributes.h"
#include "fight.h"

StatAttributes BattlerGetAttributes(Battler *self) {
    return StatAttributesAdd(self->attributes, self->weapon.attributes);
}

void BattlerUpdate(Battler *self, Battler *target, Fight *context) {
    if (!self || !target || !context)
        return;
    if (self->update) {
        self->update(self, target, context);
    }
}
