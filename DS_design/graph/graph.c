#include <stdio.h>  
#include <stdlib.h>  
#define  MaxVertices 100
typedef struct node{   //�߱� 
	int adjvex;
	struct node* next;
}EdgeNode;

typedef struct{     //�����  
	int vertex;
	EdgeNode* edgenext;
}VertexNode;

typedef VertexNode AdjList[MaxVertices];

typedef struct{
	AdjList adjlist;
	int n, e;
}AdjMatrix;

void CreateGraph(AdjMatrix* G)
{
	int i, j, k, w, v;
	EdgeNode *s;
	printf("���붥�����ͱ������м��Կո�ֿ�����");
	scanf("%d%d", &G->n, &G->e);

	printf("���������\n");
	for (i = 0; i<G->n; i++)
	{
		getchar();
		printf("�������%d���������Ϣ:", i + 1);
		G->adjlist[i].vertex = getchar();
		G->adjlist[i].edgenext = NULL;
	}
	//ǰ�巨 
	printf("�����߱�\n");
	for (k = 0; k<G->e; k++)
	{
		printf("���������ӵĶ�����ţ�");
		scanf("%d%d", &i, &j);
		i -= 1; j -= 1;//��
		 
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = j;//�߱�ֵ 
		s->next = G->adjlist[i].edgenext;
		G->adjlist[i].edgenext = s;
		
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = i;
		s->next = G->adjlist[j].edgenext;
		G->adjlist[j].edgenext = s;
	}
}
void DispGraph(AdjMatrix *G)
{
	int i;
	for (i = 0; i<G->n; i++)
	{
		printf("%d->", i + 1);
		while (1)
		{
			if (G->adjlist[i].edgenext == NULL)
			{
				printf("^");
				break;
			}
			printf("%d->", G->adjlist[i].edgenext->adjvex + 1);
			//�� 
			G->adjlist[i].edgenext = G->adjlist[i].edgenext->next;

		}
		printf("\n");
	}
}
int main()
{
	AdjMatrix* G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	CreateGraph(G);
	DispGraph(G);
	system("pause");
	return 0;
}
