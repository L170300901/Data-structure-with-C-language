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
int arrA[105];
int arrB[105];
int arrB2[105];
int temp;
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arrA[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arrB[i]);
	}
	QuickSort(arrA, 0, N - 1);//정렬 
	//출력까지 댐 정령 끝 
	QuickSort(arrB, 0, N-1);
	for (int i = N-1; i >=0; i--)
	{
			
		arrB2[N-i-1] = arrB[i];
		
	}
	for (int i = 0; i < N; i++)
	{
		temp += arrA[i] * arrB2[i];
	}
	printf("%d", temp);
	return 0;

}