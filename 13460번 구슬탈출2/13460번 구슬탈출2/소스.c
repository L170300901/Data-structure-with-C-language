#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
char map[15][15];
int map2[15][15];
int visit[15][15];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//상하좌우 이동 
int qR[10000001];//y좌표
int q2R[10000001];//x좌표
int qB[10000001];//y좌표
int q2B[10000001];//x좌표
int rearR = 0, frontR = 0, rear2R = 0, front2R = 0;
int rearB = 0, frontB = 0, rear2B = 0, front2B = 0;
void bfs()
{
	while (frontR < rearR)
	{
			int ypR = qR[frontR++];
			int xpR = q2R[front2R++];
			int ypB = qB[frontB++];
			int xpB = q2B[front2B++];
			for (int i = 0; i < 4; i++)
			{
				int cnt = 0;
				int xxR = xpR + dx[i];
				int yyR = ypR + dy[i];
				int xxB = xpB + dx[i];
				int yyB = ypB + dy[i];
				while(1)
				{
					if (map2[yyR][xxR] == 1)//레드가 벽을 만나면 
					{
						qR[rearR++] = yyR;
						q2R[rear2R++] = xxR;
						visit[yyR][xxR] = visit[ypR][xpR] + 1;
						visit[ypR][xpR] = 0;
						cnt++;
					}
					if (map2[yyB][xxB] == 1)//불루가 벽을 만나면 
					{
						qB[rearB++] = yyB;
						q2B[rear2B++] = xxB;
						visit[yyB][xxB] = visit[ypB][xpB] + 1;
						visit[ypR][xpR] = 0;
						cnt++;
					}
					if (map2[yyR][xxR] == 2)//레드가 구멍을 만나면 
					{
						qR[rearR++] = yyR;
						q2R[rear2R++] = xxR;
						visit[yyR][xxR] = visit[ypR][xpR] + 1;
						printf("%d", visit[yyR][xxR] - 1);
						return;
					}
					if (map2[yyB][xxB] == 2)//blue가 구멍을 만나면 
					{
						continue;

					}
					if (cnt == 2)//빨간 파랑 둘다 벽을 만나면 
					{
						break;
					}
					xxR = xxR + dx[i];
					yyR = yyR + dy[i];
					xxB = xxB + dx[i];
					yyB = yyB + dy[i];
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
			//문자를 다 숫자로 바꿀꺼임 
			if (map[i][j] == '#')
			{
				map2[i][j] = 0;
				visit[i][j] = 1;
			}
			if (map[i][j] == '.')
			{
				map2[i][j] = 1;
			}
			if (map[i][j] == 'O')
			{
				map2[i][j] = 2;
			}
			if (map[i][j] == 'R')
			{
				map2[i][j] = 3;
				qR[rearR++] = i;//y좌표 넣을거 
				q2R[rear2R++] = j;//x좌표 넣기 
				visit[i][j] = 1;
			}
			if (map[i][j] == 'B')
			{
				map2[i][j] = 4;
				qB[rearB++] = i;//y좌표 넣을거 
				q2B[rear2B++] = j;//x좌표 넣기 
				visit[i][j] = 1;
			}
		}
	}

	printf("map2##\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", map2[i][j]);
		}
		printf("\n");
	}
	printf("visit##\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	bfs();
	
}