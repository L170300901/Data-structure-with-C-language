#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct kruskal
{
	long long from;
	long long to;
	long long val; //가중치
}KS;
KS arr[40000000];
int parent[20001];
int visit[20001];
int graph[20001][20001];
int cnt, V, answer;

//큐 생성 
int q[20001];
int front = 0, rear = 0;
void bfs(int v)
{
	//visit 초기화 
	for (int i = 0; i < V; i++)
	{
		visit[i] = 0;
	}



	q[rear++] = v;
	visit[v] = 1;
	while (front < rear)
	{
		v = q[front++];
		for (int i = 1; i <= V; i++)
		{
			if (visit[i]==0 && graph[v][i] == 1)
			{
				//printf("bfs @@@@@@@@\n");
				q[rear++] = i;
				visit[i] = 1;
				//printf("%d\n", cnt);
				for (int ii = 0; ii < cnt; ii++)
				{
					//printf("v==%d i==%d\n", v, i);
					if (arr[ii].to == v && arr[ii].from == i)
					{
						//printf("$@#$@#\n");
						answer = answer + arr[ii].val;

					}
					if (arr[ii].from == v && arr[ii].to == i)
					{
						//printf("$@#$@#444\n");
						answer = answer + arr[ii].val;
					}
				}
			}
			
		}
	}
}
int cmp(KS* a, KS* b)
{
	if (a->val > b->val)
		return 1;
	else if (a->val < b->val)
		return -1;
	else
		return 0;
}
void init(int V)
{
	//부모를 자기 자신으로 초기화 
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
		arr[i].from=0;
		arr[i].to= 0;
		arr[i].val= 0;
	}
}
int  distance(int a, int b)
{
	return abs(b - a)%1000;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i = 0; i < T; i++)
	{
		char U;
		scanf("%d", &V);
		init(V);
		while (1)
		{
			//printf("####\n");
			scanf("%c", &U);
			if (U == 'O')
			{
				break;
			}
			if (U == 'E')
			{
				answer = 0;
				int a;
				scanf("%d", &a);
				bfs(a);
				/*qsort(arr, cnt, sizeof(KS), cmp);
				for (int iii = 0; iii < cnt; iii++)
				{
					printf("qsort test == %d\n", arr[iii].val);
				}*/
				printf("%d\n", answer);
	
				
			}
			if (U == 'I')
			{
				KS ks;
				scanf("%d %d", &ks.from, &ks.to);
				graph[ks.from][ks.to]= graph[ks.to][ks.from] = 1;
				arr[cnt].from = ks.from;
				arr[cnt].to = ks.to;
				arr[cnt].val = distance(ks.from,ks.to);
				//printf("test =====%d %d %d\n", ks.from, ks.to, arr[cnt].val);
				cnt++;		
			}
		}
	}
	
}
