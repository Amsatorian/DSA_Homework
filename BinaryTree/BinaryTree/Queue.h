#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "BinaryTree.h"

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueRear(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

void QueuePrint(Queue* pq);