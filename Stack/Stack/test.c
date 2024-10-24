#include "Stack.h"

int main()
{
	ST st;
	StackInit(&st);
	//��1,2,3,4������ջ
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPrint(&st);
	printf("ջ�ĳ���Ϊ:%d\n", StackSize(&st));

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPrint(&st);
	printf("ջ�ĳ���Ϊ:%d\n", StackSize(&st));

	StackPush(&st, 5);
	StackPush(&st, 6);
	StackPrint(&st);
	printf("ջ��Ԫ��Ϊ:%d\n", StackTop(&st));

	StackClear(&st);
	printf("Clear���ջ�ĳ���Ϊ:%d\n", StackSize(&st));

	StackDestroy(&st);//����ջ
}