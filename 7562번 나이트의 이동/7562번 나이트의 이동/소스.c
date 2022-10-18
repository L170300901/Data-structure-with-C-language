#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int map[305][305];
int visit[305][305];
int dx[8] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1};//나이트 이동 
int q[1000001];
int q2[1000001];
int startx, starty, endx, endy;
int T,N;
void bfs(int b,int a)
{
	int rear = 0, front = 0, rear2 = 0, front2 = 0;
	visit[b][a] = 1;
	q[rear++] = b;//큐에 시작점 대입 y 좌표  
	q2[rear2++] = a;//x좌표
	int cnt = 1;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 8; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (visit[yy][xx] == 0)
				{
					visit[yy][xx] = visit[yp][xp] + 1;
					if (xx == endx && yy == endy)
					{
						return;
					}
					q[rear++] = yy;
					q2[rear2++] = xx;
				}
			}
		}
		/*printf("visit##\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}*/
	}


}
int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
			{
				visit[a][b] = 0;
				map[a][b] = 0;
			}
		}
		scanf("%d %d", &startx, &starty);
		scanf("%d %d", &endx, &endy);
		bfs(starty, startx);
		printf("%d\n", visit[endy][endx]-1);
	}
}