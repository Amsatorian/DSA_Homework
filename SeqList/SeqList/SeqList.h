#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);

void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

int SeqListFind(SL* ps, SLDataType x);//查找x元素第一次1出现的位置
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
