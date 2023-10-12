//ī������� �̴ϰ��� �ҽ��ڵ�

#include "���.h"
#define CARD 14
int choicecard[CARD];//�÷��̾ ����ī��
int cardopen[CARD]; // ���µ�ī��

//14���� ī�带 ������� �����. 11223344556677 �� 14�� ����
void Setchoicecard()
{
    for (int ix = 0; ix < CARD; ix++)
    {
        //1 1 2 2 3 3 4 4 5 5  6  6  7  7
        //0 1 2 3 4 5 6 7 8 9 10 11 12 13
        int cardNum = (ix / 2) + 1;
        choicecard[ix] = cardNum;
    }
}
void Random() // ī�带 �����ִ� �Լ� 
{
    for (int ix = 0; ix < CARD; ix++)
    {

        int randIx = rand() % CARD;
        int temp = choicecard[ix];  // temp�� ix�ڸ��� ī�� �ӽ�����
        choicecard[ix] = choicecard[randIx];  //ix�ڸ��� �����ڸ� ī�带 ����
        choicecard[randIx] = temp; //�����ڸ��� temp�� ����� ixī�� ����
    }
}

//14���� ī�忡 �ʱⰪ �Ҵ�
void Initcard()
{
    for (int ix = 0; ix < CARD; ix++)
    {
        choicecard[ix] = -1;
        cardopen[ix] = 0;
    }
}
void Displaynum() //ī���� ���ڸ� �����ִ� �Լ�
{
    for (int n = 1; n <= 14; n++)
    {
        printf("%d \t", n);
    }
    printf("\n");
}
void Displaycardopen()//������ ī�带 �������ִ��Լ�
{
    for (int ix = 0; ix < CARD; ix++)
    {
        printf("%d \t", cardopen[ix]);
    }
    printf("\n");
}


int PlayGame()
{
    int end = 0, x = 0;
    while (1)
    {
        system("cls");
        Displaynum();
        Displaycardopen(); //ȭ�鿡 ī��� ��ȣ�� ���
        int num1, num2, numIx1, numIx2;
        //ù ��° ī��̱�
        while (1)
        {
            printf("ù ��° ������ ī�带 �����Ͻÿ�.  >>>>> ");
            scanf_s("%d", &num1);
            rewind(stdin);
            numIx1 = num1 - 1;
            if (num1 > 14 || num1 < 0) //1-14���� �����ܿ� �����Է½� �ٽ� �Է��ϰ�����
            {
                sys_print("�ٽ� �Է��ϼ���. \n");
                continue;
            }
            if (cardopen[numIx1] != 0) //�̹� ������ī�� ���ý� �������
            {
                sys_print("�̹� ������ ī���Դϴ�. �ٽ� �����ϼ���. \n");
                continue;
            }

            cardopen[numIx1] = choicecard[numIx1]; //������ī�尪�� ù���� ī����¹迭�� ����

            break;
        }
        //�� ��° ī��̱�
        while (1)
        {
            printf("�� ��° ������ ī�带 �����Ͻÿ�.  >>>>> ");
            scanf_s("%d", &num2);
            rewind(stdin);
            numIx2 = num2 - 1;
            if (num2 > 14 || num2 < 1)  //1-14���� �����ܿ� �����Է½� �ٽ� �Է��ϰ�����
            {
                sys_print("�ٽ� �Է��ϼ���. \n");
                continue;
            }
            if (cardopen[numIx2] != 0)
            {
                sys_print("�̹� ������ ī���Դϴ�. �ٽ� �����ϼ���. \n"); //�̹� ������ī�� ���ý� �������
                continue;
            }
            Displaynum();
            cardopen[numIx2] = choicecard[numIx2]; //������ī�尪�� �ι��� ī����¹迭�� ����
            Displaycardopen();
            break;
        }
        //�Ǵ�.ù���� ����ī��� �ι�° ���� ī�� ���Ͻ� �������� �Ǵ� ���̿ܿ��� �����Ǵ�
        if (cardopen[numIx1] == cardopen[numIx2])
        {
            sys_print("�������ϴ�! :) \n");
            Sleep(1000);
            end++;
        }
        else
        {
            sys_print("Ʋ�Ƚ��ϴ� :( \n");
            cardopen[numIx1] = 0;
            cardopen[numIx2] = 0;
            x++;
            Sleep(2000);
        }


        if (end == CARD / 2) break;

    }

    return x;
}
void Setchoicecard();
void Random();
void Display();
int game_matchingcard(player* a)
{
    int x = 0, score = 0;
    int sel = 0;
    system("cls");

    sys_print("���� : ī�� ������ ������ �÷����մϴ�.\n"); //���� ����
    sys_print("���� : ���� ������ ��� ������ 1\t\t�÷����Ϸ��� 2�� �Է��ϼ���.");
    sel = sys_select();
    if (sel == 1) {
        sys_print("���� : ī�带 �� �徿 �����ؼ� ī���� ¦�� ���߸� ī�尡 ���������� �����Դϴ�.\n");
        sys_print("���� : �ٸ� ī�� �� ���� �������� ���, ī�尡 ���������� �ʽ��ϴ�.\n");
        sys_print("���� : ��� ī���� ¦�� ���� �������� ���� �¸��Դϴ�.\n");
        sys_print("���� : ī�带 �������鼭 Ʋ�� Ƚ���� ���� ����, ���� ��带 ȹ���մϴ�.\n");
        sys_gonext();
    }
    system("cls");

    printf("3���� ���� �����մϴ�.");
    Sleep(1000);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b2���� ���� �����մϴ�.");
    Sleep(1000);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b1���� ���� �����մϴ�.");
    Sleep(1000);

    srand(time(NULL));
    Initcard();
    Setchoicecard();
    Random();
    x = PlayGame();
    sys_print("\n\n���� Ŭ����!!!\n");
    sys_print("Ʋ�� Ƚ�� : ");
    printf("%d\n", x);
    score = 150 - (5 * x);

    sys_print("ȹ�� ��� : ");
    printf("%d\n", score);
    a->gold += score;

    //���� ������ ������ �־�� �ϴ� �Լ���
    sys_playerstat(a);
    sys_checkend(a);
    sys_gonext();
}