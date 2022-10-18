#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int x, y, p, q, x2, y2, p2, q2;
int main()
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d %d %d %d %d", &x, &y, &p, &q, &x2, &y2, &p2, &q2);
		if (p < x2 || p2 < x || q < y2 || q2 < y)
		{
			printf("d\n");
			continue;
		}
		else
		{
			if (q == y2)
			{
				if (p == x2 || x == p2)
				{
					printf("c\n");
					continue;
				}
				else
				{
					printf("b\n");
					continue;
				}
			}
			if (p == x2)
			{
				if (q == y2 || q2 == y)
				{
					printf("c\n");
					continue;
				}
				else
				{
					printf("b\n");
					continue;
				}
			}
			if (y == q2)
			{
				if (q == x2 || p2 == x)
				{
					printf("c\n");
					continue;
				}
				else
				{
					printf("b\n");
					continue;
				}
			}
			if (x == p2)
			{
				if (y == q2 || y2 == q)
				{
					printf("c\n");
					continue;
				}
				else
				{
					printf("b\n");
					continue;
				}
			}
		}
		printf("a\n");
	}
}