#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int num[10];
int main()
{
	int max = 0, N = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
		if (max < num[i])
		{
			max = num[i];
			N = i;
		}
	}
	printf("%d\n", max);
	printf("%d", N+1);
	return 0;
	

}