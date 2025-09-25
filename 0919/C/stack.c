#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stack_node
{
    char data;
    struct stack_node *link;
};

struct stack_node *top = NULL;

void push(char data)
{
    struct stack_node *new_node;
    new_node = (struct stack_node *)malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->link = top;
    top = new_node;
}

char pop(void)
{
    struct stack_node *temp;
    char data;
    data = top->data;
    temp = top;
    top = top->link;
    free(temp);
    return data;
}

int main(void)
{
    int count = 0;
    char key;
    do
    {
        count++;
        printf("%2d 번 문자입력 >", count);
        key = getch();
        if (key != 27)
        {
            push(key);
            printf("%c \n", key);
        }
    } while (key != 27);
    printf("\n\n");
    printf("데이터 pop과정 \n\n");
    while (top != NULL)
    {
        key = pop();
        printf("%c ", key);
    }
    printf("\n");
    return 0;
}