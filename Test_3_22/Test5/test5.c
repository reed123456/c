#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char input[100] = { 0 };
	system("shutdown -s -t 600");
again:
	printf("��ĵ��Խ���10����֮�ڹػ���������� ������ ��ȡ���ػ�\n");
	printf("�����룺>");
	scanf("%s", input);
	if (0 == strcmp(input, "������"))
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	system("pause");
	return 0;
}