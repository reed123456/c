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
		printf("����������:>");
		scanf("%s", (pcon + *count)->name);
		printf("����������:>");
		scanf("%d", &(pcon + *count)->age);
		printf("�������Ա�:>");
		scanf("%s", (pcon + *count)->sex);
		printf("������绰:>");
		scanf("%s", (pcon + *count)->tele);
		printf("�������ַ:>");
		scanf("%s", (pcon + *count)->address);
		*count = *count + 1;
		printf("��ӳɹ�\n");
		printf("�Ƿ������ӣ�Yes or NO��\n");
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
	printf("��������Ҫ���ҵ��˵�����>");
	scanf("%s", name);
	int i = FindByName(pcon, count, name);
	if (i != -1)
	{
		printf("ɾ������...\n");
	}
	else
	{
		printf("���޴��ˣ�");
	}
	system("pause");
}


void FindContact(contact* pcon, int* count)
{
	assert(pcon);
	char name[10];
	printf("��������Ҫ���ҵ��˵�����>");
	scanf("%s", name);
	int i = FindByName(pcon, count, name);
	if (i != -1)
	{
		printf("����\t�Ա�\t����\t�绰\tסַ\n");
		printf("%-10s%-10s%-10d%-10s%-10s\n",
			(pcon + i)->name, (pcon + i)->sex, (pcon + i)->age, (pcon + i)->tele, (pcon + i)->address);
	}
	else
	{
		printf("���޴��ˣ�");
	}
	system("pause");
}

void AlterContact(contact* pcon, int* count)
{
	assert(pcon);
	char name[10];
	printf("��������Ҫ�޸ĵ��˵�����>");
	scanf("%s", name);
	int i = FindByName(pcon, count, name);
	if (i == -1)
	{
		printf("���޴��ˣ�");
		system("pause");
		return;
	}
	printf("������Ҫ�޸�ʲô��Ϣ��1-���֣�2-���䣬3-�Ա�4-�绰��5-סַ��:>");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("�������µ�����:>");
		scanf("%s", (pcon + i)->name);
		break;
	case 2:
		printf("�������µ�����:>");
		scanf("%d", &(pcon + i)->age);
		break;
	case 3:
		printf("�������µ��Ա�:>");
		scanf("%s", (pcon + i)->sex);
		break;
	case 4:
		printf("�������µĵ绰:>");
		scanf("%s", (pcon + i)->tele);
		break;
	case 5:
		printf("�������µĵ�ַ:>");
		scanf("%s", (pcon + i)->address);
		break;
	default:
		printf("���������޸�ʧ��\n");
		return;
	}
	printf("�޸ĳɹ�\n");
}

void ShowContact(contact* pcon, int* count)
{
	assert(pcon);
	printf("����\t�Ա�\t����\t�绰\tסַ\n");
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
	printf("*             ͨѶ¼              *\n");
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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("�˳�����...\n");
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
			printf("��������...\n");
			continue;

		}
	}
	system("pause");
	return 0;
}
