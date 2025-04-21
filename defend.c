#include "defend.h"

int Guard(float* AttackPower, float* Stemina)
{
	*AttackPower -= 0.5;
	*Stemina += 3;
}

int Sway(float* RatioOfMiss, float* Stemina)
{
	*RatioOfMiss += (*RatioOfMiss) / 10;
	*Stemina += 2.5;
}

int weaving(float* RelativeHitRate, float* Stemina)
{
	*RelativeHitRate -= (*RelativeHitRate) / 5;
	*Stemina += 2.5;
}
int RelativeHit(int* Counter, int* Attack, int RelativeHit, int weight)
{
	*Counter = (RelativeHit) / 5;
	*Attack = 10 * 100 / weight;
}