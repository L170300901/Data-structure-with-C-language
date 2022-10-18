#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int visit[1005];
int map[1005][1005];
int dist[10005];
int com, n;
int  size = 1, num, next;
//ť �����
int q[10000005];
int rear = 0, front = 0;
// �� ����

int size2;
int b;
int answer;
typedef struct _h 
{
	int a; //��ǻ��
	int b;//����ġ
}Heap;
Heap heap[1000005];

void minpush(int input,int temp)//temp=����ġ��
{
	heap[size].a = input;
	heap[size].b = temp;
	size++;

	for (int target = size - 1; heap[target].b < heap[target / 2].b; target /= 2)
	{
		Heap k;
		k = heap[target];
		heap[target] = heap[target / 2];
		heap[target / 2] = k;
	}

}
void minpoparray()
{
	for (int target = 1; target * 2 < size;)
	{
		if (size > target * 2 + 1)
		{
			next = heap[target * 2].b < heap[target * 2 + 1].b ? target * 2 : target * 2 + 1;

			//�ڽĳ���� �켱���� �� 
		}
		else
		{
			next = target * 2;
		}

		if (heap[target].b > heap[next].b)
		{
			Heap k;
			k = heap[target];
			heap[target] = heap[next];
			heap[next]= k;
			target = next;
		}
		else
		{
			break;
		}
	}

}
void prim(int x)
{
	//�迭�� ���Ѵ�� ���� �ϱ�
	for (int i = 0; i <= com; i++)
	{
		dist[i] = 1987654321;
	}

	//���� �������� ���� 
	heap[size].a = x;
	heap[size].b = 0;
	size++;


	dist[x] = 0;
	answer = 0;


	while (size!=1) 
	{
		int xx = heap[1].a;
		int yy = heap[1].b;
		//printf("xx= %d yy=%d\n", xx, yy);

		heap[1] = heap[--size];
		minpoparray();

		if (visit[xx] == 1)
		{
			//printf("END\n");
			continue;		
		}
		visit[xx] = 1;
		//printf("answer. before=%d\n", answer);
		answer = answer + yy;
		//printf("answer. after=%d\n", answer);


		for (int i = 1; i <= com; i++)
		{
			if (map[xx][i] != 0 && visit[i] == 0)
			{
				if (dist[i] > map[xx][i])
				{
					dist[i] = map[xx][i];
					minpush(i, map[xx][i]);
				}

			}

		}
		//printf("####\n");
		
	}
	
	

}
int main()
{
	scanf("%d", &com);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = map[b][a] =c;
	}
	prim(1); //1�� ���� �����غ��� 
	printf("%d\n", answer);

}
