#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N,H;
int map[105][105][105];
int visit[105][105][105];
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };//»óÇÏÁÂ¿ì ÀÌµ¿ 
int dz[6] = { 0,0,0,0,1,-1 };
int q[1000001];//yÁÂÇ¥
int q2[1000001];//xÁÂÇ¥
int q3[10000001];//zÁÂÇ¥
int rear = 0, front = 0, rear2 = 0, front2 = 0;
int rear3 = 0,front3 = 0;
int cnt;
void bfs()
{
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		int zp = q3[front3++];
		for (int i = 0; i < 6; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			int zz = zp + dz[i];
			printf("xx=%d yy=%d\n", xx, yy);
			if (0 <= xx && xx < M && 0 <= yy && yy < N && 0 <= zz && zz < H)
			{
				if (map[yy][xx][zz] == 0 && visit[yy][xx][zz] == 0)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					q3[rear3++]=zz;
					visit[yy][xx][zz] = visit[yp][xp][zp] + 1;
				}
			}
		}
		for (int k = 0; k < H; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					printf("%d ", visit[i][j][k]);
				}
				printf("\n");
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &M, &N,&H);
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 1)
				{
					q[rear++] = i;//yÁÂÇ¥ ³ÖÀ»°Å 
					q2[rear2++] = j;//xÁÂÇ¥ ³Ö±â 
					q3[rear3++] = k;
					visit[i][j][k] = 1;
				}
				if (map[i][j][k] == -1)
				{
					cnt++;
				}
			}
		}
	}
	bfs();
	int cntt = 0;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visit[i][j][k] == 0)
				{
					cntt++;
				}
			}
		}
	}
	//printf("cnt=%d cntt=%d\n", cnt, cntt);
	if (cnt < cntt)
	{
		//printf("----------------\n");
		printf("-1");
		return 0;
	}
	int temp = 0;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (temp < visit[i][j][k])
				{
					temp = visit[i][j][k];
				}
			}
		}
	}
	printf("%d", temp - 1);
	return 0;
}