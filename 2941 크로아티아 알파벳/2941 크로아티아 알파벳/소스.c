#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
int main()
{
	int cnt = 0;
	scanf("%s", word);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		if ((word[i] == 'c' && word[i + 1] == '=') ||
			(word[i] == 'c' && word[i + 1] == '-'))
		{
			cnt++;
			i++;
		}
		else if (word[i] == 'd' && word[i + 1] == '-')
		{
			cnt++;
			i++;
		}
		else if (word[i] == 'd' && word[i + 1] == 'z')
		{
			if (word[i + 2] == '=')
			{
				cnt++;
				i++;
				i++;
			}
			else
			{
				cnt++;
			}
		}
		else if (word[i] == 'l' && word[i + 1] == 'j')
		{
			cnt++;
			i++;
		}
		else if (word[i] == 'n' && word[i + 1] == 'j')
		{
			cnt++;
			i++;
		}
		else if (word[i] == 's' && word[i + 1] == '=')
		{
			cnt++;
			i++;
		}
		else if (word[i] == 'z' && word[i + 1] == '=')
		{
			cnt++;
			i++;
		}
		else
		{
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}