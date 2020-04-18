#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_SIZE 10
enum operation
{
	EXIT,
	ADD,
	DELETE,
	FIND,
	ALTER,
	SHOW,
	CLEAR,
	SORT
};

typedef struct contact
{
	char name[10];
	char sex[5];
	int age;
	char tele[20];
	char address[20];
}contact;


void AddContact(contact* pcon, int* count)
{
	assert(pcon);
	int flag = 1;
	while (flag)
	{
		printf("请输入名字:>");
		scanf("%s", (pcon + *count)->name);
		printf("请输入年龄:>");
		scanf("%d", &(pcon + *count)->age);
		printf("请输入性别:>");
		scanf("%s", (pcon + *count)->sex);
		printf("请输入电话:>");
		scanf("%s", (pcon + *count)->tele);
		printf("请输入地址:>");
		scanf("%s", (pcon + *count)->address);
		*count = *count + 1;
		printf("添加成功\n");
		printf("是否继续添加（Yes or NO）\n");
		scanf("%d", &flag);
	}
}

int FindByName(contact* pcon, int* count, char* name)
{
	int j = -1;
	for (int i = 0; i < *count; i++)
	{
		if (strcmp((pcon + i)->name, name) == 0)
		{
			j = i;
			break;
		}
	}
	return j;
}

void DeleContact(contact* pcon, int* count)
{
	assert(pcon);
	char name[10];
	printf("请输入需要查找的人的名字>");
	scanf("%s", name);
	int i = FindByName(pcon, count, name);
	if (i != -1)
	{
		printf("删除此人...\n");
	}
	else
	{
		printf("查无此人，");
	}
	system("pause");
}


void FindContact(contact* pcon, int* count)
{
	assert(pcon);
	char name[10];
	printf("请输入需要查找的人的名字>");
	scanf("%s", name);
	int i = FindByName(pcon, count, name);
	if (i != -1)
	{
		printf("姓名\t性别\t年龄\t电话\t住址\n");
		printf("%-10s%-10s%-10d%-10s%-10s\n",
			(pcon + i)->name, (pcon + i)->sex, (pcon + i)->age, (pcon + i)->tele, (pcon + i)->address);
	}
	else
	{
		printf("查无此人，");
	}
	system("pause");
}

void AlterContact(contact* pcon, int* count)
{
	assert(pcon);
	char name[10];
	printf("请输入需要修改的人的名字>");
	scanf("%s", name);
	int i = FindByName(pcon, count, name);
	if (i == -1)
	{
		printf("查无此人，");
		system("pause");
		return;
	}
	printf("请输入要修改什么信息（1-名字，2-年龄，3-性别，4-电话，5-住址）:>");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("请输入新的姓名:>");
		scanf("%s", (pcon + i)->name);
		break;
	case 2:
		printf("请输入新的年龄:>");
		scanf("%d", &(pcon + i)->age);
		break;
	case 3:
		printf("请输入新的性别:>");
		scanf("%s", (pcon + i)->sex);
		break;
	case 4:
		printf("请输入新的电话:>");
		scanf("%s", (pcon + i)->tele);
		break;
	case 5:
		printf("请输入新的地址:>");
		scanf("%s", (pcon + i)->address);
		break;
	default:
		printf("输入有误，修改失败\n");
		return;
	}
	printf("修改成功\n");
}

void ShowContact(contact* pcon, int* count)
{
	assert(pcon);
	printf("姓名\t性别\t年龄\t电话\t住址\n");
	for (int i = 0; i < *count; i++)
	{
		printf("%-10s%-10s%-10d%-10s%-10s\n",
			(pcon + i)->name, (pcon + i)->sex, (pcon + i)->age, (pcon + i)->tele, (pcon + i)->address);
	}
}

void ClearContact()
{

}
void SortContact()
{

}

void menu()
{
	printf("***********************************\n");
	printf("*             通讯录              *\n");
	printf("*    [1] add       [2] delete     *\n");
	printf("*    [3] fin       [4] alter      *\n");
	printf("*    [5] show      [6] clear      *\n");
	printf("*    [7] sort      [0] exit       *\n");
	printf("***********************************\n");
}
int main()
{
	int input = 0;
	int count = 0;
	contact pcon[MAX_SIZE];
	while (1)
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("退出程序...\n");
			return 0;
		case ADD:
			AddContact(pcon, &count);
			break;
		case DELETE:
			DeleContact();
			break;
		case FIND:
			FindContact(pcon, &count);
			break;
		case ALTER:
			AlterContact(pcon, &count);
			break;
		case SHOW:
			ShowContact(pcon, &count);
			break;
		case CLEAR:
			ClearContact();
			break;
		case SORT:
			SortContact();
			break;
		default :
			printf("输入有误...\n");
			continue;

		}
	}
	system("pause");
	return 0;
}
