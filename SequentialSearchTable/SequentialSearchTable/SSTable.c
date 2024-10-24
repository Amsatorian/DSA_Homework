#include "SSTable.h"

void InitTable(SSTable* T)
{
	T->elem = (ElemType*)malloc(sizeof(ElemType) * (MaxSize + 1));
	assert(T->elem != NULL);
	T->elem[0] = Sentry;
	T->length = 0;
}

void AddElem(SSTable* T, ElemType elem)
{
	if (T->length == MaxSize)
	{
		printf("顺序表已满，元素添加失败");
		return;
	}
	T->elem[T->length + 1] = elem;
	T->length++;
	return;
}

int SequentialSearch(SSTable T, ElemType key)
{
	assert(T.length != 0);//表为空
	T.elem[0] = key;
	for (int i = 1; i <= MaxSize; i++)
	{
		if (T.elem[i] == key)
		{
			return i;
		}
	}
	return 0;
}

int BinarySearch(SSTable T, ElemType key)
{
	int low = 1;
	int high = T.length;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key > T.elem[mid])
		{
			low = mid + 1;
		}
		else if (key < T.elem[mid])
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return 0;
}