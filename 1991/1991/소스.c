#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _bTreeNode
{
	char left;
	char right;
} BTreeNode;
BTreeNode arr[100];


void PreorderTraverse(char node)
{
	if (node == '.')
		return;

	printf("%c", node);
	PreorderTraverse(arr[node].left);
	PreorderTraverse(arr[node].right);
}

void InorderTraverse(char node) //ÁßÀ§
{
	if (node == '.')
		return;

	InorderTraverse(arr[node].left);
	printf("%c", node);
	InorderTraverse(arr[node].right);
}

void PostorderTraverse(char node)
{
	if (node == '.')
		return;

	PostorderTraverse(arr[node].left);
	PostorderTraverse(arr[node].right);
	printf("%c", node);

}
int main()
{
	int N;
	scanf("%d", &N);
	int i;
	char a, b, c;
	for (i = 0; i < N;i++)
	{
		scanf(" %c %c %c", &a, &b, &c);
		arr[a].left = b;
		arr[a].right = c;
		
	}
	
	PreorderTraverse('A');
	printf("\n");
	InorderTraverse('A');
	printf("\n");
	PostorderTraverse('A');
}