//Visual C에서 게임의 틀을 구성하는 함수들 소스코드

#include "헤더.h"


void sys_gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//문자열을 말 하는 것 처럼 출력하는 함수
void sys_print(char* print) {
	Sleep(200);
	int num;
	num = strlen(print);
	for (int i = 0; i < num; i++) {
		printf("%c", print[i]);
		Sleep(1);
	}
	Sleep(100);
}

//점을 출력하며 로딩효과를 주는 함수
void sys_printdot() {
	Sleep(500);
	for (int i = 0; i < 3; i++) {
		printf("· ");
		Sleep(500);
	}
	Sleep(500);
	printf("\n");
}

//선택 번호를 입력받는 함수
int sys_select() {
	int select = 0;
	sys_print("\n<당신의 선택은?> ");
	getch();
	scanf("%d", &select);
	printf("\n");
	return select;
}

//다시 선택 번호를 입력받는 함수
int sys_reselect()
{
	int select = 0;
	sys_print("\n<잘못된 입력입니다. 다시 선택하세요.> ");
	rewind(stdin);
	scanf("%d", &select);
	getch();
	printf("\n");
	return select;
}

//캐릭터의 능력치를 말해주는 함수
void sys_playerstat(player* a) {
	sys_print("\n현재 캐릭터의 능력치는 다음과 같습니다.\n");
	printf("[골드]%4d  [체력]%3d  [민첩]%3d  [힘]%3d\n\n", a->gold, a->hp, a->dex, a->str);
	Sleep(2000);
}

//캐릭터의 능력치를 출력하는 함수. 이벤트 진행 시 상단에 표기
void sys_printstat(player* a) {
	sys_gotoxy(0, 0);
	printf("┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n│   ");
	if (a->charnum == 1) {
		printf("[이윤쟤]");
	}
	else if (a->charnum == 2) {
		printf("[손우민]");
	}
	else if (a->charnum == 3) {
		printf("[기신용]");
	}
	else if (a->charnum == 4) {
		printf("[간두리]");
	}
	else {
		printf("[밥줘영]");
	}
	printf("  [골드]%4d  [체력]%3d  [민첩]%3d  [힘]%3d    │\n", a->gold, a->hp, a->dex, a->str);
	
	if (a->charnum == 1) {
		printf("│   달성목표: [골드]%4d                                   │\n", CHARNUM1_CLR_GOLD);
	}
	else if (a->charnum == 2) {
		printf("│   달성목표: [골드]%4d             [민첩]%3d             │\n", CHARNUM2_CLR_GOLD, CHARNUM2_CLR_DEX);
	}
	else if (a->charnum == 3) {
		printf("│   달성목표: [골드]%4d  [체력]%3d             [힘]%3d    │\n", CHARNUM3_CLR_GOLD, CHARNUM3_CLR_HP, CHARNUM3_CLR_STR);
	}
	else if (a->charnum == 4) {
		printf("│   달성목표: [골드]%4d  [체력]%3d  [민첩]%3d  [힘]%3d    │\n", CHARNUM4_CLR_GOLD, CHARNUM4_CLR_HP, CHARNUM4_CLR_DEX, CHARNUM4_CLR_STR);
	}
	else {
		printf("│   달성목표: [골드]%4d  [체력]%3d  [민첩]%3d  [힘]%3d    │\n", CHARNUM5_CLR_GOLD, CHARNUM5_CLR_HP, CHARNUM5_CLR_DEX, CHARNUM5_CLR_STR);
	}
	printf("┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n\n");
}

//키 입력을 받기 전 까지 화면을 멈추는 함수
void sys_gonext() {
	printf("\n");
	printf("┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("│ 계속하려면 아무 키나 입력하세요  │\n");
	printf("┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n\n");
	getch();
	while (!_kbhit()) {

	}

	system("cls");
}

//이벤트의 개수에 따라 랜덤한 순서를 생성하는 함수
void sys_random_event_occur(int ran[]) {
	srand((int)time(NULL));
	int i = 0;
	for (i = 0; i < COUNT_EVENT; i++) {
		ran[i] = rand() % COUNT_EVENT;
		for (int j = 0; j < i; j++) {
			if (ran[i] == ran[j]) i--;
		}
	}
}

//랜덤 순서로 배열된 이벤트를 실행하는 함수.코드를 한 번 실행할 때 마다 그 순서에 맞는 이벤트가 실행된다.
int sys_playevent(int eventcount, int ran[], player* a) {
	switch (ran[eventcount]) {
	case 0:	//도넛가게 이벤트
		event_donut(a);
		break;
	case 1:	//뒷골목 이벤트
		event_street(a);
		break;
	case 2:	//도를 아십니까? 이벤트
		event_doyouknow_do(a);
		break;
	case 3:	//버스킹 이벤트
		event_busking(a);
		break;
	case 4:	//첼블루VS갱스날 승부예측 이벤트
		event_sportstoto(a);
		break;
	case 5:	//1달러만 이벤트
		event_1dollar(a);
		break;
	case 6:	//별똥별 이벤트
		event_star(a);
		break;
	case 7:	//팔씨름 이벤트
		event_armwrestle(a);
		break;
	case 8:	//한국VS영국 승부예측 이벤트
		event_engvskorea(a);
		break;
	}
	eventcount++;
	return eventcount;
}

//캐릭터 선택 함수.
void sys_selectplayer(player* a) {
	int select = 0;
	system("cls");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("  ____ _   _    _    ____     _    ____ _____ _____ ____      ____  _____ _     _____ ____ _____ \n");
	printf(" / ___| | | |  / l  |  _ l   / l  / ___|_   _| ____|  _ l    / ___|| ____| |   | ____/ ___|_   _|\n");
	printf("| |   | |_| | / _ l | |_) | / _ l| |     | | |  _| | |_) |   l___ l|  _| | |   |  _|| |     | |  \n");
	printf("| |___|  _  |/ ___ l|  _ < / ___ | |___  | | | |___|  _ <     ___) | |___| |___| |__| |___  | |  \n");
	printf(" l____|_| |_/_/   l_|_| l_/_/   l_l____| |_| |_____|_| l_l   |____/|_____|_____|_____l____| |_|\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	Sleep(500);
	sys_print("캐릭터를 선택하세요.\n");
	sys_print("각 캐릭터들은 다른 능력치를 가지고 시작합니다.\n");
	sys_print("그리고, 당신의 선택에 따라 게임의 클리어 조건 또한 달라집니다.\n\n");
	sys_print("[1]골키퍼 이윤쟤(EASY)\n[2]공격수 손우민(NORMAL)\n[3]미드필더 기신용(HARD)\n[4]수비수 간두리(VERY HARD)\n[5]공격수 밥줘영(HELL)\n");
	sys_print("\n선택하고 싶은 캐릭터의 숫자를 입력하세요.\n");
	select = sys_select();
	while (1) {
		if (select == 1) {
			system("cls");
			a->charnum = 1;
			printf("                                                       . ^ ~7 ? YYYYJJ#?s \n");
			printf("                                                   .^?PBB#BBGB##&####&G5?~:                                   \n");
			printf("                                                 :?PB#&####&##&&&&@@@@@&##B5?~.                               \n");
			printf("                                               :JB######B#&&&&&&&@@@@@@@@@@&&#GJ^                             \n");
			printf("                                             .?G##GPBP5YY5YY5BBGBB##&#&&@@@@@@&&#J:                           \n");
			printf("                                            :P##GJ7JJ7!~!!!!!JPYYY5G#G5P#&@@@@@&&@#7                          \n");
			printf("                                            5&#Y!^^^~~~~~~~~~!7?77??YPP5PB&@@@@&&@&@5.                        \n");
			printf("                                           ^#&5~^^^^::::^^^:^^~!!7777??JYPB&&&&@@@@@@P                        \n");
			printf("                                           ^#B!^^~777!~~^^^~~!7?????7??JYYP#@@@@@@@@@@?                       \n");
			printf("                                           .G?~!77?Y55Y7^~?Y5P5YJ???J?JJYY5B&@@@@@@@@@G                       \n");
			printf("                                            ~~!JJ7PGPJ7~^!J55J5YYP5555YJJYYP#@@@@@@@@@P                       \n");
			printf("                                            ::^~~!7!!^^^~7?J?JJ7J55PP5YYYYY5G&@@@@@@@@~                       \n");
			printf("                                           .:..:^^:::::^!??77~~!77!!!!?JYYY5B&@@@@@@@5                        \n");
			printf("                                           .^:.:~~~~!~!7J?7?7^^^^^^^~!?JJYYP#@@&&&@@G.                        \n");
			printf("                                           :~~~7?!^!J7YGBBG5J7^^~~!7?JYYYY55B#GGGGGJ.                         \n");
			printf("                                           ^777!~^~~^~!7?JJ?7777?JJYY55555PPP5GPYB!                           \n");
			printf("                                           ^?7!!!777!!7?JYYYJ?7?Y5PPPP555PPPYJGP5?                            \n");
			printf("                                           ^77!~^:::^^~!7?JYYJJYY5PPP5555555YJJ57.                            \n");
			printf("                                           :7!~^^^~!!7?JJJJJ??JY55PP5555555YJ?7^                              \n");
			printf("                                            !!~^^~~777JJJJJJJJYY555PPP5555PPY^                                \n");
			printf("                                            .!~^^~7!!?JY??JJJJJJY55P5555555?                                  \n");
			printf("                                             .!!!!!!7J????JJJYYYY555555P5YY:                                  \n");
			printf("                                              :7?JYY55555P55555555PPP555JJ?                                   \n");
			printf("                                              .~77JYPPPPPPPPP555PP5555YJJY!                                   \n");
			printf("                                              :~~!7?J5PPPPPP55555555YYYJJY~                                   \n");
			printf("                                              ^~~~~~!?5PPPPP5555555YYYYJJYJ^^.                                \n");
			printf("                                             .~~~~~^~!?JJY555YYYYYYYYYYJY5BP#B7.                              \n");
			printf("                            .....::::::^^^::7G7~~!~~!!7JY5555YYY555YYYYYYB#BB@P^^..                           \n");
			printf("                         !5B#BBGGGPPPPPPYY5Y5BJ!~~~!7?Y555555YYY555YYYY5G###&#!~^::::.                        \n");
			printf("                        .7P&&&BPP5J?JJP##GY55Y5PY7~!7J5555YYYYJJJJJJYY5B##&@B!^^::::::::...                   \n");
			printf("                          ~PGPBBB###G5JYG#BJJ?55?JY77?JJYY55YJ?77??JYPB#&&#Y~^^:::::::.......                 \n");
			printf("                         ~!7557?YY7P&&B555PGGJ7JJ?JPJJYY5555J?7??JYPB##B57^::^::::...............             \n");
			printf("                      ..^?77!7?5GGY^#@&GP7!?GPY5G5GPYYJYYYYJ?77?YPB#B5?^:^^::::::..................         \n\n");
			sys_print("러브풀FC의 월드클래스 골키퍼인 이윤쟤\n");
			sys_print("유럽 최정상 팀을 가리는 챔피언스 리그 결승전, 치명적인 실수로 5골을 헌납한다.\n");
			sys_print("극성 러브풀FC 팬들로부터 살해 협박을 받게 되는 이윤쟤. 가까스로 러브풀FC로부터 도망친다.\n");
			sys_print("계좌도 정지당하고 신용등급도 순식간에 불량으로 떨어진 그... ");
			sys_print("하루하루가 너무 빈곤하고... 무엇보다 굶어죽게 생겼어..!!\n");
			sys_print("\n");
			a->gold = 10;
			a->hp = 8;
			a->dex = 8;
			a->str = 8;
			break;
		}
		else if (select == 2) {
			system("cls");
			a->charnum = 2;
			printf("                                                         .........:^.                                                   \n");
			printf("                                                    ....^:.::::^^:^7?~^^:.                                              \n");
			printf("                                                 ......::~!!~~~^...:~7?!~~^::.                                          \n");
			printf("                                               ..:^:...:^:^:...::::..:~^^^^~~^::.                                       \n");
			printf("                                              ..::.....~~.  ..::::....::..:::^^~~~.                                     \n");
			printf("                                             .....:.:.::...............::. .....:~~.                                    \n");
			printf("                                            .. .....::...................:......:^^^.                                   \n");
			printf("                                            ..  ........:. ......................:....                                  \n");
			printf("                                            .:   ^7~!!^^.....:::::.::......... ......                                   \n");
			printf("                                             .. .?PPY77~7!:^^::::^:...........   ...                                    \n");
			printf("                                                .JPJ~~~7GY~^.:.    ..   ..        ..                                    \n");
			printf("                                                ^GG5?!7J7~:. . .. .:.  .......   ..                                     \n");
			printf("                                                ^YPB#BBG?:  :^!J^  ^^.. ....  ...                                       \n");
			printf("                                               .5PYYYPGGG5JJYPPY7!7YYJ~..:.:!77?7.                                      \n");
			printf("                                               7BPPP5YY55YY5YJ7!?YPPPP5!.:7YY??J7^                                      \n");
			printf("               .:^::::.                       :GBP5YY5PG5JY5P555YY55PPP?:7PPJ?JJ?.                                      \n");
			printf("          .:^!7YYPP55P5YYJ?7!~~^:.            ^BBBBBGGGGYJY55PP555PPPPPY?YP5Y5YJ^                                       \n");
			printf("     .:^^~!7??JYY55JYY5PPPP5BGBGPGY!^...      .GGBBBGGGGPYYGBBGGGGPPPP5YY555YJ!.                                        \n");
			printf("  ..::^~~!!777?JYYY?!~^!PGY?JGBGPYG#BP5PP55YJJ?PGGPJYGGGP5Y?5GGPPPPP555YY55~.                                           \n");
			printf("  ..::^^~~!!77?JJ?JY7^!JP5J^~PG5Y~~BB5?!7?JJJYGPJJ?J5P5J777?JJJYYYY555YYY5P.                                            \n");
			printf("  ...::^^^~~!7????77!~!J?77?G5?!^7GB5~       ^P55YYJ?Y5J??JJ?7~?JJJY5YYYY5P.                                            \n");
			printf("  ...::::::^^^:::.      ^!!7~~~!JY?~.  .!7??^.?P55JY5J5GG5J?7!?Y5JJYYYYY55P?                                            \n");
			printf("   ...::^^^.   ...:^^~~~77J7~7??J~. .::5@@@@&J:?Y5P555JJJ??JYYYYYJJYYYY55PPB^!^..                                       \n");
			printf("  ....:::~^^~7?JYYPPGBB##&&7:!5GGP57:.^B&&&#@&77555PPPY7!77?JYYYYYYYYYY5PPG5~P~.^?!~!~.                                 \n");
			printf("   ...:::^~~!!77??JY5YYGGB5....?GPPG?:Y&B&&#@&#B#G5PPPPP5JJYYYYYYYJJJY55PG5~57 !B&&&@@B!~~:^^:..                        \n");
			printf("   ....:::^~~~!!77??JYJY5P?.... .7JJ5GBGBBGGPPGGPGGPPPPPPPJ77?????JJY5PGGJ7P!.Y&&&&&@&@@@BGBG?~^::..                    \n");
			printf("   ....::^^~!!777?7???J?JY!   ^!?J5PPP5YYJY5PPPPGGPPPPPGG#&P~~~7JY55PP5J?JY~!B@@&&##&@@@@@#!:^^^::^~~~:                 \n");
			printf("   ..::^^~~!7??JJYYY555P5G7  :PPYYYYY5YYYYPGGPGGGGGPPG&@@@@@#Y?JYYJ??77??J5#@@&&&&&@@@@@@&!:^:::^^~!7?J?:               \n");
			printf("  ...::^^~~!77??JYYY5PPPP#7 ....7BBGGBBGGG55PPGGPGPG#@@@@@@@@@&Y!7???J5PB&&&###&@@@@@@@@@Y:^:^^^^^~!7??JJ:              \n");
			printf("  ....::^^~!!77??JY555PPPB7 .. ?###BBB##BB55555PPPP&@@@@&&@@@@@@&B?YB#&&&####&@@@@@@@@@@@!.:^^!JPB#&&B###P.             \n\n");
			sys_print("국내에서 차엄근 축구상을 수상한 유망주! 공격수인 손우민\n");
			sys_print("모두의 기대를 한 몸에 받고 잉글랜드의 도둑넘 호스퍼 유스팀에 입단하게 된다.\n");
			sys_print("하지만... 훈련 중 팀원의 거친 태클로 전방 십자인대를 파열하는 부상을 입는데...\n");
			sys_print("치료를 제때 받지 못하여 팀으로부터 방출당하게 된다.\n");
			sys_print("국내로 다시 돌아갈 순 없다!! 군대 가기 싫단 말이야...ㅠㅠ\n");
			sys_print("어떻게든 다리를 치료해서 다시 잉글랜드에서 축구를 하고 싶어!\n");
			a->gold = 100;
			a->hp = 5;
			a->dex = 5;
			a->str = 5;
			break;
		}
		else if (select == 3) {
			system("cls");
			a->charnum = 3;
			printf("                                                   ..::::::^~!~~^:.                                                     \n");
			printf("                                            ....:::::^^:::^^~77!!!~^::.                                                 \n");
			printf("                                           .:^^~^~~^::~^::::^^!777777!!~:                                               \n");
			printf("                                         .:~~^^^::^~^::^~~::::::^!7!!7??7~.                                             \n");
			printf("                                        .^~!~~^::^^::^:.:^^^:^^^::^!!!77!!~:                                            \n");
			printf("                                        ^~~^~!^::^^:.:^:..:::^^^~^::~~!??!~^.                                           \n");
			printf("                                       :^~^^~^:^^^^^^:::::..:::^^~^:^^^~JJ!^:                                           \n");
			printf("                                      .^^~~~^^~^::~~^~^::~^::^^^^~~:^^^^~?7^^:                                          \n");
			printf("                                      :^^~^:^^::^~^^:^^^^^~!^^^^^:^^:^^^^~!!~^                                          \n");
			printf("                                      .::^:.:::~!!~:^!!::~7J7^^^~~^^::::::~7~^.                                         \n");
			printf("                                       ..::.~^.:^^^:~77:~?JJ7~^^^!7!~:..::~^^^.                                         \n");
			printf("                                         ..~?!~!!!~^^~!!!7!~~~~!!77?J?~.::^^^:.                                         \n");
			printf("                                          :?J7~~^:^!!!7Y5J7!~^^77?JYY5Y!:::^:                                           \n");
			printf("                                          ^JJJ???7?JJJJPP55Y?77YYYY5PPPY~^^!^                                           \n");
			printf("                                          :YYY5YYYY5YJPBGGGGP555GGBBBGP5~~JJ^                                           \n");
			printf("                                          :J?JJ5PPPYJYPGGGGPPGGGGGPPPPPY7J7?^                                           \n");
			printf("                                          ^J77?JY5YJ!^~~~!JP55PP55YJYYYJYP5?                                            \n");
			printf("                                          .!7!!7?JYYJ?JJYY5GGP5YJJJ??JYY5PY^                                            \n");
			printf("                                            .!!!7?JJ?7???JY5PPPYYJJJJY5?^:                                              \n");
			printf("                                             ^?777!^::::^^^~7?55YYYYYY5:                                                \n");
			printf("                                              !?!!77!!7777??YYYJJY55557                                                 \n");
			printf("                                              :?7!7??77777JY5555YYYYJJ:                                                 \n");
			printf("                                              :?7!!??JYYYY5555YJ?777JJ.                                                 \n");
			printf("                                              :J77~~~~~~~~~~!~~~~!?YP?.                                                 \n");
			printf("                                              :J???7~^:::::^^~!7?Y5PG!                                                  \n");
			printf("                                              ^YJ???7!~~~~!!7?JY55PPG?:    ..                                           \n");
			printf("                                         ..:..?Y?????!~~!77?JJY555PPGGG57^.:~.                                          \n");
			printf("                                     .:^^^^::~5JJJJJ?7!~!7?YYY55PPPPGGBBB5~:^~^::.                                      \n");
			printf("                               ..:^~!!~^:^~:.^5YJJYJ?777??JYY55555PPGGBG?^::^^~!~!!~^^:.                                \n");
			printf("                          .:::^^^~!!!~^^^~!~:.75YJJYJ7!!77JYYYYYY5PGBP?^:^!77^~~~7????!~^:.                             \n");
			printf("                     ..^~!!!^^^^~7!7~^^^!7!!^..J5JJY5J777?JY5YY55GGP7^:!7??7~^~^~????7~^~~!7^.                          \n\n");
			sys_print("맨체스터 레드의 유망주, 미드필더 기신용\n");
			sys_print("팀의 대선배인 왁지송 선수를 롤 모델로 삼고 열심히 훈련하는 기신용.\n");
			sys_print("미드필더의 기본은 체력이지! 매일같이 체력단련을 위해 개인 러닝을 뛴다.\n");
			sys_print("휴... 오늘은 상당히 많이 달린 것 같은데...\n");
			sys_printdot();
			sys_print("근데 여기는..어디지? 런던?\n");
			sys_print("큰일났다..!!\n");
			sys_print("러닝하려고 나와서 지갑이랑 스마트폰도 다 없잖아?!\n");
			sys_print("런던과 맨체스터는 294.51km나 떨어진 위치....\n");
			sys_print("어떻게든 살아서 맨체스터로 돌아가야 한다...!!\n");
			a->gold = 16;
			a->hp = 3;
			a->dex = 6;
			a->str = 6;
			break;
		}
		else if (select == 4) {

			system("cls");
			a->charnum = 4;
			printf("		                        .::^~~~~^:.\n");
			printf("                                     :~?JYYYYYYYYYJ?7!^:                                                                \n");
			printf("                                  .~JPGGGP55YYYJJJJJ?JJ??!:                                                             \n");
			printf("                                 ^J5GBBBBGP5YYYJ???????J5PP7.                                                           \n");
			printf("                                ^YPPGB###BGP555YJ???JJJYGBBP?.                                                          \n");
			printf("                               .?5PPPPGGGGGG5YJJJ?????J5PGBPY!                                                          \n");
			printf("                               ~5PP5PPPPPPP55YJ????7??JYY55YJJ^                                                         \n");
			printf("                               ?PPP55PPPPPP55YJJ?JJ???JJ?JYYYY7                                                         \n");
			printf("                               ?PPPPP5YJ7~^^^^~77?7~^:::^!??Y5?                                                         \n");
			printf("                            .^^JPPPPP5YJ?7!^:::^~~~^:::^~!?YY5?.                                                        \n");
			printf("                            ^7GP5PPGP5J7!~:..:!?J?7~:...^!~?555Y~                                                       \n");
			printf("                            :JGY5PPGGGPPY?!~!JPPG5557~~~7YY5P55Y.                                                       \n");
			printf("                             77JBPPPGGGGPYJYYPPPGYGBP??JJ5PGG5Y7                                                        \n");
			printf("                             ~5GP555PPP55Y???5GBB5PG5!!7?Y55Y5Y!                                                        \n");
			printf("                             .?YJJ55YYYJ?7!!7PP5Y??YY7^~7?JJYY?^                                                        \n");
			printf("                                .:J5Y?7!~~^~J7^:::^^~!^:~?JJJ~                                                          \n");
			printf("                                  ~YYJ???77JY55J?77?JJ7^!JYYJ:                                                          \n");
			printf("                                  .?YYYYYYJYYJ7~~~~~~7J7!JYYY7^:.....                                                   \n");
			printf("                                   7JJJY5YJ?^..::^~^..7J?YYJJ7?^:::::^^::..                                             \n");
			printf("                                   ^YJJJJJ?JJJJYJJ?77?JJJYY?7^^:..::::^^::^^^:.                                         \n");
			printf("                                   :JJJJJJJ?7!~~^^^^~???JY?~:^^:.....:::^:::^~!!~^:                                     \n");
			printf("                              .:^!7?YYJJJJYYYJJ?!^:^!??JJ7^:^^:...:::..:::::^^~!7777!^:.                                \n");
			printf("                          .:~7?J?77?!YYJYY?77???!~^^~!77~::^^:...::^:..:::::^^~!7777???7!^.                             \n");
			printf("                      .:!7??JJ?77?Y!.75Y5PPY!:::...::^^^::^:...:..:^::::::^^~~!!7!7!77????7!^.                          \n");
			printf("                   .^!?JJJ???77?YJJ!:^Y555P5J!^...::^::::::...:...::::::::^~!!!!777!77!!~^~~^..                         \n");
			printf("                 :7JJ??????77?YYJJJ?!^?555YJ7~::.....::::...:....::::::::^~!!777!777!~^^^^^!!:..                        \n");
			printf("                ~????77?J??JYYYYYYJJ7!!!JYJY?^......:::..........:::::^~~!!7777777!~^^^^^^^~!!:....                     \n");
			printf("              .~JJ???JJJJYYYYYYYJJYJJ?7~^!JJ7^::::::............::::^~!!777777777~^^^^^^^^~7??7^:....                   \n");
			printf("             .^!JJ?JJJJJJJ?????????JJJJJ7~!!~~~~~^^^^~~:.......::::^~!!777777?7!^:::::::~!77?JJ?~^::::                  \n");
			printf("            .^~?YJJJJ?7!~~~~!777!!~~~~~~~!!!!!~~^~~!!~::~7!^:::^~~~~~!!!777777~::::::::^!777???J?!^^^^.                 \n");
			printf("            :^^7J?7!~~~~~!7JJ??????77777?J?7~^^!777~^:^!7777!!!!7!~!7!!777!!!~^::...::^~~~!7777?JJ!~^::.                \n");
			printf("           ^~::~7!!!!!!7???7!~~~!!!7?JJJ7!~~!?JJ?!^~^~!!77??????77!!7!!7!~~!~^::.....:^^^~~~!!777JJ7~^^^.               \n");
			printf("           ~~..:~~!!!!7!~~^~!!7!!7???7!~~!?YYJ?!^:~7~!!?JJJYYPJ7??7!!!7!~~~!~:.:.....^^^^^^^~~!7!7JJ?~^^^:              \n");
			printf("           ~~.:.:^~^^^^^^~7???JJJ?!~~!7????!~^:::~77~!7?J7YBGP57!?J7^!!~~~!~^..::...:^^^^^^^^^^!7~7JJ?!~^~:             \n\n");
			sys_print("아버지를 닮아 뛰어난 피지컬을 가진 수비수 간두리\n");
			sys_print("엄청난 주력과 몸싸움으로 상대 공격수들을 혼란하게 만든다!!\n");
			sys_print("하지만 그는 치명적인 단점이 있었는데, 술을 너무 사랑한다.\n");
			sys_print("훈련을 마칠 때 마다 매일같이 보드카를 들이킨 나머지...\n");
			sys_print("간암이 발생하여 건강한 간을 이식받거나, 자연치유를 바래야 하는 절망적 상황..!\n");
			sys_print("이 모든게... 간 때문이야..?\n");
			sys_print("간 이식을 받든가, 자연치유가 되든가 어떻게 해서라도 건강해져야 한다!\n");
			a->gold = 100;
			a->hp = 3;
			a->dex = 5;
			a->str = 5;
			break;
		}
		else if (select == 5) {
			system("cls");
			a->charnum = 5;
			printf("                                                         .J?!!7?JY?~~~~~!?7??7???7!!:::..  ..                         \n");
			printf("                                                           :Y??~!~^^:^~~!!!!7J??JYJ!?JJ~^!!~^!^.                        \n");
			printf("                                                           :JJ77~!~:~7!?J!^^^Y?~^~^~P!!~~::!J?^:                        \n");
			printf("                                                       :~J^^!~:777J7~^:7~!!~!!::?!:75!J!~^::J7!?7~:.                    \n");
			printf("                                                       ~Y7~7~.:~~:75^.:~^^~!^:::!7::J??J~!^7GJ~75J7!^:                  \n");
			printf("                                                        7J!7!!^^7~~!.^^~!!^~!:~::~^ ^?~:.^7^!?J~5P?7?7~                 \n");
			printf("                                                      .!J!!JJ?^~~^~!!~^!~:...:^~^::..:::..!~!~?~?PY7577~                \n");
			printf("                                                      :!?JY5J?~!~^:7~^:~...^^.:~:::.:^:.:::^.^!:!55Y?577                \n");
			printf("                                                     .~~?#PP57J77~^^:^~: ..:^^.:::^:::::::.^:~~.:?JJ?75!.               \n");
			printf("                                                     :?YPGJ5J^^!?7^:^~!^...:::.:::.:::.:....:^~^:^!!7!77!^              \n");
			printf("                                                      7&BYY~~!^!J57^^J?J^......... ....:.......::.^~^7~!77:             \n");
			printf("                                                      !GBG5??5Y???J5????7~:.::..... .......... ....::.:~~.              \n");
			printf("                                                      ~YPBJJGGP5YJJJ5JJY?J7::.::.....~~~^...   .......~!.               \n");
			printf("                                                      .?GG?!GYJJJJY5YY5P5P5~..::.. ^JJ5Y7J:.....:::^~~77                \n");
			printf("                                                      ~GG55PB##B#BP5555PPP5!::::^:!YJ?JP?7^:.:::::~?!~!.                \n");
			printf("                                                    .?BG555B@&&&#GG55PP555Y~^^~J?YGJJ7~P5!.:.:.::^~~!.                  \n");
			printf("                                                    ^B55P55YP&#BGP55YYYYYYJ?YJJ55YPPPJ?5?. ::::^~^::.                   \n");
			printf("                                                     :7Y?7??7GGP5YYYYYYYY5555YY55YY5555Y^ .::^:.~:                      \n");
			printf("                                                      ~#BGGPP5P5J?JJJYYYY55555555??JYP5?^..^::^7^                       \n");
			printf("                                                      :?GP55Y!YPJYJJJJJJYYY55555YY5PPP557::^~!JJ.                       \n");
			printf("            ~?:                                        7#BBP5PB5YJ?JJJJJJJYYYYYY55P5PP55?!^^~77?.                       \n");
			printf("           7BBJ                                        ?GPP55GPYY????????JJJJJJJYY5PPP55Y?~~^::~.                       \n");
			printf("           JBPB7                                       .P#BBG5YPY?J??????????JJJYY5GGP5Y5PPBG^                          \n");
			printf("           ^GP5GY^                                     ^B&&BGPPY?JJ????77777?JJJJY5GG55YY5B@@5                          \n");
			printf("         :!JPGGGGP?:                                   :5G5JJ?7777777!!!!777?????Y5GG5YJJY5PGBJ:                        \n");
			printf("      ^YG###GPBBBBBP7.                                  .^^:::^~~~~~~~~~!!!77?JJJY5GPJ!!~!???JY5Y?^.                    \n");
			printf("    .7#&##BPGGGGBBBBBY:                                         ..:?7~!!!!!!!?YJJY5J!~!??JJ??JJYY5PY?!:                 \n");
			printf("   :G##B##GPPPGGGGGBBG5:                                           7#PYJ7!~!7?YYJ7~~7??7?JJ????YJJY55BG!.               \n");
			printf("   !##B#&#5PPPPPGGPGGGG5:                                          .YP5PPPP5Y5PJ~~?JJJ??JY5J??JYJ???JYPG57:             \n");
			printf("   7BGG##P5GPPPPPPGGPGGGP~                                           :~JGBBBGGY7?YYYJ?YYJJJYYYJ777?JJJ5PPBGY~.          \n");
			printf("   ^B&#GPJ?YY5555YY5PPPPGGJ:                                            ~5BG5YJJJ?77???JJJJJJJJYY55P5YPBGGBBBGJ:        \n");
			printf("    ^7!!YY?JYY5YY55YY555PPGG?.                                          .~JJ????JJJ?77777?Y5YJYJ5GGGGGP5PGGPPG#B?.      \n");
			printf("         :~7??JYJJYYY5YPPPGBB5^                                       .!?JJ?777?77?YY?77777JYJ??7JPGG5JJYYY5Y5BBBP:     \n");
			printf("            ..:^~!?555Y55PPP55P7                                     :????JJJY?7?J???7!77???JYY55Y55J??JYJYYY5GGGG5:    \n");
			printf("                 :YBBG5555PP55PG7                                    !7JYJ????J?7?J?!!!!!!!!!7?????77?JYYYYYY5GGGP5J    \n");
			printf("                  .Y#BBPPPP5PP5PB?                                  :!!77??JYJJ?7!77!77777777777777?JJJJYYYY555BB#GG~   \n");
			printf("                   :G##BGPPPPPPPP#Y.                               :!7775B&GPB&#P?~~~~~^^^^^~~!77??7??JYYJYY5J?B@@#PP:  \n");
			printf("                    !####BGPPPPPPGB5^                            :~!??Y#@&BG55JG@&G777!!!~~^^^~~~~!!??JJ??JYYJJY&@@#P5. \n");
			printf("                     ?##B##GGPPPPPGBG7                         ^!!!!7?#@#G##B#B#BG@Y~777777!!!!777?777!!7?JJ?JJJY&@@&&7 \n");
			printf("                      J#B##BGGPP5PPGGGJ:                     .~!!!!!!5@GY#BBB#&BB&@5~!!!7777???????7!!7?J?77?????YYG@BP^\n");
			printf("                       Y###BGBGP555PPPGP7                  :~777?7!!7?P##&BGGY5#@@B7!!!777??????7!!7!?J?7!7??77??J75&&#5\n");
			printf("                       .5#B#BBBGP555PPPGB5!              :!777777?5B&G5PB####PB@#5!!777?77?77!!~~!777J77??77777777JJ#@GB\n");
			printf("                        :P#BBBBGGGPP55PPPGB5~          :~?JJ??777P###J?YBPPYJJJ7!!77777?77!~~~!777777!!!!777???77JJ7#@#5\n");
			printf("                         ^GBBBBBBBBPP55555PGBY:     .:~7?????????7?5BP5B&##J!77?????77!~~~!7??????7!!~~!????777?J???P@@#\n");
			printf("                          ^GBBBBBGBBGP5Y5PGB#&Y   .:^~!??7777777??????J5GY77777!!~~~~~!!7??????7!~!!!!!!!!!!777?7?J?J&@@\n");
			printf("                           ~GBBGGGGBGP5PB#####J~~^:!?Y5PP5??777777!777~~^^^^^^^~~!!777?777???7!~~~~~!!!!77777777???77#@@\n");
			printf("                            ~GBGGPGGGGB#BBBBB#7!J!!PB###B##G555?7?7!!!!!77?7777777777?7??77!~~~~~~!!!!!7777???????777B@@\n");
			printf("                             ^PBPGB##BBBBBGBG#5JYYB#BB###&&&&&@G77!77777?JJ????77?????77!!~^:^~~!!!!!!!77777?77?????75@@\n\n");
			sys_print("대한민국 K 리그에서 정상급 활약을 펼쳤던, 공격수 밥줘영\n");
			sys_print("이젠 한국은 시시하다는 발언 후 호기롭게 영국으로 떠났다.\n");
			sys_print("명문구단 갱스날FC에 입단하게 되는데...\n");
			sys_print("너무 무모한 도전이었던 것일까? 갱스날FC 감독은 그를 벤치 신세로 만들었다.\n");
			sys_print("하지만 나 밥줘영, 한국에서 정상을 찍고 온 남자!\n");
			sys_print("첫 출전에서 화려한 감아차기 골을 성공시키는데...\n");
			sys_print("하지만... 너무 감아버렸던 걸까? 그 이후로 밥줘영의 축구 인생 또한 감기기 시작한다.\n");
			sys_print("끝없는 부진, 사라지는 출전 시간...\n");
			sys_print("더러워서 진짜, 이딴 클럽 나가버리던가 해야지!!!\n");
			sys_print("결국 팀을 뛰쳐나가 길거리 신세로 전략해버린다.\n");
			sys_print("배...고....파....\n");
			a->gold = rand() % 50 + 1;
			a->hp = rand() % 3 + 3;
			a->dex = rand() % 3 + 3;
			a->str = rand() % 3 + 3;
			break;
		}
		else {
			sys_print("다시 선택하세요.\n");
			select = sys_select();
		}
	}
	sys_gonext();
}

//게임 시작 시 오프닝 출력 함수
void sys_opening(){
	PlaySound(TEXT("sys_opening.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Sleep(1000);
	printf("5 ? ~.          .!YB############################    :PPPPPPPPPPPPPP:    #############################BY!. :!JPPPGGG5J~.\n");
	Sleep(50);
	printf("GGP5J!:          .~JP##########################B.   :PPPPPPPPPPPPPP:   .B##########################PJ~..^7YPGGGGPY7^.   \n");
	Sleep(50);
	printf("YPGGGGP5?~.          :75B######################B.   :PPPPPPPPPPPPPP:   .B######################B5!: .~?5GGGGG5J!:       \n");
	Sleep(50);
	printf(" .~?5PGGGGPJ!:          .~JP###################B.   :PPPPPPPPPPPPPP:   .B###################P?^..^7YPGGGGPY7^.          \n");
	Sleep(50);
	printf("GJ~. :!JPGGGGP5?~.          :7YB###############B.   :PPPPPPPPPPPPPP:   .B###############BY!: .~J5GGGGG5J~:          :!YG\n");
	Sleep(50);
	printf("###B57^ .^?5PGGGGPJ!:          .~?P############B.   :PPPPPPPPPPPPPP:   .B############P?^..^7YPGGGGPY7^.         .^?5B###\n");
	Sleep(50);
	printf("#######GY!. :!JPGGGGP5?~.          :!YG########B.   :PPPPPPPPPPPPPP:   .B########GY!: .~J5GGGGP5?~:          :!YG#######\n");
	Sleep(50);
	printf("##########BP?^..^?YPGGGGPY7^.         .^?PB####B.   :PPPPPPPPPPPPPP:   .B####BP?^..^7YPGGGGPY7^.         .^?PB##########\n");
	Sleep(50);
	printf("##############GY!. :!J5GGGGP5?~.          :!YG#B.   :PPPPPPPPPPPPPP:   .##GY!. :!J5GGGGP5?~.          :!YG##############\n");
	Sleep(50);
	printf("#################BP?^..^7YPGGGGPY7^.         .^7.   :PPPPPPPPPPPPPP:   .7^..^?5PGGGGPY7^.         .^?PB#################\n");
	Sleep(50);
	printf("##################&&#B5!:.:!J5GGGGG5J!:             :PPPPPPPPPPPPPP:    :!YPGGGGP5?~.          :75B#&&##################\n");
	Sleep(50);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!~:   .^~~~~~~~^.            :PPPPPPPPPPPPPP:    ^~~~~~~~^             :~!!!!!!!!!!!!!!!!!!!!!!!!\n");
	Sleep(50);
	printf("????????????????????????????????????????????????????7YPPPPPPPPPPY7?????????????????????????????????????????????????????\n");

	printf("PPPPPPPPPPPP     #  #  ### ###     ###            ###    #   ######                  #                #    PPPPPPPPPPPP\n");
	Sleep(50);
	printf("PPPPPPPPP    #   #  #    #   #    #   #          #   # ###        #            #     #        #       #     PPPPPPPPPPP\n");
	Sleep(50);
	printf("PPPPPPP      #   #  #  ########    ###            ###  ###  ##########        # #    #      #   #     ####   PPPPPPPPPP\n");
	Sleep(50);
	printf("PPPPP        ### ####     #     ########                 #       #           #   #   #     #     #    #       PPPPPPPPP\n");
	Sleep(50);
	printf("PPPPPPPP         #  #   #####     #                  ###      #####                                   #      PPPPPPPPPP\n");
	Sleep(50);
	printf("PPPPPPPPPPP      #  #   #   #     #####             #   #         #             #                     #     PPPPPPPPPPP\n");
	Sleep(50);
	printf("PPPPPPPPPPPP            #####                        ###          #             ######                   PPPPPPPPPPPPPP\n");



	Sleep(50);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!~7PPPPPPPPPPPPPP7~!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	Sleep(50);
	printf("                                                    :PPPPPPPPPPPPPP:                                                    \n");
	Sleep(50);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!~:             ^~~~~~~~~    :PPPPPPPPPPPPPP:            .^~~~~~~~^.   :~!!!!!!!!!!!!!!!!!!!!!!!!\n");
	Sleep(50);
	printf("##################&&#B57^.         .~?5PGGGGPY!:    :PPPPPPPPPPPPPP:             :!J5GGGGG5J!:.:!YB#&&##################\n");
	Sleep(50);
	printf("#################BP?~.         .^7YPGGGGP5?^. ^7.   :PPPPPPPPPPPPPP:   .7^.         .^7YPGGGGPY7^..^?PB#################\n");
	Sleep(50);
	printf("##############GY!:          .~?5PGGGGPJ!: .!YG#B.   :PPPPPPPPPPPPPP:   .##GY!:          .~?5PGGGGPJ!: .!YG##############\n");
	Sleep(50);
	printf("##########BP?^.         .^7YPGGGGPY7^..^?PB####B.   :PPPPPPPPPPPPPP:   .B####BP?^.         .^7YPGGGGP5?^. ^?PB##########\n");
	Sleep(50);
	printf("#######GY!:          :~?5PGGGG5J!: :!YG########B.   :PPPPPPPPPPPPPP:   .B########GY!:          .~?5PGGGGPJ!: .~YG#######\n");
	Sleep(50);
	printf("###BP?^.         .^7YPGGGGPY7^..^?P############B.   :PPPPPPPPPPPPPP:   .B############P?~.          :!JPGGGGP5?^. ^75B###\n");
	Sleep(50);
	printf("GY!:          :~J5GGGGG5J~. :!YB###############B.   :PPPPPPPPPPPPPP:   .B###############BY7:          .~?5PGGGGPJ!: .~JG\n");
	Sleep(50);
	printf("          .^7YPGGGGPY7^..^?P###################B.   :PPPPPPPPPPPPPP:   .B###################PJ~.          :!JPGGGGP5?~. \n");
	Sleep(50);
	printf("       :!J5GGGGG5J~. :!YB######################B.   :PPPPPPPPPPPPPP:   .B######################B57:          .~?5PGGGGPY\n");
	Sleep(50);
	printf("   .^7YPGGGGPY7^..~JP##########################B.   :PPPPPPPPPPPPPP:   .B##########################GJ~.          :!J5PGG\n");
	Sleep(50);
	printf(".~J5GGGPPPJ!: .!YB#############################B.   :PPPPPPPPPPPPPP:   .B#############################B5!:          .~?5\n");
	Sleep(50);
	printf("       .------..------..------..------.            .------..------..------..------..------.       .------.\n");
	Sleep(50);
	printf("       |G.--. ||A.--. ||M.--. ||E.--. |            |S.--. ||T.--. ||A.--. ||R.--. ||T.--. |       |!.--. |\n");
	Sleep(50);
	printf("       | :/ : || ( /) || ( /) || ( /) |            | :/ : || :/ : || ( /) || :(): || :/ : |       | ( /) |\n");
	Sleep(50);
	printf("       | : /: || : /: || : /: || : /: |            | : /: || (__) || : /: || ()() || (__) |       | : /: |\n");
	Sleep(50);
	printf("       | '--'G|| '--'A|| '--'M|| '--'E|            | '--'S|| '--'T|| '--'A|| '--'R|| '--'T|       | '--'!|\n");
	Sleep(50);
	printf("        ------'`------'`------'`------'            `------'`------'`------'`------'`------'       `------'\n\n");
	Sleep(1000);
	sys_gonext();
}

//캐릭터 선택 후 게임을 전반적으로 설명해주는 튜토리얼
void sys_tutorial(player* a) {
	system("cls");
	sys_printstat(a);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("ooooooooooo ooooo  oooo ooooooooooo   ooooooo  oooooooooo  ooooo      o      ooooo       \n");
	printf("88  888  88  888    88  88  888  88 o888   888o 888    888  888      888      888        \n");
	printf("    888      888    88      888     888     888 888oooo88   888     8  88     888        \n");
	printf("    888      888    88      888     888o   o888 888  88o    888    8oooo88    888      o \n");
	printf("   o888o      888oo88      o888o      88ooo88  o888o  88o8 o888o o88o  o888o o888ooooo88\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	Sleep(1000);
	sys_print("이제, 당신은 당신이 선택한 캐릭터와 함께 영국의 밑바닥부터 게임을 시작합니다.\n");
	sys_print("당신의 캐릭터는 총 4가지의 능력치를 갖고 있습니다.\n");
	sys_print("골드, 체력, 민첩, 힘\n");
	sys_print("당신이 선택한 캐릭터는... ");
	if (a->charnum == 1) {
		sys_print("이윤쟤군요.\n");
		sys_print("이 캐릭터의 클리어 조건은 매우 쉽습니다.\n");
		printf("%d", CHARNUM1_CLR_GOLD);
		sys_print(" 골드 만큼만 모으면, 충분히 월드클래스 골키퍼 이윤쟤는 다시 일어날 수 있을 거에요.");
	}
	else if (a->charnum == 2) {
		sys_print("손우민이군요.\n");
		sys_print("이 캐릭터의 클리어 조건은... 적당한 수준입니다.\n");
		printf(" %d", CHARNUM2_CLR_GOLD);
		sys_print(" 골드, 그리고 민첩은 ");
		printf("%d", CHARNUM2_CLR_DEX);
		sys_print(" 이상이 되면, 손우민은 다리를 치료하고 다시 축구할 수 있을 거에요.\n");
	}
	else if (a->charnum == 3) {
		sys_print("기신용이군요.\n");
		sys_print("이 캐릭터의 클리어 조건은 조금 어려워요.\n골드는 ");
		printf("%d", CHARNUM3_CLR_GOLD);
		sys_print(" 골드 이상, 체력은 ");
		printf("%d", CHARNUM3_CLR_HP);
		sys_print(" 이상, 힘은 ");
		printf("%d", CHARNUM3_CLR_STR);
		sys_print(" 이상이면... 충분히 다시 맨체스터로 돌아갈 수 있을 거에요.\n");
	}
	else if (a->charnum == 4) {
		sys_print("간두리로군요.\n");
		sys_print("이 캐릭터의 클리어 조건은 많이....   어려워요.\n골드는 ");
		printf("%d", CHARNUM4_CLR_GOLD);
		sys_print(" 골드 이상, 체력은");
		printf("%d", CHARNUM4_CLR_HP);
		sys_print(" 이상, 민첩은 ");
		printf("%d", CHARNUM4_CLR_DEX);
		sys_print(" 이상, 힘은 ");
		printf("%d", CHARNUM4_CLR_STR);
		sys_print(" 이상이면... 간을 이식받아 다시 상대 공격수들을 부숴버릴 수 있을 거에요.\n");
		sys_print("그럴 일이 일어나지는 않겠지만, 체력이 많이 좋아지면 간이 자연치유 될 지도 몰라요?\n");
	}
	else if (a->charnum == 5) {
		sys_print("세상에나, 밥줘영이군요...\n");
		sys_print("지금 부여받은 능력치는, 아마 무작위로 정해졌을 거에요.\n");
		sys_print("이 캐릭터의 클리어 조건은... 엄청 엄청 어려워요.\n골드는");
		printf("%d", CHARNUM5_CLR_GOLD);
		sys_print(" 골드 이상, 체력은 ");
		printf("%d", CHARNUM5_CLR_HP);
		sys_print(" 이상, 민첩은 ");
		printf("%d", CHARNUM5_CLR_DEX);
		sys_print(" 이상, 힘은 ");
		printf("%d", CHARNUM5_CLR_STR);
		sys_print(" 이상이면... 밑도 끝도 없이 감겨서 꼬여버린 축구 인생을 다시 펼 수도 있을 거에요.\n");
	}
	sys_print("\n게임의 진행 방식은 간단합니다. ");
	sys_print("여러 사건들과 사람들을 만나게 될 텐데, 당신의 선택에 따라 캐릭터의 능력치가 변하게 되죠.\n");
	sys_print("카지노에서 카드 게임을 승리하면, 돈을 많이 벌 수 있을 것이고,\n");
	sys_print("빵집에서 빵이라도 훔치다가 혹여나 걸리면, 실컷 두드려 맞아 체력이 깎이겠지요.\n");

	sys_print("\n\n모든 결과는 당신의 선택에 달려있습니다.\n\n");
	sys_print("이제, 시작합니다.\n");

	sys_gonext();
}



