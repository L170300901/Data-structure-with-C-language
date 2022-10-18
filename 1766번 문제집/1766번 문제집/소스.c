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
int in[32005];

int min[200001];
int  size = 1, i, input, num, target, next,cnt;
int chk=0;
void minpush(int input)
{
	min[size++] = input;
	for (target = size - 1; min[target] < min[target / 2]; target /= 2)
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

		if (min[target] > min[next])
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
int cntt;
int main()
{
	int N, M;
	scanf("%d %d", &N,& M);
	for (int i = 0; i < M;i++)
	{
		scanf("%d %d", &arr[cnt].front, &arr[cnt].back);
		in[arr[i].back]++;
		cnt++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (in[i] == 0)
		{
			minpush(i);
		}
	}
	//printf("size ==%d \n", size);
	for(int ii=0;ii<N;ii++)
	{
		int a = 0;
		a = min[1];
		printf("%d ", min[1]);
		min[1] = min[--size];
		minpoparray();
		//printf("min[1] ==%d \n", min[1]);
		//printf("size ==%d \n", size);
		cntt = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (arr[i].front == a)
			{
				in[arr[i].back]--;
				if (in[arr[i].back] == 0)
				{
					minpush(arr[i].back);

					//printf("min[3] ==%d \n", min[3]);
					//min[1] = min[--size];
					//minpoparray();
					cntt++;
				}

			}
		}
	}
}