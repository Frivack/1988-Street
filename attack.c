#include "attack.h"

float Attack_Damage(int attack, float weight)
{
	if (attack == AS_jap)
	{
		return 1 * (weight / 40);//���� �� ������ ����
	}
	if (attack == AS_straight)
	{
		return 2 * (weight / 40);//���� �� ������ ����
	}
	if (attack == AS_uppercut)
	{
		return 4 * (weight / 40);//���� �� ������ ����
	}
	if (attack == AS_counter)
	{
		return 2 * (weight / 40);//���� �� ������ ����
	}
	if (attack == 2022)
	{
		return 2022;
	}
}

float Attack_Stamina(int attack, float weight)
{
	if (attack == AS_jap)
	{
		return -1 * (weight / 40);
	}
	if (attack == AS_straight)
	{
		return -1 * (weight / 40);
	}
	if (attack == AS_counter)
	{
		return -1 * (weight / 40);
	}
	if (attack == AS_uppercut)
	{
		return -1 * (weight / 40);
	}
}

/*AS_jap, AS_straight�� ���� ������ common.h�� enum���� �������ֱ⿡ ������ �ʿ� ����.*/
/*���� ������ ������ ���ǹ��� �� ���� else�� ���̴°� ����. if�� 4�� ���� ����� 4�������� else if�� ���̸� �ּ� 1�� ��.*/

// + ���� �Ұ� �� �ݰݱ� �߰� �ʿ�