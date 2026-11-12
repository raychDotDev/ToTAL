#include "statuseffectcontainer.h"
#include "raylib.h"
#include "statuseffect.h"

void StatusEffectContainerOnHit(StatusEffectContainer *self, Battler *owner,
                                Battler *from) {
    if (!self || !owner || !from)
        return;
}
void StatusEffectContainerUpdate(StatusEffectContainer *self, Battler *owner) {
    if (!self || !owner)
        return;
    for (StatusEffectContainerItem *i = self->start; i->next != nullptr;) {
        StatusEffectUpdate(&i->value, owner);
        if (i->value.lifetime == 0) {
            i->prev->next = i->next;
            StatusEffectContainerItem *si = i;
            i = i->next;
            MemFree(si);
            si = nullptr;
        } else {
            i = i->next;
        }
    }
}

void StatusEffectContainerApply(StatusEffectContainer *self,
                                StatusEffect value) {
    if (!self || value.lifetime <= 0)
        return;
    for (StatusEffectContainerItem *i = self->start; i != nullptr;
         i = i->next) {
        if (i->next == nullptr) {
            i->next = MemAlloc(sizeof(StatusEffectContainerItem));
            i->next->value = value;
            i->next->prev = i;
            i->next->next = nullptr;
            break;
        }
    }
}
