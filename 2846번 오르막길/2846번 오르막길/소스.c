#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int arr[1005];
int main()
{

	int n;
	int temp = 0;
	int first = 0;
	int mmax = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	first = arr[0];
	//
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] < arr[i + 1]) 
		{
			temp = arr[i + 1];
		}
		else 
		{
			if (mmax < temp - first) 
			{
				mmax = temp - first;

			}
			temp = 0;
			first = arr[i + 1];
		}
	}
	int result;
	if (mmax > temp)
	{
		result = mmax;
	}
	else
	{
		result = temp;
	}
	printf("%d", result);
}

