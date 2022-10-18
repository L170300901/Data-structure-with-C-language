#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef int BTData;

typedef struct _bTreeNode
{
	int data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	
	return nd;
}
void insert(BTreeNode* n, int data)
{
	if (n->data > data)
	{
		if (n->left == NULL)
		{
			n->left = MakeBTreeNode();
			n->left->data = data;
		}
		else
		{
			insert(n->left, data);
		}
	}
	else
	{
		if (n->right == NULL)
		{
			n->right = MakeBTreeNode();
			n->right->data = data;
		}
		else
		{
			insert(n->right, data);
		}

	}
}
void postorder(BTreeNode*n)
{
	if (n == NULL)
		return;
	if (n->left != NULL)
		postorder(n->left);
	if (n->right!= NULL)
		postorder(n->right);
	printf("%d\n", n->data);

}
int main()
{
	int num;
	BTreeNode root;
	scanf("%d", &(root.data));
	root.right = root.left = NULL;
	while (scanf("%d", &num) != EOF)
	{
		insert(&root, num);
	}
	postorder(&root);
	return 0;
}