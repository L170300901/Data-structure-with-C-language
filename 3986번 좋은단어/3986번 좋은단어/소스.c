#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cnt;
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		char stack[100005] = { 0, };
		char word[100005] = { 0, };
		int top = 0;
		scanf(" %s", &word);
		int size = strlen(word);
		for (int j = 0; j < size; j++)
		{
			if (top == 0)
			{
				stack[top++] = word[j];
			}
			else //비어 있찌 않으면 
			{
				if (stack[top - 1] == word[j])
				{
					top = top - 1;
				}
				else
				{
					stack[top++] = word[j];
				}
				
			}
		}
		if (top == 0)
		{
			cnt++;
		}
	}
	printf("%d\n", cnt);
}