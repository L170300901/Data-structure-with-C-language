#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main() {
	int heap[100001], size = 1, i, input, TC, target, next;

	scanf("%d", &TC);
	for (i = 0; i < TC; i++)
	{
		scanf("%d", &input);

		if (input == 0)
		{
			if (size == 1)
				printf("0\n");

			else
			{
				printf("%d\n", heap[1]);
				heap[1] = heap[--size];
				printf("size=%d\n", size);
				for (target = 1; target * 2 < size;)
				{
					if (size > target * 2 + 1)
					{
						next = heap[target * 2] < heap[target * 2 + 1] ? target * 2 : target * 2 + 1;
						//자식노드의 우선순위 비교 
					}
					else
					{
						next = target * 2;
					}

					if (heap[target] > heap[next])
					{
						input = heap[target];
						heap[target] = heap[next];
						heap[next] = input;
						target = next;
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			heap[size++] = input;
			for (target = size - 1; heap[target] < heap[target / 2]; target /= 2)
			{
				input = heap[target];
				heap[target] = heap[target / 2];
				heap[target / 2] = input;
			}
		}
	}
	return 0;
}