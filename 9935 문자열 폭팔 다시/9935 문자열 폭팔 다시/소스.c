#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[1000005];
char boom[50];
char stack[1000005];
int top = 0;
int main()
{
	scanf(" %s", word);
	scanf(" %s", boom);
	int size = strlen(boom);
	int sizeword = strlen(word);
	for (int i = 0; i < sizeword; i++)
	{
		int chk = 0;
		stack[top++] = word[i];
		if (stack[top - 1] == boom[size - 1])
		{
			//printf("$$$\n");
			for (int j = 0; j < size; j++)
			{
				if (stack[top - 1 - j] != boom[size - 1 - j])
				{
					chk = 1;
					break;
				}
			}
			if (chk == 0)
			{
				top = top - size;
			}
		}
		
	}
	if (top == 0)
	{
		printf("FRULA");
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			printf("%c", stack[i]);
		}
	}

	return 0;
}