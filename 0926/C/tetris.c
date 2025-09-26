#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void rotation_right(int m[][3]);
void move_shape(int m[][3]);
void print_shape(int m[][3]);
void move_control(int m[][3]);
void gotoxy(int x, int y);
void print_direction(void);
void lock_shape(int m[][3]);
int x = 35, y = 12;
int inx = 0, iny = 0;

#define BOARD_WIDTH 20  // 게임 보드 가로 칸 수 (콘솔 x 좌표 2칸당 1칸)
#define BOARD_HEIGHT 22 // 게임 보드 세로 칸 수 (y=2부터 y=23까지 총 22줄)

#define X_OFFSET 25 // 게임 보드 좌측 경계 콘솔 x 좌표 (예시 값)
#define Y_OFFSET 2  // 게임 보드 상단 경계 콘솔 y 좌표

int game_board[BOARD_HEIGHT][BOARD_WIDTH] = {0};

void rotation_right(int m[][3])
{
    int i, j;
    int temp[3][3];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            temp[j][2 - i] = m[i][j];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            m[i][j] = temp[i][j];
}

int main(void)
{
    int shape1[3][3] = {0, 1, 0,
                        0, 1, 0,
                        1, 1, 1};
    move_control(shape1);
    return 0;
}

void print_direction(void)
{
    gotoxy(25, 1);
    printf("화살표:이동, 스페이스 키:회전");
}

void move_control(int m[][3])
{
    char key = 0;

    // 🚨 1. 가장 바깥쪽 DO 루프 시작
    do
    {
        x = 35;
        y = 2;
        int is_locked = 0;

        // 2. 블록 조작 루프 시작: ESC가 아니거나, 블록이 고정되지 않았다면 반복
        while (key != 27 && !is_locked)
        {
            // 3. 키 입력 대기 및 자연 하강 처리
            while (!kbhit())
            {
                inx = 0;
                iny = 1;
                move_shape(m);
                if (y == 23)
                {
                    is_locked = 1;
                    break;
                }
            }

            if (is_locked)
                break;

            // 4. 키 입력 처리 (이하 switch-case)
            key = getch();
            switch (key)
            {
            // ... (rotation_right 및 이동 처리 로직 유지) ...
            case 32:
                rotation_right(m);
                inx = 0;
                iny = 0;
                break;
            case 72:
                inx = 0;
                iny = -1;
                break;
            case 75:
                inx = -1;
                iny = 0;
                break;
            case 77:
                inx = 1;
                iny = 0;
                break;
            case 80:
                inx = 0;
                iny = 1;
                break;
            default:
                inx = 0;
                iny = 0;
                break;
            }

            if (key != 27)
            {
                move_shape(m);
            }

            if (y == 23)
            {
                is_locked = 1;
            }
        }

        if (is_locked)
        {
            lock_shape(m);
        }

    } while (key != 27);

    printf("\n");
}

void lock_shape(int m[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (m[i][j] == 1)
            {
                // 정확한 좌표 변환
                int board_y = y + i - Y_OFFSET;
                int board_x = (x + j * 2 - X_OFFSET) / 2;

                if (board_y >= 0 && board_y < BOARD_HEIGHT &&
                    board_x >= 0 && board_x < BOARD_WIDTH)
                {
                    game_board[board_y][board_x] = 1;
                }
                else
                {
                    // 디버깅: 좌표 초과 로그
                    printf("⚠️ out of bounds: board[%d][%d]\n", board_y, board_x);
                }
            }
        }
    }
}



void print_shape(int m[][3])
{
    int i, j;

    // 1. 🧱 고정된 블록 (game_board) 출력 🧱
    for (i = 0; i < BOARD_HEIGHT; i++)
    {
        gotoxy(X_OFFSET, Y_OFFSET + i);

        for (j = 0; j < BOARD_WIDTH; j++)
        {
            if (game_board[i][j] == 1)
            {
                // 고정된 조각은 '■'로 표시 (두 칸 너비)
                printf("■");
            }
            else
            {
                // 🚨 핵심 수정: 비어 있는 공간은 반드시 두 칸 공백("  ")으로 처리
                printf("  ");
            }
        }
    }

    // 2. 🚀 현재 움직이는 블록 (m) 출력 🚀
    for (i = 0; i < 3; i++)
    {
        gotoxy(x, y + i);

        for (j = 0; j < 3; j++)
        {
            if (m[i][j] == 1)
            {
                printf("□");
            }
            else
            {
                printf("  ");
            }
        }
    }
}

void move_shape(int m[][3])
{
    int is_grounded = 0;

    x += inx;
    y += iny;

    // 경계 체크
    if (y > 23)
    {
        y = 23;
        is_grounded = 1;
    }
    else if (y < 2)
        y = 2;

    if (x > (X_OFFSET + (BOARD_WIDTH - 3) * 2))
        x = X_OFFSET + (BOARD_WIDTH - 3) * 2;
    else if (x < X_OFFSET)
        x = X_OFFSET;

    system("cls");
    print_shape(m);
    print_direction();

    Sleep(100);

    inx = 0;
    iny = 0;
}

int check_collision(int m[][3], int new_x, int new_y)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (m[i][j] == 1)
            {
                int board_x = (new_x + j * 2 - X_OFFSET) / 2;
                int board_y = new_y - Y_OFFSET + i;
                if (board_y >= 0 && board_y < BOARD_HEIGHT &&
                    board_x >= 0 && board_x < BOARD_WIDTH &&
                    game_board[board_y][board_x] == 1)
                {
                    return 1; // 충돌 발생
                }
            }
        }
    }
    return 0;
}
void gotoxy(int x, int y)
{
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
