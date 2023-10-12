//카지노 입장 함수

#include "header.h"

void game_casino(player* a) {
	int sel1 = 0;
	system("cls");
	PlaySound(TEXT("cardgame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	sys_printstat(a);
	Sleep(1000);
	Sleep(20);
	printf("  ____    _    ____ ___ _   _  ___  \n");
	Sleep(20);
	printf(" / ___|  / ;  / ___|_ _| ; | |/ _ \\ \n");
	Sleep(20);
	printf("| |     / _ ; ;___ ;| ||  ;| | | | |\n");
	Sleep(20);
	printf("| |___ / ___ ; ___) | || |;  | |_| |\n");
	Sleep(20);
	printf(" ;____/_/   ;_|____|___|_| ;_|;___/ \n");
	Sleep(300);
	Sleep(20);
	printf("                                    .:                 .^^.               .~:                                       \n");
	Sleep(20);
	printf("                                    .^                ~JJ?J:               : \n");
	Sleep(20);
	printf("                                    ^5               :!7~!?!:              5: \n");
	Sleep(20);
	printf("                                    ^Y             .::..^:..::.            5: \n");
	Sleep(20);
	printf("                                    ^Y         ^^^~~^:^~~~^::^~^^^.        5: \n");
	Sleep(20);
	printf("                                    ^Y        .Y7~^~~:~~:^~^^!~^7J~        5: \n");
	Sleep(20);
	printf("                                    .^     .::~!~7:?:7~?^~^^7:~7^!!:.      ^.      \n");
	Sleep(20);
	printf("                                    :^: .:!?!7^:Y:7Y:#~YP:P:~J.^?^:?Y~.  ..:.           \n");
	Sleep(20);
	printf("                                   ^:..^?5?7J:^Y:!Y.J#.!&^:P:~Y..~!:^Y5~....:.               \n");
	Sleep(20);
	printf("                                 ...:7PP?!5J:?J.!Y.:#P.:#P.:5::Y~ .~7^~YP?:..:.                   \n");
	Sleep(20);
	printf("                                .^?GB5!!5G!~5!.?5..5#7 .P#! ^P^.JY: .!?!~?P5!::.                       \n");
	Sleep(20);
	printf("                             .~YB#G7^7GB?~YY:.55. !BB:. 7BG: ^G7 ^5J. .!YY!!YPY!:.                          \n");
	Sleep(20);
	printf("                         .:?P##P!^~5##J~YP~.^GP..:B#5...:B#Y. :BY..?G?. .~5GY!!J5Y7^.                            \n");
	Sleep(20);
	printf("                    .^7PB#G?^:^Y#&B7!5B7..7#P...JBBP~7PPJ7GY7:~#G^ :YBJ:..:JB#57~7Y5J!:.                           \n");
	Sleep(20);
	printf("               ..^7YGBB57^.:!5#&BJ~!G#J:.:5&G^?PY7GGGPPYPPPGBB?7B#B7. ^P#P~. .~5#&GJ!~7JYYJ!^.                      \n");
	Sleep(20);
	printf("        ...^!J5GBG5?~:::!5B&#G?^^J##J:..!#&&5~PGPGGPY5PBGP5PGGPGBY7#G: .^P&B?:...!5#&#GJ!~!?YPP5J7~: \n");
	Sleep(20);
	printf("    .::~7J5GGGPY7~^^^!JPBBGY7^:^JB&#?. .:5&&Y5BG5GBPPGGYBBBYGGP5GGPG##55?...:5&&G?^...^?G#&#B5?!~!7J5GGP5J7~...  \n");
	Sleep(20);
	printf("^55PGBB#&&&&#BGP55PB#&&&&BGP5YYP#&&&&PY555&&&&PG#BPGGPGGG5PPP5GGGPGGG###PB&B555YG&&&&#P5YYYPB&&&&&&#G555PB#&&&&&#BGP5YY^ \n");
	Sleep(20);
	printf("7@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#&&&&&&&&&&&&&&###BBBBBBBBBBBB###&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@7\n");
	Sleep(20);
	printf("!&&&&#&&&&##&&######B####B##BBBB#BBBBBBBGBBBBB##BBBBBBBBBBBBBBBBBB###BB########B###########&&&##&&&##&&&#&&&&#&&&&#&&&&!\n");
	Sleep(20);
	printf(" .^~!!5&P~~~~^:^#&&~.......:BGBJ........Y&##~..Y&&&&##BBBBBBBBBBB##&&&&Y..?&##!........PGGP........J&&P..::::^B&7^~~~^: \n\n");


	sys_print("카지노를 발견했다.\n");
	sys_print("딜러 : 카지노에 오신 걸 환영합니다.\n");
	sys_print("딜러 : 카지노 안에서 다양한 게임을 즐길 수 있습니다.\n\n");
	sys_print("어떤 게임을 플레이할까?\n");
	sys_print("1.인디언 포커\t2.카드 뒤집기\t3.할리 갈리\t4.슬롯 머신\n");
	sel1 = sys_select();
	switch (sel1) {
	case 1:
		game_indianpoker(a);
		break;
	case 2:
		game_matchingcard(a);
		break;
	case 3:
		game_hg(a);
		break;
	case 4:
		game_slotmachine(a);
		break;
	}
	PlaySound(NULL, NULL, SND_PURGE | SND_NOWAIT | SND_ASYNC);
}