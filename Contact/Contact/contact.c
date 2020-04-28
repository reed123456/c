#include"Contact.h"

//��ʼ��
void InitContact(Contact *pct)
{
	assert(pct != NULL);

	pct->capacity = DEFAULT_CONTACT_SIZE;
	pct->data = (PersonInfo*)malloc(sizeof(PersonInfo)* pct->capacity);
	assert(pct->data != NULL);
	memset(pct->data, 0, sizeof(PersonInfo)* pct->capacity);
	pct->size = 0;

	LoadContact(pct);
}

//������������
static int FindByName(Contact *pct, char *name)
{
	for (size_t i = 0; i<pct->size; ++i)
	{
		if (strcmp(pct->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

//�����������̬�����ڴ�
static void CheckCapacity(Contact *pct)
{
	if (pct->size >= pct->capacity)
	{
		//�ռ�����
		PersonInfo *new_data = (PersonInfo*)realloc(pct->data, sizeof(PersonInfo)*(pct->capacity * 2));
		assert(new_data != NULL);
		pct->capacity *= 2;
		pct->data = new_data;
		printf("���ݳɹ�.....\n");
	}
}

//�����ϵ��
void AddContact(Contact *pct)
{
	assert(pct != NULL);

	//�������
	CheckCapacity(pct);

	char  name[MAX_NAME_SIZE];
	char  sex[3];
	char  tel[12];
	char  addr[MAX_ADDR_SIZE];
	short age;
	printf("��������ϵ������:>");
	scanf("%s", pct->data[pct->size].name);
	printf("��������ϵ���Ա�:>");
	scanf("%s", pct->data[pct->size].sex);
	printf("��������ϵ������:>");
	scanf("%d", &(pct->data[pct->size].age));
	printf("��������ϵ�˵绰:>");
	scanf("%s", pct->data[pct->size].tel);
	printf("��������ϵ��סַ:>");
	scanf("%s", pct->data[pct->size].addr);
	pct->size++;
	printf("����ͨѶ¼��Ա��Ϣ�ɹ�......\n");
}

//��ʾͨѶ¼��Ϣ
void ShowContact(Contact *pct)
{
	assert(pct != NULL);
	printf("-----------------��ϵ����Ϣ ------------------\n");
	printf("%-10s%-8s%-8s%-12s%-10s\n", "����", "�Ա�", "����", "�绰", "סַ");
	for (size_t i = 0; i<pct->size; ++i)
	{
		printf("%-10s%-8s%-8d%-12s%-10s\n", pct->data[i].name,
			pct->data[i].sex,
			pct->data[i].age,
			pct->data[i].tel,
			pct->data[i].addr);
	}
	printf("---------------------------------------------\n");
}

//����
void FindContact(Contact *pct)
{
	assert(pct != NULL);
	if (pct->size == 0)
	{
		printf("ͨѶ¼Ϊ��,���ܲ�ѯ.....\n");
		return;
	}

	char name[MAX_NAME_SIZE] = { 0 };
	printf("������Ҫ��ѯ������:>");
	scanf("%s", name);
	int index = FindByName(pct, name);
	if (index == -1)
	{
		printf("���޴���.....\n");
		return;
	}

	printf("*%-10s%-8s%-8s%-12s%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
	printf("*%-10s%-8s%-8d%-12s%-30s\n", pct->data[index].name,
		pct->data[index].sex,
		pct->data[index].age,
		pct->data[index].tel,
		pct->data[index].addr);
}

//ɾ��
void DelContact(Contact *pct)
{
	assert(pct != NULL);
	if (pct->size == 0)
	{
		printf("ͨѶ¼Ϊ��,����ɾ��.....\n");
		return;
	}

	char name[MAX_NAME_SIZE] = { 0 };
	printf("������Ҫɾ��������:>");
	scanf("%s", name);
	int index = FindByName(pct, name);
	if (index == -1)
	{
		printf("Ҫɾ�����˲�����.....\n");
		return;
	}

	for (int i = index; i<pct->size; ++i)
		pct->data[i] = pct->data[i + 1];
	pct->size--;
	printf("ɾ���ɹ�......\n");
}

//�޸�
void ModifyContact(Contact *pct)
{
	assert(pct != NULL);
	if (pct->size == 0)
	{
		printf("ͨѶ¼Ϊ��,�����޸�.....\n");
		return;
	}
	char name[MAX_NAME_SIZE] = { 0 };
	printf("������Ҫ�޸ĵ�����:>");
	scanf("%s", name);
	int index = FindByName(pct, name);
	if (index == -1)
	{
		printf("Ҫ�޸ĵ��˲�����.....\n");
		return;
	}

	int select = 1;
	while (select)
	{
		printf("�����޸�ʲô��Ϣ(1-���� 2-�Ա� 3-���� 4-�绰 5-סַ)\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫ�޸ĵ�����:>");
			scanf("%s", pct->data[index].name);
			break;
		case 2:
			printf("������Ҫ�޸ĵ��Ա�:>");
			scanf("%s", pct->data[index].sex);
			break;
		case 3:
			printf("������Ҫ�޸ĵ�����:>");
			scanf("%d", &(pct->data[index].age));
			break;
		case 4:
			printf("������Ҫ�޸ĵĵ绰:>");
			scanf("%s", pct->data[index].tel);
			break;
		case 5:
			printf("������Ҫ�޸ĵ�סַ:>");
			scanf("%s", pct->data[index].addr);
			break;
		default:
			printf("�޸�ѡ�����������ѡ��.\n");
			continue;
		}
		break;
	}
	printf("�޸ĳɹ�......\n");
}

//���
void ClearContact(Contact *pct)
{
	printf("ȷ��Ҫ���ͨѶ¼��?<Y/N> :>");
	char ch;
	fflush(stdin);  //��ջ��������\n
	scanf("%c", &ch);
	if (ch == 'N' || ch == 'n')
		return;
	pct->size = 0;
	memset(pct->data, 0, sizeof(pct->data));
}
void SortContact(Contact *pct)
{
	for (int i = 0; i<pct->size - 1; ++i)
	{
		for (int j = 0; j<pct->size - i - 1; ++j)
		{
			if (strcmp(pct->data[j].name, pct->data[j + 1].name) > 0)
			{
				PersonInfo tmp = pct->data[j];
				pct->data[j] = pct->data[j + 1];
				pct->data[j + 1] = tmp;
			}
		}
	}
	printf("����ɹ�.....\n");
}

void DestroyContact(Contact *pct)
{
	free(pct->data);
	pct->data = NULL;
	pct->capacity = pct->size = 0;
	printf("��������ɹ�.....\n");
}

//����
void SaveContact(Contact *pct)
{
	FILE *fp = fopen("contact.dat", "w");
	assert(fp != NULL);

	for (size_t index = 0; index<pct->size; ++index)
	{
		fprintf(fp, "%-10s%-8s%-8d%-12s%-30s\n", pct->data[index].name,
			pct->data[index].sex,
			pct->data[index].age,
			pct->data[index].tel,
			pct->data[index].addr);
	}
	fclose(fp);
	printf("ͨѶ¼����ɹ�.....\n");
}

//�����ļ�������
void LoadContact(Contact *pct)
{
	FILE *fp = fopen("contact.dat", "r");
	assert(fp != NULL);

	while (!feof(fp))
	{
		CheckCapacity(pct);
		int res = fscanf(fp, "%s %s %d %s %s", pct->data[pct->size].name,
			                         pct->data[pct->size].sex,
			                         &(pct->data[pct->size].age),
			                         pct->data[pct->size].tel,
			                         pct->data[pct->size].addr);
		if (res == EOF)
			break;
		pct->size++;
	}

	fclose(fp);
	printf("����ͨѶ¼�ɹ�.....\n");
}