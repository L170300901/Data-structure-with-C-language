#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int num;
	int num2 = 0;
	scanf("%d", &num);
	int cnt = 0;
	int i, j;
	for (i =2; i <= 500000; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				cnt++;
			}
			if (cnt > 2)
			{
				break;
			}			
		}
		if (cnt == 2)
		{
			num2++;
		}	
		cnt = 0;
		if (num == num2)
		{
			printf("%d", i);
			break;
		}
	}
}