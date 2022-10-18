#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int arr[100001];
int N;

int main()
{
	scanf("%d", &N);
	arr[1] = 1;
	int a, b;
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		while (cnt = 1)
		{
			if (a == 1)
			{
				cnt++;
				break;
			}
			else
			{

			}
		}
		if (arr[a] == 0)
			arr[a] = b;
		else
			arr[b] = a;
	}

	for (int i = 2; i <= N; i++) {
		printf("%d\n", arr[i]);
	}
}