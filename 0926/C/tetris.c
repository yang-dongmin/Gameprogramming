#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define BOARD_WIDTH  12
#define BOARD_HEIGHT 20
#define BLOCK_SIZE   4

void rotation_right(int m[BLOCK_SIZE][BLOCK_SIZE]);
void print_shape(int m[BLOCK_SIZE][BLOCK_SIZE]);
void move_control(int m[BLOCK_SIZE][BLOCK_SIZE]);
int check_collision(int nx, int ny, int m[BLOCK_SIZE][BLOCK_SIZE]);
void clear_line(void);
void gotoxy(int x,int y);
void print_border(void);
void hide_cursor(void);
void print_direction(void);

int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
int x, y;

typedef struct {
    char name[20];
    int shape[BLOCK_SIZE][BLOCK_SIZE];
} Tetromino;

int main(void) {
    hide_cursor();
    print_border();
    print_direction();
    srand(time(NULL));

    Tetromino blocks[5] = {
        {"O", {{0,0,0,0},
               {0,1,1,0},
               {0,1,1,0},
               {0,0,0,0}}},
        {"I", {{0,0,0,0},
               {1,1,1,1},
               {0,0,0,0},
               {0,0,0,0}}},
        {"T", {{0,0,0,0},
               {0,1,0,0},
               {1,1,1,0},
               {0,0,0,0}}},
        {"L", {{0,0,0,0},
               {0,0,1,0},
               {1,1,1,0},
               {0,0,0,0}}},
        {"J", {{0,0,0,0},
               {1,0,0,0},
               {1,1,1,0},
               {0,0,0,0}}}
    };

    while(1) {
        int index = rand() % 5;
        move_control(blocks[index].shape);
    }

    return 0;
}

void rotation_right(int m[BLOCK_SIZE][BLOCK_SIZE]) {
    int temp[BLOCK_SIZE][BLOCK_SIZE] = {0};
    for(int i=0;i<BLOCK_SIZE;i++)
        for(int j=0;j<BLOCK_SIZE;j++)
            temp[j][BLOCK_SIZE-1-i] = m[i][j];
    for(int i=0;i<BLOCK_SIZE;i++)
        for(int j=0;j<BLOCK_SIZE;j++)
            m[i][j] = temp[i][j];
}

void move_control(int m[BLOCK_SIZE][BLOCK_SIZE]) {
    char key;
    int collision = 0;
    x = BOARD_WIDTH/2 - 2;
    y = 0;

    while(!collision) {
        system("cls");
        print_border();
        print_direction();
        print_shape(m);
        Sleep(200);

        int next_x = x;
        int next_y = y + 1;

        if(kbhit()) {
            key = getch();
            switch(key) {
                case 32: rotation_right(m); break;
                case 75: if(!check_collision(x-1,y,m)) x--; break;
                case 77: if(!check_collision(x+1,y,m)) x++; break;
                case 80: next_y = y+1; break;
                case 27: exit(0);
            }
        }

        if(!check_collision(x,next_y,m)) {
            y = next_y;
        } else {
            for(int i=0;i<BLOCK_SIZE;i++)
                for(int j=0;j<BLOCK_SIZE;j++)
                    if(m[i][j]==1 && y+i>=0)
                        board[y+i][x+j] = 1;
            clear_line();
            collision = 1;
        }
    }
}

int check_collision(int nx, int ny, int m[BLOCK_SIZE][BLOCK_SIZE]) {
    for(int i=0;i<BLOCK_SIZE;i++)
        for(int j=0;j<BLOCK_SIZE;j++)
            if(m[i][j]==1) {
                int tx = nx+j;
                int ty = ny+i;
                if(tx<0 || tx>=BOARD_WIDTH || ty>=BOARD_HEIGHT) return 1;
                if(board[ty][tx]==1) return 1;
            }
    return 0;
}

void clear_line() {
    for(int i=0;i<BOARD_HEIGHT;i++) {
        int full = 1;
        for(int j=0;j<BOARD_WIDTH;j++)
            if(board[i][j]==0) { full=0; break; }
        if(full) {
            for(int k=i;k>0;k--)
                for(int j=0;j<BOARD_WIDTH;j++)
                    board[k][j]=board[k-1][j];
            for(int j=0;j<BOARD_WIDTH;j++)
                board[0][j]=0;
            i--;
        }
    }
}

void print_shape(int m[BLOCK_SIZE][BLOCK_SIZE]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // 고정 블록
    for(int i=0;i<BOARD_HEIGHT;i++)
        for(int j=0;j<BOARD_WIDTH;j++)
            if(board[i][j]==1) {
                gotoxy(j,i+1);
                SetConsoleTextAttribute(hConsole,BACKGROUND_RED);
                printf(" ");
            }
    // 현재 블록
    for(int i=0;i<BLOCK_SIZE;i++)
        for(int j=0;j<BLOCK_SIZE;j++)
            if(m[i][j]==1 && y+i>=0) {
                gotoxy(x+j,y+i+1);
                SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE);
                printf(" ");
            }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void gotoxy(int x,int y) {
    COORD Pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void print_border() {
    for(int i=0;i<=BOARD_WIDTH;i++) { gotoxy(i,0); printf("-"); gotoxy(i,BOARD_HEIGHT+1); printf("-"); }
    for(int i=1;i<=BOARD_HEIGHT;i++) { gotoxy(0,i); printf("|"); gotoxy(BOARD_WIDTH,i); printf("|"); }
}

void hide_cursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole,&cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole,&cursorInfo);
}

void print_direction() {
    gotoxy(0,BOARD_HEIGHT+2);
    printf("[← → ↓ : 이동, SPACE : 회전, ESC : 종료]");
}
