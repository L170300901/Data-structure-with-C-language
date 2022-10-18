#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int n, m;
	int s, d, l, i;
	scanf("%d %d", &n, &m);
	int winrate[10005];
	
	for (i = 0; i < n; i++)
	{
		
		scanf("%d %d %d", &s, &d, &l);
		winrate[i] = 3 * s + 1 * d;
	}
	
	int temp = 0;
	temp = winrate[m - 1];
	int cnt = 0;
	for (i = 0; i < n; i++)
	{
		if (winrate[i] > temp)
			cnt++;
	}
	printf("%d", cnt + 1);
	return 0;
}