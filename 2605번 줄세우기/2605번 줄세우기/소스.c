#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int pick[105];
int answer[105];
int move[105];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &pick[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < pick[i]; j++)
		{
			move[j] = answer[i + j - pick[i]];
		}
		answer[i - pick[i]] = i + 1;
		for (int k = 0; k < pick[i]; k++)
		{
			answer[i + k - pick[i] + 1] = move[k];
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", answer[i]);
	}
	return 0;
}