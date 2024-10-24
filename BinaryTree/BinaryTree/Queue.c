#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);//检测newnode是否为空
	newnode->data = x;
	newnode->next = NULL;
	if (pq->front == NULL)
	{
		pq->front = pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->front->next;
	free(pq->front);
	pq->front = next;
	if (pq->front == NULL)
	{
		pq->rear = NULL;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->front->data;
}

QDataType QueueRear(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->rear->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->front;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue* pq)//若队列为空，返回true，否则返回false
{
	assert(pq);
	return pq->front == NULL;
}

void QueuePrint(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	/*if (pq->front == NULL)
	{
		printf("队列为空");
		return;
	}*/
	QueueNode* cur = pq->front;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}