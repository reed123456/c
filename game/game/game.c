#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j <cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] 
		+ mine[x - 1][y] 
		+ mine[x - 1][y + 1] 
		+ mine[x][y - 1] 
		+ mine[x][y + 1] 
		+ mine[x + 1][y - 1] 
		+ mine[x + 1][y] 
		+ mine[x + 1][y + 1]
		- 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0; 
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("���������׵�����:>");
		scanf("%d %d", &x, &y);
		system("cls");
		printf("**********************\n");
		printf("**     ɨ   ��      **\n");
		printf("**     1.play       **\n");
		printf("**     0.exit       **\n");
		printf("**********************\n");
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (mine[x][y] == '1')
			{
				DisplayBoard(mine, ROW, COL);
				printf("���ź����㱻ը����.\n");
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
			if (win == row * col - EASY_COUNT)
			{
				printf("��ϲ�㣬�����ʤ��.\n");
			}
		}
		else
		{
			DisplayBoard(show, ROW, COL);
			printf("��������.\n");
		}
	}
}