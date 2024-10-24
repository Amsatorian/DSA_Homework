#include "CQueue.h"

void CQueueInit(CQueue* pcq)
{
	assert(pcq);
	pcq->base = (CQDataType*)malloc(MAXSIZE * sizeof(CQDataType));
	if (pcq->base == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	pcq->front = pcq->rear = 0;
}

void CQueueDestroy(CQueue* pcq)
{
	assert(pcq);
	free(pcq->base);
	pcq->base = NULL;
}

CQDataType CQueueFront(CQueue* pcq)
{
	assert(pcq);
	return pcq->base[pcq->front];
}

void CQueueClear(CQueue* pcq)
{
	assert(pcq);
	pcq->front = pcq->rear = 0;
}

void CQueuePush(CQueue* pcq, CQDataType x)
{
	assert(pcq);
	assert(!CQueueFull(pcq));
	pcq->base[pcq->rear] = x;
	pcq->rear = (pcq->rear + 1) % MAXSIZE;
}

void CQueuePop(CQueue* pcq)
{
	assert(pcq);
	assert(!CQueueEmpty(pcq));
	pcq->front = (pcq->front + 1) % MAXSIZE;
}

int CQueueSize(CQueue* pcq)
{
	assert(pcq);
	return (pcq->rear - pcq->front + MAXSIZE) % MAXSIZE;
}

bool CQueueEmpty(CQueue* pcq)//若队列为空，返回true，否则返回false
{
	assert(pcq);
	return pcq->front == pcq->rear;
}

bool CQueueFull(CQueue* pcq)//若队列为满，返回true。否则返回false
{
	assert(pcq);
	return pcq->front == (pcq->rear + 1) % MAXSIZE;
}

void CQueuePrint(CQueue* pcq)
{
	assert(pcq);
	assert(!CQueueEmpty(pcq));
	int cur = pcq->front;
	while (cur != pcq->rear)
	{
		printf("%d ", pcq->base[cur]);
		cur = (cur + 1) % MAXSIZE;
	}
	printf("\n");
}