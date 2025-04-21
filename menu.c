#include "menu.h"

void GotoXY(int x, int y)//콘솔창에서 출력 위치 옮겨주는 함수
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int Menu_Selector(int iswin)
{
	int menu_select;
	if (iswin == 2)
	{
		int x = 25, y = 7;
		Champion(global_step);
		GotoXY(x, y++);
		printf("       ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		GotoXY(x, y++);
		printf("      /                               /");
		GotoXY(x, y++);
		printf("     /         1988 길거리           /");
		GotoXY(x, y++);
		printf("    /                               /");
		GotoXY(x, y++);
		printf("     ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n\n\n\n\n\n\n\n");
	}
	else
	{
		printf("               ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
		printf("              /                               /\n");
		printf("             /         1988 길거리           /\n");
		printf("            /                               /\n");
		printf("             ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
		printf("찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵\n");
		printf("찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵\n");
		printf("∧_∧　　　 　　∧_∧ 　　　 ∧_∧　　∧_∧　　　 　∧_∧　　　　 ∧_∧\n");
		printf("()】()】　　　()】 【()　　　 【()　　　 【()     【(　　 )    【(　　 )\n");
		printf("/　 /┘　.　 　/　 /┘.　 　　/ 　 /┘    └ ＼ ＼ 　　└ ＼ ＼　  　└ ＼ ＼\n");
		printf("ノ￣ノ　 　　ノ￣ノ 　　　　ノ￣ノ　 　　ノ￣＼ 　　 ノ￣＼　  　ノ￣＼\n\n");
	}
	printf("1. 게임 시작\n2. 게임 종료\n");
	printf("메뉴 선택: ");
	scanf("%d", &menu_select);

	if (menu_select == 1)
	{
		system("cls");
		printf("게임을 시작합니다.\n\n");
		return 1;
	}
	else if (menu_select == 2)
	{
		printf("게임을 종료합니다.\n\n");
		return 2;
	}
	else
	{
		system("cls");
		printf("잘못 입력했습니다.\n\n");
		return 0;
	}
}

int Character_Selector()
{
	int i, w = 1, r;
	while (w)
	{
		printf("1.봉팔이\n체력: 12, 스테미너: 12, 공격력: 1.5\n2.춘식이\n체력: 13, 스테미너: 13, 공격력: 1.6\n3.만식이\n체력: 15, 스테미너: 15, 공격력: 1.9\n4.종찬이\n체력: 18, 스테미너: 18, 공격력: 2.3\n\n");
		printf("캐릭터를 선택하세요: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("봉팔이를 선택\n\n");
			w = 0;
			r = 60;
			break;
		case 2:
			printf("춘식이를 선택\n\n");
			w = 0;
			r = 65;
			break;
		case 3:
			printf("만식이를 선택\n\n");
			w = 0;
			r = 75;
			break;
		case 4:
			printf("종찬이를 선택\n\n");
			w = 0;
			r = 90;
			break;
		default:
			system("cls");
			printf("잘못 입력했습니다.\n\n");
			break;
		}
	}
	getch();
	system("cls");
	return r;
}

int Step_Selector()
{
	int i, w = 1;
	int Step_select;
	printf("\n\n");
	while (w)
	{
		printf("스텝 목록\n1.제자리 스텝\n2.전진 스텝\n3.후진 스텝\n4.좌측으로 움직임\n5.우측으로 움직임\n\n");
		printf("스텝을 선택하세요: ");
		scanf("%d", &i);
		system("cls");
		switch (i)
		{
		case 1:
			printf("제자리 스텝을 선택.\n");
			w = 0;
			break;
		case 2:
			printf("전진 스텝을 선택.\n");
			w = 0;
			break;
		case 3:
			printf("후진 스텝을 선택.\n");
			w = 0;
			break;
		case 4:
			printf("좌측으로 움직임 스텝을 선택.\n");
			w = 0;
			break;
		case 5:
			printf("우측으로 움직임 스텝을 선택.\n");
			w = 0;
			break;
		default:
			printf("잘못 입력했습니다.\n\n");
			break;
		}
	}
	Print_Steps(i, 0);
	getch();
	system("cls");
	return i;
}

void Print_Steps(int pstep, int estep)
{
	switch (pstep)
	{
	case 1:
		printf("∧＿∧\n");
		printf("('ω')＝つ≡つ\n");
		printf("(っ　≡つ＝つ\n");
		printf(". / ) 바바바바\n");
		printf("(/ ￣∪\n");
		printf("/-/  /-/ 통통\n\n");
		break;
	case 2:
		printf("-)   ∧＿∧\n");
		printf("-)   ('ω')＝つ≡つ\n");
		printf("-)   (っ　≡つ＝つ\n");
		printf("-)   . / ) 바바바바\n");
		printf("-)   (/ ￣∪\n\n");
		break;
	case 3:
		printf("∧＿∧          (-\n");
		printf("('ω')＝つ≡つ  (-\n");
		printf("(っ　≡つ＝つ   (-\n");
		printf(". / ) 바바바바  (-\n");
		printf("(/ ￣∪         (-\n\n");
		break;
	case 4:
		printf(".  ∧＿＿∧\n");
		printf("(（('ω')三 때려봐 때려봐~\n");
		printf("   (_っっ = _っっ'　휘익 휘익\n");
		printf("     ＼　　ノ\n");
		printf("      (/ ￣∪\n\n");
		break;
	case 5:
		printf("    ∧＿＿∧\n");
		printf(" 三('ω')) ) 때려봐 때려봐~\n");
		printf("(_っっ = _っっ'　휘익 휘익\n");
		printf(" ＼　　ノ\n");
		printf("  (/ ￣∪\n\n");
		break;
	default:
		printf("잘못입력하였습니다.\n\n");
		break;
	}
	
	int x = 55, y = 4;
	switch (estep)
	{
	case 0: break;
	case 1:
		y++;
		GotoXY(x, y++);
		printf("   ハ_ハ");
		GotoXY(x, y++);
		printf("ヘ('ω')");
		GotoXY(x, y++);
		printf("   ＼ヘ｜");
		GotoXY(x, y++);
		printf("    < <\n\n\n");
		break;
	case 2:
		y++;
		GotoXY(x, y++);
		printf("  ∧＿∧");
		GotoXY(x, y++);
		printf("（-ω~* )");
		GotoXY(x, y++);
		printf(" ⊂、⊂.'");
		GotoXY(x, y++);
		printf("  ⊂￢,_)\n\n\n");
		break;
	case 3:		
		y++;
		GotoXY(x, y++);
		printf(" ∧_∧");
		GotoXY(x, y++);
		printf("('ω' )");
		GotoXY(x, y++);
		printf("⊂ロ⊂)");
		GotoXY(x, y++);
		printf(" し―J\n\n\n");
		break;
	case 4:
		y++;
		GotoXY(x, y++);
		printf("∧, , ∧");
		GotoXY(x, y++);
		printf("(^ ω ^)");
		GotoXY(x, y++);
		printf(" ∪　∪");
		GotoXY(x, y++);
		printf(" し─ Ｊ\n\n\n");
		break;
	default:
		printf("잘못입력하였습니다.\n\n");
		break;
	}
}

void Champion(int step)
{
	printf("#   #  ###  #  #     #   ###  ####   ##### #  # ####    #### #  #   #   #   # #### #  ###  #  #   #   #   # \n");
	printf(" # #  ## ## #  #    ###  # #  #        #   #  # #      ##    #  #  ###  ## ## #  # # ## ## ## #   #   #   #\n");
	printf(" # #  #   # #  #    # #  # #  ###      #   #### ###    #     ####  # #  ## ## #  # # #   # ## #   #   #   # \n");
	printf("  #   #   # #  #    ###  ##   #        #   #  # #      #     #  #  ###  ## ## ###  # #   # # ##   #   #   # \n");
	printf("  #   ## ## #  #   #   # # #  #        #   #  # #      ##  # #  # #   # # # # #    # ## ## # ##    \n");
	printf("  #    ###  ####   #   # #  # ####     #   #  # ####    #### #  # #   # # # # #    #  ###  #  #   #   #   # \n\n");
	Print_Steps(step, 0);
	printf("찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵\n");
	printf("찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵 　찰칵\n");
	printf("∧_∧　　　 　　∧_∧ 　　　 ∧_∧　　∧_∧　　　 　∧_∧　　　　 ∧_∧\n");
	printf("()】()】　　　()】 【()　　　 【()　　　 【()     【(　　 )    【(　　 )\n");
	printf("/　 /┘　.　 　/　 /┘.　 　　/ 　 /┘    └ ＼ ＼ 　　└ ＼ ＼　  　└ ＼ ＼\n");
	printf("ノ￣ノ　 　　ノ￣ノ 　　　　ノ￣ノ　 　　ノ￣＼ 　　 ノ￣＼　  　ノ￣＼\n\n");
	global_step = step;
}

int Player_Behavior(struct character player)
{
	int Player_Behavior;
	int x = 17, y = 11;
	int r = 0;
	printf(" 공격 목록\n 1. 잽\n 2. 스트레이트\n 3. 어퍼컷\n 4. 카운터\n");
	GotoXY(x, y++);
	printf("회피 목록");
	GotoXY(x, y++);
	printf("5. 가드");
	GotoXY(x, y++);
	printf("6. 스웨이");
	GotoXY(x, y++);
	printf("7. 위빙\n\n\n");
	while (1)
	{
		printf("행동 선택: ");
		scanf("%d", &Player_Behavior);
		if (Player_Behavior == 1)
		{
			printf("【잽】을 선택.\n\n");
			r = BH_01;
		}
		else if (Player_Behavior == 2)
		{
			printf("【스트레이트】를 선택.\n\n");
			r = BH_02;
		}
		else if (Player_Behavior == 3)
		{
			printf("【어퍼컷】을 선택.\n\n");
			r = BH_03;
		}
		else if (Player_Behavior == 4)
		{
			printf("【카운터】를 선택.\n\n");
			r = BH_04;
		}
		else if (Player_Behavior == 5)
		{
			printf("【가드】를 선택.\n\n");
			r = BH_11;
		}
		else if (Player_Behavior == 6)
		{
			printf("【스웨이】를 선택.\n\n");
			r = BH_12;
		}
		else if (Player_Behavior == 7)
		{
			printf("【위빙】을 선택.\n\n");
			r = BH_13;
		}
		else if (Player_Behavior == 2022)
		{
			printf("【화요일 8, 9 교시, 수요일 1, 2 교시】 발동\n\n");
			r = 2022;
		}
		else
			printf("잘못 입력\n");

		if (r > BH_04 || player.SP >= player.weight / 40)//공격이 아니거나 스테미너가 있을 경우
			break;
		else
		{
			printf("스테미너 부족으로 공격 불가!\n");
		}
	}
	return r;
}


void Show_Skill(int sk)
{
	switch (sk)
	{
	case BH_01:
		printf("【잽】");
		break;
	case BH_02:
		printf("【스트레이트】");
		break;
	case BH_03:
		printf("【어퍼컷】");
		break;
	case BH_04:
		printf("【카운터】");
		break;
	case BH_11:
		printf("【가드】");
		break;
	case BH_12:
		printf("【스웨이】");
		break;
	case BH_13:
		printf("【위빙】");
		break;
	default:
		break;
	}
}

void Print_Behavior(struct character at, struct character df)
{
	if (at.stat == 0)//공격일 경우
	{
		printf("%s가 %s에게 ", at.name, df.name);
		Show_Skill(at.select);
		if (at.select == BH_01 || at.select == BH_03)
			printf("으로 ");
		else
			printf("로 ");
		printf("%.1f의 데미지를 입힘!\n", at.dmg);
	}
	else//방어일 경우
	{
		printf("%s가 ", at.name);
		Show_Skill(at.select);
		if (at.select == BH_11)
			printf("로 방어!\n");
		else if (at.select == BH_12)
			printf("로 회피 시도!\n");
		else
			printf("으로 회피 시도!\n");
	}
}

void Print_Weight_Class(float w)
{
	if (w < WC_light)
		printf("《라이트》급");
	else if (w < WC_light_welter)
		printf("《라이트 웰터》급");
	else if (w < WC_welter)
		printf("《웰터》급");
	else if (w < WC_light_middle)
		printf("《라이트 미들》급");
	else if (w < WC_middle)
		printf("《미들》급");
	else if (w < WC_light_heavy)
		printf("《라이트 헤비》급");
	else
		printf("《헤비》급");
}

void Print_Points(struct character p, struct character e)
{
	int pmax = p.weight / 5, emax = e.weight / 5;
	int x = 55, y = 0;

	//플레이어 출력부분
	printf("%s     ", p.name);
	Print_Weight_Class(p.weight);
	printf("\n체력    ");
	for (int i = 0; i < pmax; i++)
	{
		if (i < p.HP) printf("■");
		else printf("□");
	}
	printf(" %.1f \n스테미너", p.HP);
	for (int i = 0; i < pmax; i++)
	{
		if (i < p.SP) printf("■");
		else printf("□");
	}
	printf(" %.1f \n", p.SP);

	//적 출력부분
	GotoXY(x, y++);
	printf("%s     ", e.name);
	Print_Weight_Class(e.weight);
	GotoXY(x, y++);
	printf("체력    ");
	for (int i = 0; i < emax; i++)
	{
		if (i < e.HP) printf("■");
		else printf("□");
	}
	printf(" %.1f", e.HP);
	GotoXY(x, y++);
	printf("스테미너");
	for (int i = 0; i < emax; i++)
	{
		if (i < e.SP) printf("■");
		else printf("□");
	}
	printf(" %.1f", e.SP);
	GotoXY(x, y++);
	printf("\n");
}