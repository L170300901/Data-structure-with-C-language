#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int num = 0;
	num = n/(m + 1)*m+n%(m+1);
	printf("%d\n", num);
	return 0;
}