#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) //길이 비교 
{
	if (strlen(a) < strlen(b))
	{
		return -1;
	}
	else if (strlen(a) > strlen(b))
	{
		return 1;
	}
	else
	{
		return strcmp(a, b);
	}

}
char word[20000][52];
char sorted[52];//char sorted[20000][52];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", word[i]);
	}
	qsort(word, n, sizeof(char) * 52, cmp);
	printf("%s\n", word[0]);
	strcpy(sorted, word[0]);//strcpy(sorted[0],word[0]);
	for (int i = 1; i < n; i++)
	{
		if (strcmp(sorted, word[i]) == 0)//if(strcmp(sorted[i],word[i])==0)
			continue;
		printf("%s\n", word[i]);
		strcpy(sorted, word[i]);//strcpy(sorted[i],word[i]);
	}
}

