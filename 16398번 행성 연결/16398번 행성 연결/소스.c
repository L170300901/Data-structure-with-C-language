#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct kruskal
{
	int from;
	int to;
	int val; 
}KS;
KS arr[1000005];
int parent[1005];
int chk;
long long answer;
int map[1005][1005];
int cnt = 0;
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
	{
		return 1;
	}
	else if (a->val < b->val)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int V;
	scanf("%d", &V);
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	//�ʱ�ȭ �Ϸ� 
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	//map �Է� ���� 
	//map�� ���� �ؼ� ũ�罺Į �ȿ� ���� 
	for (int i = 1; i <= V-1; i++)
	{
		for (int j = i+1; j <= V; j++)
		{
			arr[cnt].from = i;
			arr[cnt].to = j;
			arr[cnt].val = map[i][j];
			cnt++;
			//printf("i==%d j==%d map==%d\n", i, j, map[i][j]);
		}
	}
	//ũ�罺Į�� �Է� �Ϸ� 

	qsort(arr, cnt, sizeof(KS), cmp);
	//��Ʈ �Ϸ� 

	for (int i = 0; i < cnt; i++)
	{
		merge(arr[i].from, arr[i].to);
		if (chk == 1)
		{
			answer = answer + arr[i].val;
		}
	}
	printf("%lld", answer);
}
