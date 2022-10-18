#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int V, E;
typedef struct kruskal
{
	int from;
	int to;
	int val; //가중치
}KS;
KS arr[200005];
int parent[200002];
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
void init()
{
	for (int i = 0; i < V; i++)
	{
		arr[i].from = 0;
		arr[i].to = 0;
		arr[i].val = 0;
	}
	res = 0;
}
int main()
{
	while (1)
	{
		scanf("%d", &V);
		scanf("%d", &E);
		if (V == 0 && E == 0)
		{
			return 0;
		}
		//부모를 자기 자신으로 초기화 
		for (int i = 0; i <= V; i++)
		{
			parent[i] = i;
		}
		int temp = 0;
		init();
		for (int i = 0; i <E; i++)
		{
			KS ks;
			scanf("%d %d %d", &ks.from, &ks.to, &ks.val);

			arr[i].from = ks.from;
			arr[i].to = ks.to;
			arr[i].val = ks.val;
			temp = ks.val + temp;			
		}
		//qsort
		qsort(arr, E, sizeof(KS), cmp);
		/*
		for (int i = 0; i <E ; i++)
		{
			printf("%d\n", arr[i].val);
		}
		*/
		//잘 정렬 됨 
		for (int i = 0; i < E; i++)
		{
			merge(arr[i].from, arr[i].to);
			//printf("chk==%d\n", chk);
			if (chk == 1)
			{
				res = res + arr[i].val;
				//printf("res==%d\n", res);
			}
		}
		printf("%d\n", temp - res);
	}
}
