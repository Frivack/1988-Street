#pragma once
#include "common.h"

struct character Set_Character(float weight, int step, int p);
void Set_movement(struct character *c);
int Weight_Up(int weight);
int Choose_AT();
int Choose_GD();
int Enemy_Behavior(struct character player, struct character enemy);