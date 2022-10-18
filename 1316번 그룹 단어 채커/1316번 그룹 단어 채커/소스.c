#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int n;
	char word[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", word);
		for (int j = 0; j < strlen(word); j++)
		{
			if (word[i] == word[i - 1])
			{
				continue;
			}

		}
	}

}