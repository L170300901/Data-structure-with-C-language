#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
char stack[105];
char pop[105];
int main()
{
	int top = -1;
	int cnt = 0;
	gets(word);
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == ')') //´Ù •ûÀÚ 
		{
			while (top != -1)
			{
				pop[cnt] = stack[top];
				cnt++;
				top--;
				if (stack[top] == '(')
				{
					top--;
					break;
				}
			}
			//pop[cnt] = stack[top];
			//cnt++;
			//top--;
		}
		else if (word[i] == '+' || word[i] == '-')
		{
			while(top!=-1)//ÀÏ´Ü ´Ù »©°í ½×±â
			{
				if (stack[top] == '(')
				{
					break;
				}
				pop[cnt] = stack[top];
				cnt++;
				top--;
				
			}
			top++;
			stack[top] = word[i];
		}
		else if (word[i] == '*' || word[i] == '/')
		{
			while (top!=-1&&(stack[top] == '*' || stack[top] == '/'))
			{
				pop[cnt] = stack[top];
				cnt++;
				top--;
			}
			top++;
			stack[top] = word[i];
		}
		else if (word[i] == '(')
		{
			top++;
			stack[top] = word[i];
		}

		else
		{
			pop[cnt] = word[i];
			cnt++;
		}
	}
	if (top != -1)
	{
		while (top != -1)
		{
			pop[cnt] = stack[top];
			cnt++;
			top--;
		}
	}
	for (int i = 0; i < strlen(word); i++)
	{
		printf("%c", pop[i]);
	}
	return 0;
}