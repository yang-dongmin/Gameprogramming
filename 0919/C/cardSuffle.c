//터미널에서 chcp 65001 입력 후 실행하면 특수문자 깨짐 해결
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct trump{
    int orders;
    char shape[4];
    int number;
} trump;

void make_card(trump m_card[]);
void display_card(trump m_card[]);
void shuffle_card(trump m_card[]);

int main(void)
{
    trump card[52];
    make_card(card);
    shuffle_card(card);
    display_card(card);
    
    return 0;
}

void make_card(trump m_card[])
{
    int i, j;
    char shape[4][4] = {"♠", "◆", "♥", "♣"};
    for (i = 0; i < 4; i++)
    {
        for (j = i * 13; j < i * 13 + 13; j++)
        {
            m_card[j].orders = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = j % 13 + 1;

            switch (m_card[j].number)
            {
            case 1:
                m_card[j].number = 'A';
                break;
            case 11:
                m_card[j].number = 'J';
                break;
            case 12:
                m_card[j].number = 'Q';
                break;
            case 13:
                m_card[j].number = 'K';
                break;
            }
        }
    }
}

void display_card(trump m_card[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        printf("%s", m_card[i].shape);  // 카드 모양 출력

        switch (m_card[i].number)
        {
            case 1:
                printf("A  ");
                break;
            case 11:
                printf("J  ");
                break;
            case 12:
                printf("Q  ");
                break;
            case 13:
                printf("K  ");
                break;
            default:
                printf("%-2d ", m_card[i].number);
                break;
        }

        if ((i + 1) % 13 == 0)  // 13장마다 줄바꿈
            printf("\n");
    }
}


void shuffle_card(trump m_card[])
{
    int i, rnd;
    trump temp;
    srand(time(NULL));
    for (i = 0; i < 52; i++)
    {
        rnd = rand() % 52;
        temp = m_card[rnd];
        m_card[rnd] = m_card[i];
        m_card[i] = temp;
    }
}