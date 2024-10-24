#include "Stack.h"

int main()
{
	ST st;
	StackInit(&st);
	//将1,2,3,4依次入栈
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPrint(&st);
	printf("栈的长度为:%d\n", StackSize(&st));

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPrint(&st);
	printf("栈的长度为:%d\n", StackSize(&st));

	StackPush(&st, 5);
	StackPush(&st, 6);
	StackPrint(&st);
	printf("栈顶元素为:%d\n", StackTop(&st));

	StackClear(&st);
	printf("Clear后的栈的长度为:%d\n", StackSize(&st));

	StackDestroy(&st);//销毁栈
}