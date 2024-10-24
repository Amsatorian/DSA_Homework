#include "CQueue.h"

int main()
{
	CQueue cq;
	CQueueInit(&cq);

	//1,2,3,4,5���
	CQueuePush(&cq, 1);
	CQueuePush(&cq, 2);
	CQueuePush(&cq, 3);
	CQueuePush(&cq, 4);
	CQueuePush(&cq, 5);
	CQueuePrint(&cq);
	printf("��ͷԪ��Ϊ:%d\n", CQueueFront(&cq));
	printf("���еĳ���Ϊ:%d\n", CQueueSize(&cq));
	printf("\n");

	//����3��
	CQueuePop(&cq);
	CQueuePop(&cq);
	CQueuePop(&cq);
	CQueuePrint(&cq);
	printf("��ͷԪ��Ϊ:%d\n", CQueueFront(&cq));
	printf("���еĳ���Ϊ:%d\n", CQueueSize(&cq));
	printf("\n");

	//2,5���
	CQueuePush(&cq, 2);
	CQueuePush(&cq, 5);
	CQueuePrint(&cq);
	printf("��ͷԪ��Ϊ:%d\n", CQueueFront(&cq));
	printf("���еĳ���Ϊ:%d\n", CQueueSize(&cq));
	printf("\n");

	CQueueClear(&cq);//�ÿն���
	printf("�ÿպ���еĳ���Ϊ:%d\n", CQueueSize(&cq));
	printf("\n");

	CQueueDestroy(&cq);//���ٶ���
}