#pragma once

typedef struct StatusEffect StatusEffect;
typedef struct Battler Battler;
typedef struct StatusEffect {
	const char* name;
	int lifetime;
	bool stun;
	void (*update)(StatusEffect *s, Battler* o);
	void (*onHit)(StatusEffect *s, Battler* o, Battler* f);
} StatusEffect;

void StatusEffectUpdate(StatusEffect *self, Battler* owner);
void StatusEffectOnHit(StatusEffect *self, Battler* owner, Battler* from);

