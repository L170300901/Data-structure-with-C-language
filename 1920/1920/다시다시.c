#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot > arr[low])
			low++;

		while (pivot < arr[high])
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
int N, M,num;
int arr[100005];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	QuickSort(arr, 0,N-1);//Á¤·Ä ³¡
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d",&num);
		BSearch(arr, N, num);
	}
	return 0;	
}