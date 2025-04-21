#include "character.h"


struct character Set_Character(float weight, int step, int p)
{
	struct character c;
	c.weight = weight;
	c.HP = weight / 5;
	c.SP = weight / 5;
	c.maxpoints = weight / 5;
	c.stat = 0;
	c.select = 0;
	c.step = step;

	if (p == 0)//플레이어가 아닐 경우
	{
		int r = rand() % 12;
		switch (r)
		{
		case 0:
			strcpy(c.name, "「지훈이」");
			break;
		case 1:
			strcpy(c.name, "「진철이」");
			break;
		case 2:
			strcpy(c.name, "「태용이」");
			break;
		case 3:
			strcpy(c.name, "「을식이」");
			break;
		case 5:
			strcpy(c.name, "「범식이」");
			break;
		case 6:
			strcpy(c.name, "「주찬이」");
			break;
		case 7:
			strcpy(c.name, "「석훈이」");
			break;
		case 8:
			strcpy(c.name, "「성훈이」");
			break;
		case 9:
			strcpy(c.name, "「영식이」");
			break;
		case 10:
			strcpy(c.name, "「기영이」");
			break;
		case 11:
			strcpy(c.name, "「봉식이」");
			break;
		default:
			strcpy(c.name, "「지훈이」");
			break;
		}
	}
	else//플레이어가 맞을 경우
	{
		if (weight == 60)
			strcpy(c.name, "『봉팔이』");
		else if (weight == 65)
			strcpy(c.name, "『춘식이』");
		else if (weight == 75)
			strcpy(c.name, "『만식이』");
		else if (weight == 90)
			strcpy(c.name, "『종찬이』");
	}

	Set_movement(&c);

	if (weight > WC_light_heavy)//헤비급이라면
		c.personality = P_agressive;//공격적인 성향
	else if (weight < WC_light_welter)//웰터급 이하라면
		c.personality = P_defensive;//방어적인 성향
	else
	{
		int r = rand() % 100 + (weight - WC_middle);//그 외 랜덤, 무게가 높을수록 공격적일 확률이, 낮을수록 방어적일 확률이 높음
		if (r >= 75)
			c.personality = P_agressive;
		else if (r >= 50)
			c.personality = P_mix;
		else if (r >= 25)
			c.personality = P_random;
		else
			c.personality = P_defensive;
	}
	return c;
}

void Set_movement(struct character *c)
{
	c->accuracy = 0;
	if (c->weight <= WC_light_welter)
		c->avoid = 30;
	else if (c->weight <= WC_light_middle)
		c->avoid = 25;
	else if (c->weight <= WC_middle)
		c->avoid = 20;
	else if (c->weight <= WC_light_heavy)
		c->avoid = 15;
	else
		c->avoid = 10;
}

int Weight_Up(int weight)
{
	if (weight < WC_light_welter)
	{
		return WC_light_welter + rand() % (WC_light_middle - WC_light_welter);
	}
	else if (weight < WC_light_middle)
	{
		return WC_light_middle + rand() % (WC_middle - WC_light_middle);
	}
	else if (weight < WC_middle)
	{
		return WC_middle + rand() % (WC_light_heavy - WC_middle);
	}
	else if (weight < WC_light_heavy)
	{
		return WC_light_heavy + rand() % (WC_heavy - WC_light_heavy);
	}
	else
	{
		return 0;
	}
}

int Choose_AT()
{
	int r = rand() % 4;
	if (r == 0) return BH_01;
	else if (r == 1) return BH_02;
	else if (r == 2) return BH_03;
	else if (r == 3) return BH_04;
	else return -1;
}

int Choose_GD()
{
	int r = rand() % 3;
	if (r == 0) return BH_11;
	else if (r == 1) return BH_12;
	else if (r == 2) return BH_13;
	else return -1;
}

int Enemy_Behavior(struct character player, struct character enemy)
{
	global_counter++;
	switch (enemy.personality)
	{
	case P_defensive:
		if (enemy.HP <= (enemy.weight / 5) / 3 || enemy.SP <= enemy.weight / 40)// 적 체력이 1/3이하거나 스테미너가 없을 때
			return Choose_GD();// 가드 
		else
		{
			if (global_counter % 3 == 0)// 1/3의 확률로
				return Choose_AT();// 공격
			else
				return Choose_GD();
		}
		break;
	case P_agressive:
		if (enemy.SP < enemy.weight / 40)// 스테미너가 없을 때
			return Choose_GD();
		else if (player.HP <= (player.weight / 5) / 3 && enemy.SP >= enemy.weight / 40)// 플레이어 체력이 1/3이하이고 스테미너가 있을 때
			return Choose_AT();// 공격
		else
		{
			if (global_counter % 3 == 0)
				return Choose_GD();
			else
				return Choose_AT();
		}
		break;
	case P_mix:
		if (enemy.HP <= (enemy.weight / 5) / 3 || enemy.SP <= enemy.weight / 40)// 적 체력이 1/3이하거나 스테미너가 없을 때
			return Choose_GD();// 가드
		else if (player.HP <= (player.weight / 5) / 3 && enemy.SP >= enemy.weight / 40)// 플레이어 체력이 1/3이하이고 스테미너가 있을 때
			return Choose_AT();// 공격
		else
		{
			if (global_counter % 2 == 0)// 1/2의 확률로
				return Choose_GD();
			else
				return Choose_AT();
		}
		break;
	case P_random:
		if (enemy.SP < enemy.weight / 40)// 스테미너가 없을 때
			return Choose_GD();
		else
			return rand() % BH_MAX;
		break;
	default:
		break;
	}
	return -1;
}