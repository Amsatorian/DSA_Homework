#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int CQDataType;
#define MAXSIZE 6//实际只能存储n-1个元素

typedef struct CQueue
{
	CQDataType* base;
	int front;
	int rear;
}CQueue;

void CQueueInit(CQueue* pcq);
void CQueueDestroy(CQueue* pcq);
void CQueueClear(CQueue* pcq);
CQDataType CQueueFront(CQueue* pcq);
void CQueuePush(CQueue* pcq, CQDataType x);
void CQueuePop(CQueue* pcq);
int CQueueSize(CQueue* pcq);
bool CQueueEmpty(CQueue* pcq);
bool CQueueFull(CQueue* pcq);

void CQueuePrint(CQueue* pcq);