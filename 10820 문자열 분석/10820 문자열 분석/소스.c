#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
int main()
{
	while (fgets(word,102,stdin))
	{
		if (feof(stdin))
		{
			break;
		}
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 0; i < strlen(word); i++)
		{
			if ('a' <= word[i] && word[i] <= 'z')
			{
				a++;

			}
			else if ('A' <= word[i] && word[i] <= 'Z')
			{
				b++;

			}
			else if ('0' <= word[i] && word[i] <= '9')
			{
				c++;

			}
			else if(word[i]==' ')
			{
				d++;
			}
		}
		printf("%d %d %d %d\n", a, b, c, d);
	}
	return 0;
}