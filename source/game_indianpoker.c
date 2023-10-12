//인디언 포커 소스코드

#include "header.h"

//카드 구조체 선언. 카드는 문양과 숫자가 같이 있음
typedef struct card {
	int number;
	char* symbol;
}card;

card deck[52];
int top = -1;

//덱 생성 함수
void make_deck(card* deck)
{
	int i = 0;
	for (i = 0; i < 13; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "♥";
	}

	for (i = 13; i < 26; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "♠";
	}

	for (i = 26; i < 39; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "◆";
	}

	for (i = 39; i < 52; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "♣";
	}

	top = i - 1;
}

//덱 셔플 함수
//반복문을 이용해 첫 번째 카드와 랜덤번째의 카드의 위치를 서로 바꾼다
//이 동작을 52번 반복하면 모든 카드의 위치가 섞이게 된다
void shuffle_deck(card* deck)
{
	srand(time(NULL));
	int i, random;
	card buffer;
	for (i = 0; i < 52; i++)
	{
		random = rand() % 52;//난수 발생
		buffer = deck[i];//버퍼에 deck[0] 입력
		deck[i] = deck[random];//deck[0]에 deck[랜덤] 카드 입력
		deck[random] = buffer;//deck[랜덤]에 버퍼 입력하면 두 카드의 위치 교체 완료
	}
	top = i - 1;
}

int is_empty_deck()
{
	return top == -1;
}

void init_deck()
{
	top = -1;
}

//pop과 같은 동작.
card draw_card()
{
	return deck[top--];
}

void make_standard_deck()
{
	init_deck();
	make_deck(deck);
	shuffle_deck(deck);
}

//카드 숫자와 모양 출력 함수
void print_card(card ex)
{
	if (ex.number < 11)
		printf("%d ,%s", ex.number, ex.symbol);
	else if (ex.number == 11)
		printf("J ,%s", ex.symbol);
	else if (ex.number == 12)
		printf("Q ,%s", ex.symbol);
	else if (ex.number == 13)
		printf("K ,%s", ex.symbol);
}

//11, 12, 13번째 카드를 J, Q, K로 출력해야 함
void print_card_number(card ex)
{
	if (ex.number < 11)
		printf("%d", ex.number);
	else if (ex.number == 11)
		printf("J");
	else if (ex.number == 12)
		printf("Q");
	else if (ex.number == 13)
		printf("K");
}

//카드 모양의 우선순위. 숫자가 높을수록 높다
int precedence_card(card ex)
{
	if (ex.symbol == "♠")
		return 3;
	else if (ex.symbol == "◆")
		return 2;
	else if (ex.symbol == "♥")
		return 1;
	else if (ex.symbol == "♣")
		return 0;
}

void print_indianpoker()
{
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("8888888 888b    888 8888888b.  8888888       d8888 888b    888 8888888b.   .d88888b.  888    d8P  8888888888 8888888b.  \n");
	printf("  888   8888b   888 888  'Y88b   888        d88888 8888b   888 888   Y88b d88P' 'Y88b 888   d8P   888        888   Y88b \n");
	printf("  888   88888b  888 888    888   888       d88P888 88888b  888 888    888 888     888 888  d8P    888        888    888 \n");
	printf("  888   888Y88b 888 888    888   888      d88P 888 888Y88b 888 888   d88P 888     888 888d88K     8888888    888   d88P \n");
	printf("  888   888 Y88b888 888    888   888     d88P  888 888 Y88b888 8888888P'  888     888 8888888b    888        8888888P'  \n");
	printf("  888   888  Y88888 888    888   888    d88P   888 888  Y88888 888        888     888 888  Y88b   888        888 T88b   \n");
	printf("  888   888   Y8888 888  .d88P   888   d8888888888 888   Y8888 888        Y88b. .d88P 888   Y88b  888        888  T88b  \n");
	printf("8888888 888    Y888 8888888P'  8888888 88P     888 888    Y888 888         'Y88888P'  888    Y88b 8888888888 888   T88b \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n\n");

}

//카드의 모양 사용자에게 출력해줌
void print_table(card a)
{
	int num;
	num = a.number;
	printf("\n\t\tME\t\t\t\t\t\t\t\tDEALER\n");
	printf("\t\t--------------\t\t\t\t\t\t\t--------------\n");
	if (num == 6 || num == 7 || num == 8 || num == 9 || num == 10)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 11)
		printf("\t\t-            -\t\t\t\t\t\t\t-     %s%s%s -\n", a.symbol, a.symbol, a.symbol);
	else if (num == 12)
		printf("\t\t-            -\t\t\t\t\t\t\t-  %s%s%s%s  -\n", a.symbol, a.symbol, a.symbol, a.symbol);
	else if (num == 13)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else printf("\t\t-            -\t\t\t\t\t\t\t-            -\n");
	if (num == 4 || num == 5)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 3 || num == 10)
		printf("\t\t-            -\t\t\t\t\t\t\t-     %s     -\n", a.symbol);
	else if (num == 11)
		printf("\t\t-            -\t\t\t\t\t\t\t-       %s   -\n", a.symbol);
	else if (num == 12)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 13)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s    %s   -\n", a.symbol, a.symbol);
	else printf("\t\t-            -\t\t\t\t\t\t\t-            -\n");
	if (num == 2 || num == 8)
		printf("\t\t-            -\t\t\t\t\t\t\t-     %s     -\n", a.symbol);
	else if (num == 9 || num == 10)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 11)
		printf("\t\t-            -\t\t\t\t\t\t\t-       %s   -\n", a.symbol);
	else if (num == 12)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 13)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s  %s     -\n", a.symbol, a.symbol);
	else
		printf("\t\t-            -\t\t\t\t\t\t\t-            -\n");
	if (num == 1 || num == 3 || num == 5 || num == 9)
		printf("\t\t-      ?     -\t\t\t\t\t\t\t-     %s     -\n", a.symbol);
	else if (num == 6 || num == 7 || num == 8)
		printf("\t\t-      ?     -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 11)
		printf("\t\t-      ?     -\t\t\t\t\t\t\t-       %s   -\n", a.symbol);
	else if (num == 12)
		printf("\t\t-      ?     -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 13)
		printf("\t\t-      ?     -\t\t\t\t\t\t\t- %s%s       -\n", a.symbol, a.symbol);
	else
		printf("\t\t-      ?     -\t\t\t\t\t\t\t-            -\n");
	if (num == 2 || num == 7 || num == 8)
		printf("\t\t-            -\t\t\t\t\t\t\t-     %s     -\n", a.symbol);
	else if (num == 9 || num == 10)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 11)
		printf("\t\t-            -\t\t\t\t\t\t\t-       %s   -\n", a.symbol);
	else if (num == 12)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s   %s %s -\n", a.symbol, a.symbol, a.symbol);
	else if (num == 13)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s  %s     -\n", a.symbol, a.symbol);
	else
		printf("\t\t-            -\t\t\t\t\t\t\t-            -\n");
	if (num == 4 || num == 5)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 3 || num == 10)
		printf("\t\t-            -\t\t\t\t\t\t\t-     %s     -\n", a.symbol);
	else if (num == 11)
		printf("\t\t-            -\t\t\t\t\t\t\t-   %s  %s   -\n", a.symbol, a.symbol);
	else if (num == 12)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s     %s  -\n", a.symbol, a.symbol);
	else if (num == 13)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s    %s   -\n", a.symbol, a.symbol);
	else printf("\t\t-            -\t\t\t\t\t\t\t-            -\n");
	if (num == 6 || num == 7 || num == 8 || num == 9 || num == 10)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else if (num == 11)
		printf("\t\t-            -\t\t\t\t\t\t\t-    %s%s    -\n", a.symbol, a.symbol);
	else if (num == 12)
		printf("\t\t-            -\t\t\t\t\t\t\t-  %s%s%s %s -\n", a.symbol, a.symbol, a.symbol, a.symbol);
	else if (num == 13)
		printf("\t\t-            -\t\t\t\t\t\t\t- %s      %s -\n", a.symbol, a.symbol);
	else printf("\t\t-            -\t\t\t\t\t\t\t-            -\n");
	printf("\t\t--------------\t\t\t\t\t\t\t--------------\n\n");
}

//플레이어의 카드를 출력해주는 함수
int print_my_card(card a)
{
	int num;
	num = a.number;
	printf("\n\t\tME");
	printf("\n\t\t--------------\n");
	Sleep(1000);
	if (num == 6 || num == 7 || num == 8 || num == 9 || num == 10)
	{
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(800);
	}
	else if (num == 11)
	{
		printf("\t\t-     %s%s%s -\n", a.symbol, a.symbol, a.symbol);
		Sleep(800);
	}
	else if (num == 12)
	{
		printf("\t\t-  %s%s%s%s  -\n", a.symbol, a.symbol, a.symbol, a.symbol);
		Sleep(800);
	}
	else if (num == 13)
	{
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(800);
	}
	else
	{
		printf("\t\t-            -\n");
		Sleep(800);
	}

	if (num == 4 || num == 5)
	{
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(600);
	}
	else if (num == 3 || num == 10)
	{
		printf("\t\t-     %s     -\n", a.symbol);
		Sleep(600);
	}
	else if (num == 11)
	{
		printf("\t\t-       %s   -\n", a.symbol);
		Sleep(600);
	}
	else if (num == 12)
	{
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(600);
	}
	else if (num == 13)
	{
		printf("\t\t- %s    %s   -\n", a.symbol, a.symbol);
		Sleep(600);
	}
	else
	{
		printf("\t\t-            -\n");
		Sleep(600);
	}
	if (num == 2 || num == 8)
	{
		printf("\t\t-     %s     -\n", a.symbol);
		Sleep(300);
	}
	else if (num == 9 || num == 10) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(300);
	}
	else if (num == 11) {
		printf("\t\t-       %s   -\n", a.symbol);
		Sleep(300);
	}
	else if (num == 12) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(300);
	}
	else if (num == 13)
	{
		printf("\t\t- %s  %s     -\n", a.symbol, a.symbol);
		Sleep(300);
	}
	else
	{
		printf("\t\t-            -\n");
		Sleep(300);
	}
	if (num == 1 || num == 3 || num == 5 || num == 9) {
		printf("\t\t-     %s     -\n", a.symbol);
		Sleep(100);
	}
	else if (num == 6 || num == 7 || num == 8) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 11) {
		printf("\t\t-       %s   -\n", a.symbol);
		Sleep(100);
	}
	else if (num == 12) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 13) {
		printf("\t\t- %s%s       -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else {
		printf("\t\t-            -\n");
		Sleep(100);
	}
	if (num == 2 || num == 7 || num == 8) {
		printf("\t\t-     %s     -\n", a.symbol);
		Sleep(100);
	}
	else if (num == 9 || num == 10) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 11) {
		printf("\t\t-       %s   -\n", a.symbol);
		Sleep(100);
	}
	else if (num == 12) {
		printf("\t\t- %s   %s %s -\n", a.symbol, a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 13) {
		printf("\t\t- %s  %s     -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else {
		printf("\t\t-            -\n");
		Sleep(100);
	}
	if (num == 4 || num == 5) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 3 || num == 10) {
		printf("\t\t-     %s     -\n", a.symbol);
		Sleep(100);
	}
	else if (num == 11) {
		printf("\t\t-   %s  %s   -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 12) {
		printf("\t\t- %s     %s  -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 13) {
		printf("\t\t- %s    %s   -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else {
		printf("\t\t-            -\n");
		Sleep(100);
	}
	if (num == 6 || num == 7 || num == 8 || num == 9 || num == 10) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 11) {
		printf("\t\t-    %s%s    -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 12) {
		printf("\t\t-  %s%s%s %s -\n", a.symbol, a.symbol, a.symbol, a.symbol);
		Sleep(100);
	}
	else if (num == 13) {
		printf("\t\t- %s      %s -\n", a.symbol, a.symbol);
		Sleep(100);
	}
	else printf("\t\t-            -\n");
	printf("\t\t--------------\t\t");

}

//베팅 후 카드의 승패를 결정해주는 함수
int rank_card(card me, card dealer)
{
	//숫자로 승패를 가릴 수 있을 경우
	if (me.number > dealer.number)
	{
		print_my_card(me);
		sys_print("my card : ");
		print_card(me);
		sys_print("\t\tdealer card : ");
		print_card(dealer);

		sys_print("\n\n\t\t\t\t\tME WIN !!!\n");
		return 1;
	}
	else if (me.number < dealer.number)
	{
		print_my_card(me);
		sys_print("my card : ");
		print_card(me);
		sys_print("\t\tdealer card : ");
		print_card(dealer);

		sys_print("\n\n\t\t\t\t\tDEALER WIN !!!\n");
		return 2;
	}
	//숫자가 같을 경우는 모양의 우선순위를 비교
	else if (me.number == dealer.number)
	{
		if (precedence_card(me) > precedence_card(dealer))
		{
			print_my_card(me);
			sys_print("my card : ");
			print_card(me);
			sys_print("\t\tdealer card : ");
			print_card(dealer);

			sys_print("\n\n\t\t\t\t\tME WIN !!!\n");
			return 1;
		}
		else if (precedence_card(me) < precedence_card(dealer))
		{
			print_my_card(me);
			sys_print("my card : ");
			print_card(me);
			sys_print("\t\tdealer card : ");
			print_card(dealer);

			sys_print("\n\n\t\t\t\t\tDEALER WIN !!!\n");
			return 2;
		}
	}
}
//인디언포커 메인 함수
void game_indianpoker(player* a)
{
	card player1, player2;//1은 사용자, 2는 딜러
	int bet;
	int stop = 0;

	int sel1 = 0;
	sys_print("딜러 : 인디언 포커 게임을 플레이합니다.\n");
	sys_print("딜러 : 게임 설명을 듣고 싶으시면 1, 바로 시작하시려면 다른 키를 입력하세요.\n");
	sel1 = sys_select();
	if (sel1 == 1) {
		sys_print("  Indian Poker는 자신의 카드를 보지 않은채 상대방의 카드만을 보고 베팅하는 포커입니다.\n");
		sys_print("  일반적인 포커와는 다르게 단 2장의 카드로 승부하기에 다른 복잡한 카드 게임에 비해 입문할때 좋은 선택지가 될 수 있겠네요\n");
		sys_print("  덱은 일반적인 카드뭉치와 같이 52장의 카드로 이루어져 있습니다.\n");
		sys_print("  덱에 남은 카드를 기억하고 있다면, 승패에 대한 예측이 좀 더 쉬울 수 있겠죠?\n");
		sys_gonext();
	}
	
	system("cls");
	print_indianpoker();//시각적 효과


	while (a->gold > 0)//골드가 바닥나면 게임 종료
	{
		system("cls");
		print_indianpoker();//시각적 효과
		if (is_empty_deck == 1)
			make_standard_deck();
		make_standard_deck();
		player1 = draw_card();
		player2 = draw_card();//서로 한 장씩 카드를 뽑는다
		print_table(player2);//먼저 딜러의 카드를 화면에 출력

		while (1)
		{
			printf("\tmy gold : %d\n", a->gold);
			sys_print("\tBetting gold : ");
			rewind(stdin);
			scanf("%d", &bet);//베팅금 입력받음
			rewind(stdin);

			if (bet > a->gold)//보유골드 이상을 베팅했을 경우 다시 베팅
			{
				sys_print("\ttoo much betting, try again\n\n");
				continue;
			}
			else if (bet == a->gold)//보유골드와 베팅금이 같을 경우 ALL IN 출력
			{
				sys_print("\tALL-IN!!\n\n");
				a->gold -= bet;//베팅금 차감
				break;
			}
			else if (bet < a->gold && bet > 0)//정상 베팅
			{
				printf("\t%d gold is betted\n\n", bet);
				a->gold -= bet;//베팅금 차감
				break;
			}
			else if (bet <= 0)//0이하의 금액을 베팅했을 경우 다시 베팅
			{
				sys_print("\tbet more than 0 gold\n\n");
				continue;
			}
		}
		if (rank_card(player1, player2) == 1)//사용자의 카드가 딜러의 카드보다 높을 경우
		{
			a->gold += 2 * bet;//게임 승리 및 베팅금의 2배 획득
		}
		sys_print("\n\n\n딜러 : 계속 플레이 하시겠습니까?");
		sys_print("\n\t계속하려면 1번\t\t\t그만두려면 다른키를 입력하세요\n\n\n");
		stop = sys_select();
		if (stop == 1)
			continue;
		else
			break;
	}


	system("cls");
	Sleep(1000);
	sys_print("녹초가 된 몸을 이끌며 카지노를 나섰다.\n");
	sys_print("아... 머리아파...\n");
	sys_print("도박은 이래서 하면 안된다는 거구나.\n");

	sys_print("★도박상담전화는 국번없이 1336★\n");
	sys_gonext();

	//게임 끝나면 무조건 넣어야 하는 함수들
	sys_playerstat(a);//캐릭터 현재 상태 표시
	sys_checkend(a);//캐릭터 엔딩 조건 달성했는지 확인
	sys_gonext();
}