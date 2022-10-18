#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int num[10];
int num2[10];
int main()
{
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (num[i] >= num[j])
			{
				int temp;
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}

		}

	}
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{	
		if (num[i] % 2 == 1)
		{
			sum = sum + num[i];
		}		
	}
	if (sum == 0)
	{
		printf("-1");
		return 0;
	}
	else
	{
		printf("%d\n", sum);
	}
	
	for (int i = 0; i < 7; i++)
	{
		if (num[i] % 2 == 1)
		{
			printf("%d", num[i]);
			return 0;
		}
	}
}