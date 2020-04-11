#include <stdio.h>

int add(int a, int b){ return a + b; }
int sub(int a, int b){ return a - b; }
int mul(int a, int b){ return a * b; }
int div(int a, int b){ return a / b; }


int main(int argc, char *argv)
{
	system("title 简易计算器");//设置标题
	system("mode con cols=29 lines=10");//打印窗口大小
	system("color 0F");//设置背景和字体颜色
	int x, y;
	int input = 1;
	int ret = 0;
	char oper[4] = { '+', '-', '*', '/' };
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div };
	while (input)
	{
		printf("*****************************\n");
		printf("*   [1]add         [2]sub   *\n");
		printf("*   [3]mul         [4]div   *\n");
		printf("*   [0]quit                 *\n");
		printf("*****************************\n");
		printf("请选择>");
		scanf("%d", &input);
		if (input <= 4 && input >= 1)
		{
			printf("请输入数字>");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else if (input == 0)
		{
			break;
		}
		else
		{
			printf("输入有误，请重新输入...\n");
			system("pause");
			system("cls");
			continue;
		}
		//printf("%c\n", oper[input - 1]);
		printf("%d %c %d = %d\n", x, oper[input - 1], y, ret);
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}