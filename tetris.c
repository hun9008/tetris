#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#define VER 22
#define HOR 12
void block(i, k, t);
void print();
void type_f(n);
char out[100][100];
int in[VER][HOR] = { 0 }; //가로 36, 세로 60, 크기를 바꿀경우 print()도 바꿔줘야함
void erase(i, k, t, n);
void turn(i, k, t, n);
void block_down(k);
int position_rows = 0;
int position_cols = 0;
void block_move(k);
void movement_right(k);
void movement_left(k);
void movement_turn(k);
int count = 0;
int repeat;
int stack(int i, int k, int t, int n);
int side_stack(int i, int k, int t, int n);
int check_line(j);
void check_move();
int check_finish();
int check_line_ex(j);
void ending();
void opening();
int condition_not_turn(int k);
point = 0;
void print_point();



struct block {
    int type; //7가지;
    int cols_type; //4가지;
    int spin; //4가지;
};
struct block b[100] = { 0, 0, 0 };


int main(void)
{
    //outline(32, 20);
    //print_outline(32);
    int i;
    int n = 0; //블럭 번호
    opening();
    while (1)
    {
        srand(time(NULL));
        type_f(n);
        block(position_rows, position_cols, b[n].type);
        print();

        if (b[n].type == 0)
        {
            repeat = VER - 2;
        }
        else if (b[n].type == 6)
        {
            repeat = VER - 4;
        }
        else
        {
            repeat = VER - 3;
        }

        for (i = 0; i < repeat; i++)
        {
            block_down(n);
            if (stack(position_rows, position_cols, b[n].type, n) == 1)
            {
                break;
            }
            block_move(n);
        }
        system("cls");
        check_move();
        system("cls");

        if (check_finish() == 1)
        {
            break;
        }
        position_rows = 0;
        position_cols = 0;
        count = 0;
        n++;
    }

    ending();

    return 0;
}

void print_point()
{
    printf("■■■■■■■■■■■■");
    if (HOR > 10)
    {
        for (int r = 0; r < HOR - 10; r++)
        {
            printf("■");
        }
    }
    printf("\n");

    printf("■                    ");
    if (HOR > 10)
    {
        for (int r = 0; r < HOR - 10; r++)
        {
            printf("  ");
        }
    }
    printf("■\n");
    printf("□       %2d,000       ", point);
    if (HOR > 10)
    {
        for (int r = 0; r < HOR - 10; r++)
        {
            printf("  ");
        }
    }
    printf("□\n");
    printf("■                    ");
    if (HOR > 10)
    {
        for (int r = 0; r < HOR - 10; r++)
        {
            printf("  ");
        }
    }
    printf("■\n");
    printf("■■■■■■■■■■■■");
    if (HOR > 10)
    {
        for (int r = 0; r < HOR - 10; r++)
        {
            printf("■");
        }
    }
    printf("\n\n");
}

void opening()
{
    printf("\n\n\n\n□■□■□■□■□■□■□■□■□■□■□\n");
    printf("■                                      ■\n");
    printf("□                                      □\n");
    printf("■                                      ■\n");
    printf("□                                      □\n");
    printf("■     시작하려면 s키를 입력하세요.     ■\n");
    printf("□                                      □\n");
    printf("■   왼쪽 : a / 오른쪽 : d / 회전 : w   ■\n");
    printf("□                                      □\n");
    printf("■                                      ■\n");
    printf("□■□■□■□■□■□■□■□■□■□■□\n");
    printf("  키보트 연타 시, 입력값이 모두 저장되고\n");
    printf("   다음 블록에도 적용되니 연타 금지!!   \n");

    int s;

    s = _getch();

    if (s == 115)
    {
        system("cls");
        printf("\n\n\n\n□■□■□■□■□■□■□■□■□■□■□\n");
        printf("■                                      ■\n");
        printf("□                                      □\n");
        printf("■               ■■■                 ■\n");
        printf("□                   ■                 □\n");
        printf("■               ■■■                 ■\n");
        printf("□                   ■                 □\n");
        printf("■               ■■■                 ■\n");
        printf("□                                      □\n");
        printf("■                                      ■\n");
        printf("□■□■□■□■□■□■□■□■□■□■□\n");
        Sleep(1000);

        system("cls");
        printf("\n\n\n\n□■□■□■□■□■□■□■□■□■□■□\n");
        printf("■                                      ■\n");
        printf("□                                      □\n");
        printf("■               ■■■                 ■\n");
        printf("□                   ■                 □\n");
        printf("■               ■■■                 ■\n");
        printf("□               ■                     □\n");
        printf("■               ■■■                 ■\n");
        printf("□                                      □\n");
        printf("■                                      ■\n");
        printf("□■□■□■□■□■□■□■□■□■□■□\n");
        Sleep(1000);

        system("cls");
        printf("\n\n\n\n□■□■□■□■□■□■□■□■□■□■□\n");
        printf("■                                      ■\n");
        printf("□                                      □\n");
        printf("■                 ■                   ■\n");
        printf("□               ■■                   □\n");
        printf("■                 ■                   ■\n");
        printf("□                 ■                   □\n");
        printf("■               ■■■                 ■\n");
        printf("□                                      □\n");
        printf("■                                      ■\n");
        printf("□■□■□■□■□■□■□■□■□■□■□\n");
        Sleep(1000);

        system("cls");
    }


}

void ending()
{
    system("cls");
    printf("\n\n  ■■■■      ■■■■      ■■  ■■      ■■■■\n");
    Sleep(100);
    printf("■              ■    ■      ■  ■  ■      ■\n");
    Sleep(100);
    printf("■    ■■■    ■■■■      ■  ■  ■      ■■■■\n");
    Sleep(100);
    printf("■      ■      ■    ■      ■      ■      ■\n");
    Sleep(100);
    printf("  ■■■■      ■    ■      ■      ■      ■■■■\n\n");
    Sleep(500);
    printf("  ■■■      ■■      ■■    ■■■■      ■■■■\n");
    Sleep(100);
    printf("■      ■      ■■  ■■      ■            ■      ■\n");
    Sleep(100);
    printf("■      ■        ■  ■        ■■■■      ■■■■\n");
    Sleep(100);
    printf("■      ■        ■■■        ■            ■      ■\n");
    Sleep(100);
    printf("  ■■■            ■          ■■■■      ■      ■\n\n");
    Sleep(300);
    printf("    ■■■■■■\n");
    Sleep(100);
    printf("  ■            ■\n");
    Sleep(100);
    printf("■                ■\n");
    Sleep(100);
    printf("■   ■      ■   ■\n");
    Sleep(100);
    printf("■                ■\n");
    Sleep(100);
    printf("■   ■■■■■   ■            최종 점수 : %d,000 point \n", point);
    Sleep(100);
    printf("■     ■  ■     ■\n");
    Sleep(100);
    printf("■     ■■■     ■\n");
    Sleep(100);
    printf("  ■            ■\n");
    Sleep(100);
    printf("    ■■■■■■                     Developer Y.H\n");
    Sleep(1000);
}

void block_move(int k)
{
    int net_turn = b[k].spin % 4;
    int m;
    if (_kbhit())
    {
        m = _getch();

        if (m == 100) // type과 cols_type을 고려하도록 변경해야함.
        {
            if (b[k].cols_type == 0)
            {
                if (position_cols < HOR - 4)
                {
                    movement_right(k);
                }
            }
            else if (b[k].cols_type == 1)
            {
                if (position_cols < HOR - 3)
                {
                    movement_right(k);
                }
            }
            else if (b[k].cols_type == 2)
            {
                if (position_cols < HOR - 2)
                {
                    movement_right(k);
                }
            }
            else if (b[k].cols_type == 3)
            {
                if (position_cols < HOR - 1)
                {
                    movement_right(k);
                }
            }
        }
        else if (m == 97)
        {

            if (position_cols > HOR - 10)
            {
                movement_left(k);
            }
            else if (position_cols <= HOR - 10 && count != 3)
            {
                if (net_turn > 1 && b[k].type == 0)
                {
                    movement_left(k);
                    count = 3;
                }
                else if (net_turn == 2 && b[k].type > 0 && b[k].type < 4)
                {
                    movement_left(k);
                    count = 3;
                }
                else if (net_turn == 1 && b[k].type > 3 && b[k].type < 6)
                {
                    movement_left(k);
                    count = 3;
                }
                else if (net_turn == 2 && b[k].type == 6)
                {
                    movement_left(k);
                    count++;
                }

            }
        }
        else if (m == 119) //w키
        {
            if (condition_not_turn(k) != 1)
            {
                movement_turn(k);
            }
        }
        else if (m == 32)
        {
            while (1)
            {
                erase(position_rows, position_cols, b[k].type, k);
                if (stack(position_rows, position_cols, b[k].type, k) == 1)
                {
                    break;
                }
                position_rows += 1;
                turn(position_rows, position_cols, b[k].type, k);
            }
            Sleep(300);
            system("cls");
            print();
        }
    }
}

int condition_not_turn(int k) // 회전 안되는 조건일때 1을 반환한다. 아니면 0
{
    int net_turn = b[k].spin % 4;

    if (b[k].type == 0)
    {
        if (net_turn == 1 && position_cols == HOR - 2)
        {
            return 1;
        }
        else if (net_turn == 3 && position_cols == HOR - 11)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (b[k].type < 4 && b[k].type > 0) //1~3
    {
        if (net_turn == 0 && position_cols == HOR - 2)
        {
            return 1;
        }
        else if (net_turn == 2 && position_cols == HOR -11)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (b[k].type < 6 && b[k].type > 3) //4~5
    {
        if (net_turn == 3 && position_cols == HOR - 2)
        {
            return 1;
        }
        else if (net_turn == 1 && position_cols == HOR -11)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (b[k].type == 6)
    {
        if (net_turn == 0 && position_cols > HOR - 4 && position_cols < HOR) //7~9
        {
            return 1;
        }
        else if (net_turn == 2 && position_cols > HOR -14 && position_cols < HOR - 10)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }


}

void movement_right(int k)
{
    if (side_stack(position_rows, position_cols, b[k].type, k) != 1)
    {
        system("cls");
        erase(position_rows, position_cols, b[k].type, k);
        position_cols += 1;
        turn(position_rows, position_cols, b[k].type, k);
        print();
    }
}

void movement_left(int k)
{
    if (side_stack(position_rows, position_cols, b[k].type, k) != 2)
    {
        system("cls");
        erase(position_rows, position_cols, b[k].type, k);
        position_cols -= 1;
        turn(position_rows, position_cols, b[k].type, k);
        print();
    }
}

void movement_turn(int k)
{
    system("cls");
    erase(position_rows, position_cols, b[k].type, k);
    b[k].spin += 1;
    turn(position_rows, position_cols, b[k].type, k);
    print();
}

void block_down(int k)
{
    Sleep(300);
    system("cls");
    erase(position_rows, position_cols, b[k].type, k);
    position_rows += 1;
    turn(position_rows, position_cols, b[k].type, k);
    print();
}






void block(int i, int k, int t)
{
    switch (t)
    {
    case 0:
        in[i][k] += 1;
        in[i][k + 1] += 1;
        in[i + 1][k] += 1;
        in[i + 1][k + 1] += 1;
        break;
    case 1:
        in[i][k] += 1;
        in[i + 1][k] += 1;
        in[i + 2][k] += 1;
        in[i + 2][k + 1] += 1;
        break;
    case 2:
        in[i][k + 1] += 1;
        in[i + 1][k] += 1;
        in[i + 1][k + 1] += 1;
        in[i + 2][k + 1] += 1;
        break;
    case 3:
        in[i][k + 1] += 1;
        in[i + 1][k + 1] += 1;
        in[i + 2][k + 1] += 1;
        in[i + 2][k] += 1;
        break;
    case 4:
        in[i + 1][k + 1] += 1;
        in[i + 1][k + 2] += 1;
        in[i + 2][k] += 1;
        in[i + 2][k + 1] += 1;
        break;
    case 5:
        in[i + 1][k] += 1;
        in[i + 1][k + 1] += 1;
        in[i + 2][k + 1] += 1;
        in[i + 2][k + 2] += 1;
        break;
    case 6:
        in[i][k] += 1;
        in[i + 1][k] += 1;
        in[i + 2][k] += 1;
        in[i + 3][k] += 1;
        break;
    default:
        break;
    }
}

void print()
{
    int i, k;
    printf("□□□□□□□□□□□□");
    if (HOR > 10)
    {
        for (int r = 0; r < HOR - 10; r++)
        {
            printf("□");
        }
    }
    printf("\n");
    for (i = 0; i < VER; i++)
    {
        printf("□");
        for (k = 0; k < HOR; k++)
        {
            if (in[i][k] == 1)
            {
                printf("■");
            }
            else if (in[i][k] == 0)
            {
                printf("  ");
            }


            //printf("%d", in[i][k]);
        }
        printf("□\n");
    }
    printf("□□□□□□□□□□□□");
    if (HOR > 10)
    {
        for (int r = 0; r < HOR - 10; r++)
        {
            printf("□");
        }
    }
    printf("\n");
    print_point();
}

void type_f(int n)
{
    srand(time(NULL));
    b[n].type = rand() % 7;
}

void erase(int i, int k, int t, int n)
{
    int net_turn = b[n].spin % 4;
    switch (t)
    {
    case 0:
        if (net_turn == 1)
        {
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 2;
        }
        else if (net_turn == 2)
        {
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;
            in[i + 2][k + 1] = 0;
            in[i + 2][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k + 1] = 0;
            in[i][k + 2] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 0)
        {
            in[i][k] = 0;
            in[i][k + 1] = 0;
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;

            b[n].cols_type = 2;
        }
        break;
    case 1:
        if (net_turn == 1)
        {
            in[i + 1][k + 2] = 0;
            in[i + 2][k] = 0;
            in[i + 2][k + 1] = 0;
            in[i + 2][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] = 0;
            in[i][k + 2] = 0;
            in[i + 1][k + 2] = 0;
            in[i + 2][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k] = 0;
            in[i][k + 1] = 0;
            in[i][k + 2] = 0;
            in[i + 1][k] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 0)
        {
            in[i][k] = 0;
            in[i + 1][k] = 0;
            in[i + 2][k] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 2;
        }
        break;
    case 2:
        if (net_turn == 1)
        {
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k + 1] = 0;
            in[i + 1][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;
            in[i][k + 1] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 0)
        {
            in[i][k + 1] = 0;
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 2;
        }
        break;
    case 3:
        if (net_turn == 1)
        {
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;
            in[i + 2][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] = 0;
            in[i][k + 2] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k] = 0;
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 0)
        {
            in[i][k + 1] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k + 1] = 0;
            in[i + 2][k] = 0;

            b[n].cols_type = 2;
        }
        break;
    case 4:
        if (net_turn == 1)
        {
            in[i][k + 1] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;
            in[i + 2][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] = 0;
            in[i][k + 2] = 0;
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k] = 0;
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 0)
        {
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;
            in[i + 2][k] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 1;
        }
        break;
    case 5:
        if (net_turn == 1)
        {
            in[i][k + 2] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;
            in[i + 2][k + 1] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k] = 0;
            in[i][k + 1] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 1][k + 2] = 0;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k + 1] = 0;
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k] = 0;

            b[n].cols_type = 2;
        }
        else if (net_turn == 0)
        {
            in[i + 1][k] = 0;
            in[i + 1][k + 1] = 0;
            in[i + 2][k + 1] = 0;
            in[i + 2][k + 2] = 0;

            b[n].cols_type = 1;
        }
        break;
    case 6:
        if (net_turn == 1)
        {
            in[i + 3][k] = 0;
            in[i + 3][k + 1] = 0;
            in[i + 3][k + 2] = 0;
            in[i + 3][k + 3] = 0;

            b[n].cols_type = 0;
        }
        else if (net_turn == 2)
        {
            in[i][k + 3] = 0;
            in[i + 1][k + 3] = 0;
            in[i + 2][k + 3] = 0;
            in[i + 3][k + 3] = 0;

            b[n].cols_type = 0;
        }
        else if (net_turn == 3)
        {
            in[i][k] = 0;
            in[i][k + 1] = 0;
            in[i][k + 2] = 0;
            in[i][k + 3] = 0;

            b[n].cols_type = 0;
        }
        else if (net_turn == 0)
        {
            in[i][k] = 0;
            in[i + 1][k] = 0;
            in[i + 2][k] = 0;
            in[i + 3][k] = 0;

            b[n].cols_type = 3;
        }
        break;
    default:
        break;
    }
}

void turn(int i, int k, int t, int n) //n은 블럭의 번호, t는 b[n].type의 값
{
    int net_turn = b[n].spin % 4;
    switch (t)
    {
    case 0:
        if (net_turn == 1)
        {
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 2;
            repeat = VER - 2;
        }
        else if (net_turn == 2)
        {
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;
            in[i + 2][k + 1] += 1;
            in[i + 2][k + 2] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k + 1] += 1;
            in[i][k + 2] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;

            b[n].cols_type = 1;
            repeat = VER - 1;
        }
        else if (net_turn == 0)
        {
            in[i][k] += 1;
            in[i][k + 1] += 1;
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;

            b[n].cols_type = 2;
        }
        break;
    case 1:
        if (net_turn == 1)
        {
            in[i + 1][k + 2] += 1;
            in[i + 2][k] += 1;
            in[i + 2][k + 1] += 1;
            in[i + 2][k + 2] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] += 1;
            in[i][k + 2] += 1;
            in[i + 1][k + 2] += 1;
            in[i + 2][k + 2] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k] += 1;
            in[i][k + 1] += 1;
            in[i][k + 2] += 1;
            in[i + 1][k] += 1;

            b[n].cols_type = 1;
            repeat = VER - 2;
        }
        else if (net_turn == 0)
        {
            in[i][k] += 1;
            in[i + 1][k] += 1;
            in[i + 2][k] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 2;
            repeat = VER - 3;
        }
        break;
    case 2:
        if (net_turn == 1)
        {
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k + 1] += 1;
            in[i + 1][k + 2] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;
            in[i][k + 1] += 1;

            b[n].cols_type = 1;
            repeat = VER - 2;
        }
        else if (net_turn == 0)
        {
            in[i][k + 1] += 1;
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 2;
            repeat = VER - 3;
        }
        break;
    case 3:
        if (net_turn == 1)
        {
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;
            in[i + 2][k + 2] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] += 1;
            in[i][k + 2] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 3)
        {
            in[i][k] += 1;
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;

            b[n].cols_type = 1;
            repeat = VER - 2;
        }
        else if (net_turn == 0)
        {
            in[i][k + 1] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k + 1] += 1;
            in[i + 2][k] += 1;

            b[n].cols_type = 2;
            repeat = VER - 3;
        }
        break;
    case 4:
        if (net_turn == 1)
        {
            in[i][k + 1] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;
            in[i + 2][k + 2] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k + 1] += 1;
            in[i][k + 2] += 1;
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;

            b[n].cols_type = 1;
            repeat = VER - 2;
        }
        else if (net_turn == 3)
        {
            in[i][k] += 1;
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 1;
            repeat = VER - 3;
        }
        else if (net_turn == 0)
        {
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;
            in[i + 2][k] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 1;
        }
        break;
    case 5:
        if (net_turn == 1)
        {
            in[i][k + 2] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;
            in[i + 2][k + 1] += 1;

            b[n].cols_type = 1;
        }
        else if (net_turn == 2)
        {
            in[i][k] += 1;
            in[i][k + 1] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 1][k + 2] += 1;

            b[n].cols_type = 1;
            repeat = VER - 2;
        }
        else if (net_turn == 3)
        {
            in[i][k + 1] += 1;
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k] += 1;

            b[n].cols_type = 2;
            repeat = VER - 3;
        }
        else if (net_turn == 0)
        {
            in[i + 1][k] += 1;
            in[i + 1][k + 1] += 1;
            in[i + 2][k + 1] += 1;
            in[i + 2][k + 2] += 1;

            b[n].cols_type = 1;
        }
        break;
    case 6:
        if (net_turn == 1)
        {
            in[i + 3][k] += 1;
            in[i + 3][k + 1] += 1;
            in[i + 3][k + 2] += 1;
            in[i + 3][k + 3] += 1;

            b[n].cols_type = 0;
        }
        else if (net_turn == 2)
        {
            in[i][k + 3] += 1;
            in[i + 1][k + 3] += 1;
            in[i + 2][k + 3] += 1;
            in[i + 3][k + 3] += 1;

            b[n].cols_type = 0;
        }
        else if (net_turn == 3)
        {
            in[i][k] += 1;
            in[i][k + 1] += 1;
            in[i][k + 2] += 1;
            in[i][k + 3] += 1;

            b[n].cols_type = 0;
            repeat = VER - 1;
        }
        else if (net_turn == 0)
        {
            in[i][k] += 1;
            in[i + 1][k] += 1;
            in[i + 2][k] += 1;
            in[i + 3][k] += 1;

            b[n].cols_type = 3;
            repeat = VER - 4;
        }
        break;
    default:
        break;
    }
}

int stack(int i, int k, int t, int n) //바로 아래에 블럭이 있으면 1을 반환, 없으면 0을 반환.
{
    int net_turn = b[n].spin % 4;
    switch (t)
    {
    case 0:
        if (net_turn == 1)
        {
            if (in[i + 3][k] == 1 || in[i + 3][k + 1] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 3][k + 1] == 1 || in[i + 3][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i + 2][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 2][k] == 1 || in[i + 2][k + 1] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 1:
        if (net_turn == 1)
        {
            if (in[i + 3][k] == 1 || in[i + 3][k + 1] == 1 || in[i + 3][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 1][k + 1] == 1 || in[i + 3][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i + 2][k] == 1 || in[i + 1][k + 1] == 1 || in[i + 1][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 3][k] == 1 || in[i + 3][k + 1] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 2:
        if (net_turn == 1)
        {
            if (in[i + 2][k] == 1 || in[i + 3][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 3][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i + 2][k] == 1 || in[i + 2][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 2][k] == 1 || in[i + 3][k + 1] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 3:
        if (net_turn == 1)
        {
            if (in[i + 2][k] == 1 || in[i + 2][k + 1] == 1 || in[i + 3][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 3][k + 1] == 1 || in[i + 1][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i + 2][k] == 1 || in[i + 2][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 3][k] == 1 || in[i + 3][k + 1] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 4:
        if (net_turn == 1)
        {
            if (in[i + 2][k + 1] == 1 || in[i + 3][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 2][k] == 1 || in[i + 2][k + 1] == 1 || in[i + 1][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i + 2][k] == 1 || in[i + 3][k + 1] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 3][k] == 1 || in[i + 3][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 5:
        if (net_turn == 1)
        {
            if (in[i + 3][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 1][k] == 1 || in[i + 2][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i + 3][k] == 1 || in[i + 2][k + 1] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 2][k] == 1 || in[i + 3][k + 1] == 1 || in[i + 3][k + 2] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 6:
        if (net_turn == 1)
        {
            if (in[i + 4][k] == 1 || in[i + 4][k + 1] == 1 || in[i + 4][k + 2] == 1 || in[i + 4][k + 3] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 4][k + 3] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i + 1][k] == 1 || in[i + 1][k + 1] == 1 || in[i + 1][k + 2] == 1 || in[i + 1][k + 3] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 4][k] == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    default:
        break;
    }
}

int side_stack(int i, int k, int t, int n) //return 1 = 우측에 블럭있음, return 2 = 좌측에 블럭있음, return 0 = 블럭없음
{
    int net_turn = b[n].spin % 4;
    switch (t)
    {
    case 0:
        if (net_turn == 1)
        {
            if (in[i + 1][k + 2] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i + 1][k - 1] == 1 || in[i + 2][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i + 1][k + 3] == 1 || in[i + 2][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i + 1][k] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i][k + 3] == 1 || in[i + 1][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1 || in[i + 1][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 1:
        if (net_turn == 1)
        {
            if (in[i + 1][k + 3] == 1 || in[i + 2][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i + 2][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i][k + 3] == 1 || in[i + 1][k + 3] == 1 || in[i + 2][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k + 1] == 1 || in[i + 2][k + 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i][k + 3] == 1 || in[i + 1][k + 1] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1 || in[i + 1][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i][k + 1] == 1 || in[i + 1][k + 1] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1 || in[i + 1][k - 1] == 1 || in[i + 2][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 2:
        if (net_turn == 1)
        {
            if (in[i + 1][k + 3] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i + 1][k - 1] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 3] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 2] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k - 1] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 3:
        if (net_turn == 1)
        {
            if (in[i + 1][k + 3] == 1 || in[i + 2][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i + 1][k - 1] == 1 || in[i + 2][k + 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i][k + 3] == 1 || in[i + 1][k + 2] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i][k + 1] == 1 || in[i + 1][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1 || in[i + 1][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 2] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k] == 1 || in[i + 2][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 4:
        if (net_turn == 1)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 3] == 1 || in[i + 2][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k] == 1 || in[i + 2][k + 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i][k + 3] == 1 || in[i + 1][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i][k + 1] == 1 || in[i + 1][k + 2] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1 || in[i + 1][k - 1] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 1][k + 3] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i + 1][k] == 1 || in[i + 2][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 5:
        if (net_turn == 1)
        {
            if (in[i][k + 3] == 1 || in[i + 1][k + 3] == 1 || in[i + 2][k + 2] == 1)
            {
                return 1;
            }
            else if (in[i][k + 1] == 1 || in[i + 1][k] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1 || in[i + 1][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i][k + 2] == 1 || in[i + 1][k + 2] == 1 || in[i + 2][k + 1] == 1)
            {
                return 1;
            }
            else if (in[i][k] == 1 || in[i + 1][k - 1] == 1 || in[i + 2][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i + 1][k + 2] == 1 || in[i + 2][k + 3] == 1)
            {
                return 1;
            }
            else if (in[i + 1][k - 1] == 1 || in[i + 2][k] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        break;
    case 6:
        if (net_turn == 1)
        {
            if (in[i + 3][k + 4] == 1)
            {
                return 1;
            }
            else if (in[i + 3][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 2)
        {
            if (in[i][k + 4] == 1 || in[i + 1][k + 4] == 1 || in[i + 2][k + 4] == 1 || in[i + 3][k + 4] == 1)
            {
                return 1;
            }
            else if (in[i][k + 2] == 1 || in[i + 1][k + 2] == 1 || in[i + 2][k + 2] == 1 || in[i + 3][k + 2] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 3)
        {
            if (in[i][k + 4] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        else if (net_turn == 0)
        {
            if (in[i][k + 1] == 1 || in[i + 1][k + 1] == 1 || in[i + 2][k + 1] == 1 || in[i + 3][k + 1] == 1)
            {
                return 1;
            }
            else if (in[i][k - 1] == 1 || in[i + 1][k - 1] == 1 || in[i + 2][k - 1] == 1 || in[i + 3][k - 1] == 1)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
        break;
    default:
        break;
    }
}

int check_line(int j) //return 1이면 한 줄이 체워짐(한 줄이 모두 1임)을 의미함.
//return 0 = 한 줄에 0과 1이 모두 있음.
{
    //in[20][10]
    int i;
    int cnt = 0;
    for (i = 0; i < HOR; i++)
    {
        if (in[j][i] == 0)
        {
            cnt++;
        }
    }

    if (cnt == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_finish() //해당행에 숫자가 있으면 1을 반환함.
{
    //in[20][10]
    int i, j;
    int cnt = 0;
    for (j = 0; j < VER; j++)
    {
        for (i = 0; i < HOR; i++)
        {
            if (in[j][i] > 1)
            {
                cnt++;
            }
        }
    }

    if (cnt > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void check_move()
{
    int n, m, p;
    for (p = VER - 1; p > 0; p--)
    {
        if (check_line(p) == 1)
        {
            for (n = 0; n < HOR; n++)
            {
                in[p][n] = 0;
            }
            for (m = p; m > 0; m--)
            {
                for (n = 0; n < HOR; n++)
                {
                    in[m][n] = in[m - 1][n];
                }
            }
            if (check_line_ex(p) == 1)
            {
                for (m = p; m > 0; m--)
                {
                    for (n = 0; n < HOR; n++)
                    {
                        in[m][n] = in[m - 1][n];
                    }
                }
            }
            point += 1;
            print();
            p++;
        }
    }
}

int check_line_ex(int j) //return 1이면 한 줄이 비워짐(한 줄이 모두 0임)을 의미함.
//return 0 = 한 줄에 0과 1이 모두 있음.
{
    //in[20][10]
    int i;
    int cnt = 0;
    for (i = 0; i < HOR; i++)
    {
        if (in[j][i] == 0)
        {
            cnt++;
        }
    }

    if (cnt == HOR)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
