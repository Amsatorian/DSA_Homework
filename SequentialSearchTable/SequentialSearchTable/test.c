#include "SSTable.h"

int main()
{
	SSTable T1;
	InitTable(&T1);
	ElemType arr1[10] = { 0, 5, 3, 6, 2, 7, 9, 8, 1, 4 };
	for (int i = 0; i < 10; i++)
	{
		AddElem(&T1, arr1[i]);
	}
	printf("T1中元素为5的下标为:%d\n", SequentialSearch(T1, 5));
	printf("T1中元素为6的下标为:%d\n", SequentialSearch(T1, 6));
	printf("T1中元素为4的下标为:%d\n", SequentialSearch(T1, 4));

	printf("\n");

	SSTable T2;
	InitTable(&T2);
	ElemType arr2[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < 10; i++)
	{
		AddElem(&T2, arr2[i]);
	}
	printf("T2中元素为8的下标为:%d\n", BinarySearch(T2, 8));
	printf("T2中元素为2的下标为:%d\n", BinarySearch(T2, 2));
	printf("T2中元素为5的下标为:%d\n", BinarySearch(T2, 5));

	return 0;
}