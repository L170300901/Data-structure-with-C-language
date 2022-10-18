#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int stack[500005];
int answer[500005];
int cnt;
typedef struct _ar
{
	int a;  //À§Ä¡
	int b;  //°ª
}ar;
ar arr[100001];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int temp;
		scanf("%d", &temp);
		arr[i].a = i;
		arr[i].b = temp;
	}
	//printf("%d\n", N);
	for (int i = N; i >1; i--)
	{
		int chk = 0;
		for (int j = i - 1; j>=1; j--)
		{
			if (arr[i].b < arr[j].b)
			{
				chk = 1;
				printf("i==%d j==%d\n", i, j);
				answer[cnt++] = arr[j].a;
				break;
			}
		}
		if (chk == 0)
		{
			answer[cnt++] = 0;
		}	
	}
	answer[cnt++] = 0;
	for (int i = cnt-1; i >= 0; i--)
	{
		printf("%d ", answer[i]);
	}
}