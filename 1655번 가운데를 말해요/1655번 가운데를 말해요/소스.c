#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int max[100055];//max
int min[100055];//min
int cnt2 = 0,cnt=0;
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
			if (max[2 * q] >= max[2 * q + 1])//������ ũ�ٸ� 
			{

				if (max[q] <= max[2 * q])//��ȯ 
				{
					printf("%d\n", q);
					swap(&max[q], &max[2*q]);
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
			else//�������� �� ũ�ٸ� 
			{
				if (cnt < 2 * q)
				{
					break;
				}
				else if (max[q] <= max[2 * q + 1])//��ȯ 
				{
					swap(&max[q], &max[2*q+1]);
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
			if (max[q] <= max[2 * q])//��ȯ 
			{
				swap(&max[q], &max[2*q]);
				q = 2 * q;
			}
			else
			{
				break;
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
			if (min[2 * k] <= min[2 * k + 1])//������ �� �۴ٸ� 
			{
				if (min[k] >= min[2 * k])//��ȯ 
				{
					int temp = 0;
					if (min[2 * k] == 0)
					{
						break;
					}
					swap(&min[k], &min[2*k]);
					k = 2 * k;
				}
				else
				{
					break;
				}
			}
			else//�������� �� �۴ٸ� 
			{
				if (min[k] >= min[2 * k + 1])//��ȯ 
				{
					int temp = 0;
					if (min[2 * k + 1] == 0)
					{
						break;
					}
					swap(&min[k], &min[2*k+1]);
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
			if (min[k] >= min[2 * k])//��ȯ 
			{
				int temp = 0;
				if (min[2 * k] == 0)
				{
					break;
				}
				swap(&max[k], &max[2*k]);
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
	int N,num;
	scanf("%d", &num);
	for (int i = 1; i <=num; i++)
	{
		scanf("%d", &N);
		if (i % 2 == 1)//Ȧ���̸�
		{
			maxpush(N);
		}
		else
		{
			minpush(N);
		}
		//��� ------------------------------------
		if (cnt == 1&&cnt2==0)
		{
			printf("%d\n", max[1]);

		}
		else if (max[1] <= min[1])
		{
			printf("%d\n", max[1]);
		}
		else
		{
			swap(&max[1], &min[1]);
			//printf("max[1]=%d min[1]=%d\n", max[1], min[1]);
			//printf("max[2]=%d min[2]=%d\n", max[2], min[2]);
			//printf("max[3]=%d min[3]=%d\n", max[3], min[3]);
			//printf("######\n");
			//�ڸ� �ٲ� �� 
			//max����
			maxpop();
			//min ���� 
			minpop();
			printf("%d\n", max[1]);
		}	
	}
}