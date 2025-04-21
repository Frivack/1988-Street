#include "menu.h"
#include "attack.h"
#include "defend.h"
#include "character.h"

void main()
{
	int menu_select;//메뉴 선택용 변수
	int iswin = 1;//승리 판단 변수, 0이면 패배, 1이면 승리, 2이면 우승
	struct character player, enemy;

	srand(time(NULL));//현재 시간을 기준으로 랜덤 초기값 설정

	/*0~2 사이의 랜덤 값 (예시)*/
	int random = rand() % 3;
	printf("\n\n");

	while (1)
	{
		menu_select = Menu_Selector(iswin);// 메뉴 선택
		if (menu_select == 2)	break;// 종료
		else if (menu_select == 0) continue;// 잘못 선택시 다시

		player = Set_Character(Character_Selector(), 0, 1);// 캐릭터 고르고 값 설정
		player.step = Step_Selector();// 스텝 고르기

		enemy.step = rand() % (ST_MAX - 2) + 1;// 적 스텝 설정
		enemy = Set_Character(57 + rand() % 6, enemy.step, 0);// 적 설정, 라이트 ~ 라이트 웰터 수준

		while (1)//게임 진행
		{
			// + 체력/스테미너 출력
			// + 그림 출력
			Print_Points(player, enemy);//플레이어 HP/SP 출력
			Print_Steps(player.step, enemy.step);//적, 플레이어 

			// 플레이어 공격 or 방어/회피 선택
			player.select = Player_Behavior(player);
			if (player.select <= BH_04 || player.select > BH_MAX)//공격이거나 이스터에그일 경우
			{
				player.dmg = Attack_Damage(player.select, player.weight);//데미지 설정
				player.SP += Attack_Stamina(player.select, player.weight);//스테미너 -
				player.stat = 0;//공격 상태
			}
			else
			{
				player.stat = 1;//방어상태
			}

			// 적 공격 or 방어/회피 선택
			enemy.select = Enemy_Behavior(player, enemy);
			if (enemy.select <= BH_04)//공격일 경우
			{
				enemy.dmg = Attack_Damage(enemy.select, enemy.weight);//데미지 설정
				enemy.SP += Attack_Stamina(enemy.select, enemy.weight);//스테미너 -
				enemy.stat = 0;//공격 상태
			}
			else
			{
				enemy.stat = 1;//방어 상태
			}
			
			if (player.stat == 1)//플레이어가 방어 상태일 경우
			{
				switch (player.select)
				{
				case BH_11 :
					Guard(&enemy.dmg, &player.SP);
					break;
				case BH_12 :
					Sway(&player.avoid, &player.SP);
					break;
				case BH_13 :
					weaving(&player.accuracy, &player.SP);
					break;
				default:
					break;
				}
				Print_Behavior(player, enemy);//행동 출력
				if (player.SP > player.maxpoints)//스테미너 최대치가 넘었을 경우
					player.SP = player.maxpoints;//최대치로 설정
			}
			if(enemy.stat == 1)//적이 방어 상태일 경우
			{
				switch (enemy.select)
				{
				case BH_11:
					Guard(&player.dmg, &enemy.SP);
					break;
				case BH_12:
					Sway(&enemy.avoid, &enemy.SP);
					break;
				case BH_13:
					weaving(&enemy.accuracy, &enemy.SP);
					break;
				default:
					break;
				}
				if (enemy.SP > enemy.maxpoints)
					enemy.SP = enemy.maxpoints;
				Print_Behavior(enemy, player);//행동 출력
			}

			if (player.stat == 0)//플레이어가 공격 상태일 경우
			{
				random = rand()%100;
				if (random>enemy.avoid - player.accuracy)//회피율 - 정확도 보다 클 경우
				{
					if (player.select == BH_03)//어퍼컷일 경우
					{
						random = rand() % 100;
						if (random < 30)//30% 확률로
						{
							enemy.HP -= player.dmg;
							Print_Behavior(player, enemy);//행동 출력
						}
						else
						{
							printf("%s의 어퍼컷이 빗나감.\n", player.name);
						}
					}
					else//어퍼컷이 아닐 경우
					{
						enemy.HP -= player.dmg;
						Print_Behavior(player, enemy);//행동 출력
					}
				}
				else
				{
					printf("%s의 공격이 빗나감.\n", player.name);
					random = rand() % 100;
					if (random < 50)//5%확률로 카운터
					{
						enemy.dmg = Attack_Damage(AS_counter, enemy.weight);
						player.HP -= enemy.dmg;
						printf("%s가 %s에게 카운터!! %.1f의 데미지를 입힘!!\n", enemy.name, player.name, enemy.dmg);
					}
				}
			}
			
			if (enemy.stat == 0)//적이 공격 상태일 경우
			{
				random = rand() % 100;
				if (random > player.avoid - enemy.accuracy)//회피율 - 정확도 보다 클 경우
				{
					if (enemy.select == BH_03)//어퍼컷일 경우
					{
						random = rand() % 100;
						if (random < 30)//30% 확률로
						{
							player.HP -= enemy.dmg;
							Print_Behavior(enemy, player);//행동 출력
						}
						else
						{
							printf("%s의 어퍼컷이 빗나감.\n", enemy.name);
						}
					}
					else//어퍼컷이 아닐 경우
					{
						player.HP -= enemy.dmg;
						Print_Behavior(enemy, player);//행동 출력
					}
				}
				else
				{
					printf("%s의 공격이 빗나감.\n", enemy.name);
					random = rand() % 100;
					if (random < 50)//5%확률로 카운터
					{
						player.dmg = Attack_Damage(AS_counter, player.weight);
						enemy.HP -= player.dmg;
						printf("%s가 %s에게 카운터!! %.1f의 데미지를 입힘!!\n", player.name, enemy.name, player.dmg);
					}
				}
			}

			Set_movement(&player);//회피율, 명중률 초기화
			Set_movement(&enemy);

			if (player.HP <= 0 && enemy.HP <= 0)//둘 다 체력이 0 이하일 경우
			{
				getch();
				printf("더블 KO!\n");
				iswin = 0;
				break;
			}
			else if (player.HP <= 0)//플레이어의 체력이 0 이하일 경우
			{
				getch();
				printf("\n┌──────────┐\n");
				printf("│ ☆패배!★│\n");
				printf("└──────────┘\n");
				getch();
				system("cls");
				iswin = 0;
				break;
			}
			else if (enemy.HP <= 0)//적의 체력이 0 이하일 경우
			{
				getch();
				if (enemy.weight >= WC_light_heavy)//적이 라이트 헤비급 이상이라면
				{
					system("cls");
					printf("모든 적을 물리쳤습니다!\n\n");
					Champion(player.step);//우승!
					getch();
					system("cls");
					iswin = 2;
					break;
				}
				else//적이 라이트 헤비급 미만이라면
				{
					system("cls");
					printf("\n┌───────────────────────────┐\n");
					printf("   %s에게 승리!\n", enemy.name);
					enemy = Set_Character(Weight_Up(enemy.weight), rand() % (ST_MAX - 2) + 1, 0);//적 체급 + 1
					printf("   다음 상대 %s 등장!\n", enemy.name);
					printf("└───────────────────────────┘\n");
					player = Set_Character(player.weight, player.step, 1);
					iswin = 1;
				}
			}
			getch();
			system("cls");
		}
	}
}