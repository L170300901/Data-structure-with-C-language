#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
double stack[105];
char word[105];
int num[30];
int main()
{
	int n;
	scanf("%d", &n);
	scanf(" %s", word);
	int top = -1, cnt = 0;
	int len = strlen(word);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < len; i++)
	{
		if('A' <= word[i] && word[i] <= 'Z')
		{
			stack[++top] =num[word[i]-'A'];
		}
		else //연산자가 나오면 
		{
			if (word[i] == '+')
			{
				double temp;
				temp = stack[top - 1] + stack[top];
				top = top - 2;
				stack[++top] = temp;
			}
			else if (word[i] == '-')
			{
				double temp;
				temp = stack[top - 1] - stack[top];
				top = top - 2;
				stack[++top] = temp;
			}
			else if (word[i] == '*')
			{
				double temp;
				temp = stack[top - 1] * stack[top];
				top = top - 2;
				stack[++top] = temp;
			}
			else if (word[i] == '/')
			{
				double temp;
				temp = stack[top - 1] / stack[top];
				top = top - 2;
				stack[++top] = temp;
			}
		}
	}
	printf("%.2lf", stack[top]);
	return 0;	
}