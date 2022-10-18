#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int map[9][9];
int tmap[9][9];
int visit[9][9];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//»óÇÏÁÂ¿ì ÀÌµ¿  
int N, M;
int cnt,ans;
int result = 0;
typedef struct _q
{
	int x;  //xÁÂÇ¥ 
	int y;  //ÁÂÇ¥ 
}queue;
queue q[10000001];
int rear = 0, front = 0;
void initVisit() 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < virus.size(); i++)
	{
		visit[virus[i].first][virus[i].second] = 1;

	}
}

int bfs()
{
	initVisit();
	while (front < rear)
	{
		int yp = q[front].y;
		int xp = q[front].x;
		front++;

		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < M && 0 <= yy && yy < N)
			{
				if (tmap[yy][xx] <= 0 && visit[yy][xx] == 0)
				{
					q[rear].y = yy;
					q[rear].x = xx;
					rear++;
					visit[yy][xx] = 1;
					tmap[yy][xx] = 2;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			if (tmap[i][j] <= 0)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
void dfs(int depth, int r, int c) 
{
	if (depth == 3) 
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				tmap[i][j] = map[i][j];
			}
		}
		int result = bfs();
		if (result > ans)
		{
			ans = result;
		}
		return;
	}
	for (int j = c; j < M; j++) 
	{
		if (map[r][j] == 0) 
		{
			map[r][j] = 3;
			dfs(depth + 1, r, j);
			map[r][j] = 0;
		}
	}
	for (int i = r + 1; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			if (map[i][j] == 0) 
			{
				map[i][j] = 3;
				dfs(depth + 1, i, j);
				map[i][j] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
			{
				q[rear].y = i;
				q[rear].x = j;
				rear++;
			}
		}
	}
	dfs(0,0,0);
	printf("%d", ans);
	return 0;
}