#include "TBTree.h"

//定义一个全局变量prev，指向当前访问节点的前驱
BTNode* prev = NULL;

//按照先序遍历创建一个二叉树，并用#表示空树
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

//线索化
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
	if (prev != NULL && prev->RChild == NULL)//对最后一个结点线索化处理
	{
		prev->RTag = 1;
	}
}

//找到以root为根的子树中，第一个被中序遍历的结点
BTNode* FirstNode(BTNode* root)
{
	while (root->LTag == 0)
	{
		root = root->LChild;
	}
	return root;
}

//在中序线索二叉树中找到结点root的后继结点
BTNode* NextNode(BTNode* root)
{
	//右子树最左下结点
	if (root->RTag == 0)
	{
		return FirstNode(root->RChild);
	}
	else
	{
		return root->RChild;
	}
}

//对中序线索二叉树进行中序遍历
void InOrder(BTNode* root)
{
	for (BTNode* T = FirstNode(root); T != NULL; T = NextNode(T))
	{
		printf("%c ", T->data);
	}
}

//找到以root为根的子树中，最后一个被中序遍历的结点
BTNode* LastNode(BTNode* root) {
	while (root->RTag == 0)
	{
		root = root->RChild;
	}
	return root;
}

//在中序线索二叉树中找到结点p的前驱结点
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

//对中序线索二叉树进行逆中序遍历
void RevInOrder(BTNode* root)
{
	for (BTNode* T = LastNode(root); T != NULL; T = PrevNode(T))
	{
		printf("%c ", T->data);
	}
}
