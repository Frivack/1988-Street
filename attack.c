#include "attack.h"

float Attack_Damage(int attack, float weight)
{
	if (attack == AS_jap)
	{
		return 1 * (weight / 40);//공격 별 데미지 리턴
	}
	if (attack == AS_straight)
	{
		return 2 * (weight / 40);//공격 별 데미지 리턴
	}
	if (attack == AS_uppercut)
	{
		return 4 * (weight / 40);//공격 별 데미지 리턴
	}
	if (attack == AS_counter)
	{
		return 2 * (weight / 40);//공격 별 데미지 리턴
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

/*AS_jap, AS_straight와 같은 변수는 common.h에 enum으로 지정되있기에 선언할 필요 없음.*/
/*같은 변수로 여러번 조건문을 쓸 때는 else를 붙이는게 좋음. if를 4번 쓰면 계산을 4번하지만 else if를 붙이면 최소 1번 함.*/

// + 가드 불가 및 반격기 추가 필요