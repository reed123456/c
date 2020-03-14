//#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int input;
	printf("加入比特");
	printf("你要好好学习吗？（0 or 1）\n");
	scanf("%d", &input);
	if (input == 1){
		printf("成功！");
	}
	else{
		printf("卖红薯。");
	}
	system("pause");
	return 0;
}