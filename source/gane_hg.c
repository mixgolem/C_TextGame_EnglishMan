//할리 갈리 소스코드

#include "header.h"

typedef struct card {
	int number;
	char* symbol;
}card;

//순서대로 전체 카드 덱, 플레이어의 카드, 딜러의 카드, 바닥에 내려놓은 카드
card hg_deck[40], player1[40], player2[40], table[2];
int top_deck, top_player1 = -1, top_player2 = -1;
int i;

//각 모양의 카드를 1부터 5까지, 2장씩 총 40장의 카드 덱 생성
void make_hg_deck(card* deck)
{
	for (i = 0; i < 10; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "♥";
	}

	for (i = 10; i < 20; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "♠";
	}

	for (i = 20; i < 30; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "◆";
	}

	for (i = 30; i < 40; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "♣";
	}
	top_deck = i - 1;
}

//카드 뭉치를 셔플하는 함수
void shuffle_hg_deck(card* deck)
{
	srand(time(NULL));
	int random;
	card buffer;
	for (i = 0; i < 40; i++)
	{
		random = rand() % 40;;//0부터 39까지 난수 발생
		buffer = deck[i];//버퍼에 덱의 0번째 인덱스 입력
		deck[i] = deck[random];//deck[0]에 deck[random] 카드 입력
		deck[random] = buffer;//deck[random]에 다시 deck[0] 카드 입력
		//만약 random이 20일 때, deck[0]과 deck[20]의 카드가 서로 바뀐다
	}//위 과정을 40번 반복 시 카드 순서가 모두 섞인다.
}

//종을 울린 후 바닥의 카드 뭉치를 승자가 가져가는데,
//그렇게 합친 카드 뭉치를 다시 섞는 함수
void shuffle_player_deck(card* player, int count)
{//count정수를 인수로 받는데 이는 카드를 합친 후 각각 플레이어의 카드 뭉치의 총 카드 개수이다.
	srand(time(NULL));
	int random;
	int A = count + 1;
	card buffer;
	for (i = 0; i < A + 1; i++)
	{
		random = rand() % A;
		buffer = player[i];
		player[i] = player[random];
		player[random] = buffer;
	}
}

//플레이어와 딜러가 서로 카드를 나눠가짐
void deal_hg_deck(card* deck, card* player1, card* player2)
{
	for (i = 0; i < 20; i++)//플레이어는 위에서부터 20장
	{
		player1[i] = deck[i];
		top_player1 = i;
	}
	for (i = 20; i < 40; i++)//딜러는 나머지 20장을 가져감
	{
		player2[i % 20] = deck[i];
		top_player2 = i % 20;
	}
	top_deck = 0;
}

//딜러의 벨 누르는 속도 랜덤값으로 반환 (0.6초~1.2초 사이)
double hg_dspeed() {
	srand(time(NULL));
	double dspeed = 0;
	dspeed = ((rand() % 600) + 600);
	return dspeed/1000;
}

//할리갈리 조건을 만족할 경우를 확인하는 함수
int check_hg()
{
	double timediff = 0, dspeed = 0;
	clock_t start, end;
	char bell;

	//할리갈리 조건을 만족할 경우
	if (((table[0].symbol == table[1].symbol) && (table[0].number + table[1].number) == 5) || ((table[0].symbol != table[1].symbol) && (table[0].number == 5 || table[1].number == 5)))
	{
		start = clock();
		bell = getch();
		end = clock();
		timediff = (double)(end - start) / CLOCKS_PER_SEC;
		if (bell == 'q')
		{
			return 3;//게임 종료
		}
		else if (bell == 'a') {
			printf("dealer : a는 종을 울리는 버튼이 아니에요, 제가 이겼네요\n");
			return 2;//딜러 승리
		}
		else
		{
			dspeed = hg_dspeed();
			if (timediff < dspeed)//딜러보다 종을 울리는 버튼 'a'를 입력했을 경우
			{
				printf("딜러 반응속도: %.0lfms , 사용자 반응속도: %.0lfms\n", 1000*dspeed, 1000*timediff);
				printf("dealer : 아주 빠르시군요, 당신이 이겼네요\n");
				return 1;//플레이어 승리
			}
			else//딜러가 먼저 눌렀을 경우
			{
				printf("딜러 반응속도: %.0lfms , 사용자 반응속도: %.0lfms\n", 1000 * dspeed, 1000 * timediff);
				printf("dealer : 느리시네요, 제가 이겼네요\n");
				return 2;//딜러 승리
			}
		}
	}
	else
		return 0;
}

//할리갈리 인터페이스 출력
void print_interface_hg()
{
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□□■□□□■□□□□■□□□□■□□□□□■□□□□□■□□□■■■□□□□□■□□□□■□□□□□■□□□□□■□□\n");
	printf("□□■□□□■□□□■□■□□□■□□□□□■□□□□□■□□■□□□□□□□■□■□□□■□□□□□■□□□□□■□□\n");
	printf("□□■□□□■□□□■□■□□□■□□□□□■□□□□□■□□■□□□□□□□■□■□□□■□□□□□■□□□□□■□□\n");
	printf("□□■■■■■□□□■■■□□□■□□□□□■□□□□□■□□■□■■■□□□■■■□□□■□□□□□■□□□□□■□□\n");
	printf("□□■□□□■□□■□□□■□□■□□□□□■□□□□□■□□■□□□■□□■□□□■□□■□□□□□■□□□□□■□□\n");
	printf("□□■□□□■□□■□□□■□□■□□□□□■□□□□□■□□■□□□■□□■□□□■□□■□□□□□■□□□□□■□□\n");
	printf("□□■□□□■□□■□□□■□□■■■■□□■■■■□□■□□□■■■□□□■□□□■□□■■■■□□■■■■□□■□□\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t나의 카드 수 : %d\t\t딜러의 카드 수 :%d\t\t테이블위 카드 수 :%d\t\t\t|\n", top_player1 + 1, top_player2 + 1, top_deck);
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t[A]카드 뽑기, 턴 넘어가기\t\t[다른 키]종 울리기\t\t[Q]게임 종료\t\t\t|\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

//카드 출력 함수
void print_hg(card table1, card table2)
{
	if (table[0].number == 0 && table[1].number == 0)
	{
		print_interface_hg();
		printf("\n\t\tME\t\t\t\t\t\t\t\tDEALER\n");
		printf("\t\t-------------\t\t\t\t\t\t\t-------------\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-     ?     -\t\t\t\t\t\t\t-     ?     -\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-------------\t\t\t\t\t\t\t-------------\n\n");
		printf("\t\t\t\t   게임을 시작하려면 [A]를 입력하세요\n");
	}
	else if (table[0].number != 0 && table[1].number == 0)
	{
		print_interface_hg();
		printf("\n\t\tME\t\t\t\t\t\t\t\tDEALER\n");
		printf("\t\t-------------\t\t\t\t\t\t\t-------------\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		if (table[0].number > 1)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		if (table[0].number > 2)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-     ?     -\n", table[0].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-     ?     -\n");
		if (table[0].number > 3)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		if (table[0].number > 4)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-------------\t\t\t\t\t\t\t-------------\n\n");
	}
	else if (table[0].number != 0 && table[1].number != 0)
	{
		print_interface_hg();
		printf("\n\t\tME\t\t\t\t\t\t\t\tDEALER\n");
		printf("\t\t-------------\t\t\t\t\t\t\t-------------\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-     %s    -\t\t\t\t\t\t\t-     %s    -\n", table[0].symbol, table[1].symbol);
		if (table[0].number > 1 && table[1].number > 1)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-     %s    -\n", table[0].symbol, table[1].symbol);
		else if (table[0].number > 1 && table[1].number <= 1)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		else if (table[0].number <= 1 && table[1].number > 1)
			printf("\t\t-           -\t\t\t\t\t\t\t-     %s    -\n", table[1].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");

		if (table[0].number > 2 && table[1].number > 2)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-     %s    -\n", table[0].symbol, table[1].symbol);
		else if (table[0].number > 2 && table[1].number <= 2)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		else if (table[0].number <= 2 && table[1].number > 2)
			printf("\t\t-           -\t\t\t\t\t\t\t-     %s    -\n", table[1].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");

		if (table[0].number > 3 && table[1].number > 3)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-     %s    -\n", table[0].symbol, table[1].symbol);
		else if (table[0].number > 3 && table[1].number <= 3)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		else if (table[0].number <= 3 && table[1].number > 3)
			printf("\t\t-           -\t\t\t\t\t\t\t-     %s    -\n", table[1].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");

		if (table[0].number > 4 && table[1].number > 4)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-     %s    -\n", table[0].symbol, table[1].symbol);
		else if (table[0].number > 4 && table[1].number <= 4)
			printf("\t\t-     %s    -\t\t\t\t\t\t\t-           -\n", table[0].symbol);
		else if (table[0].number <= 4 && table[1].number > 4)
			printf("\t\t-           -\t\t\t\t\t\t\t-     %s    -\n", table[1].symbol);
		else
			printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-           -\t\t\t\t\t\t\t-           -\n");
		printf("\t\t-------------\t\t\t\t\t\t\t-------------\n\n");
	}
}

//처음 게임 실행 시 바닥의 카드는 0장으로 설정
void init_table()
{
	table[0].number = 0;
	table[1].number = 0;
}

//할리갈리 메인 함수
void game_hg(player* a)
{
	int sel_start = 0;
	sys_print("딜러 : 할리 갈리 게임을 플레이합니다.\n");
	sys_print("딜러 : 게임 설명을 듣고 싶으시면 [1] 바로 시작하시려면 다른 키를 입력하세요.\n");
	sel_start = sys_select();
	if (sel_start == 1) {
		sys_print("\n할리갈리는 1부터 5까지 적힌 스페이드, 다이아, 하트, 클로버 카드 각각 2장씩 \n  총 40장을 가지고 플레이하는 게임입니다.\n");
		sys_print("무작위로 카드를 섞은 다음, 사용자와 딜러는 카드를 20장씩 나눠가집니다.\n");
		sys_print("게임은 카드를 모으는 식으로 진행되며, 카드를 모두 잃으면 탈락하고\n  마지막까지 카드가 남아있는 사람이 승리하게 됩니다.\n");
		sys_print("플레이어 - 딜러 순서로 돌아가면서, [A] 버튼으로 각자 카드를 한 장씩 뒤집어서 본인의 앞에 놓으며 공개합니다.\n");
		sys_print("바닥에 놓인 펼쳐진 카드들 중에서 같은 모양의 개수가 5개가 되었다면\n  [a를 제외한] 버튼으로 종을 최대한 빨리 치면 바닥의 카드를 가져갑니다.\n");
		sys_print("승리 시 300골드를 획득하고, 패배 시 100골드를 지불해야 합니다.\n");
		sys_gonext();
	}
	system("cls");

	make_hg_deck(hg_deck);//덱 생성
	shuffle_hg_deck(hg_deck);//덱 셔플
	deal_hg_deck(hg_deck, player1, player2);//카드를 서로 나눠가짐
	char sel_1 = '\0';
	int check_1 = 0, check_2 = 0, quit = 0;
	init_table();//바닥 초기화
	system("cls");
	print_hg(table[0], table[1]);//바닥에 카드를 출력
	getch();
	
	while (top_player1 > 0 && top_player2 > 0 && quit != 1 && sel_1 != 'q')//카드를 모두 소모하거나 종료할 때 까지 반복
	{
		table[0] = player1[top_player1--];//사용자가 먼저 바닥에 카드를 내려놓으며 플레이어 카드 감소
		hg_deck[top_deck++] = table[0];
		system("cls");
		print_hg(table[0], table[1]);
		printf("\n\n사용자가 카드를 내려놓았습니다.\n\n");
		check_1 = check_hg();
		fseek(stdin, 0, SEEK_END);
		//사용자가 먼저 카드를 내려놓고 할리갈리 조건을 만족할 경우
		if (check_1 == 1)//사용자가 종을 먼저 쳤을 경우
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player1[++top_player1] = hg_deck[i];
			}//바닥에 내려놓아진 카드를 사용자의 카드에 합친다
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);
			//사용자는 카드를 얻고 딜러는 카드를 잃었기 때문에 각각의 카드를 재셔플
			init_table();//바닥 초기화
			continue;
		}
		else if (check_1 == 2)//딜러가 먼저 종을 쳤을 경우
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player2[++top_player2] = hg_deck[i];
			}//바닥에 내려놓아진 카드를 딜러의 카드에 합친다
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);
			//사용자는 카드를 잃고 딜러는 카드를 얻었기 때문에 각각의 카드를 재셔플
			init_table();//바닥 초기화
			continue;
		}
		else if(check_1 == 3) {//q를 입력해 게임 종료시켰을 경우
			sys_print("\n\n게임을 종료합니다\n\n");
			sys_gonext();
			quit = 1;
			break;
		}
		if (sel_1 == 'q' || quit == 1) {//q눌러서 게임 탈출 시 바로 반복문 종료
			break;
		}
		

		while (1)
		{
			sel_1 = getch();
			if (sel_1 != 'a' && sel_1 != 'q')//할리갈리 조건을 만족하지 않았는데 a를 눌렀을 경우
			{
				printf("오답입니다. 카드 1장 패널티\n\n");
				hg_deck[top_deck++] = player1[top_player1--];
				sel_1 = 0;
			}
			else if (sel_1 == 'q') {
				sys_print("\n\n게임을 종료합니다\n\n");
				sys_gonext();
				quit = 1;
				break;
			}
			else break;
		}
		if (sel_1 == 'q' || quit == 1) {//q눌러서 게임 탈출 시 바로 반복문 종료
			break;
		}


		//딜러가 카드를 내려놓는 상황
		printf("3초후 딜러가 카드 드로우");
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b2초후 딜러가 카드 드로우");
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b1초후 딜러가 카드 드로우");
		Sleep(1000);

		table[1] = player2[top_player2--];
		hg_deck[top_deck++] = table[1];//딜러의 바닥에 딜러가 카드를 내려놓는다
		system("cls");
		print_hg(table[0], table[1]);
		printf("\n\n딜러가 카드를 내려놓았습니다.\n\n");
		check_2 = check_hg();
		//딜러가 카드를 내려놓았는데 할리갈리 조건 만족할 경우
		if (check_2 == 1)//사용자가 종을 먼저 쳤을 경우
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player1[++top_player1] = hg_deck[i];
			}//바닥에 내려놓아진 카드를 사용자의 카드에 합친다
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);//사용자는 카드를 얻고 딜러는 카드를 잃었기 때문에 각각의 카드를 재셔플
			init_table();//바닥 초기화
			continue;
		}
		else if (check_2 == 2)//딜러가 먼저 종을 쳤을 경우
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player2[++top_player2] = hg_deck[i];
			}//바닥에 내려놓아진 카드를 딜러의 카드에 합친다
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);//사용자는 카드를 잃고 딜러는 카드를 얻었기 때문에 각각의 카드를 재셔플
			init_table();//바닥 초기화
			continue;
		}
		else if (check_1 == 3) {//q를 입력해 게임 종료시켰을 경우
			sys_print("\n\n게임을 종료합니다\n\n");
			sys_gonext();
			quit = 1;
		}
		if (sel_1 == 'q' || quit == 1) {//q눌러서 게임 탈출 시 바로 반복문 종료
			break;
		}

		while (1)
		{
			sel_1 = getch();
			if (sel_1 != 'a' && sel_1 != 'q')//할리갈리 조건을 만족하지 않았는데 a를 눌렀을 경우
			{
				printf("오답입니다. 카드 1장 패널티\n\n");
				hg_deck[top_deck++] = player1[top_player1--];
				Sleep(1000);
				sel_1 = 0;
			}
			else if (sel_1 == 'q') {//q입력시 게임 종료
				sys_print("\n\n게임을 종료합니다\n\n");
				quit = 1;
				break;
			}
			else break;
		}
		if (sel_1 == 'q' || quit == 1) {//q눌러서 게임 탈출 시 바로 반복문 종료
			break;
		}
	}

	if (top_player1 <= 0)
	{	
		sys_print("게임 종료 ! ! !");
		sys_print("사용자의 카드가 모두 소모되었습니다.\n");//사용자의 카드가 0장이 되면 딜러 승리
		sys_print("딜러 WIN ! ! ! !\n");
		sys_print("게임에서 패배하여 100골드를 지불했다.\n");
		a->gold -= 100;
	}
	else if (top_player2 <= 0)
	{
		sys_print("게임 종료 ! ! !");
		sys_print("딜러의 카드가 모두 소모되었습니다.\n");//딜러의 카드가 0장이 되면 사용자 승리
		sys_print("사용자 WIN ! ! ! !");
		sys_print("게임에서 승리하여 300골드를 획득했다.\n");
		a->gold += 300;
	}

	//게임 끝나면 무조건 넣어야 하는 함수들
	sys_playerstat(a);
	sys_checkend(a);
	sys_gonext();
}
