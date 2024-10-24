#include "CSTree.h"

//�����ȸ���������һ����������#��ʾ����
CSNode* CreateTree(CSDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	CSNode* root = (CSNode*)malloc(sizeof(CSNode));
	if (root == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	root->data = a[*pi];
	(*pi)++;
	root->FirstChild = CreateTree(a, pi);
	root->NextSibling = CreateTree(a, pi);

	return root;
}

//�ȸ�����
void PrevOrder(CSNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->FirstChild);
	PrevOrder(root->NextSibling);
}