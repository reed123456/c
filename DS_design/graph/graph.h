//#include"stdio.h"
//#include "stdlib.h"
//#include "conio.h"
//
//#define MAXADJSIZE 20
//int visited[MAXADJSIZE];
//
////ͼ��  �ڽӱ�  ���淽ʽ
//typedef struct ArcNode{
//	struct ArcNode *nextarc;//��һ���� 
//	int adjvex;//���ڶ��� 
//}ArcNode;
//typedef struct VNode{
//	struct ArcNode *firstarc;  //ָ���һ���� 
//	int data;  //������Ϣ 
//}VNode, AdjList[MAXADJSIZE];
//typedef struct{
//	AdjList vex;
//	int vexnum, arcnum;
//}Graph;
//
////���е���ʽ����   ���ڹ�����ȵı��� 
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
////	if (!(Q.front = Q.rear = (Qptr)malloc(sizeof(QNode)*MAXADJSIZE))) printf("�������ʧ�ܣ�����\n");
////	else{
////		Q.front->next = NULL;
////	}
////}
///*
//void EnQueue(LinkQ Q, int e)
//{
//Qptr p;
//if (!(p = (Qptr)malloc(sizeof(QNode)))) printf("�������ʧ�ܣ�����\n");
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
//if (Q.rear == Q.front) printf("�˶���Ϊ�գ�����\n");
//else{
//Qptr p;
//if (!(p = (Qptr)malloc(sizeof(QNode)))) printf("�������ʧ�ܣ�����\n");
//else{
//p = Q.front->next;
//e = p->v;
//Q.front->next = p->next;
//if (Q.rear == p) Q.rear = Q.front;  //�������е����һ��Ԫ�ر�ɾ����ʱ��rear�ᶪʧ��Ӧ�ö������¸�ֵ
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
////��ڵ�v��ӵĵ�һ����
//int FirstAdjVex(Graph G, int v)
//{
//return G.vex[v].firstarc->adjvex;
//}
//// ��ڵ�v��ӵ���һ����
//int NextAdjVex(Graph G, int v, int w)
//{
//ArcNode *p;
//if (!(p = (ArcNode *)malloc(sizeof(ArcNode))))
//printf("�������ʧ�ܣ�����\n");
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
//{//ͼ�Ĺ�����ȱ���
//int v, u;
//LinkQ Q;
//for (v = 0; v<G.vexnum; ++v)
//visited[v] = 0;
//InitQueue(Q);
//for (v = 0; v<G.vexnum; ++v)
//{
//printf("�Ե�v%dΪ���Ľ����", v + 1);
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
//void creat(Graph *G)//�����洢ͼ���ڽӱ� 
//{
//	int j, i;
//	ArcNode *s, *t, *p;
//	int v1, v2;
//	printf("��������ͼ������Ŀ������ͼ������>");
//	scanf("%d%d", &G->vexnum, &G->arcnum);
//	for (i = 0; i<G->vexnum; i++){
//		G->vex[i].data = i;
//		G->vex[i].firstarc = NULL;
//	}
//	for (int k = 0; k<G->arcnum; k++)
//	{
//		printf("�������%d������������������>", k + 1);
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
////ͷ�ڵ�
//typedef struct headnode{
//	char vertex;
//	eNode *firstedge;
//}hNode;
////�ڽӱ�
//typedef struct{
//	hNode adjlist[max];
//	int n, e;   //������������ 
//}linkG;
//
////��ӡ�ڽӱ�
//printf("�ڽӱ�Ϊ:\n");
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
//typedef struct EdgeNode{//�߱��� 
//	int adjvex;
//	struct EdgeNode *next;
//}EdgeNode;
//
//typedef struct VertexNode{//�������
//	VertexType data;
//	EdgeNode *firstedge;
//}VertexNode, AdjList[MAXVEX];
//
//typedef struct{
//	AdjList adjlist;
//	int numVertexes, numEdges;
//}GraphAdjList;
////��ӡ�ڽӱ�
//printf("�ڽӱ�Ϊ:\n");
//for (i = 0; i<G->numVertexes; i++){
//	p = G->adjlist[i].firstedge;
//	while (p){
//		printf("(%c,%c)", G->adjlist[i].data, G->adjlist[p->adjvex].data);
//		p = p->next;
//	}
//	printf("\n");
//}


