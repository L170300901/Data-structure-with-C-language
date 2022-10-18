#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
typedef struct kruskal
{
	int from;
	int to;
	int val; //가중치
}KS;
KS arr[10005];
int parent[10002];
int res;
int chk;
int find(int u)
{
	if (u == parent[u])
	{
		return u;
	}
	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	chk = 0;
	u = find(u);
	v = find(v);
	//printf("u==%d v==%d\n",u, v);
	if (u == v)
	{
		return;
	}
	parent[u] = v;
	chk = 1;
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
int main()
{
	int T;
	scanf("%d",&T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);//국가수와 비행기 수 
		for (int ii = 1; ii <= N; ii++)
		{
			parent[ii] = ii;
		}
		int res = 0;
		for (int j = 0; j < M; j++)
		{
			KS ks;
			int a, b;
			scanf("%d %d", &a,&b);
			arr[j].from = a;
			arr[j].to = b;
			arr[j].val = 1;
		
		}
		//qsort
		qsort(arr, M, sizeof(KS), cmp);
		/*
		for (int i = 0; i < M; i++)
		{
			printf("from==%d\n", arr[i].from);
		}
		for (int i = 0; i < M; i++)
		{
			printf("to==%d\n", arr[i].to);
		}
		for (int i = 0; i < M; i++)
		{
			printf("val==%d\n", arr[i].val);
		}
		*/
		for (int i = 0; i < M; i++)
		{
			merge(arr[i].from, arr[i].to);
			//printf("chk==%d\n", chk);
			if (chk == 1)
			{
				res = res + arr[i].val;
				//printf("res==%d\n", res);
			}
		}
		printf("%d\n", res);
	}

}