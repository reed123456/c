#include "testgame.h"

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

void OpenShow(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int *win)
{
	int count = GetMineCount(mine, x, y);
	if (count != 0)
	{
			show[x][y] = count + '0';
			*win = *win + 1;
	}
	else
	{
		show[x][y] = ' ';
		*win = *win + 1;
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == '*' && i > 0 && i <= row && j > 0 && j <= col)
					OpenShow(mine, show, row, col, i, j, win);
			}
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入排雷的坐标:>");
		scanf("%d %d", &x, &y);
		system("cls");
		printf("**********************\n");
		printf("**     扫   雷      **\n");
		printf("**     1.play       **\n");
		printf("**     0.exit       **\n");
		printf("**********************\n");
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (mine[x][y] == '1')
			{
				DisplayBoard(mine, ROW, COL);
				printf("很遗憾，你被炸死了.\n");
				break;
			}
			else
			{
				OpenShow(mine, show, row, col, x, y, &win);
				DisplayBoard(show, ROW, COL);
			}
			if (win == row * col - EASY_COUNT)
			{
				printf("恭喜你，获得了胜利.\n");
			}
		}
		else
		{
			DisplayBoard(show, ROW, COL);
			printf("输入有误.\n");
		}
	}
}