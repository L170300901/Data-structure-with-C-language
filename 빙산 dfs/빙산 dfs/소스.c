#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int graph[305][305];
int new[305][305];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//상하좌우 이동 
int cnt, ans;

//큐생성 
void dfs(int y, int x)
{
	int water = 0;
	if (graph[y][x] <= 0 || x < 0 || y < 0 || x >= M || y >= N)
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (graph[y + dy[i]][x + dx[i]] == 0)
		{
			water++;
		}
	}
	new[y][x] -= water;
	if (new[y][x] < 0)
	{
		new[y][x] = 0;
	}
	graph[y][x] = -1;
	for (int i = 0; i < 4; i++)
	{
		dfs(y + dy[i], x + dx[i]);
	}
		
	

}
void init()
{
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = new[i][j];
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &graph[i][j]);
			new[i][j] = graph[i][j];//뉴에 그래프 복사 
		}
	}
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (graph[i][j] > 0)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt >= 2)
		{
			printf("%d\n", ans);
			break;
		}
		else if (cnt == 0)
		{
			printf("0\n");
			break;
		}
		ans++;
		init();
	}
	return 0;
}