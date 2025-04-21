// �⺻ ��� �� ���� �߰��� ���

// ���ڵ� ��Ģ
// ������ �ҹ��ڷ�, �Լ��� ù ���� �빮�ڷ� �ۼ� (��, ���ڴ� �빮�� ���� ex) Weight_Class -> WC)
// �̸��� ������� ���ص� ����, �̹� ����а͵� ���� ����
// '//' �� ���� �ּ��� �Ϲ� �ּ�
// '/**/' �� ���� �ּ��� ÷�� �� �ּ�
// '// + '�� ���� �ּ��� �߰� �ؾߵǴ� �ڵ�

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

struct character
{
	float weight;//������
	int step;//����
	float HP;//ü��
	float SP;//���׹̳�
	int maxpoints;//�ִ� ü��/���׹̳�
	float accuracy;//��Ȯ��
	float avoid;//ȸ����
	float dmg;//������
	int personality;//����, �� ���Ͽ�
	int stat;//0�� ���� 1�� ���
	int select;//������ ���
	char name[20];//�̸�
};

enum Weight_Class {
	WC_light = 60,//60
	WC_light_welter = 63,//63
	WC_welter = 67,//67
	WC_light_middle = 71,//71
	WC_middle = 75,//75
	WC_light_heavy = 81,//81
	WC_heavy = 91//91
};

enum Attack_Skill {
	AS_jap = 0, // = 0
	AS_straight, // = 1
	AS_uppercut, // = 2
	AS_counter, // = 3
	AS_MAX, // = 4
	AS_������ = 2022
};

enum Defend_Skill {
	DS_guard = 0,
	DS_sway,
	DS_weaving,
	DS_counter,
	DS_MAX
};

enum Step {
	ST_inplace = 1, //���ڸ� ����
	ST_forward, //���� ����
	ST_backward, //���� ����
	ST_left, //�������� ������
	ST_right, //�������� ������
	ST_MAX
};

//ù��° �ڸ�=����/���, �μ���° �ڸ� = ����
enum Behavior {
	BH_01 = 0b000,//������ ù��° (��)
	BH_02 = 0b001,//������ �ι�° (��Ʈ����Ʈ)
	BH_03 = 0b010,//������ ����° (������)
	BH_04 = 0b011,//������ �׹�° (ī����) / ���� ������
	BH_11 = 0b100,//����� ù��° (����)
	BH_12 = 0b101,//����� �ι�° (������)
	BH_13 = 0b110,//����� ����° (����) 
	BH_14 = 0b111,//����� �׹�° (�ݰݱ�) / ��� ������
	BH_MAX,
	BH_������ = 2022//�̽��Ϳ��׿� (��ų)
};
/*
//ù��°, �ι�° �ڸ� = ����, ����°, �׹�° �ڸ� = ���
enum Behavior {
	BH_00 = 0b0000,//������ ù��° (��) / ����� ù��° (����)
	BH_10 = 0b0100,//������ �ι�° (��Ʈ����Ʈ), ����
	BH_20 = 0b1000,//������ ����° (������), ����
	BH_30 = 0b1100,//������ �׹�° (ī����), ����
	BH_01 = 0b0001,//��, ����� �ι�° (������)
	BH_11 = 0b0101,//��Ʈ����Ʈ, ������
	BH_21 = 0b1001,//������, ������
	BH_31 = 0b1101,//ī����, ������
	BH_02 = 0b0010,//��, ����
	BH_12 = 0b0110,//��Ʈ����Ʈ, ����
	BH_22 = 0b1010,//������, ����
	BH_32 = 0b1110,//ī����, ����
};*/

//�� ���� (���� ��)
enum Personality {
	P_defensive = 0,
	P_agressive,
	P_mix,
	P_random,
};

static int global_counter = 0;
static int global_step = 0;