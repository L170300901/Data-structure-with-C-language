#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int temp;
	int arr[6];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	//오른차순 정리 끝;
	for (int i = 1; i <= 3; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	float avr;
	avr =(float) (arr[1] + arr[2] + arr[3]) / 3;
	printf("평큐= %.1lf\n", avr);
	return 0;
}