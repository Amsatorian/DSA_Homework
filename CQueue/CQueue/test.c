#include "CQueue.h"

int main()
{
	CQueue cq;
	CQueueInit(&cq);

	//1,2,3,4,5入队
	CQueuePush(&cq, 1);
	CQueuePush(&cq, 2);
	CQueuePush(&cq, 3);
	CQueuePush(&cq, 4);
	CQueuePush(&cq, 5);
	CQueuePrint(&cq);
	printf("队头元素为:%d\n", CQueueFront(&cq));
	printf("队列的长度为:%d\n", CQueueSize(&cq));
	printf("\n");

	//出队3次
	CQueuePop(&cq);
	CQueuePop(&cq);
	CQueuePop(&cq);
	CQueuePrint(&cq);
	printf("队头元素为:%d\n", CQueueFront(&cq));
	printf("队列的长度为:%d\n", CQueueSize(&cq));
	printf("\n");

	//2,5入队
	CQueuePush(&cq, 2);
	CQueuePush(&cq, 5);
	CQueuePrint(&cq);
	printf("队头元素为:%d\n", CQueueFront(&cq));
	printf("队列的长度为:%d\n", CQueueSize(&cq));
	printf("\n");

	CQueueClear(&cq);//置空队列
	printf("置空后队列的长度为:%d\n", CQueueSize(&cq));
	printf("\n");

	CQueueDestroy(&cq);//销毁队列
}