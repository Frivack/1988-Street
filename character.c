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

	if (p == 0)//�÷��̾ �ƴ� ���
	{
		int r = rand() % 12;
		switch (r)
		{
		case 0:
			strcpy(c.name, "�������̡�");
			break;
		case 1:
			strcpy(c.name, "����ö�̡�");
			break;
		case 2:
			strcpy(c.name, "���¿��̡�");
			break;
		case 3:
			strcpy(c.name, "�������̡�");
			break;
		case 5:
			strcpy(c.name, "�������̡�");
			break;
		case 6:
			strcpy(c.name, "�������̡�");
			break;
		case 7:
			strcpy(c.name, "�������̡�");
			break;
		case 8:
			strcpy(c.name, "�������̡�");
			break;
		case 9:
			strcpy(c.name, "�������̡�");
			break;
		case 10:
			strcpy(c.name, "���⿵�̡�");
			break;
		case 11:
			strcpy(c.name, "�������̡�");
			break;
		default:
			strcpy(c.name, "�������̡�");
			break;
		}
	}
	else//�÷��̾ ���� ���
	{
		if (weight == 60)
			strcpy(c.name, "�������̡�");
		else if (weight == 65)
			strcpy(c.name, "������̡�");
		else if (weight == 75)
			strcpy(c.name, "�������̡�");
		else if (weight == 90)
			strcpy(c.name, "�������̡�");
	}

	Set_movement(&c);

	if (weight > WC_light_heavy)//�����̶��
		c.personality = P_agressive;//�������� ����
	else if (weight < WC_light_welter)//���ͱ� ���϶��
		c.personality = P_defensive;//������� ����
	else
	{
		int r = rand() % 100 + (weight - WC_middle);//�� �� ����, ���԰� �������� �������� Ȯ����, �������� ������� Ȯ���� ����
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
		if (enemy.HP <= (enemy.weight / 5) / 3 || enemy.SP <= enemy.weight / 40)// �� ü���� 1/3���ϰų� ���׹̳ʰ� ���� ��
			return Choose_GD();// ���� 
		else
		{
			if (global_counter % 3 == 0)// 1/3�� Ȯ����
				return Choose_AT();// ����
			else
				return Choose_GD();
		}
		break;
	case P_agressive:
		if (enemy.SP < enemy.weight / 40)// ���׹̳ʰ� ���� ��
			return Choose_GD();
		else if (player.HP <= (player.weight / 5) / 3 && enemy.SP >= enemy.weight / 40)// �÷��̾� ü���� 1/3�����̰� ���׹̳ʰ� ���� ��
			return Choose_AT();// ����
		else
		{
			if (global_counter % 3 == 0)
				return Choose_GD();
			else
				return Choose_AT();
		}
		break;
	case P_mix:
		if (enemy.HP <= (enemy.weight / 5) / 3 || enemy.SP <= enemy.weight / 40)// �� ü���� 1/3���ϰų� ���׹̳ʰ� ���� ��
			return Choose_GD();// ����
		else if (player.HP <= (player.weight / 5) / 3 && enemy.SP >= enemy.weight / 40)// �÷��̾� ü���� 1/3�����̰� ���׹̳ʰ� ���� ��
			return Choose_AT();// ����
		else
		{
			if (global_counter % 2 == 0)// 1/2�� Ȯ����
				return Choose_GD();
			else
				return Choose_AT();
		}
		break;
	case P_random:
		if (enemy.SP < enemy.weight / 40)// ���׹̳ʰ� ���� ��
			return Choose_GD();
		else
			return rand() % BH_MAX;
		break;
	default:
		break;
	}
	return -1;
}