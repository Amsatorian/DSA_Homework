#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define VertexType char	//顶点数据类型
#define VertexMax 20	//最大顶点个数

typedef struct ArcNode	//边表
{
	int adjVex;			//该顶点在顶点数组中的位置
	struct ArcNode* next;
}ArcNode;

typedef struct VNode	//顶点
{
	VertexType vertex;
	struct ArcNode* firstArc;
}VNode;

typedef struct ALGraph
{
	VNode AdjList[VertexMax];	//顶点构成的结构体数组，即邻接表表头
	int vexNum, arcNum;
	int kind;
}ALGraph;

int LocateVex(ALGraph* G, VertexType v);//返回顶点在顶点数组内的下标

void CreateDG(ALGraph* G);
void CreateUDG(ALGraph* G);

void GraphChoice(ALGraph* G);

void PrintList(ALGraph G);