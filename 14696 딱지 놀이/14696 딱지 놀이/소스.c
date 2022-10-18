#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int arrA[1005];
int arrB[1005];
int cnt;
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d", &a);
		for (int j = 0; j < a; j++)
		{
			int num;
			scanf("%d", &num);
			arrA[num]++;
		}
		scanf("%d", &b);
		for (int j = 0; j < b; j++)
		{
			int num;
			scanf("%d", &num);
			arrB[num]++;
		}
		for (int ii = 4; ii >= 1; ii--)
		{
			if (arrA[ii] > arrB[ii])
			{
				printf("A\n");
				break;
			}
			else if (arrA[ii] < arrB[ii])
			{
				printf("B\n");
				break;
			}
			else if (arrA[ii] == arrB[ii] && ii == 1)
			{
				printf("D\n");
				break;
			}
			else if (arrA[ii] == arrB[ii])
			{
				continue;

			}
		}
		for (int ii = 0; ii < 1005; ii++)
		{
			arrA[ii] = 0;
			arrB[ii] = 0;

		}
	}
	
}