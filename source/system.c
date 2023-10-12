//Visual C���� ������ Ʋ�� �����ϴ� �Լ��� �ҽ��ڵ�

#include "���.h"


void sys_gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//���ڿ��� �� �ϴ� �� ó�� ����ϴ� �Լ�
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

//���� ����ϸ� �ε�ȿ���� �ִ� �Լ�
void sys_printdot() {
	Sleep(500);
	for (int i = 0; i < 3; i++) {
		printf("�� ");
		Sleep(500);
	}
	Sleep(500);
	printf("\n");
}

//���� ��ȣ�� �Է¹޴� �Լ�
int sys_select() {
	int select = 0;
	sys_print("\n<����� ������?> ");
	getch();
	scanf("%d", &select);
	printf("\n");
	return select;
}

//�ٽ� ���� ��ȣ�� �Է¹޴� �Լ�
int sys_reselect()
{
	int select = 0;
	sys_print("\n<�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.> ");
	rewind(stdin);
	scanf("%d", &select);
	getch();
	printf("\n");
	return select;
}

//ĳ������ �ɷ�ġ�� �����ִ� �Լ�
void sys_playerstat(player* a) {
	sys_print("\n���� ĳ������ �ɷ�ġ�� ������ �����ϴ�.\n");
	printf("[���]%4d  [ü��]%3d  [��ø]%3d  [��]%3d\n\n", a->gold, a->hp, a->dex, a->str);
	Sleep(2000);
}

//ĳ������ �ɷ�ġ�� ����ϴ� �Լ�. �̺�Ʈ ���� �� ��ܿ� ǥ��
void sys_printstat(player* a) {
	sys_gotoxy(0, 0);
	printf("�Ȧ���������������������������������������������������������������������������������������������������������������������\n��   ");
	if (a->charnum == 1) {
		printf("[������]");
	}
	else if (a->charnum == 2) {
		printf("[�տ��]");
	}
	else if (a->charnum == 3) {
		printf("[��ſ�]");
	}
	else if (a->charnum == 4) {
		printf("[���θ�]");
	}
	else {
		printf("[���࿵]");
	}
	printf("  [���]%4d  [ü��]%3d  [��ø]%3d  [��]%3d    ��\n", a->gold, a->hp, a->dex, a->str);
	
	if (a->charnum == 1) {
		printf("��   �޼���ǥ: [���]%4d                                   ��\n", CHARNUM1_CLR_GOLD);
	}
	else if (a->charnum == 2) {
		printf("��   �޼���ǥ: [���]%4d             [��ø]%3d             ��\n", CHARNUM2_CLR_GOLD, CHARNUM2_CLR_DEX);
	}
	else if (a->charnum == 3) {
		printf("��   �޼���ǥ: [���]%4d  [ü��]%3d             [��]%3d    ��\n", CHARNUM3_CLR_GOLD, CHARNUM3_CLR_HP, CHARNUM3_CLR_STR);
	}
	else if (a->charnum == 4) {
		printf("��   �޼���ǥ: [���]%4d  [ü��]%3d  [��ø]%3d  [��]%3d    ��\n", CHARNUM4_CLR_GOLD, CHARNUM4_CLR_HP, CHARNUM4_CLR_DEX, CHARNUM4_CLR_STR);
	}
	else {
		printf("��   �޼���ǥ: [���]%4d  [ü��]%3d  [��ø]%3d  [��]%3d    ��\n", CHARNUM5_CLR_GOLD, CHARNUM5_CLR_HP, CHARNUM5_CLR_DEX, CHARNUM5_CLR_STR);
	}
	printf("�Ʀ���������������������������������������������������������������������������������������������������������������������\n\n");
}

//Ű �Է��� �ޱ� �� ���� ȭ���� ���ߴ� �Լ�
void sys_gonext() {
	printf("\n");
	printf("�Ȧ���������������������������������������������������������������������\n");
	printf("�� ����Ϸ��� �ƹ� Ű�� �Է��ϼ���  ��\n");
	printf("�Ʀ���������������������������������������������������������������������\n\n");
	getch();
	while (!_kbhit()) {

	}

	system("cls");
}

//�̺�Ʈ�� ������ ���� ������ ������ �����ϴ� �Լ�
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

//���� ������ �迭�� �̺�Ʈ�� �����ϴ� �Լ�.�ڵ带 �� �� ������ �� ���� �� ������ �´� �̺�Ʈ�� ����ȴ�.
int sys_playevent(int eventcount, int ran[], player* a) {
	switch (ran[eventcount]) {
	case 0:	//���Ӱ��� �̺�Ʈ
		event_donut(a);
		break;
	case 1:	//�ް�� �̺�Ʈ
		event_street(a);
		break;
	case 2:	//���� �ƽʴϱ�? �̺�Ʈ
		event_doyouknow_do(a);
		break;
	case 3:	//����ŷ �̺�Ʈ
		event_busking(a);
		break;
	case 4:	//ÿ���VS������ �ºο��� �̺�Ʈ
		event_sportstoto(a);
		break;
	case 5:	//1�޷��� �̺�Ʈ
		event_1dollar(a);
		break;
	case 6:	//���˺� �̺�Ʈ
		event_star(a);
		break;
	case 7:	//�Ⱦ��� �̺�Ʈ
		event_armwrestle(a);
		break;
	case 8:	//�ѱ�VS���� �ºο��� �̺�Ʈ
		event_engvskorea(a);
		break;
	}
	eventcount++;
	return eventcount;
}

//ĳ���� ���� �Լ�.
void sys_selectplayer(player* a) {
	int select = 0;
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("  ____ _   _    _    ____     _    ____ _____ _____ ____      ____  _____ _     _____ ____ _____ \n");
	printf(" / ___| | | |  / l  |  _ l   / l  / ___|_   _| ____|  _ l    / ___|| ____| |   | ____/ ___|_   _|\n");
	printf("| |   | |_| | / _ l | |_) | / _ l| |     | | |  _| | |_) |   l___ l|  _| | |   |  _|| |     | |  \n");
	printf("| |___|  _  |/ ___ l|  _ < / ___ | |___  | | | |___|  _ <     ___) | |___| |___| |__| |___  | |  \n");
	printf(" l____|_| |_/_/   l_|_| l_/_/   l_l____| |_| |_____|_| l_l   |____/|_____|_____|_____l____| |_|\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
	Sleep(500);
	sys_print("ĳ���͸� �����ϼ���.\n");
	sys_print("�� ĳ���͵��� �ٸ� �ɷ�ġ�� ������ �����մϴ�.\n");
	sys_print("�׸���, ����� ���ÿ� ���� ������ Ŭ���� ���� ���� �޶����ϴ�.\n\n");
	sys_print("[1]��Ű�� ������(EASY)\n[2]���ݼ� �տ��(NORMAL)\n[3]�̵��ʴ� ��ſ�(HARD)\n[4]����� ���θ�(VERY HARD)\n[5]���ݼ� ���࿵(HELL)\n");
	sys_print("\n�����ϰ� ���� ĳ������ ���ڸ� �Է��ϼ���.\n");
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
			sys_print("����ǮFC�� ����Ŭ���� ��Ű���� ������\n");
			sys_print("���� ������ ���� ������ è�Ǿ� ���� �����, ġ������ �Ǽ��� 5���� �峳�Ѵ�.\n");
			sys_print("�ؼ� ����ǮFC �ҵ�κ��� ���� ������ �ް� �Ǵ� ������. ����� ����ǮFC�κ��� ����ģ��.\n");
			sys_print("���µ� �������ϰ� �ſ��޵� ���İ��� �ҷ����� ������ ��... ");
			sys_print("�Ϸ��Ϸ簡 �ʹ� ����ϰ�... �������� �����װ� �����..!!\n");
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
			sys_print("�������� ������ �౸���� ������ ������! ���ݼ��� �տ��\n");
			sys_print("����� ��븦 �� ���� �ް� �ױ۷����� ���ϳ� ȣ���� �������� �Դ��ϰ� �ȴ�.\n");
			sys_print("������... �Ʒ� �� ������ ��ģ ��Ŭ�� ���� �����δ븦 �Ŀ��ϴ� �λ��� �Դµ�...\n");
			sys_print("ġ�Ḧ ���� ���� ���Ͽ� �����κ��� ������ϰ� �ȴ�.\n");
			sys_print("������ �ٽ� ���ư� �� ����!! ���� ���� �ȴ� ���̾�...�Ф�\n");
			sys_print("��Ե� �ٸ��� ġ���ؼ� �ٽ� �ױ۷��忡�� �౸�� �ϰ� �;�!\n");
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
			sys_print("��ü���� ������ ������, �̵��ʴ� ��ſ�\n");
			sys_print("���� �뼱���� ������ ������ �� �𵨷� ��� ������ �Ʒ��ϴ� ��ſ�.\n");
			sys_print("�̵��ʴ��� �⺻�� ü������! ���ϰ��� ü�´ܷ��� ���� ���� ������ �ڴ�.\n");
			sys_print("��... ������ ����� ���� �޸� �� ������...\n");
			sys_printdot();
			sys_print("�ٵ� �����..�����? ����?\n");
			sys_print("ū�ϳ���..!!\n");
			sys_print("�����Ϸ��� ���ͼ� �����̶� ����Ʈ���� �� ���ݾ�?!\n");
			sys_print("������ ��ü���ʹ� 294.51km�� ������ ��ġ....\n");
			sys_print("��Ե� ��Ƽ� ��ü���ͷ� ���ư��� �Ѵ�...!!\n");
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
			sys_print("�ƹ����� ��� �پ �������� ���� ����� ���θ�\n");
			sys_print("��û�� �ַ°� ���ο����� ��� ���ݼ����� ȥ���ϰ� �����!!\n");
			sys_print("������ �״� ġ������ ������ �־��µ�, ���� �ʹ� ����Ѵ�.\n");
			sys_print("�Ʒ��� ��ĥ �� ���� ���ϰ��� ����ī�� ����Ų ������...\n");
			sys_print("������ �߻��Ͽ� �ǰ��� ���� �̽Ĺްų�, �ڿ�ġ���� �ٷ��� �ϴ� ������ ��Ȳ..!\n");
			sys_print("�� ����... �� �����̾�..?\n");
			sys_print("�� �̽��� �޵簡, �ڿ�ġ���� �ǵ簡 ��� �ؼ��� �ǰ������� �Ѵ�!\n");
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
			sys_print("���ѹα� K ���׿��� ����� Ȱ���� ���ƴ�, ���ݼ� ���࿵\n");
			sys_print("���� �ѱ��� �ý��ϴٴ� �߾� �� ȣ��Ӱ� �������� ������.\n");
			sys_print("������ ������FC�� �Դ��ϰ� �Ǵµ�...\n");
			sys_print("�ʹ� ������ �����̾��� ���ϱ�? ������FC ������ �׸� ��ġ �ż��� �������.\n");
			sys_print("������ �� ���࿵, �ѱ����� ������ ��� �� ����!\n");
			sys_print("ù �������� ȭ���� �������� ���� ������Ű�µ�...\n");
			sys_print("������... �ʹ� ���ƹ��ȴ� �ɱ�? �� ���ķ� ���࿵�� �౸ �λ� ���� ����� �����Ѵ�.\n");
			sys_print("������ ����, ������� ���� �ð�...\n");
			sys_print("�������� ��¥, �̵� Ŭ�� ������������ �ؾ���!!!\n");
			sys_print("�ᱹ ���� ���ĳ��� ��Ÿ� �ż��� �����ع�����.\n");
			sys_print("��...��....��....\n");
			a->gold = rand() % 50 + 1;
			a->hp = rand() % 3 + 3;
			a->dex = rand() % 3 + 3;
			a->str = rand() % 3 + 3;
			break;
		}
		else {
			sys_print("�ٽ� �����ϼ���.\n");
			select = sys_select();
		}
	}
	sys_gonext();
}

//���� ���� �� ������ ��� �Լ�
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

//ĳ���� ���� �� ������ ���������� �������ִ� Ʃ�丮��
void sys_tutorial(player* a) {
	system("cls");
	sys_printstat(a);
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("ooooooooooo ooooo  oooo ooooooooooo   ooooooo  oooooooooo  ooooo      o      ooooo       \n");
	printf("88  888  88  888    88  88  888  88 o888   888o 888    888  888      888      888        \n");
	printf("    888      888    88      888     888     888 888oooo88   888     8  88     888        \n");
	printf("    888      888    88      888     888o   o888 888  88o    888    8oooo88    888      o \n");
	printf("   o888o      888oo88      o888o      88ooo88  o888o  88o8 o888o o88o  o888o o888ooooo88\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
	Sleep(1000);
	sys_print("����, ����� ����� ������ ĳ���Ϳ� �Բ� ������ �عٴں��� ������ �����մϴ�.\n");
	sys_print("����� ĳ���ʹ� �� 4������ �ɷ�ġ�� ���� �ֽ��ϴ�.\n");
	sys_print("���, ü��, ��ø, ��\n");
	sys_print("����� ������ ĳ���ʹ�... ");
	if (a->charnum == 1) {
		sys_print("����������.\n");
		sys_print("�� ĳ������ Ŭ���� ������ �ſ� �����ϴ�.\n");
		printf("%d", CHARNUM1_CLR_GOLD);
		sys_print(" ��� ��ŭ�� ������, ����� ����Ŭ���� ��Ű�� �������� �ٽ� �Ͼ �� ���� �ſ���.");
	}
	else if (a->charnum == 2) {
		sys_print("�տ���̱���.\n");
		sys_print("�� ĳ������ Ŭ���� ������... ������ �����Դϴ�.\n");
		printf(" %d", CHARNUM2_CLR_GOLD);
		sys_print(" ���, �׸��� ��ø�� ");
		printf("%d", CHARNUM2_CLR_DEX);
		sys_print(" �̻��� �Ǹ�, �տ���� �ٸ��� ġ���ϰ� �ٽ� �౸�� �� ���� �ſ���.\n");
	}
	else if (a->charnum == 3) {
		sys_print("��ſ��̱���.\n");
		sys_print("�� ĳ������ Ŭ���� ������ ���� �������.\n���� ");
		printf("%d", CHARNUM3_CLR_GOLD);
		sys_print(" ��� �̻�, ü���� ");
		printf("%d", CHARNUM3_CLR_HP);
		sys_print(" �̻�, ���� ");
		printf("%d", CHARNUM3_CLR_STR);
		sys_print(" �̻��̸�... ����� �ٽ� ��ü���ͷ� ���ư� �� ���� �ſ���.\n");
	}
	else if (a->charnum == 4) {
		sys_print("���θ��α���.\n");
		sys_print("�� ĳ������ Ŭ���� ������ ����....   �������.\n���� ");
		printf("%d", CHARNUM4_CLR_GOLD);
		sys_print(" ��� �̻�, ü����");
		printf("%d", CHARNUM4_CLR_HP);
		sys_print(" �̻�, ��ø�� ");
		printf("%d", CHARNUM4_CLR_DEX);
		sys_print(" �̻�, ���� ");
		printf("%d", CHARNUM4_CLR_STR);
		sys_print(" �̻��̸�... ���� �̽Ĺ޾� �ٽ� ��� ���ݼ����� �ν����� �� ���� �ſ���.\n");
		sys_print("�׷� ���� �Ͼ���� �ʰ�����, ü���� ���� �������� ���� �ڿ�ġ�� �� ���� �����?\n");
	}
	else if (a->charnum == 5) {
		sys_print("���󿡳�, ���࿵�̱���...\n");
		sys_print("���� �ο����� �ɷ�ġ��, �Ƹ� �������� �������� �ſ���.\n");
		sys_print("�� ĳ������ Ŭ���� ������... ��û ��û �������.\n����");
		printf("%d", CHARNUM5_CLR_GOLD);
		sys_print(" ��� �̻�, ü���� ");
		printf("%d", CHARNUM5_CLR_HP);
		sys_print(" �̻�, ��ø�� ");
		printf("%d", CHARNUM5_CLR_DEX);
		sys_print(" �̻�, ���� ");
		printf("%d", CHARNUM5_CLR_STR);
		sys_print(" �̻��̸�... �ص� ���� ���� ���ܼ� �������� �౸ �λ��� �ٽ� �� ���� ���� �ſ���.\n");
	}
	sys_print("\n������ ���� ����� �����մϴ�. ");
	sys_print("���� ��ǵ�� ������� ������ �� �ٵ�, ����� ���ÿ� ���� ĳ������ �ɷ�ġ�� ���ϰ� ����.\n");
	sys_print("ī���뿡�� ī�� ������ �¸��ϸ�, ���� ���� �� �� ���� ���̰�,\n");
	sys_print("�������� ���̶� ��ġ�ٰ� Ȥ���� �ɸ���, ���� �ε�� �¾� ü���� ���̰�����.\n");

	sys_print("\n\n��� ����� ����� ���ÿ� �޷��ֽ��ϴ�.\n\n");
	sys_print("����, �����մϴ�.\n");

	sys_gonext();
}



