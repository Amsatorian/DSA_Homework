#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct LTNode
{
	LTDateType data;
	struct LTNode* next;
	struct LTNode* prev;
}LTNode;

LTNode* ListInit();
LTNode* BuyListNode(LTDateType x);

int CountNode(LTNode* phead);
void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDateType x);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDateType x);
void ListPopFront(LTNode* phead);

void ListInsert(LTNode* phead, int pos, LTDateType x);//插入一个结点，并且该结点在pos位置
void ListErase(LTNode* phead, int pos);//删除pos结点

void ListDestroy(LTNode* phead);