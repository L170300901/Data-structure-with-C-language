#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
char map[15][15];
int visitR[15][15];//·¹µå ºÒ·ç À§Ä¡ 
int visitB[15][15];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//»óÇÏÁÂ¿ì ÀÌµ¿ 
int qR[10000001];//yÁÂÇ¥
int q2R[10000001];//xÁÂÇ¥
int qB[10000001];//yÁÂÇ¥
int q2B[10000001];//xÁÂÇ¥
int rearR = 0, frontR = 0, rear2R = 0, front2R = 0;
int rearB = 0, frontB = 0, rear2B = 0, front2B = 0;
int cnt,ans;
void bfs()
{
	while (frontR < rearR)
	{
		int len = rearR - frontR;
		while (len--)
		{
			int ypR = qR[frontR++];
			int xpR = q2R[front2R++];
			int ypB = qB[frontB++];
			int xpB = q2B[front2B++];
			if (map[ypR][xpR] == 'O' && map[ypB][xpB] != 'O')
			{
				ans = cnt;
				return;
			}
			for (int i = 0; i < 4; i++)
			{
				int xR = xpR;
				int yR = ypR;
				int xB = xpB;
				int yB = ypB;
				int nry, nrx, nby, nbx;
				while (1)
				{
					nrx = xR + dx[i];
					nry = yR + dy[i];
					if (map[nry][nrx] == '#' || map[yR][xR] == 'O')
					{
						break;
					}
					yR = nry;
					xR = nrx;
				}
				while (1)
				{
					nbx = xB + dx[i];
					nby = yB + dy[i];
					if (map[nby][nbx] == '#' || map[yB][xB] == 'O')
					{
						break;
					}
					yB = nby;
					xB = nbx;
				}
				if (yR == yB && xR == xB)//µÑÀÌ °ãÃÆÀ» ¶§ 
				{
					if (map[yB][xB] == 'O')
					{
						continue;
					}
					if (abs(ypR - yR) + abs(xpR - xR) > abs(ypB - yB) + abs(xpR - xR)) 
					{
						xR = xR - dx[i];
						yR = yR - dy[i];
					}
					else
					{
						xB = xB - dx[i];
						yB = yB - dy[i];
					}
				}
				if (visitR[yR][xR] == 1 && visitB[yB][xB] == 1)
				{
					continue;
				}
				//printf("##\n");
				qR[rearR++] = yR;
				q2R[rear2R++] = xR;
				visitR[ypR][xpR] = 1;

				qB[rearB++] = yB;
				q2B[rear2B++] = xB;
				visitB[ypB][xpB] = 1;
			}
		}
		if (cnt == 10)
		{
			ans = -1;
			return;
		}
		cnt++;	
	}
	ans = -1;
	return;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R')
			{
				qR[rearR++] = i;//yÁÂÇ¥ ³ÖÀ»°Å 
				q2R[rear2R++] = j;//xÁÂÇ¥ ³Ö±â 
				visitR[i][j] = 1;
			}
			if (map[i][j] == 'B')
			{
				qB[rearB++] = i;//yÁÂÇ¥ ³ÖÀ»°Å 
				q2B[rear2B++] = j;//xÁÂÇ¥ ³Ö±â 
				visitB[i][j] = 1;
			}
		}
	}
	bfs();
	printf("%d\n", ans);
}