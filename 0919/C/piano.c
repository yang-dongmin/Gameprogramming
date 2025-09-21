#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
// void print_frequency(int octave);
int calc_frequency(int octvae, int inx);
void practice_piano(void);

int main(void){
    printf("1���� 8���� ����Ű�� ������\n");
    printf("�� ���� �Ҹ��� ��µ˴ϴ�.\n");
    printf("1:�� 2:�� 3:�� 4:�� 5:�� 6:�� 7:�� 8:��\n");
    printf("���� : R\n");
    printf("��� : P\n");
    printf("���α׷� ����� EscŰ\n");
    practice_piano();
    return 0;
}

// int main(void){
//     int index[]={0,2,4,5,7,9,11,12};
//     int freq[8];
//     int i;
//     for(i=0;i<8;i++){
//         freq[i]=calc_frequency(4, index[i]);
//     }
//     for(i=0;i<=7;i++){
//         Beep(freq[i],500);
//     }
//     Sleep(1000);
//     for(i=7;i>=0;i++){
//         Beep(freq[i],500);
//     }
//     return 0;
// }

// int main(void){
//     char *scale[]={"��","��#","��","��#","��","��","��#","��","��#","��","��#","��","��"};
//     int i, octave, count=0;
//     printf("����� ���ļ�\n\n����\t   ");
//     for(i=0;i<12;i++){
//         printf("%-5s",scale[i]);
//     }
//     printf("\n");
//     for(i=0;i<70;i++){
//         printf("-");
//     }
//     printf("\n");
//     for(octave=1;octave<7;octave++){
//         print_frequency(octave);
//     }
//     return 0;
// }

// void print_frequency(int octave){
//     double do_scale = 32.7032;
//     double ratio = pow(2., 1/12.), temp;
//     int i;
//     temp = do_scale*pow(2,octave-1);
//     printf("%d��Ÿ�� : ",octave);
//     for(i=0;i<12;i++){
//         printf("%4ld ",(unsigned long) (temp+0.5));
//         temp*=ratio;
//     }
//     printf("\n");
// }

int calc_frequency(int octave, int inx){
    double do_scale = 32.7032;
    double ratio = pow(2., 1/12.), temp;
    int i;
    temp=do_scale*pow(2, octave-1);
    for(i=0;i<inx;i++){
        temp = (int)(temp+0.5);
        temp*=ratio;
    }
    return (int) temp;
}

void practice_piano(void){
    int index[]={0,2,4,5,7,9,11,12};
    int freq[8], code, i;

    int keys[100];
    int keyCount = 0;
    int recoding = 0;

    for(i=0;i<8;i++){
        freq[i]=calc_frequency(4, index[i]);
    }
    do{
        code = getch();

        if('R' == code || 'r' == code){
            recoding = 1;
            keyCount = 0;
            printf("REC. on\n");
            continue;
        }
        if(recoding){
            keys[keyCount++] = code;
        }
        if('1'<=code && code<='8'){
            code -=49;
            Beep(freq[code],300);
        }
        if('P' == code || 'p' == code){
            printf("Playing...\n");
            for(i=0;i<keyCount;i++){
                int index = keys[i] - '1';
                if(index >= 0 && index < 8){
                    Beep(freq[index], 300);
                }
            }
        }
    }
    while(code!=27);
}