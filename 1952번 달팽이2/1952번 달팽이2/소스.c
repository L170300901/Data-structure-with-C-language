#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cnt,a,b;
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int cnt = m * n;
	int k = 0;
	m--;
	while (1) {
		for (int i = 0; i < n; i++)
			cnt--;
		if (cnt <= 0)
			break;
		n--;
		k++;
		for (int i = 0; i < m; i++)
			cnt--;
		if (cnt <= 0)
			break;
		m--;
		k++;
		for (int i = 0; i < n; i++)
			cnt--;
		if (cnt <= 0)
			break;
		n--;
		k++;
		for (int i = 0; i < m; i++)
			cnt--;
		if (cnt <= 0)
			break;
		m--;
		k++;
	}
	printf("%d", k);
	return 0;
}