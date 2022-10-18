#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int graph[1005][1005];
int visitW[1005][1005];
int visitA[1005][1005];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//�����¿� �̵� 
int qW[1000001];//y��ǥ
int q2W[1000001];//x��ǥ
int qA[1000001];//y��ǥ
int q2A[1000001];//x��ǥ
int rearW = 0, frontW = 0, rear2W = 0, front2W = 0;
int rearA = 0, frontA = 0, rear2A = 0, front2A = 0;
void bfs()
{

	while (frontW < rearW)//water ���� �����ϲ��� 
	{
		int ypW = qW[frontW++];
		int xpW = q2W[front2W++];
		for (int i = 0; i < 4; i++)
		{
			int xxW = xpW + dx[i];
			int yyW = ypW + dy[i];
			if (0 <= xxW && xxW < M && 0 <= yyW && yyW < N)//water �̵� 
			{
				if (visitW[yyW][xxW] == 0) //���� �Ȱ�����  ����
				{
					if (graph[yyW][xxW] == '.' || graph[yyW][xxW] == '@')
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
	}*/
	

	while (frontA < rearA)//����ġ �����ϲ��� 
	{
		int ypA = qA[frontA++];
		int xpA = q2A[front2A++];
		for (int i = 0; i < 4; i++)
		{
			int xxA = xpA + dx[i];
			int yyA = ypA + dy[i];
			if (0 <= xxA && xxA < M && 0 <= yyA && yyA < N)
			{
				if (visitA[yyA][xxA] == 0 && graph[yyA][xxA] == '.')
				{
					if (visitA[ypA][xpA] + 1 < visitW[yyA][xxA] || visitW[yyA][xxA] == 0)//���� ���� �� �̵�  
					{
						qA[rearA++] = yyA;
						q2A[rear2A++] = xxA;
						visitA[yyA][xxA] = visitA[ypA][xpA] + 1;
					}

				}
			}
			else
			{
				printf("%d\n", visitA[ypA][xpA]);

				return;
			}
		}
	    /*printf("visit animal------------------\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%d ", visitA[i][j]);
			}
			printf("\n");
		}*/
		
	}
	printf("IMPOSSIBLE\n");
	return;


}

int main()
{
	int T ;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visitA[i][j] = 0;
				visitW[i][j] = 0;
			}
		}
		for (int i = 0; i < 1000001; i++)
		{
			qW[i] = 0;
			q2W[i] = 0;
			qA[i] = 0;
			q2A[i] = 0;

		}
		
		rearW = 0, frontW = 0, rear2W = 0, front2W = 0;
		rearA = 0, frontA = 0, rear2A = 0, front2A = 0;
		//�ʱ�ȭ �Ϸ� 
		scanf("%d %d", &M, &N);//����, ���� 
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
				if (graph[i][j] == '@')
				{
					qA[rearA++] = i;
					q2A[rear2A++] = j;
					visitA[i][j] = 1;
				}
				if (graph[i][j] == '#')
				{
				
					visitW[i][j] = 1;
					visitA[i][j] = 1;
				}
			}
		}
		bfs();
	}
}