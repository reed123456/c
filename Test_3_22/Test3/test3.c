#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i;
	char password[20];
	for (i = 0; i < 3; i++)
	{
		printf("����������:>");
		scanf("%s", password);//123456

		if (strcmp(password, "123456") == 0)
		{
			printf("��½�ɹ�\n");
			break;
		}
		else
		{
			printf("�������\n");
		}
	}
	if (i == 3)
	{
		printf("������������˳�����\n");
	}
	system("pause");
	return 0;
}