#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int visit[100005];
int n, k;
int cnt;
int q[100001];
void bfs(int x)
{
	int rear = 0, front = 0;
	q[rear++] = x;
	visit[x] = 1;
	while (front < rear)
	{
		int xp = q[front++];
		int dx[3] = {xp+1,xp-1,xp*2};
		for (int i = 0; i < 3; i++)
		{
			int xx = dx[i];
			if (0<=xx && xx <= 100000)
			{
				if (visit[xx] == 0) 
				{
					visit[xx] = visit[xp] + 1;
					if (xx == k)
					{
						return;
					}
					q[rear++] = xx;
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &k);
	bfs(n);
	printf("%d", visit[k]-1);
}
