#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS

#include "TBTree.h"

int main()
{
	//创建二叉树
	char str[100];
	printf("请输入二叉树的先序遍历序列:");
	scanf("%s", str);
	int i = 0;
	BTNode* root = CreateTree(str, &i);

	//中序线索化二叉树
	CreateInThread(root);

	//中序遍历
	printf("中序遍历序列为:");
	InOrder(root);
	printf("\n");

	//逆中序遍历
	printf("逆中序遍历序列为:");
	RevInOrder(root);
	printf("\n");

	return 0;
}