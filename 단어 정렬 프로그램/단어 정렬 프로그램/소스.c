#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word1[100], word2[100], word3[100];
int main()
 {
	scanf("%s %s %s", word1, word2, word3);
	if (strcmp(word1, word2) ==1)
	{
		char temp[100];
		strcpy(temp, word1);
		strcpy(word1, word2);
		strcpy(word2, temp);

	}
	if (strcmp(word1, word3) == 1)
	{
		char temp[100];
		strcpy(temp, word1);
		strcpy(word1, word3);
		strcpy(word3, temp);

	}
	if (strcmp(word2, word3) ==1)
	{
		char temp[100];
		strcpy(temp, word2);
		strcpy(word2, word3);
		strcpy(word3, temp);

	}
	
	printf("%s, %s, %s\n", word1, word2, word3);

}