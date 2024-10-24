#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define VertexType char	//������������
#define VertexMax 20	//��󶥵����

typedef struct ArcNode	//�߱�
{
	int adjVex;			//�ö����ڶ��������е�λ��
	struct ArcNode* next;
}ArcNode;

typedef struct VNode	//����
{
	VertexType vertex;
	struct ArcNode* firstArc;
}VNode;

typedef struct ALGraph
{
	VNode AdjList[VertexMax];	//���㹹�ɵĽṹ�����飬���ڽӱ��ͷ
	int vexNum, arcNum;
	int kind;
}ALGraph;

int LocateVex(ALGraph* G, VertexType v);//���ض����ڶ��������ڵ��±�

void CreateDG(ALGraph* G);
void CreateUDG(ALGraph* G);

void GraphChoice(ALGraph* G);

void PrintList(ALGraph G);