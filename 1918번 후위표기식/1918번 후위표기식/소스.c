#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char stack[105];
char word[105];
char answer[105];
int main()
{
	int top = -1, cnt = 0;
	scanf(" %s", &word);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		if ('A' <= word[i] && word[i] <= 'Z')
		{
			answer[cnt++] = word[i];
		}
		else if (word[i] == '(')
		{
			stack[++top] = word[i];
		}
		else if (word[i] == ')')  
		{
			while (top!=-1)
			{
				if (stack[top] == '(')
				{
					top--;
					break;
				}
				answer[cnt++] = stack[top--];
			}
		}
		else if (word[i] == '*' || word[i] == '/')
		{
			
			while (top!=-1)
			{
				if (stack[top] == '/' || stack[top] == '*' )
				{
					answer[cnt++] = stack[top--];
				}
				else
				{
					break;
				}
			}
			stack[++top] = word[i];
		}
		else if (word[i] == '+' || word[i] == '-')
		{
			//자기 보다 우선순위가 높은애가 있는지 검사 
			while (top!=-1)
			{
				if (stack[top] == '/' || stack[top] == '*'|| stack[top] == '-'|| stack[top] == '+')
				{
					answer[cnt++] = stack[top--];
				}
				else
				{
					break;
				}
			}		
			stack[++top] = word[i];
		}
		
	}
	if (top != -1)
	{
		while (top != -1)
		{
			answer[cnt++] = stack[top--];
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%c", answer[i]);
	}
	return 0;
}