#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
int main()
{
	gets(word);
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] >= 'a' && word[i] <= 'm')
		{
			word[i] = word[i] + 13;
		}
		else if (word[i] >= 'n' && word[i] <= 'z')
		{
			word[i] = word[i] - 13;
		}
		else if (word[i] >= 'A' && word[i] <= 'M')
		{
			word[i] = word[i] + 13;
		}
		else if (word[i] >= 'N' && word[i] <= 'Z')
		{
			word[i] = word[i] - 13;
		}
	}
	for (int i=0;i<strlen(word);i++)
	{
		printf("%c", word[i]);
	}
	return 0;
}