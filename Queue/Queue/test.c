#include "Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	//1,2,3,4,5入队
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);

	//出队2次
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);

	printf("队头元素为:%d,队尾元素为:%d\n", QueueFront(&q), QueueRear(&q));
	printf("队列的长度为:%d\n", QueueSize(&q));

	QueueDestroy(&q);//销毁队列
}