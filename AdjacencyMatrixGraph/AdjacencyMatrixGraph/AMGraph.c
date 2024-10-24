#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS

#include "AMGraph.h"

int visited[VertexMax];		//定义全局变量标志数组，若被访问过则置为1，否则为0

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
	printf("输入顶点的个数和边数(用逗号隔开):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("输入顶点元素(无需空格隔开):");
	scanf("%s", G->Vertex);
	printf("\n");

	//初始化邻接矩阵，矩阵元素全部置零
	for (int i = 0; i < G->VexNum; i++)
	{
		for (int j = 0; j < G->VexNum; j++)
		{
			G->AdjMatrix[i][j] = 0;
		}
	}

	//构建邻接矩阵
	VertexType v1, v2;
	printf("请输入边的信息:\n");
	for (int i = 0; i < G->ArcNum; i++)
	{
		printf("Arc%02d\t", i + 1);
		scanf(" %c%c", &v1, &v2);
		int n = LocateVex(G, v1);	//v1的下标
		int m = LocateVex(G, v2);	//v2的下标

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
	printf("输入顶点的个数和边数(用逗号隔开):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("输入顶点元素(无需空格隔开):");
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
	printf("请输入边的信息:\n");
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
	printf("输入顶点的个数和边数(用逗号隔开):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("输入顶点元素(无需空格隔开):");
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
	int w;	//边的权值
	printf("请输入边的信息:\n");
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
	printf("输入顶点的个数和边数(用逗号隔开):");
	scanf("%d,%d", &G->VexNum, &G->ArcNum);
	printf("\n");

	printf("输入顶点元素(无需空格隔开):");
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
	printf("请输入边的信息:\n");
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
	printf(" 请选择图的类型: 1.有向图DG  2.无向图UDG  3.有向网DN  4.无向网UDN\n\n");
	scanf("%d", &target);
	printf("\n");

	switch (target)
	{
	case 1:
		printf("选择了有向图DG\n\n");
		CreateDG(G);
		break;
	case 2:
		printf("选择了无向图UDG\n\n");
		CreateUDG(G);
		break;
	case 3:
		printf("选择了有向网DN\n\n");
		CreateDN(G);
		break;
	case 4:
		printf("选择了无向网UDN\n\n");
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
	printf("\n 邻接矩阵: \n\n");

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
					printf(" ∞");
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
	//设置访问的起始点
	printf("%c", G->Vertex[i]);
	visited[i] = 1;
	EnQueue(&Q, i);
	//由起始点开始，对后续结点进行操作
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
	printf("\n广度优先遍历:");
	assert(&G);
	for (int i = 0; i < G->VexNum; i++)
	{
		visited[i] = 0;		//初始化数组全为0
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
	//设置访问的起始点
	printf("%c", G->Vertex[i]);
	visited[i] = 1;
	//由起始点开始，对后续结点操作
	//依次搜索vi的邻接点
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
	printf("\n深度优先遍历:");
	assert(&G);
	for (int i = 0; i < G->VexNum; i++)
	{
		visited[i] = 0;		//初始化访问标志数组
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