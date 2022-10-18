#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int A, B, C,N;
	scanf("%d %d %d %d", &A, &B, &C, &N);
	int temp1 = 0, temp2 = 0,temp3=0;
	for (int i = 0; i <= N; i++) 
	{
		temp1 = A * i;
		for (int j = 0; j <= N; j++)
		{
			temp2 = B * j;
			for (int z = 0; z <= N; z++) 
			{
				temp3 = C * z;
				if (temp1 + temp2 + temp3 == N) 
				{
					printf("1\n");
					return 0;						
				}
			}			
		}
	}
	printf("0\n");
	return 0;
}