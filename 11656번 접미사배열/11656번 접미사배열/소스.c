#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[1005];
char newword[1005][1005];
int compare(const void* a, const void* b) {
	return(strcmp((char*)a, (char*)b));
}
int main()
{
	scanf("%s", word);
	int len= strlen(word); 
	for (int j = 0; j < len; j++)
	{
		for (int i = 0; i < len - j; i++)
		{
			newword[j][i] = word[i + j];
		}
	}
	//사전순서에 관계없이 잘라서 정리함
	char temp[1001];
	/*for (int i = 0; i < len; i++)
	{
		printf("##%s\n", newword[i]);
	}*/
	qsort(newword, len, sizeof(newword[0]), compare);
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", newword[i]);
	}
}