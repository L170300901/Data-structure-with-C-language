#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[505];
int main()
{
	while (1)
	{
		gets(word);
		if (strcmp(word, "END") == 0)
		{
			break;
		}
		int len;
		len = strlen(word);
		for (int i=len-1;i>=0;i-- )
		{
			printf("%c", word[i]);
		}
		printf("\n");
	}

	return 0;
}