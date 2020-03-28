#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//棋盘初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//展示棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//给Mine数组放雷
void SetMine(char board[ROWS][COLS], int row, int col);
//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);