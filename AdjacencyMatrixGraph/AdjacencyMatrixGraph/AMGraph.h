#pragma once
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define VertexMax 10	//��󶥵���
#define MaxSize 10		//�������Ԫ�ظ���
#define MaxInt 32767	//�����������ʾ��

typedef char VertexType;	//������������
typedef int DataType;		//������������

typedef enum
{
	DG, UDG, DN, UDN
}GraphKind;

typedef struct MGraph
{
	VertexType Vertex[VertexMax];	//��Ŷ���Ԫ�ص�����
	int AdjMatrix[VertexMax][VertexMax];	//�ڽӾ���
	int VexNum, ArcNum;
	int kind;	//ͼ������
}MGraph;

typedef struct CQueue
{
	DataType* base;
	int front;
	int rear;
}CQueue;

int LocateVex(MGraph* G, VertexType v);//���Ҷ�����һά������±꣬�������±�

void CreateDG(MGraph* G);//��������ͼ(Directed Graph)
void CreateUDG(MGraph* G);//��������ͼ(Undirected Graph)
void CreateDN(MGraph* G);//����������(Directed Network)
void CreateUDN(MGraph* G);//����������(Undirected Nexwork)

void GraphChoice(MGraph* G);//ѡ��ͼ������

void PrintMatrix(MGraph G);//��ӡ�ڽӾ���

void CreateCQueue(CQueue* Q);//����ѭ������
void EnQueue(CQueue* Q, DataType data);//���
void DeQueue(CQueue* Q, DataType* data);//����
bool QueueEmpty(CQueue* Q);//�ж϶����Ƿ�Ϊ�գ������򷵻�true�����򷵻�false
bool QueueFull(CQueue* Q);//�ж϶����Ƿ�Ϊ���������򷵻�true�����򷵻�false

void BFS(MGraph* G, int i);//Breadth_First Search�����������(����ͼUDG)
void BFSTraverse(MGraph* G);//Breadth_First Search Traverse������ȱ���(����ͼUDG)

void DFS(MGraph* G, int i);//Depth_First Search�����������(����ͼUDG)
void DFSTraverse(MGraph* G);//Depth_First Search Traverse�����������(����ͼUDG)