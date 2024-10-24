#include "SeqList.h"

int main()
{
	SL s;
	SeqListInit(&s);//��ʼ��

	//β��1��2��3��4
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListPrint(&s);

	//ͷ��1��2��3��4
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);

	SeqListPrint(&s);

	//ͷɾ3�Σ�βɾ2��
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	//����
	SeqListInsert(&s, 0, 1);
	SeqListInsert(&s, 2, 3);
	SeqListInsert(&s, 4, 5);

	SeqListPrint(&s);

	//ɾ��
	SeqListErase(&s, 2);
	SeqListErase(&s, 4);
	SeqListErase(&s, 1);

	SeqListPrint(&s);

	//����
	printf("Ԫ��5���±�Ϊ%d", SeqListFind(&s, 5));
}