#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int arr[20005];
int N;
char word[20005][55];
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;

	char temp2[55];
	strcpy(temp2, word[idx1]);
	strcpy(word[idx1], word[idx2]);
	strcpy(word[idx2], temp2);

}
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= high)
			low++;

		while (pivot <= arr[high] && low <= high)
			high--;

		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}
	Swap(arr, left, high);
	return high;
}
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}
int len,cnt;
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %s", word[i]);
		len = strlen(word[i]);
		arr[i] = len;
		len = 0;
	}
	QuickSort(arr, 0, N - 1);//정렬 끝 but 사전순 배열 필요
	cnt = N;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (strlen(word[i]) == strlen(word[j]))
			{
				if (strcmp(word[i], word[j]) > 0)
				{
					char temp[55];
					strcpy(temp, word[i]);
					strcpy(word[i], word[j]);
					strcpy(word[j], temp);
				
				}
				else if (strcmp(word[i], word[j]) == 0)
				{
					for (int k = j; k < N-1; k++)
					{
						strcpy(word[k], word[k + 1]);
					}
					cnt--;
					
				}

			}
		}
		

	}

	for (int i = 0; i < cnt; i++)
	{
		
		printf("%s\n", word[i]);
	}
	return 0;

}