#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
char graph[255][255];
int visit[255][255];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//상하좌우 이동 하 우 상 좌
int q[1000001];//y좌표
int q2[1000001];//x좌표
int rear = 0, front = 0, rear2 = 0, front2 = 0;
int cntW;
int cntS;
int cnttW, cnttS;
void bfs(int y,int x)
{

	cntW = 0;
	cntS = 0;
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	if (graph[y][x] == 'v')
	{
		cntW++;

	}
	if (graph[y][x] == 'o')
	{
		cntS++;

	}
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];

		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];

			//printf("@@%d %d\n", yy, xx);
			if (0 <= xx && xx < M && 0 <= yy && yy < N)
			{
				if (visit[yy][xx] == 0 && graph[yy][xx]!='#')				
				{
					if (graph[yy][xx] == 'o')
					{
						cntS++;
						q[rear++] = yy;
						q2[rear2++] = xx;
						visit[yy][xx] = 1;
		
					}
					if (graph[yy][xx] == 'v')
					{
						cntW++;
						q[rear++] = yy;
						q2[rear2++] = xx;
						visit[yy][xx] = 1;
					}
					if (graph[yy][xx] == '.')
					{
						q[rear++] = yy;
						q2[rear2++] = xx;
						visit[yy][xx] = 1;
					}

				}
			}
		}
	}
	/*printf("###visit -----\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	*/
	//printf("cnt== %d %d\n", cntS, cntW);
	if (cntS > cntW)//양의 개수가 더 많으면 
	{
		cnttS = cntS+cnttS;
	}
	else//늑대의 개수가 더 많으면 
	{
		cnttW = cntW + cnttW;
	}
	
}

int main()
{
	scanf("%d %d", &N, &M);//세로, 가로 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &graph[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((graph[i][j] == 'v'|| graph[i][j] == 'o'|| graph[i][j] == '.')&&visit[i][j]==0)
			{
				//printf("###\n");
				bfs(i, j);
			}
		}
	}
	printf("%d %d", cnttS, cnttW);
	return 0;
}