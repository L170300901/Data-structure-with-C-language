#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int map[102][102];
int func(int a) {
	int cnt = 0;
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
		{
			if (map[i][j] == a)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	int N;
	int x, y, nx, ny;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d %d", &x, &y, &nx, &ny);
		for (int j = y; j < y + ny; j++)
		{
			for (int k = x; k < x + nx; k++)
			{
				map[j][k] = i;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		printf("%d\n", func(i));
	}
}