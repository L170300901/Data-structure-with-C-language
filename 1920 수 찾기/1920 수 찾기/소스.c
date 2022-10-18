#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == ar[mid])
		{
			printf("1\n");
			return 0;

		}
		else
		{
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	printf("0\n");
	return 0;
}
int arr[100005];
int main()
{
	int N,M,num;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	//크기 순으로 정령 해야댐
	for (int i =0; i <N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			if (arr[j] > arr[j+ 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}

		}	
	}
	/*for (int i = 0; i < N; i++)
	{
		printf("%d", arr[i]);
	}
	*/
	//printf("\n");
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num);
		BSearch(arr, N, num);
	}

	return 0;

}