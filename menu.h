#pragma once
#include "common.h"

int Menu_Selector(int iswin);
int Character_Selector();
int Step_Selector();
void Print_Steps(int pstep, int estep);
int Player_Behavior(struct character player);
void Print_Behavior(struct character at, struct character df);
void Print_Points(struct character c, struct character e);
void Champion(int step);