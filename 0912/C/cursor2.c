#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int main(void)
{
    for (int i = 1; i <= 9; i++)
    {
        gotoxy(35, 5 + i);
        printf("%d*%d=%2d", 3, i, 3 * i);
    }
    printf("\n");
    getchar();
    return 0;
}
