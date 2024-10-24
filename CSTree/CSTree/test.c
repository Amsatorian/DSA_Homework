#pragma warning(disable:6031)

#define _CRT_SECURE_NO_WARNINGS

#include "CSTree.h"

int main()
{
	//创建树(以先根遍历创建一棵树)
	char str[100];
	printf("请输入树的对应二叉树的先序遍历序列:");
	scanf("%s", str);
	int i = 0;
	CSNode* root = CreateTree(str, &i);

	printf("树的先根遍历序列为:");
	PrevOrder(root);

	printf("\n");
}