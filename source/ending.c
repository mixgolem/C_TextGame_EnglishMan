//������ ���õ� �Լ��� �ҽ��ڵ�

#include "���.h"

void end_print_clear()	//���� Ŭ����� �ð��� ȿ��
{

	system("cls");
	PlaySound(TEXT("happy_end.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);	//���� Ŭ���� BGM
	Sleep(1000);
	sys_gotoxy(16, 4);
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������\n\n\n");
	Sleep(100);
	sys_gotoxy(35, 13);
	sys_print("<������ ������ �Ż簡 �Ȱ��� �����մϴ� !!!>\n\n");
}

void end_print_gameover() {	//���ӿ����� �ð���ȿ��
	system("cls");
	PlaySound(TEXT("bad_end.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);	//���� ���� BGM
	Sleep(1000);
	sys_gotoxy(31, 4);
	printf("��������������������������������������������������������������������������������������������������������������\n");
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
	printf("��������������������������������������������������������������������������������������������������������������\n\n\n");
}

void end_goldzero() //���0����
{
	Sleep(1000);
	end_print_gameover();
	sys_print("����... ���� ���ݾ�....\n");
	sys_print("�̴�� ��°� �ǹ̴� ������ �� �ñ���\n");
	Sleep(300);
	sys_print("��� ���� : ������ �Ǿ� ���� ��Ÿ��� ���ƴٴϴٰ� ��� �׾���.\n");
	sys_gonext();
	exit(1);
}

void end_hpzero() //ü��0����
{
	Sleep(1000);
	end_print_gameover();
	sys_print("��..?�Ӹ��� �ʹ� ��������..?\n");
	sys_print("(öǪ��..)\n");
	sys_print("����... �������� �ʾ�....\n");
	sys_print("��...��....\n");
	Sleep(300);
	sys_print("��� ���� : ü���� 0�� �Ǿ� Ż���ؼ� �׾���.");
	sys_gonext();
	exit(1);
}

void end_strzero() //��0����
{
	Sleep(1000);
	end_print_gameover();
	sys_print("����... ���� ����� ����...\n");
	sys_print("������... ���ϰھ�...\n");
	sys_print("(�н�)\n");
	sys_print("�� ���� �λ��̿���...\n");
	Sleep(300);
	sys_print("��� ���� : ���� 0�� �Ǿ� �濡�� �����ߴ�.");
	sys_gonext();
	exit(1);
}

void end_dexzero() //��ø0����
{
	Sleep(1000);
	end_print_gameover();
	sys_print("(���ƾƾƾƾƾ�)\n");
	sys_print("��... Ʈ���� �������� �����־�...!\n");
	sys_print("���ؾ�... �ϴµ�.... �ϴµ�....!!\n");
	sys_print("�ٸ���... ���ſ�...\n");
	sys_print("(������������)\n");
	sys_print("(��)\n");
	Sleep(300);
	sys_print("��� ���� : ��ø�� 0�� �Ǿ� ������� �׾���.");
	sys_gonext();
	exit(1);
}

void sys_checkend(player* a) //���������� Ȯ����, �̿� �ش�ȴٸ� ��� �ϰ� �ش���� �ʴ´ٸ� ���� X
{
	if (a->gold <= 0)//��尡 0 ����
	{
		end_goldzero();
	}
	else if (a->hp <= 0)//ü���� 0 ����
	{
		end_hpzero();
	}
	else if (a->str <= 0)//���� 0 ����
	{
		end_strzero();
	}
	else if (a->dex <= 0)//��ø�� 0 ����
	{
		end_dexzero();
	}
	switch (a->charnum)//ĳ���� ��ȣ�� �°Բ� Ŭ���� ��� ���
	{
	case 1:
		if (a->gold >= CHARNUM1_CLR_GOLD)//������ Ŭ��������
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("��� ���� �ص� ����ؼ� ������ ����� ���� �� ������ ������.\n");
			sys_print("������ �������� ��Ƴ��� ���� ���� �ķ� ���� ���� ������!\n");
			sys_print("�������� ��ȣ�� �� ������!! ���� �ճ��� �����Ѵ�!!\n");
			Sleep(1000);
			sys_gonext();

			exit(1);
		}
		break;
	case 2:
		if ((a->gold >= CHARNUM2_CLR_GOLD) && (a->dex >= CHARNUM2_CLR_DEX))//�տ�� Ŭ��������
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("������� ���ķ� ���� ���İ��� �տ��.\n");
			sys_print("������ �״� �����ϱ�� Ŀ�� ������ �������� ��Ƴ��Ҵ�.\n");
			sys_print("������ ���� ������ �����δ� ������ �ϴµ��� �����Ѵ�.\n");
			sys_print("����... �ٽ� �౸�� �� �� ���� �� ����!!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	case 3:
		if ((a->gold >= CHARNUM3_CLR_GOLD) && (a->hp >= CHARNUM3_CLR_HP) && (a->str >= CHARNUM3_CLR_STR))//��ſ� Ŭ��������
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("���...? �� ���� ��ǥ�� ������... ... ...\n");
			sys_print("�´�!!!\n");
			sys_print("�� ��ü���ͷ� ���ư��� ���ݾ�!!!\n");
			sys_print("������ ��� ������ ��ü���ͷ� ���ư��� �ϴ� ���� ������ ���ø� ��ſ�.\n");
			sys_print("���... ��!!! ����Ÿ�� ������!!! �� �� �ٽ� �پ�°ž�!!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	case 4:
		if ((a->gold >= CHARNUM4_CLR_GOLD) && (a->hp >= CHARNUM4_CLR_HP) && (a->str >= CHARNUM4_CLR_STR) && (a->dex >= CHARNUM4_CLR_DEX))//���θ� Ŭ��������
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("���� ������ ���� �̻��� ���� �౸�� �׸��ΰ� �� ���θ�.\n");
			sys_print("������ ���� �ϰ���� �౸�� ���� ū ������ ��������\n");
			sys_print("���� ���� ��� ������ ��������� ������ ��⸦ ���� �޲��\n");
			sys_print("������ ����� ���� ��ġ�� ������ ���θ�!! �ǰ��ϰԸ� �ڶ�ٿ�!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	case 5:
		if ((a->gold >= CHARNUM5_CLR_GOLD) && (a->hp >= CHARNUM5_CLR_HP) && (a->str >= CHARNUM5_CLR_STR) && (a->dex >= CHARNUM5_CLR_DEX))//����� Ŭ��������
		{
			system("cls");
			end_print_clear();
			Sleep(300);
			sys_print("��ɵ� �ְ� ��µ� ������ �������� �ʹ� ���ߴ� �����.\n");
			sys_print("�������� �ؿ��� �౸�� �ϱ⿡�� �������� ������� �ʴ´�!!!\n");
			sys_print("1�� �౸ ���÷�𼭰� �Ǿ� ����鿡�� �౸�� �˷��ְ� �;�!!\n");
			sys_print("�״� ��ƽ�� ������ �ø��� �����߰�, ù ������� �������� ��ȸ���� ����ߴ�.\n");
			sys_print("���ܹ��� ���� �λ�, ��ǳó�� �ٽ� �����ϴٴ�!!! ���� ����ϴ�, �����!!\n");
			Sleep(1000);
			sys_gonext();
			exit(1);
		}
		break;
	}
}