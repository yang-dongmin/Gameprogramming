#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    printf("Enter a character:");
    scanf("%c", &ch);
    system("cls");
    printf("The entered character is %c\n", ch);

    return 0;
}