//07�� ���α׷��� ���� ��� ����
//��� �ҽ����Ͽ� �߰��Ǿ�� �� �����̰�, ���� �� ������ �� �����ϰ� �ϱ����ؼ� �ۼ�

#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define COUNT_EVENT 9	//�� ������ �̺�Ʈ ����

//ĳ���� 1�� = ������
#define CHARNUM1_CLR_GOLD 600

//ĳ���� 2�� = �տ��
#define CHARNUM2_CLR_GOLD 700
#define CHARNUM2_CLR_DEX 9

//ĳ���� 3�� = ��ſ�
#define CHARNUM3_CLR_GOLD 1000
#define CHARNUM3_CLR_HP 9
#define CHARNUM3_CLR_STR 9

//ĳ���� 4�� = ���θ�
#define CHARNUM4_CLR_GOLD 1000
#define CHARNUM4_CLR_HP 10
#define CHARNUM4_CLR_DEX 10
#define CHARNUM4_CLR_STR 10

//ĳ���� 5�� = �����
#define CHARNUM5_CLR_GOLD 1500
#define CHARNUM5_CLR_HP 10
#define CHARNUM5_CLR_DEX 10
#define CHARNUM5_CLR_STR 10

typedef struct player {		//ĳ���� ����ü
	int charnum;	//���� ĳ���� ��ȣ
	int gold;		//���
	int hp;			//ü��
	int dex;		//��ø
	int str;		//��
}player;