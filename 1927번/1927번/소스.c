#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int heap[100005];
int main()
{
	int temp2 = 0;
	int height = 0, num,N;
	scanf("%d", &num);
	scanf("%d", &heap[1]);
	if (heap[1] == 0)
	{
		printf("%d\n", 0);
		heap[1] = NULL;
	}
	for (int i = 2; i < num+1;i++)
	{
		//printf("%d", i);
		/*for (int i = 1; i < num + 1; i++)
		{
			printf("###%d\n", heap[i]);
		}*/

		scanf("%d", &N);
		
		if(N==0)
		{

		}
		else
		{
			if (heap[1] == NULL)
			{
				heap[1] = heap[i];
			}
			heap[i] = N;
			while (1)
			{
				temp2 = i;
				if (heap[i] < heap[i / 2])
				{

					int temp = 0;
					temp = heap[i / 2];
					heap[i / 2] = heap[i];
					heap[i] = temp;
					i = i / 2;
				}
				else
				{
					break;
				}
				i = temp2;
			}
		}
	}
	for (int i = 1; i < num + 1; i++)
	{
		printf("###%d\n", heap[i]);
	}
	
	 
	


}