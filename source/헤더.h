//07조 프로그램의 통합 헤더 파일
//모든 소스파일에 추가되어야 할 내용이고, 관리 및 수정할 때 수월하게 하기위해서 작성

#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define COUNT_EVENT 9	//총 구현한 이벤트 개수

//캐릭터 1번 = 이윤재
#define CHARNUM1_CLR_GOLD 600

//캐릭터 2번 = 손우민
#define CHARNUM2_CLR_GOLD 700
#define CHARNUM2_CLR_DEX 9

//캐릭터 3번 = 기신용
#define CHARNUM3_CLR_GOLD 1000
#define CHARNUM3_CLR_HP 9
#define CHARNUM3_CLR_STR 9

//캐릭터 4번 = 간두리
#define CHARNUM4_CLR_GOLD 1000
#define CHARNUM4_CLR_HP 10
#define CHARNUM4_CLR_DEX 10
#define CHARNUM4_CLR_STR 10

//캐릭터 5번 = 밥줘용
#define CHARNUM5_CLR_GOLD 1500
#define CHARNUM5_CLR_HP 10
#define CHARNUM5_CLR_DEX 10
#define CHARNUM5_CLR_STR 10

typedef struct player {		//캐릭터 구조체
	int charnum;	//고유 캐릭터 번호
	int gold;		//골드
	int hp;			//체력
	int dex;		//민첩
	int str;		//힘
}player;