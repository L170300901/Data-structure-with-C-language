#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int inorder[100005];
	int postorder[100005];
	int N;
	scanf("%d", &N);
	int i;
	char a, b, c;
	for (i = 0; i < N; i++)
	{
		scanf("%d",&inorder[i]);
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &postorder[i]);
	}
	int j;
	
	return 0;
}