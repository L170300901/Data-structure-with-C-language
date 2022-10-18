#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef struct _arr
{
	int front;
	int back;
}Arr;
Arr arr[100005];
int build[1005];
int in[1005];
int cnt, cntt;


int answer;
int T, N, K;
void init()
{
	for (int i = 0; i < 100005; i++)
	{
		arr[i].front = 0;
		arr[i].back = 0;
	}
	for (int i = 0; i < 1005; i++)
	{
		in[i] = 0;
		build[i] = 0;
	}
	cnt = 1;

}
int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		init();

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
		//////////////////
		queue<int> q;

		for (int k = 1; k <= N; k++)
		{
			if (in[k] == 0)
			{
				q.push(k);
			}
		}
		int last;
		scanf("%d", &last);
		int blast = 0;
		blast = build[last];
		//visit[last] = -1;
		while (!q.empty())
		{
			//printf("$$$$$$$$$$$$$$$$$$$$$$$$\n");
			for (int h = 1; h <= N; h++)
			{
				//printf("visit[%d] ==%d\n",h, build[h]);
			}
			int x = q.front();
			q.pop();
			//printf("x==========%d\n", x);
			for (int iii = 1; iii < cnt; iii++)
			{
				if (arr[iii].front == x)
				{
					//printf("in==%d iii==%d\n", in[arr[iii].back], iii);
					if (arr[iii].back == last)
					{
						//printf("$$$\n");
						if (blast + build[arr[iii].front] > build[last])
						{
							//printf("blast==%d build.front==%d", blast, build[arr[iii].front]);
							//printf("queque====%d\n", arr[iii].back);
							q.push(arr[iii].back);
							build[last] = blast + build[arr[iii].front];
						}

					}
					else
					{
						//printf("queque====%d\n", arr[iii].back);
						q.push(arr[iii].back);
						build[arr[iii].back] = build[arr[iii].back] + build[arr[iii].front];
					}
				}
			}

		}
		printf("%d\n", build[last]);
	}
}