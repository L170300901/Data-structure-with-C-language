#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int map[1005][1005];
int visit[1005][1005];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//»óÇÏÁÂ¿ì ÀÌµ¿ 
int q[10000001];//yÁÂÇ¥
int q2[10000001];//xÁÂÇ¥
int rear = 0, front = 0, rear2 = 0, front2 = 0;
int cnt;
void bfs()
{
	while (front < rear)
	{
		//printf("###");
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			//printf("xx=%d yy=%d\n", xx, yy);
			if (0 <= xx && xx < M && 0 <= yy && yy < N)
			{
				if (map[yy][xx] == 0&&visit[yy][xx]==0)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					visit[yy][xx] = visit[yp][xp] + 1;
				}
			}
		}
		/*printf("visit##\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}*/
	}
}
int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				q[rear++] = i;//yÁÂÇ¥ ³ÖÀ»°Å 
				q2[rear2++] = j;//xÁÂÇ¥ ³Ö±â 
				visit[i][j] = 1;
			}
			if (map[i][j] == -1)
			{
				cnt++;
			}
		}
	}
	bfs();
	int cntt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0)
			{
				cntt++;
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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp<visit[i][j])
			{
				temp = visit[i][j];
			}
		}
	}
	printf("%d", temp - 1);
	return 0;
}