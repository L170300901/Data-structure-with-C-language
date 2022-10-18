#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main() 
{
	int arr[100005];
	int N;
	int cnt=1;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int stack[100005];
	int top = -1;
	stack[++top] = arr[N];
	for (int j = N - 1; j > 0; j--)
	{
		if (stack[top] < arr[j])
		{
			stack[++top] = arr[j];
			cnt++;
		}
	}
	printf("%d", cnt);
}
	
