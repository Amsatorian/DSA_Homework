#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS

#include "ALGraph.h"

int LocateVex(ALGraph* G, VertexType v)
{
	for (int i = 0; i < G->vexNum; i++)
	{
		if (v == G->AdjList[i].vertex)
		{
			return i;
		}
	}

	printf("No Such Vertex!\n");
	return -1;
}

void CreateDG(ALGraph* G)
{
	printf("输入顶点个数和边数:\n");
	printf("顶点数 v = ");
	scanf("%d", &G->vexNum);
	printf("边  数 e = ");
	scanf("%d", &G->arcNum);
	printf("\n");

	printf("\n");
	printf("输入顶点元素(用空格隔开):");
	for (int i = 0; i < G->vexNum; i++)
	{
		scanf(" %c", &G->AdjList[i].vertex);
		G->AdjList[i].firstArc = NULL;
	}
	printf("\n");

	VertexType v1, v2;
	printf("请输入边的信息:\n\n");
	for (int i = 0; i < G->arcNum; i++)
	{
		printf("Arc%02d\t", i + 1);
		scanf(" %c%c", &v1, &v2);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("No Such Vertex!\n");
			return;
		}

		ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
		assert(arc != NULL);
		/*if (arc == NULL)
		{
			printf("malloc fail!\n");
			exit(-1);
		}*/
		arc->adjVex = m;
		arc->next = G->AdjList[n].firstArc;		//头插法
		G->AdjList[n].firstArc = arc;
	}
	G->kind = 1;
}

void CreateUDG(ALGraph* G)
{
	printf("输入顶点个数和边数:\n");
	printf("顶点数 v = ");
	scanf("%d", &G->vexNum);
	printf("边  数 e = ");
	scanf("%d", &G->arcNum);
	printf("\n");

	printf("\n");
	printf("输入顶点元素(用空格隔开):");
	for (int i = 0; i < G->vexNum; i++)
	{
		scanf(" %c", &G->AdjList[i].vertex);
		G->AdjList[i].firstArc = NULL;
	}
	printf("\n");

	VertexType v1, v2;
	printf("请输入边的信息:\n\n");
	for (int i = 0; i < G->arcNum; i++)
	{
		printf("Arc%02d\t", i + 1);
		scanf(" %c%c", &v1, &v2);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("No Such Vertex!\n");
			return;
		}

		ArcNode* arc1 = (ArcNode*)malloc(sizeof(ArcNode));
		assert(arc1 != NULL);
		arc1->adjVex = m;
		arc1->next = G->AdjList[n].firstArc;
		G->AdjList[n].firstArc = arc1;

		ArcNode* arc2 = (ArcNode*)malloc(sizeof(ArcNode));
		assert(arc2 != NULL);
		arc2->adjVex = n;
		arc2->next = G->AdjList[m].firstArc;
		G->AdjList[m].firstArc = arc2;
	}
	G->kind = 2;
}

void GraphChoice(ALGraph* G)
{
	int target;
	printf(" 请选择图的类型: 1.有向图DG  2.无向图UDG\n\n");
	scanf("%d", &target);
	printf("\n");

	switch (target)
	{
	case 1:
		printf("选择的是有向图DG\n\n");
		CreateDG(G);
		break;
	case 2:
		printf("选择的是无向图UDG\n\n");
		CreateUDG(G);
		break;
	default:
		printf("Error Choice!\n");
		exit(-1);
		break;
	}
}

void PrintList(ALGraph G)
{
	printf("\n--------------------------------------------------");
	printf("\n 邻接表: \n");

	for (int i = 0; i < G.vexNum; i++)
	{
		printf("\n	AdjList[%d]%4c", i, G.AdjList[i].vertex);
		ArcNode* arc = G.AdjList[i].firstArc;

		while (arc != NULL)
		{
			printf("-->%d", arc->adjVex);
			arc = arc->next;
		}
	}
	printf("\n\n--------------------------------------------------");
}