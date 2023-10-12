//�Ҹ� ���� �ҽ��ڵ�

#include "header.h"

typedef struct card {
	int number;
	char* symbol;
}card;

//������� ��ü ī�� ��, �÷��̾��� ī��, ������ ī��, �ٴڿ� �������� ī��
card hg_deck[40], player1[40], player2[40], table[2];
int top_deck, top_player1 = -1, top_player2 = -1;
int i;

//�� ����� ī�带 1���� 5����, 2�徿 �� 40���� ī�� �� ����
void make_hg_deck(card* deck)
{
	for (i = 0; i < 10; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "��";
	}

	for (i = 10; i < 20; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "��";
	}

	for (i = 20; i < 30; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "��";
	}

	for (i = 30; i < 40; i++)
	{
		deck[i].number = i % 5 + 1;
		deck[i].symbol = "��";
	}
	top_deck = i - 1;
}

//ī�� ��ġ�� �����ϴ� �Լ�
void shuffle_hg_deck(card* deck)
{
	srand(time(NULL));
	int random;
	card buffer;
	for (i = 0; i < 40; i++)
	{
		random = rand() % 40;;//0���� 39���� ���� �߻�
		buffer = deck[i];//���ۿ� ���� 0��° �ε��� �Է�
		deck[i] = deck[random];//deck[0]�� deck[random] ī�� �Է�
		deck[random] = buffer;//deck[random]�� �ٽ� deck[0] ī�� �Է�
		//���� random�� 20�� ��, deck[0]�� deck[20]�� ī�尡 ���� �ٲ��
	}//�� ������ 40�� �ݺ� �� ī�� ������ ��� ���δ�.
}

//���� �︰ �� �ٴ��� ī�� ��ġ�� ���ڰ� �������µ�,
//�׷��� ��ģ ī�� ��ġ�� �ٽ� ���� �Լ�
void shuffle_player_deck(card* player, int count)
{//count������ �μ��� �޴µ� �̴� ī�带 ��ģ �� ���� �÷��̾��� ī�� ��ġ�� �� ī�� �����̴�.
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

//�÷��̾�� ������ ���� ī�带 ��������
void deal_hg_deck(card* deck, card* player1, card* player2)
{
	for (i = 0; i < 20; i++)//�÷��̾�� ���������� 20��
	{
		player1[i] = deck[i];
		top_player1 = i;
	}
	for (i = 20; i < 40; i++)//������ ������ 20���� ������
	{
		player2[i % 20] = deck[i];
		top_player2 = i % 20;
	}
	top_deck = 0;
}

//������ �� ������ �ӵ� ���������� ��ȯ (0.6��~1.2�� ����)
double hg_dspeed() {
	srand(time(NULL));
	double dspeed = 0;
	dspeed = ((rand() % 600) + 600);
	return dspeed/1000;
}

//�Ҹ����� ������ ������ ��츦 Ȯ���ϴ� �Լ�
int check_hg()
{
	double timediff = 0, dspeed = 0;
	clock_t start, end;
	char bell;

	//�Ҹ����� ������ ������ ���
	if (((table[0].symbol == table[1].symbol) && (table[0].number + table[1].number) == 5) || ((table[0].symbol != table[1].symbol) && (table[0].number == 5 || table[1].number == 5)))
	{
		start = clock();
		bell = getch();
		end = clock();
		timediff = (double)(end - start) / CLOCKS_PER_SEC;
		if (bell == 'q')
		{
			return 3;//���� ����
		}
		else if (bell == 'a') {
			printf("dealer : a�� ���� �︮�� ��ư�� �ƴϿ���, ���� �̰�׿�\n");
			return 2;//���� �¸�
		}
		else
		{
			dspeed = hg_dspeed();
			if (timediff < dspeed)//�������� ���� �︮�� ��ư 'a'�� �Է����� ���
			{
				printf("���� �����ӵ�: %.0lfms , ����� �����ӵ�: %.0lfms\n", 1000*dspeed, 1000*timediff);
				printf("dealer : ���� �����ñ���, ����� �̰�׿�\n");
				return 1;//�÷��̾� �¸�
			}
			else//������ ���� ������ ���
			{
				printf("���� �����ӵ�: %.0lfms , ����� �����ӵ�: %.0lfms\n", 1000 * dspeed, 1000 * timediff);
				printf("dealer : �����ó׿�, ���� �̰�׿�\n");
				return 2;//���� �¸�
			}
		}
	}
	else
		return 0;
}

//�Ҹ����� �������̽� ���
void print_interface_hg()
{
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("�������������������������������������������������������������\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t���� ī�� �� : %d\t\t������ ī�� �� :%d\t\t���̺��� ī�� �� :%d\t\t\t|\n", top_player1 + 1, top_player2 + 1, top_deck);
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t[A]ī�� �̱�, �� �Ѿ��\t\t[�ٸ� Ű]�� �︮��\t\t[Q]���� ����\t\t\t|\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

//ī�� ��� �Լ�
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
		printf("\t\t\t\t   ������ �����Ϸ��� [A]�� �Է��ϼ���\n");
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

//ó�� ���� ���� �� �ٴ��� ī��� 0������ ����
void init_table()
{
	table[0].number = 0;
	table[1].number = 0;
}

//�Ҹ����� ���� �Լ�
void game_hg(player* a)
{
	int sel_start = 0;
	sys_print("���� : �Ҹ� ���� ������ �÷����մϴ�.\n");
	sys_print("���� : ���� ������ ��� �����ø� [1] �ٷ� �����Ͻ÷��� �ٸ� Ű�� �Է��ϼ���.\n");
	sel_start = sys_select();
	if (sel_start == 1) {
		sys_print("\n�Ҹ������� 1���� 5���� ���� �����̵�, ���̾�, ��Ʈ, Ŭ�ι� ī�� ���� 2�徿 \n  �� 40���� ������ �÷����ϴ� �����Դϴ�.\n");
		sys_print("�������� ī�带 ���� ����, ����ڿ� ������ ī�带 20�徿 ���������ϴ�.\n");
		sys_print("������ ī�带 ������ ������ ����Ǹ�, ī�带 ��� ������ Ż���ϰ�\n  ���������� ī�尡 �����ִ� ����� �¸��ϰ� �˴ϴ�.\n");
		sys_print("�÷��̾� - ���� ������ ���ư��鼭, [A] ��ư���� ���� ī�带 �� �徿 ����� ������ �տ� ������ �����մϴ�.\n");
		sys_print("�ٴڿ� ���� ������ ī��� �߿��� ���� ����� ������ 5���� �Ǿ��ٸ�\n  [a�� ������] ��ư���� ���� �ִ��� ���� ġ�� �ٴ��� ī�带 �������ϴ�.\n");
		sys_print("�¸� �� 300��带 ȹ���ϰ�, �й� �� 100��带 �����ؾ� �մϴ�.\n");
		sys_gonext();
	}
	system("cls");

	make_hg_deck(hg_deck);//�� ����
	shuffle_hg_deck(hg_deck);//�� ����
	deal_hg_deck(hg_deck, player1, player2);//ī�带 ���� ��������
	char sel_1 = '\0';
	int check_1 = 0, check_2 = 0, quit = 0;
	init_table();//�ٴ� �ʱ�ȭ
	system("cls");
	print_hg(table[0], table[1]);//�ٴڿ� ī�带 ���
	getch();
	
	while (top_player1 > 0 && top_player2 > 0 && quit != 1 && sel_1 != 'q')//ī�带 ��� �Ҹ��ϰų� ������ �� ���� �ݺ�
	{
		table[0] = player1[top_player1--];//����ڰ� ���� �ٴڿ� ī�带 ���������� �÷��̾� ī�� ����
		hg_deck[top_deck++] = table[0];
		system("cls");
		print_hg(table[0], table[1]);
		printf("\n\n����ڰ� ī�带 �������ҽ��ϴ�.\n\n");
		check_1 = check_hg();
		fseek(stdin, 0, SEEK_END);
		//����ڰ� ���� ī�带 �������� �Ҹ����� ������ ������ ���
		if (check_1 == 1)//����ڰ� ���� ���� ���� ���
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player1[++top_player1] = hg_deck[i];
			}//�ٴڿ� ���������� ī�带 ������� ī�忡 ��ģ��
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);
			//����ڴ� ī�带 ��� ������ ī�带 �Ҿ��� ������ ������ ī�带 �����
			init_table();//�ٴ� �ʱ�ȭ
			continue;
		}
		else if (check_1 == 2)//������ ���� ���� ���� ���
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player2[++top_player2] = hg_deck[i];
			}//�ٴڿ� ���������� ī�带 ������ ī�忡 ��ģ��
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);
			//����ڴ� ī�带 �Ұ� ������ ī�带 ����� ������ ������ ī�带 �����
			init_table();//�ٴ� �ʱ�ȭ
			continue;
		}
		else if(check_1 == 3) {//q�� �Է��� ���� ��������� ���
			sys_print("\n\n������ �����մϴ�\n\n");
			sys_gonext();
			quit = 1;
			break;
		}
		if (sel_1 == 'q' || quit == 1) {//q������ ���� Ż�� �� �ٷ� �ݺ��� ����
			break;
		}
		

		while (1)
		{
			sel_1 = getch();
			if (sel_1 != 'a' && sel_1 != 'q')//�Ҹ����� ������ �������� �ʾҴµ� a�� ������ ���
			{
				printf("�����Դϴ�. ī�� 1�� �г�Ƽ\n\n");
				hg_deck[top_deck++] = player1[top_player1--];
				sel_1 = 0;
			}
			else if (sel_1 == 'q') {
				sys_print("\n\n������ �����մϴ�\n\n");
				sys_gonext();
				quit = 1;
				break;
			}
			else break;
		}
		if (sel_1 == 'q' || quit == 1) {//q������ ���� Ż�� �� �ٷ� �ݺ��� ����
			break;
		}


		//������ ī�带 �������� ��Ȳ
		printf("3���� ������ ī�� ��ο�");
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b2���� ������ ī�� ��ο�");
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b1���� ������ ī�� ��ο�");
		Sleep(1000);

		table[1] = player2[top_player2--];
		hg_deck[top_deck++] = table[1];//������ �ٴڿ� ������ ī�带 �������´�
		system("cls");
		print_hg(table[0], table[1]);
		printf("\n\n������ ī�带 �������ҽ��ϴ�.\n\n");
		check_2 = check_hg();
		//������ ī�带 �������Ҵµ� �Ҹ����� ���� ������ ���
		if (check_2 == 1)//����ڰ� ���� ���� ���� ���
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player1[++top_player1] = hg_deck[i];
			}//�ٴڿ� ���������� ī�带 ������� ī�忡 ��ģ��
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);//����ڴ� ī�带 ��� ������ ī�带 �Ҿ��� ������ ������ ī�带 �����
			init_table();//�ٴ� �ʱ�ȭ
			continue;
		}
		else if (check_2 == 2)//������ ���� ���� ���� ���
		{
			getch();
			for (i = 0; i < top_deck; i++)
			{
				player2[++top_player2] = hg_deck[i];
			}//�ٴڿ� ���������� ī�带 ������ ī�忡 ��ģ��
			top_deck = 0;
			shuffle_player_deck(player1, top_player1);
			shuffle_player_deck(player2, top_player2);//����ڴ� ī�带 �Ұ� ������ ī�带 ����� ������ ������ ī�带 �����
			init_table();//�ٴ� �ʱ�ȭ
			continue;
		}
		else if (check_1 == 3) {//q�� �Է��� ���� ��������� ���
			sys_print("\n\n������ �����մϴ�\n\n");
			sys_gonext();
			quit = 1;
		}
		if (sel_1 == 'q' || quit == 1) {//q������ ���� Ż�� �� �ٷ� �ݺ��� ����
			break;
		}

		while (1)
		{
			sel_1 = getch();
			if (sel_1 != 'a' && sel_1 != 'q')//�Ҹ����� ������ �������� �ʾҴµ� a�� ������ ���
			{
				printf("�����Դϴ�. ī�� 1�� �г�Ƽ\n\n");
				hg_deck[top_deck++] = player1[top_player1--];
				Sleep(1000);
				sel_1 = 0;
			}
			else if (sel_1 == 'q') {//q�Է½� ���� ����
				sys_print("\n\n������ �����մϴ�\n\n");
				quit = 1;
				break;
			}
			else break;
		}
		if (sel_1 == 'q' || quit == 1) {//q������ ���� Ż�� �� �ٷ� �ݺ��� ����
			break;
		}
	}

	if (top_player1 <= 0)
	{	
		sys_print("���� ���� ! ! !");
		sys_print("������� ī�尡 ��� �Ҹ�Ǿ����ϴ�.\n");//������� ī�尡 0���� �Ǹ� ���� �¸�
		sys_print("���� WIN ! ! ! !\n");
		sys_print("���ӿ��� �й��Ͽ� 100��带 �����ߴ�.\n");
		a->gold -= 100;
	}
	else if (top_player2 <= 0)
	{
		sys_print("���� ���� ! ! !");
		sys_print("������ ī�尡 ��� �Ҹ�Ǿ����ϴ�.\n");//������ ī�尡 0���� �Ǹ� ����� �¸�
		sys_print("����� WIN ! ! ! !");
		sys_print("���ӿ��� �¸��Ͽ� 300��带 ȹ���ߴ�.\n");
		a->gold += 300;
	}

	//���� ������ ������ �־�� �ϴ� �Լ���
	sys_playerstat(a);
	sys_checkend(a);
	sys_gonext();
}
