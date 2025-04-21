// 기본 헤더 및 정보 추가용 헤더

// ※코딩 규칙
// 변수는 소문자로, 함수는 첫 글자 대문자로 작성 (단, 약자는 대문자 가능 ex) Weight_Class -> WC)
// 이름은 마음대로 정해도 무관, 이미 적어둔것도 변경 가능
// '//' 로 쓰인 주석은 일반 주석
// '/**/' 로 쓰인 주석은 첨언 단 주석
// '// + '로 쓰인 주석은 추가 해야되는 코드

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

struct character
{
	float weight;//몸무게
	int step;//스텝
	float HP;//체력
	float SP;//스테미너
	int maxpoints;//최대 체력/스테미너
	float accuracy;//정확도
	float avoid;//회피율
	float dmg;//데미지
	int personality;//성격, 적 패턴용
	int stat;//0은 공격 1은 방어
	int select;//선택한 기술
	char name[20];//이름
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
	AS_김형준 = 2022
};

enum Defend_Skill {
	DS_guard = 0,
	DS_sway,
	DS_weaving,
	DS_counter,
	DS_MAX
};

enum Step {
	ST_inplace = 1, //제자리 스텝
	ST_forward, //전진 스텝
	ST_backward, //후진 스텝
	ST_left, //좌측으로 움직임
	ST_right, //우측으로 움직임
	ST_MAX
};

//첫번째 자리=공격/방어, 두세번째 자리 = 숫자
enum Behavior {
	BH_01 = 0b000,//공격의 첫번째 (잽)
	BH_02 = 0b001,//공격의 두번째 (스트레이트)
	BH_03 = 0b010,//공격의 세번째 (어퍼컷)
	BH_04 = 0b011,//공격의 네번째 (카운터) / 공격 마지막
	BH_11 = 0b100,//방어의 첫번째 (가드)
	BH_12 = 0b101,//방어의 두번째 (스웨이)
	BH_13 = 0b110,//방어의 세번째 (위빙) 
	BH_14 = 0b111,//방어의 네번째 (반격기) / 방어 마지막
	BH_MAX,
	BH_김형준 = 2022//이스터에그용 (원킬)
};
/*
//첫번째, 두번째 자리 = 공격, 세번째, 네번째 자리 = 방어
enum Behavior {
	BH_00 = 0b0000,//공격의 첫번째 (잽) / 방어의 첫번째 (가드)
	BH_10 = 0b0100,//공격의 두번째 (스트레이트), 가드
	BH_20 = 0b1000,//공격의 세번째 (어퍼컷), 가드
	BH_30 = 0b1100,//공격의 네번째 (카운터), 가드
	BH_01 = 0b0001,//잽, 방어의 두번째 (스웨이)
	BH_11 = 0b0101,//스트레이트, 스웨이
	BH_21 = 0b1001,//어퍼컷, 스웨이
	BH_31 = 0b1101,//카운터, 스웨이
	BH_02 = 0b0010,//잽, 위빙
	BH_12 = 0b0110,//스트레이트, 위빙
	BH_22 = 0b1010,//어퍼컷, 위빙
	BH_32 = 0b1110,//카운터, 위빙
};*/

//적 성격 (패턴 용)
enum Personality {
	P_defensive = 0,
	P_agressive,
	P_mix,
	P_random,
};

static int global_counter = 0;
static int global_step = 0;