#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int heap[200055];
int main()
{
	int num,N,cnt=0;
	int k;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &N);

		

		if (N == 0)//��尪 ���
		{
			if (cnt == 0)//��� ������ 0 ��� 
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", heap[1]);
				heap[1] = heap[cnt];
				heap[cnt] = 0;
				//printf("##%d\n", heap[1]);
				//���� 
				int k = 1;
				while (1)
				{
					if (cnt > 2 * k + 1)
					{
						if (abs(heap[2 * k]) < abs(heap[2 * k + 1]))//������ �� �۴ٸ� 
						{
							if (abs(heap[k]) >= abs(heap[2 * k]))//��ȯ 
							{
								int temp = 0;
								if (heap[2 * k] == 0)
								{
									break;
								}
								temp = heap[k];
								heap[k] = heap[2 * k];
								heap[2 * k] = temp;
								k = 2 * k;

							}
							else
							{
								break;
							}
						}
						else if (abs(heap[2 * k]) == abs(heap[2 * k + 1]))
						{
							if (heap[2 * k] < (heap[2 * k + 1]))
							{
								int temp = 0;
								if (heap[2 * k] == 0)
								{
									break;
								}
								temp = heap[k];
								heap[k] = heap[2 * k];
								heap[2 * k] = temp;
								k = 2 * k;

							}
							else
							{
								int temp = 0;
								if (heap[2 * k] == 0)
								{
									break;
								}
								temp = heap[k];
								heap[k] = heap[2 * k+1];
								heap[2 * k+1] = temp;
								k = 2 * k+1;
							}


						}
						else//�������� �� �۴ٸ� 
						{
							if (abs(heap[k]) >= abs(heap[2 * k + 1]))//��ȯ 
							{
								int temp = 0;
								if (heap[2 * k + 1] == 0)
								{
									break;
								}
								temp = heap[k];
								heap[k] = heap[2 * k + 1];
								heap[2 * k + 1] = temp;
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
						if (abs(heap[k]) >= abs(heap[2 * k]))//��ȯ 
						{
							int temp = 0;
							if (heap[2 * k] == 0)
							{
								break;
							}
							temp = heap[k];
							heap[k] = heap[2 * k];
							heap[2 * k] = temp;
							k = 2 * k;

						}
						else
						{
							break;
						}
					}
				}
				cnt--;
			}
		}
		else//push
		{
			cnt++;
			heap[cnt] = N;
			int a;
			a = cnt;
			while (1)
			{
				if (abs(heap[a]) < abs(heap[a / 2]))//���밪 �� 
				{
					int temp = 0;
					temp = heap[a / 2];
					heap[a / 2] = heap[a];
					heap[a] = temp;
					a = a / 2;
				}
				else if (abs(heap[a]) == abs(heap[a / 2]))//���밪�� ������ ũ�� �� 
				{
					if (heap[a] < heap[a / 2])//������ ��ġ �ٲ� 
					{
						int temp = 0;
						temp = heap[a / 2];
						heap[a / 2] = heap[a];
						heap[a] = temp;
						a = a / 2;
					}
					else
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
		/*for (int i = 1; i <= cnt; i++)
		{
			printf("######%d\n", heap[i]);
		}*/
	}
	return 0;
}