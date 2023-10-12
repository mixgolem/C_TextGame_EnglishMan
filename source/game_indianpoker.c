//�ε�� ��Ŀ �ҽ��ڵ�

#include "header.h"

//ī�� ����ü ����. ī��� ����� ���ڰ� ���� ����
typedef struct card {
	int number;
	char* symbol;
}card;

card deck[52];
int top = -1;

//�� ���� �Լ�
void make_deck(card* deck)
{
	int i = 0;
	for (i = 0; i < 13; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "��";
	}

	for (i = 13; i < 26; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "��";
	}

	for (i = 26; i < 39; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "��";
	}

	for (i = 39; i < 52; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].symbol = "��";
	}

	top = i - 1;
}

//�� ���� �Լ�
//�ݺ����� �̿��� ù ��° ī��� ������°�� ī���� ��ġ�� ���� �ٲ۴�
//�� ������ 52�� �ݺ��ϸ� ��� ī���� ��ġ�� ���̰� �ȴ�
void shuffle_deck(card* deck)
{
	srand(time(NULL));
	int i, random;
	card buffer;
	for (i = 0; i < 52; i++)
	{
		random = rand() % 52;//���� �߻�
		buffer = deck[i];//���ۿ� deck[0] �Է�
		deck[i] = deck[random];//deck[0]�� deck[����] ī�� �Է�
		deck[random] = buffer;//deck[����]�� ���� �Է��ϸ� �� ī���� ��ġ ��ü �Ϸ�
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

//pop�� ���� ����.
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

//ī�� ���ڿ� ��� ��� �Լ�
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

//11, 12, 13��° ī�带 J, Q, K�� ����ؾ� ��
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

//ī�� ����� �켱����. ���ڰ� �������� ����
int precedence_card(card ex)
{
	if (ex.symbol == "��")
		return 3;
	else if (ex.symbol == "��")
		return 2;
	else if (ex.symbol == "��")
		return 1;
	else if (ex.symbol == "��")
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

//ī���� ��� ����ڿ��� �������
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

//�÷��̾��� ī�带 ������ִ� �Լ�
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

//���� �� ī���� ���и� �������ִ� �Լ�
int rank_card(card me, card dealer)
{
	//���ڷ� ���и� ���� �� ���� ���
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
	//���ڰ� ���� ���� ����� �켱������ ��
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
//�ε����Ŀ ���� �Լ�
void game_indianpoker(player* a)
{
	card player1, player2;//1�� �����, 2�� ����
	int bet;
	int stop = 0;

	int sel1 = 0;
	sys_print("���� : �ε�� ��Ŀ ������ �÷����մϴ�.\n");
	sys_print("���� : ���� ������ ��� �����ø� 1, �ٷ� �����Ͻ÷��� �ٸ� Ű�� �Է��ϼ���.\n");
	sel1 = sys_select();
	if (sel1 == 1) {
		sys_print("  Indian Poker�� �ڽ��� ī�带 ���� ����ä ������ ī�常�� ���� �����ϴ� ��Ŀ�Դϴ�.\n");
		sys_print("  �Ϲ����� ��Ŀ�ʹ� �ٸ��� �� 2���� ī��� �º��ϱ⿡ �ٸ� ������ ī�� ���ӿ� ���� �Թ��Ҷ� ���� �������� �� �� �ְڳ׿�\n");
		sys_print("  ���� �Ϲ����� ī�并ġ�� ���� 52���� ī��� �̷���� �ֽ��ϴ�.\n");
		sys_print("  ���� ���� ī�带 ����ϰ� �ִٸ�, ���п� ���� ������ �� �� ���� �� �ְ���?\n");
		sys_gonext();
	}
	
	system("cls");
	print_indianpoker();//�ð��� ȿ��


	while (a->gold > 0)//��尡 �ٴڳ��� ���� ����
	{
		system("cls");
		print_indianpoker();//�ð��� ȿ��
		if (is_empty_deck == 1)
			make_standard_deck();
		make_standard_deck();
		player1 = draw_card();
		player2 = draw_card();//���� �� �徿 ī�带 �̴´�
		print_table(player2);//���� ������ ī�带 ȭ�鿡 ���

		while (1)
		{
			printf("\tmy gold : %d\n", a->gold);
			sys_print("\tBetting gold : ");
			rewind(stdin);
			scanf("%d", &bet);//���ñ� �Է¹���
			rewind(stdin);

			if (bet > a->gold)//������� �̻��� �������� ��� �ٽ� ����
			{
				sys_print("\ttoo much betting, try again\n\n");
				continue;
			}
			else if (bet == a->gold)//�������� ���ñ��� ���� ��� ALL IN ���
			{
				sys_print("\tALL-IN!!\n\n");
				a->gold -= bet;//���ñ� ����
				break;
			}
			else if (bet < a->gold && bet > 0)//���� ����
			{
				printf("\t%d gold is betted\n\n", bet);
				a->gold -= bet;//���ñ� ����
				break;
			}
			else if (bet <= 0)//0������ �ݾ��� �������� ��� �ٽ� ����
			{
				sys_print("\tbet more than 0 gold\n\n");
				continue;
			}
		}
		if (rank_card(player1, player2) == 1)//������� ī�尡 ������ ī�庸�� ���� ���
		{
			a->gold += 2 * bet;//���� �¸� �� ���ñ��� 2�� ȹ��
		}
		sys_print("\n\n\n���� : ��� �÷��� �Ͻðڽ��ϱ�?");
		sys_print("\n\t����Ϸ��� 1��\t\t\t�׸��η��� �ٸ�Ű�� �Է��ϼ���\n\n\n");
		stop = sys_select();
		if (stop == 1)
			continue;
		else
			break;
	}


	system("cls");
	Sleep(1000);
	sys_print("���ʰ� �� ���� �̲��� ī���븦 ������.\n");
	sys_print("��... �Ӹ�����...\n");
	sys_print("������ �̷��� �ϸ� �ȵȴٴ� �ű���.\n");

	sys_print("�ڵ��ڻ����ȭ�� �������� 1336��\n");
	sys_gonext();

	//���� ������ ������ �־�� �ϴ� �Լ���
	sys_playerstat(a);//ĳ���� ���� ���� ǥ��
	sys_checkend(a);//ĳ���� ���� ���� �޼��ߴ��� Ȯ��
	sys_gonext();
}