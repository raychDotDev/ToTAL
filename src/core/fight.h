#pragma once

typedef struct Battler Battler;
typedef struct Fight {
    int step;
    Battler *a, *b;
} Fight;

Fight FightNew(Battler *a, Battler *b);

// 0 - fight in process, 1 - a won, 2 - b won, 3 - tie
int FightUpdate(Fight* self);
