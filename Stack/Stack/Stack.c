#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//栈顶的上一位
	ps->capacity = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* temp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)//若为空则返回true
{
	assert(ps);

	/*if (ps->top == 0)
	{
		return 1(true);
	}
	else
	{
		return 0(false);
	}*/

	return ps->top == 0;
}

void StackClear(ST* ps)
{
	assert(ps);
	ps->top = 0;
}

void StackPrint(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	for (int i = 0; i < ps->top; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}