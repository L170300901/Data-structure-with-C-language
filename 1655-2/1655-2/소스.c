#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100000

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

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)],
			ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
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
void HInsert2(Heap* ph, HData data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) < 0)
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
HData HDelete(Heap* ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}
int DataPriorityComp(int ch1, int ch2)
{
	return ch2 - ch1;
}
int main(void)
{
	Heap heap;//내림차순 힙 
	Heap heap2;//오른 차순 힙 
	HeapInit(&heap, DataPriorityComp);//초기화 시키기 
	HeapInit(&heap2, DataPriorityComp);//초기화
	int N, num;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		HInsert(&heap, num);
		for (int j = 0; j < i / 2; j++)
		{
			HInsert2(&heap2, heap.heapArr[1]);
			HDelete(&heap);
		}
		int mid = heap.heapArr[1];
		int mid2 = 0;
		//printf("mid= %d\n", mid);
		//printf("mid2= %d\n", mid2);

		if (i != 1)//첫번째 노드가 아닐때 실행 
		{
			mid2 = heap2.heapArr[1];
		}
		for (int j = 0; j < i / 2; j++)
		{
			HInsert(&heap, heap2.heapArr[1]);
			HDelete(&heap2);
		}
		if (i % 2 == 0)
		{
			
			if (mid > mid2)
			{
				
				printf("%d\n", mid2);
			}
			else
			{
				printf("%d\n", mid);
			}
		}
		else
		{
			printf("%d\n", mid);
		}
	}
	return 0;
}