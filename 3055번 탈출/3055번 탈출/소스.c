#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int graph[55][55];
int visitW[55][55];
int visitA[55][55];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//상하좌우 이동 
int qW[1000001];//y좌표
int q2W[1000001];//x좌표
int qA[1000001];//y좌표
int q2A[1000001];//x좌표
int rearW = 0, frontW = 0, rear2W = 0, front2W = 0;
int rearA = 0, frontA = 0, rear2A= 0, front2A = 0;
int cnt;
int endX, endY;
void bfs()
{
	while (frontW < rearW)//water 먼저 움직일꺼임 
	{
		int ypW = qW[frontW++];
		int xpW = q2W[front2W++];
		for (int i = 0; i < 4; i++)
		{
			int xxW = xpW + dx[i];
			int yyW= ypW + dy[i];
			if (0 <= xxW && xxW < M && 0 <= yyW && yyW < N)//water 이동 
			{
				if (visitW[yyW][xxW] == 0) //물이 안가본곳  ㄱㄱ
				{
					if (graph[yyW][xxW] == '.' || graph[yyW][xxW] == 'S') 
					{
						qW[rearW++] = yyW;
						q2W[rear2W++] = xxW;
						visitW[yyW][xxW] = visitW[ypW][xpW] + 1;
					}
				}	
			}
		}
	}
	/*printf("visit water------------------\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", visitW[i][j]);
		}
		printf("\n");
	}
	*/

	while (frontA < rearA)//고슴도치 움직일꺼임 
	{
		int ypA = qA[frontA++];
		int xpA= q2A[front2A++];
		for (int i = 0; i < 4; i++)
		{
			int xxA = xpA + dx[i];
			int yyA = ypA + dy[i];
			if (0 <= xxA && xxA < M && 0 <= yyA && yyA < N)
			{
				if (visitA[yyA][xxA] == 0&& graph[yyA][xxA] == '.')
				{
					if (visitA[ypA][xpA] + 1 < visitW[yyA][xxA]|| visitW[yyA][xxA] == 0)//물이 없는 곳 이동  
					{
						qA[rearA++] = yyA;
						q2A[rear2A++] = xxA;
						visitA[yyA][xxA] = visitA[ypA][xpA] + 1;
					}
					
				}
				if (xxA == endX && yyA == endY)
				{
					visitA[yyA][xxA] = visitA[ypA][xpA] + 1;
					printf("%d\n", visitA[endY][endX] - 1);
					return;
				}
			}
		}
	}
	/*printf("visit A   \n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%3d", visitA[i][j]);
		}
		printf("\n");
	}
	*/
	if (visitA[endY][endX] == 0)//고슴 도치가 굴에 못가면 
	{
		printf("KAKTUS\n");
		return;
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
			if (graph[i][j] == '*')
			{
				qW[rearW++] = i;
				q2W[rear2W++] = j;
				visitW[i][j] = 1;
			}
			if (graph[i][j] == 'S')
			{
				qA[rearA++] = i;
				q2A[rear2A++] = j;
				visitA[i][j] = 1;
			}
			if (graph[i][j] == 'D')//끝나는 지점 
			{
				endY = i;
				endX = j;
				
			}
		}
	}
	bfs();
	return 0;
}