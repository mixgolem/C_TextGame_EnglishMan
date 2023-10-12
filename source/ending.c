//엔딩과 관련된 함수들 소스코드

#include "헤더.h"

void end_print_clear()	//게임 클리어시 시각적 효과
{

	system("cls");
	PlaySound(TEXT("happy_end.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);	//게임 클리어 BGM
	Sleep(1000);
	sys_gotoxy(16, 4);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	Sleep(100);
	sys_gotoxy(16, 5);
	printf("      _____          __  __ ______    _____ _      ______          _____       _    ");
	Sleep(100);
	sys_gotoxy(16, 6);
	printf("     / ____|   /l   |  l/  |  ____|  / ____| |    |  ____|   /l   |  __ l     | |   ");
	Sleep(100);
	sys_gotoxy(16, 7);
	printf("    | |  __   /  l  | l  / | |__    | |    | |    | |__     /  l  | |__) |    | |   ");
	Sleep(100);
	sys_gotoxy(16, 8);
	printf("    | | |_ | / /l l | |l/| |  __|   | |    | |    |  __|   / /l l |  _  /     | |   ");
	Sleep(100);
	sys_gotoxy(16, 9);
	printf("    | |__| |/ ____ l| |  | | |____  | |____| |____| |____ / ____ l| | l l     |_|   ");
	Sleep(100);
	sys_gotoxy(16, 10);
	printf("     l_____/_/    l_l_|  |_|______|  l_____|______|______/_/    l_l_|  l_l    (_)   ");
	Sleep(100);
	sys_gotoxy(16, 11);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	Sleep(100);
	sys_gotoxy(35, 13);
	sys_print("<진정한 영국의 신사가 된것을 축하합니다 !!!>\n\n");
}

void end_print_gameover() {	//게임오버시 시각적효과
	system("cls");
	PlaySound(TEXT("bad_end.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);	//게임 오버 BGM
	Sleep(1000);
	sys_gotoxy(31, 4);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	Sleep(100);
	sys_gotoxy(31, 5);
	printf("  ____    _    __  __ _____    _____     _______ ____  \n");
	Sleep(100);
	sys_gotoxy(31, 6);
	printf(" / ___|  / l  |  l/  | ____|  / _ l l   / | ____|  _ l \n");
	Sleep(100);
	sys_gotoxy(31, 7);
	printf("| |  _  / _ l | |l/| |  _|   | | | l l / /|  _| | |_) |\n");
	Sleep(100);
	sys_gotoxy(31, 8);
	printf("| |_| |/ ___ l| |  | | |___  | |_| |l V / | |___|  _ < \n");
	Sleep(100);
	sys_gotoxy(31, 9);
	printf(" l____/_/   l_|_|  |_|_____|  l___/  l_/  |_____|_| l_l\n");
	Sleep(100);
	sys_gotoxy(31, 10);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
}

void end_goldzero() //골드0엔딩
{
	Sleep(1000);
	end_print_gameover();
	sys_print("으윽... 돈이 없잖아....\n");
	sys_print("이대로 사는게 의미는 있을지 난 궁금해\n");
	Sleep(300);
	sys_print("배드 엔딩 : 거지가 되어 런던 밤거리를 돌아다니다가 얼어 죽었다.\n");
	sys_gonext();
	exit(1);
}

void end_hpzero() //체력0엔딩
{
	Sleep(1000);
	end_print_gameover();
	sys_print("어..?머리가 너무 어지러워..?\n");
	sys_print("(철푸덕..)\n");
	sys_print("몸이... 움직이질 않아....\n");
	sys_print("안...돼....\n");
	Sleep(300);
	sys_print("배드 엔딩 : 체력이 0이 되어 탈진해서 죽었다.");
	sys_gonext();
	exit(1);
}

void end_strzero() //힘0엔딩
{
	Sleep(1000);
	end_print_gameover();
	sys_print("으윽... 몸에 기운이 없어...\n");
	sys_print("걷지를... 못하겠어...\n");
	sys_print("(털썩)\n");
	sys_print("썩 좋은 인생이였다...\n");
	Sleep(300);
	sys_print("배드 엔딩 : 힘이 0이 되어 길에서 객사했다.");
	sys_gonext();
	exit(1);
}

void end_dexzero() //민첩0엔딩
{
	Sleep(1000);
	end_print_gameover();
	sys_print("(빠아아아아아앙)\n");
	sys_print("어... 트럭이 이쪽으로 오고있어...!\n");
	sys_print("피해야... 하는데.... 하는데....!!\n");
	sys_print("다리가... 무거워...\n");
	sys_print("(끼이이이이익)\n");
	sys_print("(쾅)\n");
	Sleep(300);
	sys_print("배드 엔딩 : 민첩이 0이 되어 교통사고로 죽었다.");
	sys_gonext();
	exit(1);
}

void sys_checkend(player* a) //엔딩조건을 확인후, 이에 해당된다면 출력 하고 해당되지 않는다면 실행 X
{
	if (a->gold <= 0)//골드가 0 이하
	{
		end_goldzero();
	}
	else if (a->hp <= 0)//체력이 0 이하
	{
		end_hpzero();
	}
	else if (a->str <= 0)//힘이 0 이하
	{
		end_strzero();
	}
	else if (a->dex <= 0)//민첩이 0 이하
	{
		end_dexzero();
	}
	switch (a->charnum)//캐릭터 번호에 맞게끔 클리어 결과 출력
	{
	case 1:
		if (a->gold >= CHARNUM1_CLR_GOLD)//이윤재 클리어조건
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("몇개월 전만 해도 빈곤해서 밥조차 제대로 먹을 수 없었던 이윤재.\n");
			sys_print("하지만 영국에서 살아나는 법을 익힌 후로 많은 돈을 벌었다!\n");
			sys_print("세계적인 부호가 된 이윤재!! 그의 앞날을 응원한다!!\n");
			Sleep(1000);
			sys_gonext();

			exit(1);
		}
		break;
	case 2:
		if ((a->gold >= CHARNUM2_CLR_GOLD) && (a->dex >= CHARNUM2_CLR_DEX))//손우민 클리어조건
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("방출당한 이후로 점점 지쳐가던 손우민.\n");
			sys_print("하지만 그는 절망하기는 커녕 오히려 악착같이 살아남았다.\n");
			sys_print("열심히 모은 돈으로 십자인대 수술을 하는데에 성공한다.\n");
			sys_print("이제... 다시 축구를 할 수 있을 것 같아!!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	case 3:
		if ((a->gold >= CHARNUM3_CLR_GOLD) && (a->hp >= CHARNUM3_CLR_HP) && (a->str >= CHARNUM3_CLR_STR))//기신용 클리어조건
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("어라...? 내 삶의 목표가 뭐였지... ... ...\n");
			sys_print("맞다!!!\n");
			sys_print("나 맨체스터로 돌아가야 하잖아!!!\n");
			sys_print("열심히 살던 나머지 맨체스터로 돌아가야 하는 것을 이제야 떠올린 기신용.\n");
			sys_print("잠깐... 야!!! 버스타고 가야지!!! 왜 또 다시 뛰어가는거야!!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	case 4:
		if ((a->gold >= CHARNUM4_CLR_GOLD) && (a->hp >= CHARNUM4_CLR_HP) && (a->str >= CHARNUM4_CLR_STR) && (a->dex >= CHARNUM4_CLR_DEX))//간두리 클리어조건
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("술을 좋아해 간에 이상이 생겨 축구를 그만두게 된 간두리.\n");
			sys_print("간암이 생겨 하고싶은 축구를 못해 큰 절망에 빠졌지만\n");
			sys_print("술도 끊고 모든 음식을 유기농으로 먹으며 재기를 위해 꿈꿨다\n");
			sys_print("착실히 노력한 끝에 완치에 성공한 간두리!! 건강하게만 자라다오!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	case 5:
		if ((a->gold >= CHARNUM5_CLR_GOLD) && (a->hp >= CHARNUM5_CLR_HP) && (a->str >= CHARNUM5_CLR_STR) && (a->dex >= CHARNUM5_CLR_DEX))//밥줘용 클리어조건
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("재능도 있고 노력도 했지만 자존심이 너무 강했던 밥줘용.\n");
			sys_print("누군가의 밑에서 축구를 하기에는 자존심이 허락하지 않는다!!!\n");
			sys_print("1인 축구 인플루언서가 되어 사람들에게 축구를 알려주고 싶어!!\n");
			sys_print("그는 톡틱에 영상을 올리기 시작했고, 첫 영상부터 폭발적인 조회수를 기록했다.\n");
			sys_print("감겨버린 그의 인생, 태풍처럼 다시 복귀하다니!!! 정말 대단하다, 밥줘용!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	}
}