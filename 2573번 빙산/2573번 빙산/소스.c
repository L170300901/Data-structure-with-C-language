#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N,flag;
int graph[305][305];
int visit[305][305];
int new[305][305];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//�����¿� �̵� 
int cnt, day;
int q[100000];//y��ǥ
int q2[100000];//x��ǥ
int rear = 0, front = 0, rear2 = 0, front2 = 0;
//ť���� 
void dfs(int y, int x)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (0 <= xx && xx < M && 0 <= yy && yy < N)
		{
			if (visit[yy][xx] != 1 && graph[yy][xx] > 0)
			{
				dfs(yy, xx);
			}
		}

	}

}
void bfs()
{
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		int zero = 0;
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < M && 0 <= yy && yy < N)
			{
				/*if (new[yy][xx] != 0 && visit[yy][xx] == 0) //���� �϶�
				{
					q[rear++] = yy;//y��ǥ ������
					q2[rear2++] = xx;//x��ǥ �ֱ�
					visit[yy][xx] = 1;
				}*/
				if (graph[yy][xx] == 0 && visit[yy][xx] == 0) //�ٴ� �ϋ� 
				{
					if (graph[yp][xp] != 0) //���� �������� 
					{
						new[yp][xp] = new[yp][xp] - 1;
						if (new[yp][xp] == -1)
						{
							new[yp][xp] = 0;

						}
					}
				}
			}

		}
	}
	day++;
	//�ʱ�ȭ
	cnt = 0;
	//visit �ʱ�ȭ ��Ű��
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;
			graph[i][j] = new[i][j];//�������ٰ� ���ΰ� ���� 
		}
	}
	//dfs �˻� 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] > 0 && visit[i][j] != 1)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	/*//��� �غ��� test ���߿� �����
	printf("new -----------\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", new[i][j]);
		}
		printf("\n");
	}*/

	if (cnt >= 2)//���ϰ� 2�κ� �̻����� ������ ������� 
	{
		printf("%d", day);
		flag = 1;
		return;

	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &graph[i][j]);
			new[i][j] = graph[i][j];//���� �׷��� ���� 
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] > 0 && visit[i][j] != 1)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	if (cnt >= 2)
	{
		printf("0\n");
		return 0;

	}
	else
	{
		//visit �ʱ�ȭ ��Ű��
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visit[i][j] = 0;
			}
		}
		//bfs ���� 
		int temp2 = 0;
		while (1)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (new[i][j] != 0 && visit[i][j] == 0)//������ ã�� 
					{
						if (rear > 10000)
						{
							rear = 0;
							front = 0;
						}
						q[rear++] = i;//y��ǥ ������ 
						q2[rear2++] = j;//x��ǥ �ֱ� 
						visit[i][j] = 1;
						
					}
				}
			}
			bfs();

			if (flag == 1)
			{
				return 0;
			}
			int temp = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{

					temp = temp + new[i][j];
				}
			}
			if (temp==0)
			{
				printf("0\n");
				return;
			}
			//visit �ʱ�ȭ
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					visit[i][j] = 0;
				}
			}

		}
	}
}