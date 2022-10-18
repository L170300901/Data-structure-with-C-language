#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int n, m, i, j, x, y, k, l, a, b;
	int s[305][305];
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	scanf("%d", &k);
	for (l = 1; l <= k; l++)
	{
		int sum = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for (a = i; a <= x; a++)
		{
			for (b = j; b <= y; b++)
			{
				sum += s[a][b];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}



