#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <algorithm>
#include <stdlib.h>
char word[1000005];
char answer[1000005];
int main()
{
	int N, M,cnt=0;
	scanf("%d %d", N, M);
	for (int i = 0; i < N+M; i++)
	{
		scanf(" %s", word[i]);
	}

	sort(word, word + N + M);
	for (int i = 1; i < N + M; i++)
	{
		if (word[i] == word[i-1])
		{
			answer[cnt++] = i;

		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf(" %s", answer[i]);
	}
}