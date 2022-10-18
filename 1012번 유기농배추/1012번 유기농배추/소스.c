#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int T, M, N, K;
int map[55][55];
int visit[55][55];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };//상하좌우 이동 
int q[100001];
int q2[100001];
void bfs(int x, int y)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = x;//x좌표 넣을거 
	q2[rear2++] = y;
	visit[x][y] = 1;
	while (front < rear)
	{
		int xp = q[front++];
		int yp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0<= xx && xx < M && 0 <= yy && yy <N && visit[xx][yy] == 0 && map[xx][yy] == 1)
			{
				q[rear++] = xx;
				q2[rear2++] = yy;
				visit[xx][yy] = 1;
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	for (int a = 0; a < T; a++)
	{
		int cnt = 0;
		scanf("%d %d %d", &M, &N, &K);
		for (int j = 0; j < K; j++)
		{
			int m, n;
			scanf("%d %d", &m, &n);
			map[m][n] = 1;
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 0 && map[i][j] == 1)
				{
					cnt++;
					bfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
		for (int i = 0; i < 55; i++)
		{
			for (int j = 0; j < 55; j++)
			{
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
	
	}
	return 0;
}