//슬롯머신 미니게임 소스코드

#include "header.h"

//당첨 사례와 사례 금액을 출력하는 함수
void display_rule(void)
{
    sys_gotoxy(52, 7);
    printf("조합 릴1 릴2 릴3    사례금\n");

    sys_gotoxy(51, 8);
    printf("---------------------------\n");

    sys_gotoxy(50, 9);
    printf("   1:    ★ ★ ★\t  *10\n");

    sys_gotoxy(50, 10);
    printf("   2:    ♠ ♠ ♠\t   *7\n");

    sys_gotoxy(50, 11);
    printf("   3:    ◆ ◆ ◆\t   *5\n");

    sys_gotoxy(50, 12);
    printf("   4:    ★ ★ 기타\t   *4\n");

    sys_gotoxy(50, 13);
    printf("   5:    ♠ ♠ 기타\t   *3\n");

    sys_gotoxy(50, 14);
    printf("   6:    ◆ ◆ 기타\t   *3\n");

    sys_gotoxy(50, 15);
    printf("   7:    ♥ ♥ 기타\t   *3\n");

    sys_gotoxy(50, 16);
    printf("   8:    ♣ ♣ 기타\t   *2\n");

    sys_gotoxy(50, 17);
    printf("   9:    ○ ○ 기타\t   *1\n");
}

//각 릴에 대한 기호의 순서를 결정하는 함수
void reel_series(int r[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            r[j][i] = (r[0][i] + j) % 6;
}

//게임 진행상황과 배팅 금액을 입력받아 반환하는함수
int game_progress(int* money)
{
    int bet;

    sys_gotoxy(1, 20);
    printf("현재 남은 금액: %d골드     ", *money);

    sys_gotoxy(45, 20);
    printf("--------------<GUIDE>--------------");

    sys_gotoxy(45, 21);
    printf("| 배팅금액을 입력하고 Enter키 입력 |");

    sys_gotoxy(45, 22);
    printf("| 0을 입력하면 종료합니다.         |");

    sys_gotoxy(45, 23);
    printf("-----------------------------------");

    sys_gotoxy(1, 17);
    printf("게임을 시작합니다. 금액 입력>");

    sys_gotoxy(30, 17);
    scanf_s("%d", &bet);

    sys_gotoxy(1, 18);
    printf("아무키나 한번만 키를 누르면 릴이 멈춥니다.");

    return bet;
}

//화면에 표시된 지시어들을 지우는 함수
void clear_text(void)
{
    int i, j;

    for (i = 17; i < 20; i++)
    {
        sys_gotoxy(1, i);

        for (j = 0; j < 42; j++)
            printf(" ");
    }
}

//회전순서에 따라 릴을 화면에 출력하는 함수
void display_reel(char rc[][3], int r[][3], int index)
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            sys_gotoxy(13 + j * 4, 10 + i * 2);
            printf("%s", rc[r[i][j]]);
        }
}

//슬롯머신게임을 제어하는 함수
int game_control(char reel[][3], int reel_num[][3], int* money)
{
    int i, j, bet, case_num = 0, thank, num[3];
    double pst;
    clock_t start, end;

    display_reel(reel, reel_num, 0);

    bet = game_progress(money);
    if (bet == 0) // 만약 게임 종료를 입력하면 1반환
        return 1;

    else if ((*(money)-bet) < 0)
    {
        while ((*(money)-bet) < 0) {
            sys_gotoxy(1, 18);
            printf("골드가 부족합니다. 다시 베팅하십시오.       \n");
            bet = game_progress(money);
            if (bet == 0)
                return 1;
        }
    }

    for (i = 0; i < 3; i++)
    {
        start = clock();

        do
        {
            for (j = i; j < 3; j++)
                reel_num[0][j] = reel_num[1][j];

            reel_series(reel_num);

            display_reel(reel, reel_num, i);

            end = clock();
            pst = (double)(end - start) / CLK_TCK;

        } while (!kbhit() || (pst < 1));

        num[i] = reel_num[1][i];
    }

    getch();

    thank = return_money(num, bet, &case_num);

    if (thank == 0)
        *money -= bet;

    else
        *money += thank;

    if (case_num)
    {
        sys_gotoxy(1, 21);

        printf("조합:%d, 배팅:%d골드, 사례금:%d골드", case_num, bet, thank);
    }

    clear_text();
}

//당첨사례따라배팅 금액과 사례금을 계산하는 함수
int return_money(int r[], int betting, int* case_num)
{
    int total = 0;

    if (r[0] == r[1] && r[1] == r[2] && r[0] == r[2])
    {
        if (r[0] == 0)
        {
            total = betting * 10;
            *case_num = 1;
        }

        else if (r[0] == 1)
        {
            total = betting * 7;
            *case_num = 2;
        }

        else if (r[0] == 2)
        {
            total = betting * 5;
            *case_num = 3;
        }

    }

    else if ((r[0] == 0 && r[1] == 0) || (r[1] == 0 && r[2] == 0) || (r[0] == 0 && r[2] == 0))
    {
        total = betting * 4;
        *case_num = 4;
    }

    else if ((r[0] == 1 && r[1] == 1) || (r[1] == 1 && r[2] == 1) || (r[0] == 1 && r[2] == 1))
    {
        total = betting * 3;
        *case_num = 5;
    }

    else if ((r[0] == 2 && r[1] == 2) || (r[1] == 2 && r[2] == 2) || (r[0] == 2 && r[2] == 2))
    {
        total = betting * 3;
        *case_num = 6;
    }

    else if ((r[0] == 3 && r[1] == 3) || (r[1] == 3 && r[2] == 3) || (r[0] == 3 && r[2] == 3))
    {
        total = betting * 3;
        *case_num = 7;
    }

    else if ((r[0] == 4 && r[1] == 4) || (r[1] == 4 && r[2] == 4) || (r[0] == 4 && r[2] == 4))
    {
        total = betting * 2;
        *case_num = 8;
    }

    else if ((r[0] == 5 && r[1] == 5) || (r[1] == 5 && r[2] == 5) || (r[0] == 5 && r[2] == 5))
    {
        total = betting * 1;
        *case_num = 9;
    }

    return total;
}

int game_slotmachine(player* a)
{
    sys_print("슬롯 머신 게임으로 이동 중 . . .");

    system("cls");

    char reel[6][3] = { "★","♠","◆","♥","♣","○" };

    int i, reel_num[3][3];


    srand(time(NULL));

    printf("   _____ _      ____ _______   __  __          _____ _    _ _____ _   _ ______ \n");
    printf("  / ____| |    / __ W__   __| |  W/  |   /W   / ____| |  | |_   _| W | |  ____|\n");
    printf(" | (___ | |   | |  | | | |    | W  / |  /  W | |    | |__| | | | |  W| | |__   \n");
    printf("  W___ W| |   | |  | | | |    | |W/| | / /W W| |    |  __  | | | | . ` |  __|  \n");
    printf("  ____) | |___| |__| | | |    | |  | |/ ____ W |____| |  | |_| |_| |W  | |____ \n");
    printf(" |_____/|______W____/  |_|    |_|  |_/_/    W_W_____|_|  |_|_____|_| W_|______|\n");


    display_rule();

    sys_gotoxy(13, 8);

    printf("릴1 릴2 릴3");

    sys_gotoxy(11, 9);

    for (i = 0; i < 3; i++)
        reel_num[0][i] = rand() % 5;

    reel_series(reel_num);

    do {
        if (game_control(reel, reel_num, &a->gold) == 1) // 만약 게임 진행 중 0 입력해서 게임 종료했을 때 1 반환되므로 break; 
            break;
    } while (a->gold>0); // 골드가 0이되면 끝
    
    system("cls");

    //게임 끝나면 무조건 넣어야 하는 함수들
    sys_playerstat(a);//캐릭터 현재 상태 표시
    sys_checkend(a);//캐릭터 엔딩 조건 달성했는지 확인
    sys_gonext();
}
