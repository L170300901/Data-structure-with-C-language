#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int max[200001], min[200001];
int  size = 1, i, input, num, target, next;
int  size2 = 1, i2, target2, next2;
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void maxpush(int input)
{
	max[size++] = input;
	for (target = size - 1; max[target] > max[target / 2]; target /= 2)
	{
		if (target / 2 == 0)
		{
			break;
		}
		input = max[target];
		max[target] = max[target / 2];
		max[target / 2] = input;
	}

}
void minpush(int input)
{
	min[size2++] = input;
	//printf("size=%d input=%d\n", size,input);
	for (target2 = size2 - 1; min[target2] < min[target2 / 2]; target2 /= 2)
	{
		if (target2 / 2 == 0)
		{
			break;
		}
		input = min[target2];
		min[target2] = min[target2 / 2];
		min[target2 / 2] = input;
	}

}
void maxpoparray()
{
	for (target = 1; target * 2 < size;)
	{
		if (size > target * 2 + 1)
		{
			next = max[target * 2] > max[target * 2 + 1] ? target * 2 : target * 2 + 1;
			//자식노드의 우선순위 비교 
		}
		else
		{
			next = target * 2;
		}
		if (max[target] < max[next])
		{
			input = max[target];
			max[target] = max[next];
			max[next] = input;
			target = next;
		}
		else
		{
			break;
		}
	}
}
void minpoparray()
{
	for (target2 = 1; target2 * 2 < size2;)
	{
		if (size2 > target2 * 2 + 1)
		{
			next2 = min[target2 * 2] < min[target2 * 2 + 1] ? target2 * 2 : target2 * 2 + 1;
			//자식노드의 우선순위 비교 
		}
		else
		{
			next2 = target2 * 2;
		}

		if (min[target2] > min[next2])
		{
			input = min[target2];
			min[target2] = min[next2];
			min[next2] = input;
			target2 = next2;
		}
		else
		{
			break;
		}
	}

}
int main()
{
	int N, num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &input);
		//printf("%d %d\n", max[1], min[1]);
		if (i % 2 == 1)//홀수이면
		{
			maxpush(input);
		}
		else
		{
			minpush(input);
		}
		//printf("max[1]=%d min[1]=%d\n", max[1], min[1]);
		//printf("max[2]=%d min[2]=%d\n", max[2], min[2]);
		//printf("max[3]=%d min[3]=%d\n", max[3], min[3]);
		//출력 ------------------------------------
		if (size == 2 && size2 == 1)
		{
			printf("%d\n", max[1]);

		}
		else if (max[1] <= min[1])
		{
			printf("%d\n", max[1]);
		}
		else
		{
			//printf("##\n");
			//printf("%d %d\n", max[1], min[1]);
			swap(&max[1], &min[1]);
			//printf("%d %d\n", max[1], min[1]);
			maxpoparray();
			minpoparray();
			printf("%d\n", max[1]);
		}
	}
}