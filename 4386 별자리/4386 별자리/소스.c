#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
typedef struct kruskal
{
	double y;
	double x;
}KS;
typedef struct star
{
	int  from;
	int  to;
	double val; //가중치
}Star;
Star star[10005];
KS arr[105];
int parent[105];
double res;
int chk;
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
	printf("u==%d v==%d\n",u, v);
	if (u == v)
	{
		return;
	}
	parent[u] = v;
	chk = 1;
}
int cmp(Star* a, Star* b)
{
	if (a->val > b->val)
		return 1;
	else if (a->val < b->val)
		return -1;
	else
		return 0;
}
double distance(int a, int b) 
{
	return sqrt(abs(arr[b].x - arr[a].x)*abs(arr[b].x - arr[a].x)+
		+abs(arr[b].y - arr[a].y) * abs(arr[b].y - arr[a].y));
}
int main()
{
	int V;
	scanf("%d", &V);
	//부모를 자기 자신으로 초기화 
	for (int i = 1; i <= V; i++)
	{
		KS ks;
		scanf("%lf %lf", &ks.x, &ks.y);
		arr[i].x = ks.x;
		arr[i].y = ks.y;
	}
	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = i+1; j <= V; j++)
		{
			if (i == j)
			{
				continue;
			}
			star[cnt].from = i;
			star[cnt].to = j;
			star[cnt].val= distance(i, j);
			printf("%d %d %.2lf\n", star[cnt].from, star[cnt].to, star[cnt].val);
			cnt++;
		}
	}
	//qsort
	for (int i = 0; i <= cnt; i++)
	{
		parent[i] = i;
	}
	printf("cnt==%d\n", cnt);
	qsort(star, cnt, sizeof(Star), cmp);

	for (int i = 0; i < cnt; i++)
	{
		printf("%.2lf\n", star[i].val);
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("############3\n");
		merge(star[i].from, star[i].to);
		printf("chk==%d\n", chk);
		if (chk == 1)
		{
			printf("val==%.2lf\n", star[i].val);
			res = res + star[i].val;
			printf("res==%.2lf\n", res);
		}
	}
	printf("%.2lf", res);
}