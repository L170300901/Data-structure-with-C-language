#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[15];
int main()
{
	for (int i = 1;; i++)
	{
		scanf("%s", word);
		int len;
		len = strlen(word);
		if (len > 5)
		{
			for (int j = 5; j < len; j++)
			{
				word[j] = '*';
			}
		}
		printf("%s\n", word);
	}
	return 0;
	

}