#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct _queue
{
	int Rx;
	int Ry;
	int Bx;
	int By;
	int cnt;
}queue;
queue q[100001];
int rear, front;
int N, M;
char map[15][15];
int visit[15][15][15][15];
int end_x, end_y;
int s_rx, s_ry, s_bx, s_by;
int ans=-1;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int nbx, nby;
int nrx, nry;
void bfs()
{
	while (front < rear)
	{
		int ypR = q[front].Ry;
		int xpR = q[front].Rx;
		int ypB = q[front].By;
		int xpB = q[front].Bx;
		int cntt = q[front].cnt;
		front++;
		if (cntt>10)
		{
			break;
		}
		if (map[ypR][xpR] == 'O')
		{
			ans = cntt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int rx = xpR;
			int ry = ypR;
			int bx = xpB;
			int by = ypB;
			while (1)
			{
				rx = rx + dx[i];
				ry = ry + dy[i];
				if (map[ry][rx] == '#')
				{
					rx = rx - dx[i];
					ry = ry - dy[i];
					break;
				}
				else if (map[ry][rx] == 'O')
				{
					break;
				}

			}
			while (1)
			{
				bx = bx + dx[i];
				by = by + dy[i];
				if (map[by][bx] == '#')
				{
					bx = bx - dx[i];
					by = by - dy[i];
					break;
				}
				else if (map[by][bx] == 'O')
				{
					break;
				}
			}
			if (by == end_y && bx == end_x)
			{
				continue;
			}
			if (bx == rx && by == ry) //°ãÃÆÀ»¶§ 
			{
				if (i == 0)
				{
					ypR < ypB ? ry-- : by--;
				}
				if (i == 1)
				{
					xpR < xpB ? rx-- : bx--;
					
				}
				if (i == 2)
				{
					ypR < ypB ? by++ : ry++;
	
				}
				if (i == 3)
				{
					xpR < xpB ? bx++ : rx++;
					
				}
			}
			if (visit[ry][rx][by][bx] == 0)
			{
				q[rear].Ry = ry;
				q[rear].Rx = rx;
				q[rear].By = by;
				q[rear].Bx = bx;
				q[rear].cnt = cntt+1;
				rear++;
			
				visit[ry][rx][by][bx]=1;
			}

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
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '0')
			{
				end_y = i;
				end_x = j;
			}
			if (map[i][j] == 'R')
			{
				s_ry = i;
				s_rx = j;
			}
			if (map[i][j] == 'B')
			{
				s_by = i;
				s_bx = j;
			}
		}
	}
	q[rear].Ry = s_ry;
	q[rear].Rx = s_rx;
	q[rear].By = s_by;
	q[rear].Bx = s_bx;
	rear++;
	visit[s_ry][s_rx][s_by][s_bx]=1;
	bfs();
	printf("%d\n", ans);
}