#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
double stack[105];//피연산자 넣을거임
double temp;
int N[30];
int main()
{
	int top = -1, cnt = 0, num;
	scanf("%d", &num);
	scanf(" %s", word);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &N[i]);
	}
	for (int i = 0; i < strlen(word); i++)
	{
		
		if ('A' <= word[i] && word[i] <= 'Z')
		{
			
			top++;
			stack[top] = N[word[i]-'A'];
			
			
		}
		else if (word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == '/')
		{
			
			if (word[i] == '+')
			{
				temp = stack[top - 1] + stack[top];
				top = top - 2;
				top++;
				stack[top] = temp;

			}
			else if (word[i] == '-')
			{
				temp = stack[top - 1] - stack[top];
				top = top - 2;
				top++;
				stack[top] = temp;

			}
			else if (word[i] == '*')
			{
				temp = stack[top - 1] * stack[top];
				top = top - 2;
				top++;
				stack[top] = temp;

			}
			else if (word[i] == '/')
			{
				temp = stack[top - 1] / stack[top];
				top = top - 2;
				top++;
				stack[top] = temp;

			}
			
		}
	}
	printf("%.2lf", stack[top]);
	return 0;
}