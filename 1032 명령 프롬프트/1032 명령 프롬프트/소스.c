#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[55];
char word2[55];
int main()
{
	int n;
	scanf("%d", &n);
	scanf(" %s", word);
	for (int j = 1; j < n; j++)
	{	
		scanf(" %s", word2);
		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] != word2[i])
			{
				word[i] = '?';
			}
		}
	}
	
	
	printf("%s", word);

	
}