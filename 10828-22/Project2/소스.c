#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int stack[100000];
	int n, i;
	int top = -1;
	char str[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(" %s", str);
		if (strcmp("push", str) == 0)
		{
			int num;
			scanf("%d", &num);
			top++;
			stack[top] = num;


		}
		else if (strcmp("pop", str) == 0)
		{
			if (top == -1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", stack[top]);
				stack[top] = 0;
				top--;
			}
		}
		else if (strcmp("size", str) == 0)
		{
			printf("%d\n", top + 1);
		}
		else if (strcmp("empty", str) == 0)
		{
			if (top == -1)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}

		}
		else if (strcmp("top", str) == 0)
		{
			if (top == -1)
			{
				printf("-1\n");
			}
			else
				printf("%d\n", stack[top]);

		}
	}
	return 0;
}
