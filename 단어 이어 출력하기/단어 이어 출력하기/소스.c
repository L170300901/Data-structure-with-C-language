#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[100];
char sen[100];
int main()
{
	while (1)
	{
		gets(word);
		if (strcmp(word,"end")==0)
		{
			break;
		}
		strcat(sen, word);
		strcat(sen, " ");
		printf("%s\n", sen);
	}
	return 0;
}