#include "Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	//1,2,3,4,5���
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);

	//����2��
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);

	printf("��ͷԪ��Ϊ:%d,��βԪ��Ϊ:%d\n", QueueFront(&q), QueueRear(&q));
	printf("���еĳ���Ϊ:%d\n", QueueSize(&q));

	QueueDestroy(&q);//���ٶ���
}