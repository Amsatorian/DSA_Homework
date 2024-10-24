#include "SeqList.h"

int main()
{
	SL s;
	SeqListInit(&s);//初始化

	//尾插1，2，3，4
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListPrint(&s);

	//头插1，2，3，4
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);

	SeqListPrint(&s);

	//头删3次，尾删2次
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	//插入
	SeqListInsert(&s, 0, 1);
	SeqListInsert(&s, 2, 3);
	SeqListInsert(&s, 4, 5);

	SeqListPrint(&s);

	//删除
	SeqListErase(&s, 2);
	SeqListErase(&s, 4);
	SeqListErase(&s, 1);

	SeqListPrint(&s);

	//查找
	printf("元素5的下标为%d", SeqListFind(&s, 5));
}