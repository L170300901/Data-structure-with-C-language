#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
int len;
int main()
{
	gets(word);
	len = strlen(word);
	printf("%d", len);
	return 0;
}
