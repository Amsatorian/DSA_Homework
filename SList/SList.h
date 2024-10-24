#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

SLTNode* SListInit();
SLTNode* BuySListNode(SLTDateType x);

int CountNode(SLTNode* phead);//计算结点数

void SListPrint(SLTNode* phead);

void SListInsert(SLTNode* phead, int pos, SLTDateType x);//插入x，并且x是第pos个结点的数据
void SListPushFront(SLTNode* phead, SLTDateType x);//头插
void SListPushBack(SLTNode* phead, SLTDateType x);//尾插

void SListErase(SLTNode* phead, int pos);//删除pos位置的结点
void SListPopBack(SLTNode* phead);//头删
void SListPopFront(SLTNode* phead);//尾删