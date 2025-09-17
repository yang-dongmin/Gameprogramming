#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define X_MAX 79 // 가로(열)방향의 최대값
#define Y_MAX 24 // 세로(행)방향의 최대값
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b)
{
    switch (chr)
    {
    case 72: // 위쪽(상) 방향의 화살표 키 입력
        *y = *y - 1;
        if (*y < 1)
            *y = 1; // y좌표의 최소값
        break;
    case 75: // 왼쪽(좌) 방향의 화살표 키 입력
        *x = *x - 1;
        if (*x < 1)
            *x = 1; // x좌표의 최소값
        break;
    case 77: // 오른쪽(우) 방향의 화살표 키 입력
        *x = *x + 1;
        if (*x > x_b)
            *x = x_b; // x좌표의 최대값
        break;
    case 80: // 아래쪽(하) 방향의 화살표 키 입력
        *y = *y + 1;
        if (*y > y_b)
            *y = y_b; // y좌표의 최대값
        break;
    }
}
void gotoxy(int x, int y)
{
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int main(void)
{
    char key;
    int x = 10, y = 5;
    do
    {
        gotoxy(x, y);
        printf("A");
        key = getch();
        move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
    } while (key != 27);
    return 0;
}