//#include"stdio.h"
//#include "stdlib.h"
//#include "conio.h"
//
//#define MAXADJSIZE 20
//int visited[MAXADJSIZE];
//
////图的  邻接表  储存方式
//typedef struct ArcNode{
//	struct ArcNode *nextarc;//下一个弧 
//	int adjvex;//所在定点 
//}ArcNode;
//typedef struct VNode{
//	struct ArcNode *firstarc;  //指向第一个弧 
//	int data;  //顶点信息 
//}VNode, AdjList[MAXADJSIZE];
//typedef struct{
//	AdjList vex;
//	int vexnum, arcnum;
//}Graph;
//
////队列的链式储存   用于广度优先的遍历 
////typedef struct QNode{
////	int v;
////	struct QNode *next;
////}QNode, *Qptr;
////
////typedef struct{
////	Qptr front;
////	Qptr rear;
////}LinkQ;
////
////void InitQueue(LinkQ *Q)
////{
////	if (!(Q.front = Q.rear = (Qptr)malloc(sizeof(QNode)*MAXADJSIZE))) printf("储存分配失败！！！\n");
////	else{
////		Q.front->next = NULL;
////	}
////}
///*
//void EnQueue(LinkQ Q, int e)
//{
//Qptr p;
//if (!(p = (Qptr)malloc(sizeof(QNode)))) printf("储存分配失败！！！\n");
//else
//{
//p->v = e;
//p->next = NULL;
//Q.rear->next = p;
//Q.rear = p;
//}
//}
//
//void DeQueue(LinkQ Q, int e)
//{
//if (Q.rear == Q.front) printf("此队列为空！！！\n");
//else{
//Qptr p;
//if (!(p = (Qptr)malloc(sizeof(QNode)))) printf("储存分配失败！！！\n");
//else{
//p = Q.front->next;
//e = p->v;
//Q.front->next = p->next;
//if (Q.rear == p) Q.rear = Q.front;  //当队列中的最后一个元素被删除的时候，rear会丢失，应该对其重新赋值
//free(p);
//}
//}
//
//}
//
//int EmptyQueue(LinkQ Q)
//{
//if (Q.front == Q.rear) return 1;
//else return 0;
//}
//
//void VISIT(int v)
//{
//printf("v%d  ", v + 1);
//}
////与节点v相接的第一个边
//int FirstAdjVex(Graph G, int v)
//{
//return G.vex[v].firstarc->adjvex;
//}
//// 与节点v相接的下一个边
//int NextAdjVex(Graph G, int v, int w)
//{
//ArcNode *p;
//if (!(p = (ArcNode *)malloc(sizeof(ArcNode))))
//printf("储存分配失败！！！\n");
//p = G.vex[v].firstarc;
//while (p->adjvex != w&&p->nextarc != NULL)
//p = p->nextarc;
//if (p->nextarc == NULL)
//return -5;
//else{
//p = p->nextarc;
//w = p->adjvex;
//return w;
//}
//}
//void BFSTraverse(Graph G)
//{//图的广度优先遍历
//int v, u;
//LinkQ Q;
//for (v = 0; v<G.vexnum; ++v)
//visited[v] = 0;
//InitQueue(Q);
//for (v = 0; v<G.vexnum; ++v)
//{
//printf("以点v%d为起点的结果：", v + 1);
//if (!visited[v]) {
//VISIT(v); visited[v] = 1;
//EnQueue(Q, v);
//while (!EmptyQueue(Q)){
//DeQueue(Q, u);
//for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
//if (!visited[w]){
//VISIT(w);
//visited[w] = 1;
//EnQueue(Q, w);
//}
//}
//}
//for (int i = 0; i<G.vexnum; ++i)
//visited[i] = 0;
//InitQueue(Q);
//printf("\n");
//}
//}*/
//void creat(Graph *G)//创建存储图的邻接表 
//{
//	int j, i;
//	ArcNode *s, *t, *p;
//	int v1, v2;
//	printf("输入无向图顶点数目和无向图边数：>");
//	scanf("%d%d", &G->vexnum, &G->arcnum);
//	for (i = 0; i<G->vexnum; i++){
//		G->vex[i].data = i;
//		G->vex[i].firstarc = NULL;
//	}
//	for (int k = 0; k<G->arcnum; k++)
//	{
//		printf("请输入第%d条边依附的两个顶点>", k + 1);
//		scanf("%d %d", &v1, &v2);
//		v1--;
//		v2--;
//		s = (ArcNode*)malloc(sizeof(ArcNode));
//		t = (ArcNode*)malloc(sizeof(ArcNode));
//		s->adjvex = v1;
//		s->nextarc = G->vex[v2].firstarc;
//		G->vex[v2].firstarc = s;
//		t->adjvex = v2;
//		t->nextarc = G->vex[v1].firstarc;
//		G->vex[v1].firstarc = t;
//	}
//}
//
//void Print(Graph *G)
//{
//	ArcNode *p;
//	for (int i = 0; i<G->vexnum; i++)
//	{
//		printf("%4d     v%d", i, G->vex[i].data + 1);
//		for (p = G->vex[i].firstarc; p; p = p->nextarc)
//			printf("%4d", p->adjvex);
//		printf("\n");
//
//	}
//}
//
//
//int main()
//{
//	Graph G;
//	creat(&G);
//	Print(&G);
//	//BFSTraverse(G);
//	system("pause");
//	return 0;
//}
//
//typedef struct node{
//	int adjvex;
//	struct node *next;
//}eNode;
////头节点
//typedef struct headnode{
//	char vertex;
//	eNode *firstedge;
//}hNode;
////邻接表
//typedef struct{
//	hNode adjlist[max];
//	int n, e;   //顶点数，边数 
//}linkG;
//
////打印邻接表
//printf("邻接表为:\n");
//for (i = 0; i<g->e; i++){
//	s = g->adjlist[i].firstedge;
//	while (s){
//		printf("(%c,%c)", g->adjlist[i].vertex, g->adjlist[s->adjvex].vertex);
//		s = s->next;
//	}
//	printf("\n");
//}

//
//
//typedef struct EdgeNode{//边表结点 
//	int adjvex;
//	struct EdgeNode *next;
//}EdgeNode;
//
//typedef struct VertexNode{//顶点表结点
//	VertexType data;
//	EdgeNode *firstedge;
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct{
//	AdjList adjlist;
//	int numVertexes, numEdges;
//}GraphAdjList;
////打印邻接表
//printf("邻接表为:\n");
//for (i = 0; i<G->numVertexes; i++){
//	p = G->adjlist[i].firstedge;
//	while (p){
//		printf("(%c,%c)", G->adjlist[i].data, G->adjlist[p->adjvex].data);
//		p = p->next;
//	}
//	printf("\n");
//}


