#pragma once
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define VertexMax 10	//最大顶点数
#define MaxSize 10		//队列最大元素个数
#define MaxInt 32767	//最大整数，表示∞

typedef char VertexType;	//顶点数据类型
typedef int DataType;		//队列数据类型

typedef enum
{
	DG, UDG, DN, UDN
}GraphKind;

typedef struct MGraph
{
	VertexType Vertex[VertexMax];	//存放顶点元素的数组
	int AdjMatrix[VertexMax][VertexMax];	//邻接矩阵
	int VexNum, ArcNum;
	int kind;	//图的类型
}MGraph;

typedef struct CQueue
{
	DataType* base;
	int front;
	int rear;
}CQueue;

int LocateVex(MGraph* G, VertexType v);//查找顶点在一维数组的下标，并返回下标

void CreateDG(MGraph* G);//创建有向图(Directed Graph)
void CreateUDG(MGraph* G);//创建无向图(Undirected Graph)
void CreateDN(MGraph* G);//创建有向网(Directed Network)
void CreateUDN(MGraph* G);//创建无向网(Undirected Nexwork)

void GraphChoice(MGraph* G);//选择图的类型

void PrintMatrix(MGraph G);//打印邻接矩阵

void CreateCQueue(CQueue* Q);//创建循环队列
void EnQueue(CQueue* Q, DataType data);//入队
void DeQueue(CQueue* Q, DataType* data);//出队
bool QueueEmpty(CQueue* Q);//判断队列是否为空，若空则返回true，否则返回false
bool QueueFull(CQueue* Q);//判断队列是否为满，若满则返回true，否则返回false

void BFS(MGraph* G, int i);//Breadth_First Search广度优先搜索(无向图UDG)
void BFSTraverse(MGraph* G);//Breadth_First Search Traverse广度优先遍历(无向图UDG)

void DFS(MGraph* G, int i);//Depth_First Search深度优先搜索(无向图UDG)
void DFSTraverse(MGraph* G);//Depth_First Search Traverse深度优先搜索(无向图UDG)