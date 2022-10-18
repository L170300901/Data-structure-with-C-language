#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
int main()
{
	scanf(" %s", word);
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] != word[strlen(word) - i - 1])
		{
			printf("0");
			return 0;
		}

	}
	printf("1");
	return 0;
}