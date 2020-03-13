#include <stdio.h>
#include <malloc.h>


typedef  struct Node
{
	char  data;
	struct Node *next;
}Node, *LinkList;

void printList(LinkList head)//print
{
	LinkList p;
	p = head->next;
	while (p != NULL){
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

void  CreateList(LinkList L)//��������ͷ���뷨
{
	Node *s;
	int flag = 1;
	char c;
	printf("�������ַ�(����$����)��\n");
	while (flag){
		c = getchar();
		if (c != '$'){
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;          
		}               
		else{
			flag = 0;
		}
	}
	printf("ԭʼ����");
	printList(L);
}



void InvertList(LinkList L)
{
	Node *p, *q, *r;
	if (L->next == NULL){
		return;
	}
	p = L->next;
	q = p->next;
	p->next = NULL;
	while (q != NULL){
		r = q->next;
		q->next = L->next;
		L->next = q;
		q = r;
	}
	printf("  �����");
	printList(L);
}

void printArray(int * q, int *num)//print
{
	int i;
	for (i = 0; i < *num; i++){
		printf("%d ", q[i]);
	}
	printf("\n");
}

void CreateArray(int *q, int *num)
{
	int i;
	printf("������10�����֣�\n");
	for (i = 0; i < *num; i++){
		scanf("%d", &q[i]);
	}
	printf("ԭʼ���飺");
	printArray(q, num);
}

void InvertArray(int * q, int *num)
{
	int j;
	int tmp;
	for (j = 0; j <= (*num - 1) / 2; j++){
		tmp = q[j];
		q[j] = q[*num - j - 1];
		q[*num - j - 1] = tmp;
	}
	printf("  �����");
	printArray(q, num);
}
int main()
{
	
	//����������   [ͷ���][ָ��]  [��Ԫ][null]
	LinkList head;//    [//][null]
	head = (LinkList)malloc(sizeof(Node));
	head->next = NULL;

    CreateList(head);//����������ӡ��ͷ���뷨
	InvertList(head);//���򲢴�ӡ

	//��������
	int MAXSIZE = 10;
	int arr[10] = { 0 };
	CreateArray(arr, &MAXSIZE);//�������鲢��ӡ
	InvertArray(arr, &MAXSIZE);//���򲢴�ӡ
	return 0;
}