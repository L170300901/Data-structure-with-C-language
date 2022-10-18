#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int max[11500055];//max
int min[11500055];//min
int cnt2 = 0, cnt = 0;
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void maxpush(int N)
{
	cnt++;
	max[cnt] = N;
	int a;
	a = cnt;
	while (1)
	{
		if (cnt == 1)
		{
			break;
		}
		else if (max[a] > max[a / 2])
		{
			swap(&max[a / 2], &max[a]);
			a = a / 2;
			if (a == 1)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}
void minpush(int N)
{

	cnt2++;
	min[cnt2] = N;
	//printf("cnt2=%d N=%d\n", cnt2, N);
	int a;
	a = cnt2;
	while (1)
	{
		if()
		if (min[a] < min[a / 2])
		{

			swap(&min[a / 2], &min[a]);
			a = a / 2;
			if (a == 1)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}
void maxpop()
{
	int q = 1;
	while (1)
	{
		if (cnt > 2 * q + 1)
		{
			if (max[2 * q] >= max[2 * q + 1])//왼쪽이 크다면 
			{

				if (max[q] <= max[2 * q])//교환 
				{
					printf("%d\n", q);
					swap(&max[q], &max[2 * q]);
					q = 2 * q;
					if (2 * q > cnt)
					{
						printf("%d\n", q);
						break;
					}
				}
				else
				{
					break;
				}
			}
			else//오른쪽이 더 크다면 
			{
				if (max[q] <= max[2 * q + 1])//교환 
				{
					swap(&max[q], &max[2 * q + 1]);
					q = 2 * q + 1;
					if (2 * q > cnt)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if (cnt ==1)
			{
				break;
		
			}
			else
			{
				if (max[q] <= max[2 * q])//교환 
				{
					swap(&max[q], &max[2 * q]);
					q = 2 * q;
				}
				else
				{
					break;
				}
			}	    
		}

	}

}
void minpop()
{
	int k = 1;
	while (1)
	{
		if (cnt2 > 2 * k + 1)
		{
			if (min[2 * k] <= min[2 * k + 1])//왼쪽이 더 작다면 
			{
				if (min[k] >= min[2 * k])//교환 
				{
					int temp = 0;
					if (min[2 * k] == 0)
					{
						break;
					}
					swap(&min[k], &min[2 * k]);
					k = 2 * k;
				}
				else
				{
					break;
				}
			}
			else//오른쪽이 더 작다면 
			{
				if (min[k] >= min[2 * k + 1])//교환 
				{
					int temp = 0;
					if (min[2 * k + 1] == 0)
					{
						break;
					}
					swap(&min[k], &min[2 * k + 1]);
					k = 2 * k + 1;
				}
				else
				{
					break;
				}

			}
		}
		else
		{
			if (min[k] >= min[2 * k])//교환 
			{
				int temp = 0;
				if (min[2 * k] == 0)
				{
					break;
				}
				swap(&max[k], &max[2 * k]);
				k = 2 * k;
			}
			else
			{
				break;
			}
		}
	}
}
int main()
{
	int N, num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &N);
		if (i % 2 == 1)//홀수이면
		{
			maxpush(N);
		}
		else
		{
			minpush(N);
		}
		//출력 ------------------------------------
		if (cnt == 1 && cnt2 == 0)
		{
			printf("%d\n", max[1]);

		}
		else if (max[1] <= min[1])
		{
			printf("%d\n", max[1]);
		}
		else
		{
			printf("%d %d", max[1], min[1]);
			swap(&max[1], &min[1]);
			printf("%d %d\n", max[1], min[1]);
			maxpop();
			minpop();
			printf("%d\n", max[1]);
		}
	}
}