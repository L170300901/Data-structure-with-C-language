#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int q[100001];
int rear,start,cnt;
void push(int num)
{
	 q[rear] = num;
	 rear++;
	 cnt++;
}
void pop()
{
	if (cnt == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", q[start]);
		start++;
		cnt--;
	}

}
void size()
{
	printf("%d\n", cnt);

}
void empty()
{
	if (cnt == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}
void front()
{
	if (cnt == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", q[start]);
	}

}
void back()
{
	if (cnt == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", q[rear-1]);
	}

}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char str[10];	
		scanf(" %s", str);
		if (strcmp("push", str) == 0)
		{
				int num;
				scanf("%d", &num);
				push(num);

		}
		else if (strcmp("pop", str) == 0)
		{
			pop();
				
		}
		else if (strcmp("size", str) == 0)
		{
			size();
				
		}
		else if (strcmp("empty", str) == 0)
		{
			empty();
				
		}
		else if (strcmp("front", str) == 0)
		{
			front();	
		}
		else if (strcmp("back", str) == 0)
		{
			back();
		}
	}
	return 0;

}
