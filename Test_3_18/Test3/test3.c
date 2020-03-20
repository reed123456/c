#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int age = 18;
	int a = 0;
	int b = 2;
	if (age < 18){
		printf("未成年。\n");
	}
	else{
		printf("已成年。\n");
	}
	if (a == 1){
		if (b == 2){
			printf("haha\n");
		}
		else{
			printf("hehe\n");
		}
	}
	
	system("pause");
	return 0;
}