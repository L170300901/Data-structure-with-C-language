#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define STACK_LEN  100
typedef int Data;
typedef struct _arraystack
{
	Data stackArr[STACK_LEN];
	int top;

} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data Speek(Stack* pstack);


void StackInit(Stack* pstack)
{
	pstack->top = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->top == -1)
		return 1;
	else
		return 0;
}

void SPush(Stack* pstack, Data data)
{
	pstack->top += 1;
	pstack->stackArr[pstack->top] = data;
}

Data SPop(Stack* pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->top;
	pstack->top -= 1;

	return pstack->stackArr[rIdx];
}
Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		exit(-1);
	}
	return pstack->stackArr[pstack->top];
}
int main(void)
{
	Stack s;
	StackInit(&s);
	int n, i,j, temp;
	int num = 0, idx = 0,num2=0;
	int input[100005];
	int output[100005];
	char array[200005];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (input[i] > num)
		{
			while (input[i] < num) 
			{
				num++;
				SPush(&s, num);
				array[idx++] = '+';
			}
		}
		else if (input[i] == num)
		{
			SPop(&s);
			array[idx++] = '-';
		}
		else if (input[i] < num)
		{
			break;
		}
	}
	if (i != n)
		puts("NO\n");
	else
		for (i = 0; i < idx; i++)
		{
			printf("%s", array[i]);
		}
	return 0;
}
	