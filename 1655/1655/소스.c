#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

#define HEAP_LEN	200005

typedef int HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}
int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}
void HInsert(Heap* ph, HData data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}
int DataPriorityComp(int ch1, int ch2)
{
	return ch2 - ch1;
}
int main(void)
{
	Heap heap;
	HeapInit(&heap,DataPriorityComp);
	int N,num;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		HInsert(&heap, num);
		if (i% 2 == 1)//È¦¼öÀÌ¸é
		{
			if (heap.numOfData == 1)
			{
				printf("%d\n", heap.heapArr[1]);
			}
			
			else if ((heap.heapArr[(heap.numOfData + 1) / 2]) > (heap.heapArr[((heap.numOfData + 1) / 2) + 1]))
			{
				printf("%d\n",heap.heapArr[(heap.numOfData + 1) /2+1]);
			}
			else
			{
				printf("%d\n", heap.heapArr[(heap.numOfData + 1) / 2]);
			}
		}
		else//Â¦¼öÀÌ¸é
		{
			if ((heap.heapArr[(heap.numOfData + 1) / 2]) > (heap.heapArr[((heap.numOfData + 1) / 2) + 1]))
			{
				printf("%d\n", heap.heapArr[(heap.numOfData + 1) / 2 + 1]);
			}
			else
			{
				printf("%d\n", heap.heapArr[(heap.numOfData + 1) / 2]);
			}
		

		}
	}	
	return 0;
}