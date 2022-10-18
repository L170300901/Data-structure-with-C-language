#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int N;
char graph[105][105];
int map1[105][105];//정상인 
int map2[105][105];//적록색약
int visit[105][105];
int visit[105][105];
int cnt,cntt;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };//상하좌우 이동 
int q[100001];
int q2[100001];
void bfs1(int y, int x)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (visit[yy][xx] == 0 && map1[yy][xx] == 1)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					visit[yy][xx] = 1;
				}

			}
		}
	}
}
void bfs2(int y, int x)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (visit[yy][xx] == 0 && map1[yy][xx] == 2)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					visit[yy][xx] = 1;
				}

			}
		}
	}
}
void bfs3(int y, int x)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (visit[yy][xx] == 0 && map1[yy][xx] == 3)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					visit[yy][xx] = 1;
				}

			}
		}
	}
}
void bfs11(int y, int x)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (visit[yy][xx] == 0 && map2[yy][xx] == 1)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					visit[yy][xx] = 1;
				}

			}
		}
	}
}
void bfs22(int y, int x)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (visit[yy][xx] == 0 && map2[yy][xx] == 2)
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
	scanf("%d", &N);
	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j <N; j++)
		{
			scanf(" %c", &graph[i][j]);
			if (graph[i][j] == 'B')
			{
				map1[i][j] = 1;
				map2[i][j] = 1;
			}
			if (graph[i][j] == 'R')
			{
				map1[i][j] = 2;
				map2[i][j] = 2;
			}
			if (graph[i][j] == 'G')
			{
				map1[i][j] = 3;
				map2[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0 && map1[i][j] == 1)
			{
				cnt++;
				bfs1(i, j);
			}
			if (visit[i][j] == 0 && map1[i][j] == 2)
			{
				cnt++;
				bfs2(i, j);
			}
			if (visit[i][j] == 0 && map1[i][j] == 3)
			{
				cnt++;
				bfs3(i, j);
			}
		}
	}
	//초기화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
		}
	}
	//비정상인
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0 && map2[i][j] == 1)
			{
				cntt++;
				bfs11(i, j);
			}
			if (visit[i][j] == 0 && map2[i][j] == 2)
			{
				cntt++;
				bfs22(i, j);
			}
		}
	}
	printf("%d %d", cnt,cntt);
}