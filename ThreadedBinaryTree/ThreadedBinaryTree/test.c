#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS

#include "TBTree.h"

int main()
{
	//����������
	char str[100];
	printf("������������������������:");
	scanf("%s", str);
	int i = 0;
	BTNode* root = CreateTree(str, &i);

	//����������������
	CreateInThread(root);

	//�������
	printf("�����������Ϊ:");
	InOrder(root);
	printf("\n");

	//���������
	printf("�������������Ϊ:");
	RevInOrder(root);
	printf("\n");

	return 0;
}