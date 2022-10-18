#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct
{
	char str[21];
}Str;
int cmp(const Str* a, const Str* b)
{
	return strcmp(a->str, b->str);
}

int main(void)
{
	int N, M;
	Str* arr;
	Str* find;
	int i, cou = 0;
	scanf("%d%d", &N, &M);
	arr = (Str*)malloc(21 * N);
	find = (Str*)malloc(21 * M);
	//(1)
	for (i = 0; i < N; i++)
		scanf("%s", arr[i].str);
	//(2)
	qsort(arr, N, 21, (int(*)(const void*, const void*))cmp);
	//(3)
	for (i = 0; i < M; i++)
		scanf("%s", find[i].str);
	//(4)
	qsort(find, M, 21, (int(*)(const void*, const void*))cmp);
	//(5)
	for (i = 0; i < M; i++)
		if (bsearch(find[i].str, arr, N, 21, (int(*)(const void*, const void*))cmp) != NULL)
			cou++;
	printf("%d\n", cou);
	//(6)
	for (i = 0; i < M; i++)
		if (bsearch(find[i].str, arr, N, 21, (int(*)(const void*, const void*))cmp) != NULL)
			printf("%s\n", find[i].str);
	return 0;
}