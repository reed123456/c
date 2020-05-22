#include <stdio.h>  
#include <stdlib.h>  
#define  MaxVertices 100
typedef struct node{   //边表 
	int adjvex;
	struct node* next;
}EdgeNode;

typedef struct{     //顶点表  
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
	printf("输入顶点数和边数（中间以空格分开）：");
	scanf("%d%d", &G->n, &G->e);

	printf("建立顶点表\n");
	for (i = 0; i<G->n; i++)
	{
		getchar();
		printf("请输入第%d个顶点的信息:", i + 1);
		G->adjlist[i].vertex = getchar();
		G->adjlist[i].edgenext = NULL;
	}
	//前插法 
	printf("建立边表\n");
	for (k = 0; k<G->e; k++)
	{
		printf("输入有连接的顶点序号：");
		scanf("%d%d", &i, &j);
		i -= 1; j -= 1;//①
		 
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = j;//边表赋值 
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
			//② 
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
