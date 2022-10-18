#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int map[505][505];
int visit[505];
int dist[505];

typedef struct _q
{
	int a; //거리
	int b;//가중치
}Queue;
int N, M;
int answer[505];
int cntt = 0;
int answerr;
void bfs(int s,int e)
{
	Queue q[10005];
	int rear = 0, front = 0;
	answerr = 1000;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		visit[i] = 0;
		answer[i] = 0;
	}
	
	//초기화 완료


	q[rear++].a = s;

	visit[s] = 1;
	//printf("s===%d\n", s);
	while (front<rear)
	{
		int xx = q[front++].a;
		printf("$$$$$$$$$$$$\n");
		printf("xx===%d\n", xx);
		for (int i = 0; i <N; i++)
		{
			if (map[xx][i] != 0 && visit[i] == 0)
			{
				printf("i===%d \n", i);
				if (i == e)
				{	
					int temp = 0;
					temp= map[xx][i] + visit[xx];
					printf("visit[i]==%d \n", visit[i]);
					printf("temp====%d\n", temp);

					answer[cntt] = temp;
					cntt++;
			
				}
				else
				{
					q[rear++].a = i;
					visit[i] = map[xx][i] + visit[xx];
					printf("visit[i]==%d \n",visit[i]);
				}	
			}

		}
	}
}
int main()
{
	while (1)
	{
		printf("#####\n");
		scanf("%d %d", &N, &M);
		for (int i = 0; i < 505; i++)
		{
			for (int j = 0; j < 505; j++)
			{
				map[i][j] = 0;
			}
		}
		cntt = 0;
		if (N == 0 && M == 0)
		{
			return 0;
		}
		int S, E; 
		scanf("%d %d", &S, &E);
		int a, b,c;
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d", &a, &b,&c);
			map[a][b] = c;		
		}
		bfs(S,E);
		for (int i = 0; i < cntt; i++)
		{
			printf("%d\n", answer[i]-1);
		}
		
		
		
	}
}