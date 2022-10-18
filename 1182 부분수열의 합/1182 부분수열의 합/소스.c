#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int arr[25];
int N, S;
int cnt;
void dfs(int a, int b) 
{
	printf("a==%d, b==%d\n", a, b);
	if (a == b)
	{
		return;
	}
	int sum = 0;
	for (int i = a; i < b; i++) 
	{
		sum = sum+ arr[i];
	}
	if (sum == S)
	{
		printf("####################\n");
		printf("####a==%d, b==%d\n", a, b);
		cnt++;
	}
	dfs(a, b - 1);

}
int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		dfs(i, N);

	}
	printf("%d", cnt);

}