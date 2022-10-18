#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int map[1005][1005];
int visit[1005][1005];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//상하좌우 이동 
int q[10000001];//y좌표
int q2[10000001];//x좌표
int rear = 0, front = 0, rear2 = 0, front2 = 0;
int cnt;
void()//소수 판단 
{

}
void bfs(int x, int y)
{
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			//printf("xx=%d yy=%d\n", xx, yy);
			if (0 <= xx && xx < M && 0 <= yy && yy < N)
			{
				if (map[yy][xx] == 0 && visit[yy][xx] == 0)
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
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		bfs(a, b);
	}
	return 0;
}