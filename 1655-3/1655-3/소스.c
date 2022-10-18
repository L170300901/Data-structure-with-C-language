#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0
typedef int HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[100005];
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

int DataPriorityComp(int ch1, int ch2)
{
	return ch2 - ch1;
}
int main()
{
	Heap heap;//mid
	Heap heap2;//max
	HeapInit(&heap, DataPriorityComp);//초기화 시키기 
	HeapInit(&heap2, DataPriorityComp);//초기화
	int N, num;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		if (i % 2 == 0)//짝수이면
		{
			HInsert(&heap, num);
		}
		else
		{
			HInsert2(&heap2, num);
			//int mid;
			//mid = heap2.heapArr[1];

		}
		/*if (heap2.heapArr[1] > heap.heapArr[1])
		{
			int temp = 0;
			temp = heap2.heapArr[1];
			HDelete(&heap2);
			int temp2 = 0;
			temp2 = heap.heapArr[1];
			HDelete2(&heap);
			HInsert2(&heap2, temp2);
			HInsert2(&heap2, temp);

		}
		printf("%d\n", heap2.heapArr[1]);*/
	}
	for (int i = 1; i <= N; i++)
	{
		printf("@%d\n", heap2.heapArr[i]);
		
	}

	for (int i = 1; i <= N; i++)
	{
		printf("#%d\n", heap.heapArr[i]);

	}
    return 0;
}