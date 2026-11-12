#include "fight.h"
#include "battler.h"

Fight FightNew(Battler *a, Battler *b) { return (Fight){0, a, b}; }

// 0 - fight in process, 1 - a won, 2 - b won, 3 - tie
int FightUpdate(Fight* self) {

	BattlerUpdate(self->a, self->b, self);
	BattlerUpdate(self->b, self->a, self);
	int aAlive = self->a->health <= 0;
	int bAlive = self->b->health <= 0;
	if (aAlive && !bAlive) return 1; 
	if (bAlive && !aAlive) return 2; 
	if (aAlive && bAlive) return 3;
	return 0;
}
