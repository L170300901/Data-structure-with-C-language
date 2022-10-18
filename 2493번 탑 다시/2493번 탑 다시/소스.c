#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cnt;
int top;
typedef struct _ar
{
	int a;  //À§Ä¡
	int b;  //°ª
}ar;
ar stack[500005];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		while (top > 0)
		{
			if (stack[top].b >= temp)
			{
				printf("%d ", stack[top].a);
				break;
			}
			else
			{
				top--;
			}
		}
		if (top <= 0)
		{
			printf("0 ");
		}
		top++;
		stack[top].a = i + 1;
		stack[top].b = temp;
	}
}