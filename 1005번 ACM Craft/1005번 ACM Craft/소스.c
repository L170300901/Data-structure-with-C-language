#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _arr
{
	int front;
	int back;
}Arr;
Arr arr[100005];
int build[1005];
int in[100005];
int min[200001];
int  size = 1, i, input, num, target, next, cnt;
void minpush(int input)
{
	min[size++] = input;
	for (target = size - 1;min[target] < min[target / 2]; target /= 2)
	{
		input = min[target];
		min[target] = min[target / 2];
		min[target / 2] = input;
	}

}
void minpoparray()
{
	for (target = 1; target * 2 < size;)
	{
		if (size > target * 2 + 1)
		{
			next = min[target * 2] < min[target * 2 + 1] ? target * 2 : target * 2 + 1;
		}
		else
		{
			next = target * 2;
		}

		if (build[min[target]] > build[min[next]])
		{
			input = min[target];
			min[target] = min[next];
			min[next] = input;
			target = next;
		}
		else
		{
			break;
		}
	}

}
int answer;
int chkX,chkY;
int T, N, K;
int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		answer = 0;
		cnt = 1;
		scanf("%d %d", &N, &K);
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &build[j]);
		}
		for (int ii = 1; ii <= K; ii++)
		{
			scanf("%d %d", &arr[cnt].front, &arr[cnt].back);
			in[arr[cnt].back]++;
			cnt++;
		}
		for (int k = 1; k <= N; k++)
		{
			if (in[k] == 0)
			{
				printf("$$\n");
				minpush(k);

			}
		}
		printf("size ===%d\n", size);
		printf("min[1]===%d\n", min[1]);
		int last;
		chkX = 0;
		scanf("%d", &last);
		for (int ii = 0; ii < N; ii++)
		{
			printf("####################\n");
			int cntt;
			cntt = 0;

			int a = 0;
			a = min[1];
			printf("before node===%d\n", min[1]);

			printf("%d\n", size);
			int an = 0;
			for (int jjjj = 1; jjjj <size; jjjj++)
			{
				for (int jj = 1; jj <= N; jj++)
				{
					if (min[jjjj] == jj)
					{
						if (an < build[jj])
						{
							if (chkY == jj)
							{
								continue;
							}
							else
							{
								an = build[jj];
								chkX = jj;

							}
							
						}
					}
				}
			}
			answer = answer + an;

			chkY = chkX;
			printf("answer====%d\n", answer);
			//도착 하고자 하는곳에 도착하면 break;
			if (min[1] == last)
			{
				printf("%d\n", answer);
				break;
			}

			for (int kk = 1; kk <cnt; kk++)
			{
				if (arr[kk].front == a)
				{
					in[arr[kk].back]--;
					if (in[arr[kk].back] == 0)
					{
						minpush(arr[kk].back);
						cntt++;
					}

				}
			}
			printf("size==%d\n", size);
			printf("after node===%d\n", min[1]);
			min[1] = min[--size];
			minpoparray();
			printf("after node===%d\n", min[1]);
		}
		for (int bb = 0; bb <= N; bb++)
		{
			min[bb] = 0;
		}
		size = 1;
	}
	printf("END\n");
}