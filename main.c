#include "menu.h"
#include "attack.h"
#include "defend.h"
#include "character.h"

void main()
{
	int menu_select;//�޴� ���ÿ� ����
	int iswin = 1;//�¸� �Ǵ� ����, 0�̸� �й�, 1�̸� �¸�, 2�̸� ���
	struct character player, enemy;

	srand(time(NULL));//���� �ð��� �������� ���� �ʱⰪ ����

	/*0~2 ������ ���� �� (����)*/
	int random = rand() % 3;
	printf("\n\n");

	while (1)
	{
		menu_select = Menu_Selector(iswin);// �޴� ����
		if (menu_select == 2)	break;// ����
		else if (menu_select == 0) continue;// �߸� ���ý� �ٽ�

		player = Set_Character(Character_Selector(), 0, 1);// ĳ���� ���� �� ����
		player.step = Step_Selector();// ���� ����

		enemy.step = rand() % (ST_MAX - 2) + 1;// �� ���� ����
		enemy = Set_Character(57 + rand() % 6, enemy.step, 0);// �� ����, ����Ʈ ~ ����Ʈ ���� ����

		while (1)//���� ����
		{
			// + ü��/���׹̳� ���
			// + �׸� ���
			Print_Points(player, enemy);//�÷��̾� HP/SP ���
			Print_Steps(player.step, enemy.step);//��, �÷��̾� 

			// �÷��̾� ���� or ���/ȸ�� ����
			player.select = Player_Behavior(player);
			if (player.select <= BH_04 || player.select > BH_MAX)//�����̰ų� �̽��Ϳ����� ���
			{
				player.dmg = Attack_Damage(player.select, player.weight);//������ ����
				player.SP += Attack_Stamina(player.select, player.weight);//���׹̳� -
				player.stat = 0;//���� ����
			}
			else
			{
				player.stat = 1;//������
			}

			// �� ���� or ���/ȸ�� ����
			enemy.select = Enemy_Behavior(player, enemy);
			if (enemy.select <= BH_04)//������ ���
			{
				enemy.dmg = Attack_Damage(enemy.select, enemy.weight);//������ ����
				enemy.SP += Attack_Stamina(enemy.select, enemy.weight);//���׹̳� -
				enemy.stat = 0;//���� ����
			}
			else
			{
				enemy.stat = 1;//��� ����
			}
			
			if (player.stat == 1)//�÷��̾ ��� ������ ���
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
				Print_Behavior(player, enemy);//�ൿ ���
				if (player.SP > player.maxpoints)//���׹̳� �ִ�ġ�� �Ѿ��� ���
					player.SP = player.maxpoints;//�ִ�ġ�� ����
			}
			if(enemy.stat == 1)//���� ��� ������ ���
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
				Print_Behavior(enemy, player);//�ൿ ���
			}

			if (player.stat == 0)//�÷��̾ ���� ������ ���
			{
				random = rand()%100;
				if (random>enemy.avoid - player.accuracy)//ȸ���� - ��Ȯ�� ���� Ŭ ���
				{
					if (player.select == BH_03)//�������� ���
					{
						random = rand() % 100;
						if (random < 30)//30% Ȯ����
						{
							enemy.HP -= player.dmg;
							Print_Behavior(player, enemy);//�ൿ ���
						}
						else
						{
							printf("%s�� �������� ������.\n", player.name);
						}
					}
					else//�������� �ƴ� ���
					{
						enemy.HP -= player.dmg;
						Print_Behavior(player, enemy);//�ൿ ���
					}
				}
				else
				{
					printf("%s�� ������ ������.\n", player.name);
					random = rand() % 100;
					if (random < 50)//5%Ȯ���� ī����
					{
						enemy.dmg = Attack_Damage(AS_counter, enemy.weight);
						player.HP -= enemy.dmg;
						printf("%s�� %s���� ī����!! %.1f�� �������� ����!!\n", enemy.name, player.name, enemy.dmg);
					}
				}
			}
			
			if (enemy.stat == 0)//���� ���� ������ ���
			{
				random = rand() % 100;
				if (random > player.avoid - enemy.accuracy)//ȸ���� - ��Ȯ�� ���� Ŭ ���
				{
					if (enemy.select == BH_03)//�������� ���
					{
						random = rand() % 100;
						if (random < 30)//30% Ȯ����
						{
							player.HP -= enemy.dmg;
							Print_Behavior(enemy, player);//�ൿ ���
						}
						else
						{
							printf("%s�� �������� ������.\n", enemy.name);
						}
					}
					else//�������� �ƴ� ���
					{
						player.HP -= enemy.dmg;
						Print_Behavior(enemy, player);//�ൿ ���
					}
				}
				else
				{
					printf("%s�� ������ ������.\n", enemy.name);
					random = rand() % 100;
					if (random < 50)//5%Ȯ���� ī����
					{
						player.dmg = Attack_Damage(AS_counter, player.weight);
						enemy.HP -= player.dmg;
						printf("%s�� %s���� ī����!! %.1f�� �������� ����!!\n", player.name, enemy.name, player.dmg);
					}
				}
			}

			Set_movement(&player);//ȸ����, ���߷� �ʱ�ȭ
			Set_movement(&enemy);

			if (player.HP <= 0 && enemy.HP <= 0)//�� �� ü���� 0 ������ ���
			{
				getch();
				printf("���� KO!\n");
				iswin = 0;
				break;
			}
			else if (player.HP <= 0)//�÷��̾��� ü���� 0 ������ ���
			{
				getch();
				printf("\n������������������������\n");
				printf("�� ���й�!�ڦ�\n");
				printf("������������������������\n");
				getch();
				system("cls");
				iswin = 0;
				break;
			}
			else if (enemy.HP <= 0)//���� ü���� 0 ������ ���
			{
				getch();
				if (enemy.weight >= WC_light_heavy)//���� ����Ʈ ���� �̻��̶��
				{
					system("cls");
					printf("��� ���� �����ƽ��ϴ�!\n\n");
					Champion(player.step);//���!
					getch();
					system("cls");
					iswin = 2;
					break;
				}
				else//���� ����Ʈ ���� �̸��̶��
				{
					system("cls");
					printf("\n����������������������������������������������������������\n");
					printf("   %s���� �¸�!\n", enemy.name);
					enemy = Set_Character(Weight_Up(enemy.weight), rand() % (ST_MAX - 2) + 1, 0);//�� ü�� + 1
					printf("   ���� ��� %s ����!\n", enemy.name);
					printf("����������������������������������������������������������\n");
					player = Set_Character(player.weight, player.step, 1);
					iswin = 1;
				}
			}
			getch();
			system("cls");
		}
	}
}