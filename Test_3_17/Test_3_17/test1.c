#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int day;
	printf("请输入数字：");
	scanf("%d", &day);
	switch (day){
	case 1: printf("今天是星期一。\n"); break;
	case 2: printf("今天是星期二。\n"); break;
	case 3: printf("今天是星期三。\n"); break;
	case 4: printf("今天是星期四。\n"); break;
	case 5: printf("今天是星期五。\n"); break;
	case 6: printf("今天是星期六。\n"); break;
	case 7: printf("今天是星期天。\n"); break;
	default:printf("不存在的日期哦。\n");
	}
	system("pause");
	return 0;
}