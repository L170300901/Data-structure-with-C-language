#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char word[105];
char ans[105];
char stack[105];
int main()
{
	int idx = 0, top = -1;
	scanf(" %s", word);
	for (int i = 0; i < strlen(word); i++)
	{
		if ('A' <= word[i] && word[i] <= 'Z')
		{
			ans[idx++] = word[i];
		}
		else
		{
			switch (word[i])
			{
			case '(':
				stack[++top] = word[i];
				break;
			case '*':
			case'/':
				while (top != -1 && (stack[top] == '*' || stack[top] == '/'))
				{
					ans[idx++] = stack[top--];

				}
				stack[++top] = word[i];
				break;
			case'+':
			case'-':
				while (top != -1 && stack[top] != '(')
				{
					ans[idx++] = stack[top--];
				}
				stack[++top] = word[i];
				break;
			case')':
				while (top != -1 && stack[top] != '(')
				{
					ans[idx++] = stack[top--];
				}
				stack[top--];
				break;

			}
		}
	}
	while (top >= 0)
	{
		ans[idx++] = stack[top--];
	}
	printf("%s", ans);
	return 0;
}