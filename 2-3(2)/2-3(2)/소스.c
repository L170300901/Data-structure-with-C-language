#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int arr[7500000];

int main()
{
	int num; 
	scanf("%d", &num);
	int i,j;
	for (i = 2; i < 7500000; i++)
	{
		if (arr[i] == 0) {
			for (j = i*2; j < 7500000; j=j+i)
			{
				arr[j] = 1;
			}
		}
	}
	int cnt = 0;
	for (i = 2; i < 7500000; i++)
	{
		if (arr[i] == 0) {
			cnt++;
			if (cnt == num) {
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}	