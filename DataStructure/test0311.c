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

void  CreateList(LinkList L)//创建链表，头插入法
{
	Node *s;
	int flag = 1;
	char c;
	printf("请输入字符(输入$结束)：\n");
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
	printf("原始链表：");
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
	printf("  逆序后：");
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
	printf("请输入10个数字：\n");
	for (i = 0; i < *num; i++){
		scanf("%d", &q[i]);
	}
	printf("原始数组：");
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
	printf("  逆序后：");
	printArray(q, num);
}
int main()
{
	
	//创建空链表   [头结点][指针]  [首元][null]
	LinkList head;//    [//][null]
	head = (LinkList)malloc(sizeof(Node));
	head->next = NULL;

    CreateList(head);//创建链表并打印，头插入法
	InvertList(head);//逆序并打印

	//创建数组
	int MAXSIZE = 10;
	int arr[10] = { 0 };
	CreateArray(arr, &MAXSIZE);//创建数组并打印
	InvertArray(arr, &MAXSIZE);//逆序并打印
	return 0;
}