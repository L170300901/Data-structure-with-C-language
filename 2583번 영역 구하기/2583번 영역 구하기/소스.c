#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int M,N,K;
int graph[105][105];
int visit[105][105];
int cnt, cntt;//단지수 , 아파트수
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };//상하좌우 이동 
int q[100001];
int q2[100001];
int answer[500];
int a, b, c, d;
int m;

void bfs(int y, int x)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	cntt = 0;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		cntt++;
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <=xx && xx <M && 0 <=yy && yy < N )
			{
				if (visit[yy][xx] == 0 && graph[yy][xx] == 0)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					visit[yy][xx] = 1;
				}
				
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int j = b; j < d; j++)
		{
			for (int k = a; k < c; k++)
			{
				graph[k][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0 && graph[i][j] == 0)
			{
				cnt++;
				bfs(i, j);
				answer[m] = cntt;
				m++;
			}
		}
	}
	qsort(answer, m, sizeof(int), cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < m; i++)
	{
		printf("%d ", answer[i]);
	}
}