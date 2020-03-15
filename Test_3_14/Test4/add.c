#define _CRT_SECURE_NO_WARNINGS 1

int g_val = 2020;//被static修饰后再别的.c文件中不可用

int Add(int x, int y)
{
	int sum;
	sum = x + y;
	return sum;
}