#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


typedef int BTData;
typedef struct _bTreeNode
{
	BTData data;
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

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}
int main()
{
	int N,i;
	BTreeNode* a = MakeBTreeNode();
	BTreeNode* b = MakeBTreeNode();
	int cnt = 0;
	int b2=0;
	scanf("%d", &N);
	for (i = 1; i <= N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		if (a == 1 || b == 1)
		{
			if (a == 1)
			{
				MakeLeftSubTree(a, b);
				cnt++;
				b2 = b;
				break;
			}
			if (b == 1 && cnt == 1)
			{
				MakeRightSubTree(a, b);

				break;
			}
			if (b == 1 && cnt == 0)
			{
				MakeLeftSubTree(a, b);
				break;
			}
			if (a == 1 && cnt == 1)
			{
				MakeRightSubTree(a, b);
				break;
			}
		}
		else
		{
			if (b == b2 || a == b2)
			{
				if (b == b2)
				{
					MakeRightSubTree(b2,b);
					b2 = b;
					break;				}
				if (a == b2)
				{
					MakeRightSubTree(b2,a);
					b2 = a;
					break;
				}
				

			}
		
			
		}


	}
	return 0;

}