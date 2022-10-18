#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[100005];
int cnt;
int main()
{
	
	gets(word);
	int len;
	len = strlen(word);
	for (int i = 0;i<len;i++)
	{

		if (word[i] == ' ')
		{
			printf("%c", word[i]);
		}
		else if (word[i] == '<')
		{
			printf("%c", word[i]);
			i++;
			while (word[i] != '>')
			{
				printf("%c", word[i]);
				i++;
			}
			printf("%c", word[i]);
		}
		else
		{
			cnt = i;
			while (word[cnt] != ' ')
			{
				if (cnt == len)
				{
					break;
				}
				if (word[cnt] == '<')
				{
					break;
				}
				cnt++;
			}
			for (int j = cnt-1; j >= i; j--)
			{
				printf("%c", word[j]);
			}
			i = cnt-1;
		}
		
	}

	return 0;
}