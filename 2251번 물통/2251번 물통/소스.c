#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int A, B, C;
int visit[205][205][205];
//물통 A의 큐 
int qA[100001];
int rearA = 0, frontA = 0;
//물통 B의 큐 
int qB[100001];
int rearB = 0, frontB = 0;
//물통 C의 큐 
int qC[100001];
int rearC = 0, frontC = 0;
int answer[205];
int cnt=0;
void bfs(int a,int b, int c)
{
	qA[rearA++] = a;
	qB[rearB++] = b;
	qC[rearC++] = c;
	while (frontA < rearA)
	{
		int vA = qA[frontA++];
		int vB = qB[frontB++];
		int vC = qC[frontC++];
		if (visit[vA][vB][vC] == 1)
		{
			continue;
		}
		visit[vA][vB][vC] = 1;
		/*printf("start--------\n");
		printf("vA=%d vB=%d vC=%d\n", vA, vB, vC);	*/
		//물통 A 가 비어 있으면 c를 배열에 저장 
		if (vA == 0)
		{
			answer[cnt] = vC;
			cnt++;
		}
		//a->b
		if (vA != 0 && vB < B) 
		{
			if (B - vB < vA)  //va가 물통 B보다 큼 
			{
				qA[rearA++] = vA - (B - vB);
				qB[rearB++] = B;
				qC[rearC++] = vC;
			}
			else
			{
				qA[rearA++] = 0;
				qB[rearB++] = vB + vA;
				qC[rearC++] = vC;
				
			}
		}
		//a->c
		if (vA != 0 && vC < C) 
		{
			if (C - vC < vA)
			{
				qA[rearA++] = vA - (C - vC);
				qB[rearB++] = vB;
				qC[rearC++] = C;
			}
			else
			{
				qA[rearA++] = 0;
				qB[rearB++] = vB;
				qC[rearC++] = vC + vA;
				
			}

		}
		//b->a
		if (vB != 0 && vA <A )
		{
			if (A - vA < vB)
			{
				qA[rearA++] = A;
				qB[rearB++] = vB - (A - vA);
				qC[rearC++] = vC;
			}
			else
			{
				qA[rearA++] = vA + vB;
				qB[rearB++] = 0;
				qC[rearC++] = vC;
			}
			
		}
		//b->c
		if (vB != 0 && vC < C ) 
		{
			if (C - vC < vB)
			{
				qA[rearA++] = vA;
				qB[rearB++] = vB - (C - vC);
				qC[rearC++] = C;
			}
			else
			{
				qA[rearA++] = vA;
				qB[rearB++] = 0;
				qC[rearC++] = vC + vB;
			}
		}
		//c->a
		if (vC != 0 && vA < A) 
		{
			if (A - vA < vC)
			{	
				qA[rearA++] = A;
				qB[rearB++] = vB;
				qC[rearC++] = vC - (A - vA);
				
			}
			else
			{
				qA[rearA++] = vA + vC;
				qB[rearB++] = vB;
				qC[rearC++] = 0;
			}
			
		}
		//c->b
		if (vC != 0 && vB < B) 
		{
			if (B - vB < vC)
			{
				qA[rearA++] = vA;
				qB[rearB++] = B;
				qC[rearC++] = vC - (B - vB);
			}
			else
			{
				qA[rearA++] = vA;
				qB[rearB++] = vB + vC;;
				qC[rearC++] = 0;

			}
			
		}
	}
}
int main()
{
	scanf("%d %d %d", &A,&B,&C);

	bfs(0,0,C);
	for (int i = 0; i < cnt; i++)		
	{
		for (int j = 0; j < cnt - 1; j++)
		{
			if (answer[j] > answer[j + 1])
			{
				int temp;
				temp = answer[j];
				answer[j] = answer[j + 1];
				answer[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", answer[i]);
	}

}