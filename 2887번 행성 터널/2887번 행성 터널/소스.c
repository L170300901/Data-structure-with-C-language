#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct kruskal
{
	long long x;
	long long y;
	long long z;
}KS;
typedef struct star
{
	long long   from;
	long long   to;
	long long val; //°¡ÁßÄ¡
}Star;
Star star[1000005];
KS arr[1000005];
int parent[100005];
long long res;
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
	//printf("u==%d v==%d\n", u, v);
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

long long  distance(int a, int b)
{
	long long min = 0;
	long long c, d, e;
	c = abs(arr[a].x - arr[b].x);
	d = abs(arr[a].y - arr[b].y);
	e = abs(arr[a].z - arr[b].z);
	if (c < d)
	{
		min = c;
		if (e < c)
		{
			min = e;
		}
	}
	else
	{
		min = d;
		if (e < d)
		{
			min = e;
		}
	}
	return min;
}
int main()
{
	int V;
	scanf("%d",&V); 
	for (int i = 1; i <= V; i++)
	{
		scanf("%lld %lld %lld",&arr[i].x, &arr[i].y, &arr[i].z);
		parent[i] = i;
	}

	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = i + 1; j <= V; j++)
		{
			star[cnt].from = i;
			star[cnt].to = j;
			star[cnt].val = distance(i, j);
			//printf("%d %d %d \n", star[cnt].from, star[cnt].to, star[cnt].val);
			cnt++;
		}
	}
	//qsort
	//printf("cnt==%d\n", cnt);
	qsort(star, cnt, sizeof(Star), cmp);

	/*for (int i = 0; i < cnt; i++)
	{
		printf("qsort ==%d %d %d \n", star[i].from, star[i].to, star[i].val);
	}*/
	for (int i = 0; i < cnt; i++)
	{
		//printf("############3\n");
		merge(star[i].from, star[i].to);
		//printf("chk==%d\n", chk);
		if (chk == 1)
		{
			//printf("val==%d\n", star[i].val);
			res = res + star[i].val;
			//printf("res==%.2lf\n", res);
		}
	}
	printf("%lld", res);
}