#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void)
{
    gotoxy(2, 4);
    printf("Hello");
    gotoxy(40, 20);
    printf("Hello");
    getchar();
    return 0;
}
void gotoxy(int x, int y)
{
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}