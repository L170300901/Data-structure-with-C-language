#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int num[100005];
int num2;
int cmp(const void* a, const void* b)
{
	if (*(int*)a > * (int*)b)
		return 1;
	else if(*(int*)a < * (int*)b)
		return -1;
	else
		return 0;
}
void Bsearch(int arr[],int len,int target)
{
	int first=0;
	int last = len - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (arr[mid] == target)
		{
			printf("1\n");
			return;
		}
		else
		{
			if (arr[mid] > target)
			{
				last = mid - 1;

			}
			else
			{
				first = mid + 1;
			}
		}
	}
	printf("0\n");
	return;
}
int main()
{
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d ", &num[i]);
	}
	qsort(num, N, sizeof(int), cmp);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num2);
		Bsearch(num, N, num2);
	}
	return 0;
}