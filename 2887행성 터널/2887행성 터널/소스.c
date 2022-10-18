#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct kruskal
{
	int x;
	int y;
	int z;
}KS;
KS arr[100005];
int parent[100002];
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
int cmpx(KS* a, KS* b)
{
	if (a->x > b->x)
		return 1;
	else if (a->x < b->x)
		return -1;
	else
		return 0;
}
int main()
{
	int N;
	scanf("%d", &N);
	//부모를 자기 자신으로 초기화 
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		KS ks;
		scanf("%d %d %d", &ks.x, &ks.y, &ks.z);

		arr[i].x = ks.x;
		arr[i].y = ks.y;
		arr[i].z = ks.z;
	}
	//qsort
	/*
	qsort(arr, N, sizeof(KS), cmpx);
	for (int i = 0; i <N ; i++)
	{
		printf("%d\n", arr[i].x);
	}
	*/
	//잘 정렬 됨

}