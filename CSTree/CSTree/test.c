#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS

#include "CSTree.h"

int main()
{
	//������(���ȸ���������һ����)
	char str[100];
	printf("���������Ķ�Ӧ�������������������:");
	scanf("%s", str);
	int i = 0;
	CSNode* root = CreateTree(str, &i);

	printf("�����ȸ���������Ϊ:");
	PrevOrder(root);

	printf("\n");
}