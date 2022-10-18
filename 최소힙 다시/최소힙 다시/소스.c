#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int min[200001];
int  size = 1, i, input, num, target, next;
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
			//자식노드의 우선순위 비교 
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
int main()
{
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &input);
		if (input == 0)
		{
			if (size == 1)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", min[1]);
				min[1] = min[--size];
				minpoparray();
			}
		}
		else
		{
			minpush(input);
		}
	}
}