//카드뒤집기 미니게임 소스코드

#include "헤더.h"
#define CARD 14
int choicecard[CARD];//플레이어가 맞힐카드
int cardopen[CARD]; // 오픈될카드

//14장의 카드를 순서대로 만든다. 11223344556677 총 14장 생성
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
void Random() // 카드를 섞어주는 함수 
{
    for (int ix = 0; ix < CARD; ix++)
    {

        int randIx = rand() % CARD;
        int temp = choicecard[ix];  // temp에 ix자리의 카드 임시저장
        choicecard[ix] = choicecard[randIx];  //ix자리의 랜덤자리 카드를 저장
        choicecard[randIx] = temp; //랜덤자리에 temp에 저장된 ix카드 저장
    }
}

//14장의 카드에 초기값 할당
void Initcard()
{
    for (int ix = 0; ix < CARD; ix++)
    {
        choicecard[ix] = -1;
        cardopen[ix] = 0;
    }
}
void Displaynum() //카드의 숫자를 보여주는 함수
{
    for (int n = 1; n <= 14; n++)
    {
        printf("%d \t", n);
    }
    printf("\n");
}
void Displaycardopen()//선택한 카드를 오픈해주는함수
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
        Displaycardopen(); //화면에 카드와 번호들 출력
        int num1, num2, numIx1, numIx2;
        //첫 번째 카드뽑기
        while (1)
        {
            printf("첫 번째 뒤집을 카드를 선택하시오.  >>>>> ");
            scanf_s("%d", &num1);
            rewind(stdin);
            numIx1 = num1 - 1;
            if (num1 > 14 || num1 < 0) //1-14까지 범위외에 숫자입력시 다시 입력하게해줌
            {
                sys_print("다시 입력하세요. \n");
                continue;
            }
            if (cardopen[numIx1] != 0) //이미 뒤집은카드 선택시 오류출력
            {
                sys_print("이미 뒤집힌 카드입니다. 다시 선택하세요. \n");
                continue;
            }

            cardopen[numIx1] = choicecard[numIx1]; //선택한카드값을 첫번쨰 카드오픈배열에 저장

            break;
        }
        //두 번째 카드뽑기
        while (1)
        {
            printf("두 번째 뒤집을 카드를 선택하시오.  >>>>> ");
            scanf_s("%d", &num2);
            rewind(stdin);
            numIx2 = num2 - 1;
            if (num2 > 14 || num2 < 1)  //1-14까지 범위외에 숫자입력시 다시 입력하게해줌
            {
                sys_print("다시 입력하세요. \n");
                continue;
            }
            if (cardopen[numIx2] != 0)
            {
                sys_print("이미 뒤집힌 카드입니다. 다시 선택하세요. \n"); //이미 뒤집은카드 선택시 오류출력
                continue;
            }
            Displaynum();
            cardopen[numIx2] = choicecard[numIx2]; //선택한카드값을 두번쨰 카드오픈배열에 저장
            Displaycardopen();
            break;
        }
        //판단.첫번쨰 선택카드와 두번째 선택 카드 동일시 정답으로 판단 그이외에는 오답판단
        if (cardopen[numIx1] == cardopen[numIx2])
        {
            sys_print("맞혔습니다! :) \n");
            Sleep(1000);
            end++;
        }
        else
        {
            sys_print("틀렸습니다 :( \n");
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

    sys_print("딜러 : 카드 뒤집기 게임을 플레이합니다.\n"); //게임 설명
    sys_print("딜러 : 게임 설명을 듣고 싶으면 1\t\t플레이하려면 2를 입력하세요.");
    sel = sys_select();
    if (sel == 1) {
        sys_print("딜러 : 카드를 두 장씩 선택해서 카드의 짝을 맞추면 카드가 뒤집어지는 게임입니다.\n");
        sys_print("딜러 : 다른 카드 두 장을 선택했을 경우, 카드가 뒤집어지지 않습니다.\n");
        sys_print("딜러 : 모든 카드의 짝을 맞춰 뒤집으면 게임 승리입니다.\n");
        sys_print("딜러 : 카드를 뒤집으면서 틀린 횟수가 적을 수록, 많은 골드를 획득합니다.\n");
        sys_gonext();
    }
    system("cls");

    printf("3초후 게임 시작합니다.");
    Sleep(1000);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b2초후 게임 시작합니다.");
    Sleep(1000);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b1초후 게임 시작합니다.");
    Sleep(1000);

    srand(time(NULL));
    Initcard();
    Setchoicecard();
    Random();
    x = PlayGame();
    sys_print("\n\n게임 클리어!!!\n");
    sys_print("틀린 횟수 : ");
    printf("%d\n", x);
    score = 150 - (5 * x);

    sys_print("획득 골드 : ");
    printf("%d\n", score);
    a->gold += score;

    //게임 끝나면 무조건 넣어야 하는 함수들
    sys_playerstat(a);
    sys_checkend(a);
    sys_gonext();
}