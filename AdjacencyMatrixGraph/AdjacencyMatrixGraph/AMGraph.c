#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS

#include "AMGraph.h"

int visited[VertexMax];		//����ȫ�ֱ�����־���飬�������ʹ�����Ϊ1������Ϊ0

int LocateVex(MGraph* G, VertexType v)
{
	for (int i = 0; i < G->VexNum; i++)
	{
		if (v == G->Vertex[i])
		{
			return i;
		}
	}

	printf("No Such Vertex!");
	return -1;
}

void CreateDG(MGraph* G)
{
	printf("���붥��ĸ����ͱ���(�ö��Ÿ���):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("���붥��Ԫ��(����ո����):");
	scanf("%s", G->Vertex);
	printf("\n");

	//��ʼ���ڽӾ��󣬾���Ԫ��ȫ������
	for (int i = 0; i < G->VexNum; i++)
	{
		for (int j = 0; j < G->VexNum; j++)
		{
			G->AdjMatrix[i][j] = 0;
		}
	}

	//�����ڽӾ���
	VertexType v1, v2;
	printf("������ߵ���Ϣ:\n");
	for (int i = 0; i < G->ArcNum; i++)
	{
		printf("Arc%02d\t", i + 1);
		scanf(" %c%c", &v1, &v2);
		int n = LocateVex(G, v1);	//v1���±�
		int m = LocateVex(G, v2);	//v2���±�

		if (n == -1 || m == -1)
		{
			printf("This Vertex Does Not Exist!\n");
			return;
		}
		G->AdjMatrix[n][m] = 1;
	}
	G->kind = 1;
}

void CreateUDG(MGraph* G)
{
	printf("���붥��ĸ����ͱ���(�ö��Ÿ���):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("���붥��Ԫ��(����ո����):");
	scanf("%s", G->Vertex);
	printf("\n");

	for (int i = 0; i < G->VexNum; i++)
	{
		for (int j = 0; j < G->VexNum; j++)
		{
			G->AdjMatrix[i][j] = 0;
		}
	}

	VertexType v1, v2;
	printf("������ߵ���Ϣ:\n");
	for (int i = 0; i < G->ArcNum; i++)
	{
		printf("Arc%02d\t", i + 1);
		scanf(" %c%c", &v1, &v2);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("This Vertex Does Not Exist!\n");
			return;
		}
		G->AdjMatrix[n][m] = 1;
		G->AdjMatrix[m][n] = 1;
	}
	G->kind = 2;
}

void CreateDN(MGraph* G)
{
	printf("���붥��ĸ����ͱ���(�ö��Ÿ���):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("���붥��Ԫ��(����ո����):");
	scanf("%s", G->Vertex);
	printf("\n");

	for (int i = 0; i < G->VexNum; i++)
	{
		for (int j = 0; j < G->VexNum; j++)
		{
			G->AdjMatrix[i][j] = MaxInt;
		}
	}

	VertexType v1, v2;
	int w;	//�ߵ�Ȩֵ
	printf("������ߵ���Ϣ:\n");
	for (int i = 0; i < G->ArcNum; i++)
	{
		printf("Arc%02d\t", i + 1);
		scanf(" %c%c,%d", &v1, &v2, &w);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("This Vertex Does Not Exist!\n");
			return;
		}
		G->AdjMatrix[n][m] = w;
	}
	G->kind = 3;
}

void CreateUDN(MGraph* G)
{
	printf("���붥��ĸ����ͱ���(�ö��Ÿ���):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("���붥��Ԫ��(����ո����):");
	scanf("%s", G->Vertex);
	printf("\n");

	for (int i = 0; i < G->VexNum; i++)
	{
		for (int j = 0; j < G->VexNum; j++)
		{
			G->AdjMatrix[i][j] = MaxInt;
		}
	}

	VertexType v1, v2;
	int w;
	printf("������ߵ���Ϣ:\n");
	for (int i = 0; i < G->ArcNum; i++)
	{
		printf("Arc%02d\t", i + 1);
		scanf(" %c%c,%d", &v1, &v2, &w);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("This Vertex Does Not Exist!\n");
			return;
		}
		G->AdjMatrix[n][m] = w;
		G->AdjMatrix[m][n] = w;
	}
	G->kind = 4;
}

void GraphChoice(MGraph* G)
{
	int target;
	printf(" ��ѡ��ͼ������: 1.����ͼDG  2.����ͼUDG  3.������DN  4.������UDN\n\n");
	scanf("%d", &target);
	printf("\n");

	switch (target)
	{
	case 1:
		printf("ѡ��������ͼDG\n\n");
		CreateDG(G);
		break;
	case 2:
		printf("ѡ��������ͼUDG\n\n");
		CreateUDG(G);
		break;
	case 3:
		printf("ѡ����������DN\n\n");
		CreateDN(G);
		break;
	case 4:
		printf("ѡ����������UDN\n\n");
		CreateUDN(G);
		break;
	default:
		printf("Error Choice!");
		exit(-1);
		break;
	}
}

void PrintMatrix(MGraph G)
{
	printf("\n-------------------------------------------------------");
	printf("\n �ڽӾ���: \n\n");

	if (G.kind == 1 || G.kind == 2)
	{
		printf("\t ");
		for (int i = 0; i < G.VexNum; i++)
		{
			printf(" %c", G.Vertex[i]);
		}
		printf("\n");

		for (int i = 0; i < G.VexNum; i++)
		{
			printf("\t%c", G.Vertex[i]);

			for (int j = 0; j < G.VexNum; j++)
			{
				printf(" %d", G.AdjMatrix[i][j]);
			}
			printf("\n");
		}
	}

	else if (G.kind == 3 || G.kind == 4)
	{
		printf("\t ");
		for (int i = 0; i < G.VexNum; i++)
		{
			printf(" %c", G.Vertex[i]);
		}
		printf("\n");

		for (int i = 0; i < G.VexNum; i++)
		{
			printf("\t%c", G.Vertex[i]);

			for (int j = 0; j < G.VexNum; j++)
			{
				if (G.AdjMatrix[i][j] == MaxInt)
				{
					printf(" ��");
				}
				else
				{
					printf(" %d", G.AdjMatrix[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n-------------------------------------------------------");
	}
}

void CreateCQueue(CQueue* Q)
{
	Q->base = (DataType*)malloc(sizeof(DataType) * MaxSize);
	//assert(Q->base);
	if (!Q->base)
	{
		printf("malloc fail");
		exit(-1);
	}
	Q->front = Q->rear = 0;
	return;
}

void EnQueue(CQueue* Q, DataType data)
{
	//assert(Q);
	if (QueueFull(Q))
	{
		printf("Queue is Ful\nl");
		exit(-1);
	}
	Q->base[Q->rear] = data;
	Q->rear = (Q->rear + 1) % MaxSize;
}

void DeQueue(CQueue* Q, DataType* data)
{
	//assert(Q);
	if (QueueEmpty(Q))
	{
		printf("Queue is Empty\n");
	}
	*data = Q->base[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
}

bool QueueEmpty(CQueue* Q)
{
	assert(Q);
	return Q->front == Q->rear;
}

bool QueueFull(CQueue* Q)
{
	assert(Q);
	return (Q->rear + 1) % MaxSize == Q->front;
}

void BFS(MGraph* G, int i)
{
	assert(&G);
	CQueue Q;
	CreateCQueue(&Q);
	assert(&Q);
	//���÷��ʵ���ʼ��
	printf("%c", G->Vertex[i]);
	visited[i] = 1;
	EnQueue(&Q, i);
	//����ʼ�㿪ʼ���Ժ��������в���
	while (!QueueEmpty(&Q))
	{
		DeQueue(&Q, &i);
		for (int j = 0; j < G->VexNum; j++)
		{
			if (G->AdjMatrix[i][j] == 1 && visited[j] == 0)
			{
				printf("%c", G->Vertex[j]);
				visited[j] = 1;
				EnQueue(&Q, j);
			}
		}
	}
}

void BFSTraverse(MGraph* G)
{
	printf("\n-------------------------------------------------------");
	printf("\n������ȱ���:");
	assert(&G);
	for (int i = 0; i < G->VexNum; i++)
	{
		visited[i] = 0;		//��ʼ������ȫΪ0
	}
	for (int i = 0; i < G->VexNum; i++)
	{
		if (visited[i] == 0)
		{
			BFS(G, i);
		}
	}
	printf("\n");
}

void DFS(MGraph* G, int i)
{
	assert(&G);
	//���÷��ʵ���ʼ��
	printf("%c", G->Vertex[i]);
	visited[i] = 1;
	//����ʼ�㿪ʼ���Ժ���������
	//��������vi���ڽӵ�
	for (int j = 0; j < G->VexNum; j++)
	{
		if (G->AdjMatrix[i][j] == 1 && visited[j] == 0)
		{
			DFS(G, j);
		}
	}
}

void DFSTraverse(MGraph* G)
{
	printf("\n-------------------------------------------------------");
	printf("\n������ȱ���:");
	assert(&G);
	for (int i = 0; i < G->VexNum; i++)
	{
		visited[i] = 0;		//��ʼ�����ʱ�־����
	}
	for (int i = 0; i < G->VexNum; i++)
	{
		if (visited[i] == 0)
		{
			DFS(G, i);
		}
	}
	printf("\n");
}