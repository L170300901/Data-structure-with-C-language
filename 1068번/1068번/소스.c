#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
/*struct tree
{
	int left;
	int right;
};
typedef struct tree arr;*/
int arr[50];
int main()
{
	int N, i,l,del;
	int root=0;
	int cnt = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] = -1)
		{
			root = i;
		}
	}
	scanf("%d",&del);
	int j;
	for (j = 0; j < N; j++)
	{
		if (del == root)
		{
			cnt = 0;
		}
		else
		{
			if (del == arr[j])
			{
				cnt--;
			}
			else
			{
				for (l = 0; l < N; l++)
				{
					if (l == root)
						continue;
					if (l == del)
						continue;
				}
			}
		}
	}
		printf("%d",cnt);
		return 0;	
}