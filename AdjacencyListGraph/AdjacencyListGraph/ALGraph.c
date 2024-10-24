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
	printf("���붥������ͱ���:\n");
	printf("������ v = ");
	scanf("%d", &G->vexNum);
	printf("��  �� e = ");
	scanf("%d", &G->arcNum);
	printf("\n");

	printf("\n");
	printf("���붥��Ԫ��(�ÿո����):");
	for (int i = 0; i < G->vexNum; i++)
	{
		scanf(" %c", &G->AdjList[i].vertex);
		G->AdjList[i].firstArc = NULL;
	}
	printf("\n");

	VertexType v1, v2;
	printf("������ߵ���Ϣ:\n\n");
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
		arc->next = G->AdjList[n].firstArc;		//ͷ�巨
		G->AdjList[n].firstArc = arc;
	}
	G->kind = 1;
}

void CreateUDG(ALGraph* G)
{
	printf("���붥������ͱ���:\n");
	printf("������ v = ");
	scanf("%d", &G->vexNum);
	printf("��  �� e = ");
	scanf("%d", &G->arcNum);
	printf("\n");

	printf("\n");
	printf("���붥��Ԫ��(�ÿո����):");
	for (int i = 0; i < G->vexNum; i++)
	{
		scanf(" %c", &G->AdjList[i].vertex);
		G->AdjList[i].firstArc = NULL;
	}
	printf("\n");

	VertexType v1, v2;
	printf("������ߵ���Ϣ:\n\n");
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
	printf(" ��ѡ��ͼ������: 1.����ͼDG  2.����ͼUDG\n\n");
	scanf("%d", &target);
	printf("\n");

	switch (target)
	{
	case 1:
		printf("ѡ���������ͼDG\n\n");
		CreateDG(G);
		break;
	case 2:
		printf("ѡ���������ͼUDG\n\n");
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
	printf("\n �ڽӱ�: \n");

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