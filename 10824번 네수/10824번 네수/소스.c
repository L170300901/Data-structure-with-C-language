#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char A[20];
char B[20];
char C[20];
char D[20];
char plus[30];

int main()
{
	scanf(" %s %s %s %s", A, B, C, D);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int lenC = strlen(C);
	int lenD = strlen(D);
	int j = 0;
	for (int i = lenA; i < lenA + lenB; i++)
	{
		A[i] = B[j];
		j++;
	}
	j = 0;
	for (int i = lenC; i < lenC + lenD; i++)
	{
		C[i] = D[j];
		j++;
	}
	long long int result1 = atoll(A);
	long long int result2 = atoll(C);
	printf("%ld", result1 + result2);
}