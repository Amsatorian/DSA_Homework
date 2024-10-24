#include "TBTree.h"

//����һ��ȫ�ֱ���prev��ָ��ǰ���ʽڵ��ǰ��
BTNode* prev = NULL;

//���������������һ��������������#��ʾ����
BTNode* CreateTree(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	root->data = a[*pi];
	root->LTag = 0;
	root->RTag = 0;
	(*pi)++;
	root->LChild = CreateTree(a, pi);
	root->RChild = CreateTree(a, pi);

	return root;
}

void visit(BTNode* root)
{
	if (root->LChild == NULL)
	{
		root->LChild = prev;
		root->LTag = 1;
	}

	if (prev != NULL && prev->RChild == NULL)
	{
		prev->RChild = root;
		prev->RTag = 1;
	}
	prev = root;
}

//������
void InThread(BTNode* root)
{
	if (root != NULL)
	{
		InThread(root->LChild);
		visit(root);
		InThread(root->RChild);
	}
}

void CreateInThread(BTNode* root)
{
	prev = NULL;
	if (root != NULL)
	{
		InThread(root);
	}
	if (prev != NULL && prev->RChild == NULL)//�����һ���������������
	{
		prev->RTag = 1;
	}
}

//�ҵ���rootΪ���������У���һ������������Ľ��
BTNode* FirstNode(BTNode* root)
{
	while (root->LTag == 0)
	{
		root = root->LChild;
	}
	return root;
}

//�������������������ҵ����root�ĺ�̽��
BTNode* NextNode(BTNode* root)
{
	//�����������½��
	if (root->RTag == 0)
	{
		return FirstNode(root->RChild);
	}
	else
	{
		return root->RChild;
	}
}

//���������������������������
void InOrder(BTNode* root)
{
	for (BTNode* T = FirstNode(root); T != NULL; T = NextNode(T))
	{
		printf("%c ", T->data);
	}
}

//�ҵ���rootΪ���������У����һ������������Ľ��
BTNode* LastNode(BTNode* root) {
	while (root->RTag == 0)
	{
		root = root->RChild;
	}
	return root;
}

//�������������������ҵ����p��ǰ�����
BTNode* PrevNode(BTNode* root) {
	if (root->LTag == 0)
	{
		return LastNode(root->LChild);
	}
	else
	{
		return root->LChild;
	}
}

//�����������������������������
void RevInOrder(BTNode* root)
{
	for (BTNode* T = LastNode(root); T != NULL; T = PrevNode(T))
	{
		printf("%c ", T->data);
	}
}
