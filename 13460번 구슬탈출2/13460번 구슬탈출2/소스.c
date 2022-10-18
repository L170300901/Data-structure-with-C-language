#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
char map[15][15];
int map2[15][15];
int visit[15][15];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//�����¿� �̵� 
int qR[10000001];//y��ǥ
int q2R[10000001];//x��ǥ
int qB[10000001];//y��ǥ
int q2B[10000001];//x��ǥ
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
					if (map2[yyR][xxR] == 1)//���尡 ���� ������ 
					{
						qR[rearR++] = yyR;
						q2R[rear2R++] = xxR;
						visit[yyR][xxR] = visit[ypR][xpR] + 1;
						visit[ypR][xpR] = 0;
						cnt++;
					}
					if (map2[yyB][xxB] == 1)//�ҷ簡 ���� ������ 
					{
						qB[rearB++] = yyB;
						q2B[rear2B++] = xxB;
						visit[yyB][xxB] = visit[ypB][xpB] + 1;
						visit[ypR][xpR] = 0;
						cnt++;
					}
					if (map2[yyR][xxR] == 2)//���尡 ������ ������ 
					{
						qR[rearR++] = yyR;
						q2R[rear2R++] = xxR;
						visit[yyR][xxR] = visit[ypR][xpR] + 1;
						printf("%d", visit[yyR][xxR] - 1);
						return;
					}
					if (map2[yyB][xxB] == 2)//blue�� ������ ������ 
					{
						continue;

					}
					if (cnt == 2)//���� �Ķ� �Ѵ� ���� ������ 
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
			//���ڸ� �� ���ڷ� �ٲܲ��� 
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
				qR[rearR++] = i;//y��ǥ ������ 
				q2R[rear2R++] = j;//x��ǥ �ֱ� 
				visit[i][j] = 1;
			}
			if (map[i][j] == 'B')
			{
				map2[i][j] = 4;
				qB[rearB++] = i;//y��ǥ ������ 
				q2B[rear2B++] = j;//x��ǥ �ֱ� 
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